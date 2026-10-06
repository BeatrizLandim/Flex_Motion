#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

// ================================================================
// Sensor Flex - ESP32 DevKit V1
//
// Montagem do divisor:
//   3V3 -> sensor Flex -> GPIO36 -> resistor fixo de 10 kOhm -> GND
//
// Calibracao feita no Monitor Serial, a cada reinicializacao.
// Abra o Monitor Serial em 115200 baud e mantenha "Nova linha" ativado.
// ================================================================

// ---------------------- Wi-Fi e MQTT -----------------------------
// Preencha com os dados da sua rede e do broker. Nao compartilhe senhas.
const char* WIFI_SSID = "NOME";
const char* WIFI_PASSWORD = "SENHA";

const char* MQTT_HOST = "f5ed40d580064617825b438740fade7a.s1.eu.hivemq.cloud";
const uint16_t MQTT_PORT = 8883;
const char* MQTT_USER = "landim";
const char* MQTT_PASSWORD = "SENHA";
const char* MQTT_DATA_TOPIC = "landim/flexmotion/dados";

// -------------------------- Hardware -----------------------------
const uint8_t FLEX_PIN = 36;       // ADC1: funciona normalmente com Wi-Fi
const uint8_t LED_GREEN_PIN = 25;
const uint8_t LED_YELLOW_PIN = 26;
const uint8_t LED_RED_PIN = 27;

const float ADC_REFERENCE_V = 3.3f;
const float FIXED_RESISTOR_OHM = 10000.0f;
const uint16_t ADC_MAX = 4095;

// ------------------------ Comportamento --------------------------
const uint16_t PREPARATION_SECONDS = 5;
const uint16_t CALIBRATION_SAMPLES = 150;
const uint16_t CALIBRATION_SAMPLE_INTERVAL_MS = 10;
const uint16_t MEASUREMENT_SAMPLES = 20;
const uint16_t MEASUREMENT_SAMPLE_INTERVAL_MS = 4;
const uint16_t MIN_CALIBRATION_DISTANCE_ADC = 100;
const uint32_t DATA_INTERVAL_MS = 1000;
const uint32_t WIFI_RETRY_INTERVAL_MS = 10000;
const uint32_t MQTT_RETRY_INTERVAL_MS = 3000;

WiFiClientSecure secureClient;
PubSubClient mqttClient(secureClient);

float calibrationAdc[3] = {0.0f, 0.0f, 0.0f};
bool calibrationIncreasing = true;

uint32_t lastDataAt = 0;
uint32_t lastWifiAttemptAt = 0;
uint32_t lastMqttAttemptAt = 0;

enum LedColor {
  LED_OFF,
  LED_GREEN,
  LED_YELLOW,
  LED_RED
};

void setLed(LedColor color) {
  digitalWrite(LED_GREEN_PIN, color == LED_GREEN ? HIGH : LOW);
  digitalWrite(LED_YELLOW_PIN, color == LED_YELLOW ? HIGH : LOW);
  digitalWrite(LED_RED_PIN, color == LED_RED ? HIGH : LOW);
}

int readRawAdc() {
  return analogRead(FLEX_PIN);
}

float readAverageAdc(uint16_t samples, uint16_t intervalMs) {
  uint32_t sum = 0;

  for (uint16_t i = 0; i < samples; i++) {
    sum += readRawAdc();
    if (i + 1 < samples) delay(intervalMs);
  }

  return static_cast<float>(sum) / samples;
}

float linearInterpolate(float value, float x0, float y0, float x1, float y1) {
  if (x0 == x1) return y0;
  return y0 + ((value - x0) * (y1 - y0) / (x1 - x0));
}

bool calibrationIsValid() {
  const float p1 = calibrationAdc[0];
  const float p2 = calibrationAdc[1];
  const float p3 = calibrationAdc[2];

  const bool increasing = p1 < p2 && p2 < p3;
  const bool decreasing = p1 > p2 && p2 > p3;
  const bool enoughDistance = fabsf(p2 - p1) >= MIN_CALIBRATION_DISTANCE_ADC &&
                              fabsf(p3 - p2) >= MIN_CALIBRATION_DISTANCE_ADC;

  calibrationIncreasing = increasing;
  return (increasing || decreasing) && enoughDistance;
}

float collectCalibrationPoint(uint8_t point, LedColor led, const char* position) {
  setLed(led);

  Serial.println();
  Serial.print("CALIBRACAO - PONTO ");
  Serial.println(point);
  Serial.print("LED ");
  Serial.print(point == 1 ? "VERDE" : point == 2 ? "AMARELO" : "VERMELHO");
  Serial.println(" ACESO");
  Serial.print("Mantenha o dedo ");
  Serial.println(position);

  for (int secondsLeft = PREPARATION_SECONDS; secondsLeft > 0; secondsLeft--) {
    const int currentAdc = readRawAdc();
    Serial.print(secondsLeft);
    Serial.print("... leitura atual do sensor: ");
    Serial.println(currentAdc);
    delay(1000);
  }

  Serial.print("COLETANDO ");
  Serial.print(CALIBRATION_SAMPLES);
  Serial.println(" AMOSTRAS...");

  const float average = readAverageAdc(CALIBRATION_SAMPLES, CALIBRATION_SAMPLE_INTERVAL_MS);
  Serial.print("Media do ponto ");
  Serial.print(point);
  Serial.print(": ");
  Serial.println(average, 2);
  return average;
}

void calibrate() {
  while (true) {
    Serial.println();
    Serial.println("========================================");
    Serial.println("INICIANDO CALIBRACAO");
    Serial.println("========================================");

    calibrationAdc[0] = collectCalibrationPoint(1, LED_GREEN, "ESTENDIDO (0/10 - 0 graus).");
    calibrationAdc[1] = collectCalibrationPoint(2, LED_YELLOW, "NA POSICAO INTERMEDIARIA (5/10 - 45 graus).");
    calibrationAdc[2] = collectCalibrationPoint(3, LED_RED, "NA MAXIMA FLEXAO (10/10 - 90 graus).");

    if (calibrationIsValid()) {
      setLed(LED_OFF);
      Serial.println();
      Serial.println("Calibracao valida.");
      Serial.print("P1: ");
      Serial.println(calibrationAdc[0], 2);
      Serial.print("P2: ");
      Serial.println(calibrationAdc[1], 2);
      Serial.print("P3: ");
      Serial.println(calibrationAdc[2], 2);
      Serial.println(calibrationIncreasing ? "Orientacao ADC: crescente." : "Orientacao ADC: decrescente.");
      return;
    }

    setLed(LED_OFF);
    Serial.println();
    Serial.println("Calibracao invalida.");
    Serial.println("Os pontos devem ser crescentes ou decrescentes e ter pelo menos 100 ADC de distancia entre P1/P2 e P2/P3.");
    Serial.println("Repita mantendo o dedo parado em cada posicao.");
    delay(1500);
  }
}

float adcToLevel(float adc) {
  if (calibrationIncreasing) {
    if (adc <= calibrationAdc[0]) return 0.0f;
    if (adc <= calibrationAdc[1]) return linearInterpolate(adc, calibrationAdc[0], 0.0f, calibrationAdc[1], 5.0f);
    if (adc <= calibrationAdc[2]) return linearInterpolate(adc, calibrationAdc[1], 5.0f, calibrationAdc[2], 10.0f);
  } else {
    if (adc >= calibrationAdc[0]) return 0.0f;
    if (adc >= calibrationAdc[1]) return linearInterpolate(adc, calibrationAdc[0], 0.0f, calibrationAdc[1], 5.0f);
    if (adc >= calibrationAdc[2]) return linearInterpolate(adc, calibrationAdc[1], 5.0f, calibrationAdc[2], 10.0f);
  }

  return 10.0f;
}

float adcToVoltage(float adc) {
  return (adc / ADC_MAX) * ADC_REFERENCE_V;
}

float voltageToFlexResistanceKohm(float voltage) {
  if (voltage <= 0.01f) return 999.0f;

  // Para: 3V3 -> Flex -> ADC -> resistor fixo -> GND.
  const float flexResistanceOhm = FIXED_RESISTOR_OHM * ((ADC_REFERENCE_V / voltage) - 1.0f);
  return max(0.0f, flexResistanceOhm / 1000.0f);
}

void updateMeasurementLed(float level) {
  if (level <= 3.3f) {
    setLed(LED_GREEN);
  } else if (level <= 6.6f) {
    setLed(LED_YELLOW);
  } else {
    setLed(LED_RED);
  }
}

float roundToOneDecimal(float value) {
  return roundf(value * 10.0f) / 10.0f;
}

float roundToTwoDecimals(float value) {
  return roundf(value * 100.0f) / 100.0f;
}

void connectWiFi() {
  if (WiFi.status() == WL_CONNECTED) return;
  if (lastWifiAttemptAt != 0 && millis() - lastWifiAttemptAt < WIFI_RETRY_INTERVAL_MS) return;

  lastWifiAttemptAt = millis();
  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("Tentando conectar ao Wi-Fi...");
}

void connectMqtt() {
  if (mqttClient.connected() || WiFi.status() != WL_CONNECTED) return;
  if (lastMqttAttemptAt != 0 && millis() - lastMqttAttemptAt < MQTT_RETRY_INTERVAL_MS) return;

  lastMqttAttemptAt = millis();
  Serial.print("Conectando ao MQTT...");

  const uint64_t chipId = ESP.getEfuseMac();
  char clientId[32];
  snprintf(clientId, sizeof(clientId), "flex-%04X%08X", static_cast<uint16_t>(chipId >> 32), static_cast<uint32_t>(chipId));

  if (mqttClient.connect(clientId, MQTT_USER, MQTT_PASSWORD)) {
    Serial.println(" conectado.");
  } else {
    Serial.print(" falhou, codigo ");
    Serial.println(mqttClient.state());
  }
}

void publishMeasurement() {
  const int rawAdc = readRawAdc();
  const float averageAdc = readAverageAdc(MEASUREMENT_SAMPLES, MEASUREMENT_SAMPLE_INTERVAL_MS);
  const float level = roundToOneDecimal(constrain(adcToLevel(averageAdc), 0.0f, 10.0f));
  const float angle = roundToOneDecimal(level * 9.0f);
  const float resistanceKohm = roundToTwoDecimals(voltageToFlexResistanceKohm(adcToVoltage(averageAdc)));

  updateMeasurementLed(level);

  // O site recebe somente as quatro grandezas definidas no escopo.
  JsonDocument document;
  document["nivel"] = level;
  document["angulo_graus"] = angle;
  document["resistencia_kohm"] = resistanceKohm;
  document["adc"] = rawAdc;

  char payload[256];
  serializeJson(document, payload, sizeof(payload));

  if (mqttClient.connected()) {
    const bool sent = mqttClient.publish(MQTT_DATA_TOPIC, payload, false);
    if (!sent) Serial.println("Falha ao publicar os dados MQTT.");
  }

  // Ordem exigida para a operacao normal no Monitor Serial.
  Serial.print("Nivel: ");
  Serial.print(level, 1);
  Serial.println("/10");
  Serial.print("Angulacao: ");
  Serial.print(angle, 1);
  Serial.println(" graus");
  Serial.print("Resistencia: ");
  Serial.print(resistanceKohm, 2);
  Serial.println(" kOhm");
  Serial.print("ADC: ");
  Serial.println(rawAdc);
  Serial.print("Media: ");
  Serial.println(averageAdc, 2);
}

void setup() {
  pinMode(LED_GREEN_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  setLed(LED_OFF);

  Serial.begin(115200);
  delay(300);

  analogReadResolution(12);
  analogSetPinAttenuation(FLEX_PIN, ADC_11db);

  Serial.println();
  Serial.println("========================================");
  Serial.println("Sensor Flex - ESP32 DevKit V1");
  Serial.println("Abra o Monitor Serial em 115200 baud.");
  Serial.println("========================================");

  // A calibracao precisa terminar antes de Wi-Fi e MQTT.
  calibrate();

  // O broker do codigo anterior usa TLS. Em um projeto final, prefira setCACert().
  secureClient.setInsecure();
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  mqttClient.setBufferSize(512);

  connectWiFi();
}

void loop() {
  connectWiFi();
  connectMqtt();
  mqttClient.loop();

  // A medicao normal so inicia (ou continua) quando as duas conexoes existem.
  // Se uma delas cair, o ESP32 tenta reconectar e nao faz leituras nem altera LEDs.
  if (WiFi.status() != WL_CONNECTED || !mqttClient.connected()) return;

  if (millis() - lastDataAt >= DATA_INTERVAL_MS) {
    lastDataAt = millis();
    publishMeasurement();
  }
}
