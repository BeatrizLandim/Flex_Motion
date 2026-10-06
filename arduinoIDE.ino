<!DOCTYPE html>
<!-- saved from url=(0114)file:///C:/Users/Setup%20Gamer/Documents/Codex/2026-08-24/aqui-esta-uma-explica-o-de/outputs/FlexMotion_final.html -->
<html lang="pt-BR" data-theme="dark"><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
  
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <meta name="theme-color" content="#0b1212">
  <title>FlexMotion</title>
  <script>
    (() => {
      try {
        document.documentElement.dataset.theme = localStorage.getItem('flexmotion-theme') ||
          (matchMedia('(prefers-color-scheme: dark)').matches ? 'dark' : 'light');
      } catch (_) { document.documentElement.dataset.theme = 'light'; }
    })();
  </script>
  <style>
    :root {
      --bg: #e8f0ec; --surface: #fbfdfb; --surface-alt: #edf5f1; --text: #123b31;
      --muted: #55736a; --line: #c9ddd4; --accent: #238f7c; --accent-soft: #d9f1e9;
      --green: #278f62; --yellow: #c98715; --red: #ce5268; --shadow: 0 18px 50px rgba(27, 72, 59, .14);
      --radius-xl: 28px; --radius-lg: 20px;
    }
    html[data-theme="dark"] {
      --bg: #0b1212; --surface: #111b1a; --surface-alt: #15211f; --text: #ecf7f2;
      --muted: #93a79f; --line: #2a3b37; --accent: #56cdb6; --accent-soft: #17372f;
      --shadow: 0 18px 50px rgba(0, 0, 0, .25);
    }
    * { box-sizing: border-box; }
    html { color-scheme: light; scroll-behavior: smooth; }
    html[data-theme="dark"] { color-scheme: dark; }
    body {
      margin: 0; min-height: 100vh; color: var(--text); background:
        radial-gradient(circle at 8% 0%, rgba(126, 213, 187, .23), transparent 25rem),
        radial-gradient(circle at 96% 15%, rgba(167, 150, 225, .16), transparent 27rem), var(--bg);
      font-family: Inter, ui-sans-serif, system-ui, -apple-system, "Segoe UI", sans-serif;
      -webkit-font-smoothing: antialiased;
    }
    button, input { font: inherit; }
    button { cursor: pointer; }
    .app { width: min(1240px, calc(100% - 48px)); margin: auto; padding: 24px 0 48px; }
    .topbar { display: flex; justify-content: space-between; align-items: center; gap: 18px; margin-bottom: 22px; }
    .brand, .topbar-actions, .connection-pill, .metric-top, .chart-legend, .history-head { display: flex; align-items: center; }
    .brand { gap: 12px; }
    .brand-mark { display: grid; width: 47px; height: 47px; place-items: center; overflow: hidden; border: 1px solid rgba(255,255,255,.52); border-radius: 15px; background: linear-gradient(145deg, #5cd7c1, #32a991); box-shadow: 0 12px 25px rgba(35,143,124,.30), inset 0 1px rgba(255,255,255,.4); }
    .brand-mark svg { width: 32px; height: 32px; filter: drop-shadow(0 2px 2px rgba(10,80,66,.17)); }
    .brand-name { margin: 0; font-size: 16px; font-weight: 800; letter-spacing: -.02em; }
    .brand-subtitle { margin: 3px 0 0; color: var(--muted); font-size: 12px; }
    .topbar-actions { gap: 9px; }
    .connection-pill, .icon-button, .settings-button { min-height: 40px; border: 1px solid var(--line); border-radius: 999px; background: color-mix(in srgb, var(--surface) 90%, transparent); box-shadow: 0 8px 24px rgba(36,76,65,.05); }
    .connection-pill { gap: 8px; padding: 0 13px; color: var(--muted); font-size: 12px; font-weight: 750; }
    .connection-dot { width: 8px; height: 8px; border-radius: 50%; background: #8b9996; }
    .connection-pill[data-status="connected"] { color: #27825d; border-color: #ccebdd; background: #f2fbf7; }
    .connection-pill[data-status="connected"] .connection-dot { background: var(--green); box-shadow: 0 0 0 5px rgba(55,173,120,.12), 0 0 14px rgba(55,173,120,.55); animation: pulse 1.8s infinite; }
    .connection-pill[data-status="connecting"] .connection-dot { background: var(--yellow); }
    .icon-button, .settings-button { color: var(--text); padding: 0 13px; font-size: 12px; font-weight: 750; }
    .icon-button { display: grid; width: 40px; padding: 0; place-items: center; }
    .theme-moon, .theme-sun { width: 17px; height: 17px; fill: none; stroke: currentColor; stroke-width: 1.8; }
    .theme-sun { display: none; color: #d79420; } html[data-theme="dark"] .theme-moon { display: none; } html[data-theme="dark"] .theme-sun { display: block; }
    .settings-button { display: inline-flex; align-items: center; gap: 8px; }
    .hero, .panel, .metric-card { border: 1px solid var(--line); background: color-mix(in srgb, var(--surface) 93%, transparent); box-shadow: var(--shadow); }
    .hero { position: relative; display: grid; min-height: 300px; grid-template-columns: minmax(0, 1.25fr) minmax(280px, .75fr); align-items: center; gap: 48px; overflow: hidden; margin-bottom: 16px; padding: 46px 50px; border-radius: var(--radius-xl); isolation: isolate; }
    .hero::after { position: absolute; z-index: -1; right: -130px; bottom: -210px; width: 520px; height: 520px; content: ""; border-radius: 50%; background: radial-gradient(circle, rgba(118,215,190,.25), transparent 67%); }
    .eyebrow { margin: 0 0 16px; color: var(--accent); font-size: 11px; font-weight: 800; letter-spacing: .13em; text-transform: uppercase; }
    h1, h2, h3, p { margin-top: 0; }
    h1 { max-width: 720px; margin-bottom: 0; font-size: clamp(38px, 5vw, 66px); font-weight: 760; line-height: 1.02; letter-spacing: -.055em; }
    .hero-description { max-width: 620px; margin: 20px 0 0; color: var(--muted); font-size: 15px; line-height: 1.7; }
    .hero-actions { display: flex; flex-wrap: wrap; gap: 10px; margin-top: 26px; }
    .btn { min-height: 45px; padding: 0 18px; border: 0; border-radius: 14px; font-size: 12px; font-weight: 780; transition: transform .15s ease, opacity .15s ease; }
    .btn:hover { transform: translateY(-1px); }
    .btn-primary { color: #fff; background: #2fae98; box-shadow: 0 12px 26px rgba(47,174,152,.22); }
    .btn-secondary { color: var(--text); border: 1px solid var(--line); background: var(--surface); }
    .hero-visual { position: relative; display: grid; min-height: 215px; place-items: center; }
    .sensor-orbit { display: grid; width: 245px; aspect-ratio: 1; place-items: center; border: 1px solid color-mix(in srgb, var(--accent) 28%, var(--line)); border-radius: 50%; background: radial-gradient(circle, color-mix(in srgb, var(--accent-soft) 70%, var(--surface)) 0 59%, transparent 60%), linear-gradient(145deg, rgba(65,190,170,.12), rgba(129,106,217,.08)); box-shadow: inset 0 0 0 18px color-mix(in srgb, var(--accent) 6%, transparent), 0 20px 36px rgba(34,97,81,.11); }
    .sensor-orbit::before { position: absolute; width: 178px; height: 178px; content: ""; border: 1px solid color-mix(in srgb, var(--accent) 42%, var(--line)); border-radius: 50%; }
    .sensor-orbit::after { position: absolute; top: 23px; left: 40px; width: 12px; height: 12px; content: ""; border-radius: 50%; background: #8f7be0; box-shadow: 144px 136px 0 #ee7185; }
    .hero-sensor { position: relative; z-index: 1; width: 165px; height: 165px; filter: drop-shadow(0 10px 10px rgba(21,113,97,.18)); }
    .live-chip { position: absolute; z-index: 2; right: -14px; bottom: 10px; display: inline-flex; align-items: center; gap: 7px; padding: 9px 12px; color: var(--text); border: 1px solid color-mix(in srgb, var(--accent) 26%, var(--line)); border-radius: 999px; background: color-mix(in srgb, var(--surface) 94%, transparent); box-shadow: 0 10px 22px rgba(36,76,65,.12); font-size: 10px; font-weight: 760; }
    .live-chip i { width: 7px; height: 7px; border-radius: 50%; background: var(--green); box-shadow: 0 0 0 5px rgba(55,173,120,.12); }
    .metrics { display: grid; grid-template-columns: repeat(4, minmax(0, 1fr)); gap: 12px; margin-bottom: 16px; }
    .metric-card { min-height: 132px; padding: 20px 21px; border-radius: var(--radius-lg); }
    .metric-top { justify-content: space-between; gap: 10px; }
    .metric-label { margin: 0; color: var(--muted); font-size: 10px; font-weight: 800; letter-spacing: .1em; text-transform: uppercase; }
    .metric-icon { display: grid; width: 34px; height: 34px; place-items: center; border-radius: 11px; color: var(--accent); background: var(--accent-soft); font-size: 15px; }
    .metric-icon svg { width: 18px; height: 18px; fill: none; stroke: currentColor; stroke-linecap: round; stroke-linejoin: round; stroke-width: 1.8; }
    .level-icon { color: #8d7ada; background: #eeebff; box-shadow: inset 0 1px rgba(255,255,255,.7); }
    .adc-icon { color: #df6d82; background: #fff0f2; }
    .metric-card:nth-child(2) .metric-icon { color: #8275ce; background: #f0eefb; }
    .metric-card:nth-child(3) .metric-icon { color: #dc8d23; background: #fff5e4; }
    .metric-card:nth-child(4) .metric-icon { color: #df6678; background: #fff0f2; }
    html[data-theme="dark"] .metric-card:nth-child(2) .metric-icon { background: rgba(142,130,216,.16); } html[data-theme="dark"] .metric-card:nth-child(3) .metric-icon { background: rgba(232,170,50,.14); } html[data-theme="dark"] .metric-card:nth-child(4) .metric-icon { background: rgba(233,109,126,.14); }
    .metric-value { margin: 16px 0 0; font-size: clamp(26px, 3vw, 36px); font-weight: 740; letter-spacing: -.045em; font-variant-numeric: tabular-nums; }
    .metric-unit { margin-left: 4px; color: var(--muted); font-size: 13px; font-weight: 640; letter-spacing: 0; }
    .workspace { display: grid; grid-template-columns: minmax(0, 1.7fr) minmax(290px, .72fr); gap: 16px; margin-bottom: 16px; }
    .panel { border-radius: var(--radius-xl); }
    .chart-panel, .state-panel { min-height: 404px; padding: 25px; }
    .chart-head, .history-head { display: flex; align-items: flex-start; justify-content: space-between; gap: 16px; }
    .panel-kicker { margin: 0 0 6px; color: var(--muted); font-size: 10px; font-weight: 800; letter-spacing: .12em; text-transform: uppercase; }
    h2 { margin-bottom: 0; font-size: 19px; letter-spacing: -.025em; } h3 { margin-bottom: 0; font-size: 15px; }
    .chart-legend { flex-wrap: wrap; justify-content: flex-end; gap: 10px; color: var(--muted); font-size: 10px; }
    .chart-legend span { display: inline-flex; align-items: center; gap: 5px; }
    .dot { width: 7px; height: 7px; border-radius: 50%; }
    .chart-wrap { position: relative; height: 305px; margin-top: 18px; }
    canvas { display: block; width: 100%; height: 100%; }
    .state-panel { display: flex; flex-direction: column; }
    .gauge-wrap { display: grid; flex: 1; place-items: center; padding: 17px 0 10px; }
    .gauge { --gauge-angle: 0deg; position: relative; display: grid; width: min(225px, 72vw); aspect-ratio: 1; place-items: center; border-radius: 50%; background: radial-gradient(circle, var(--surface) 57%, transparent 58%), conic-gradient(from 220deg, var(--accent) var(--gauge-angle), var(--line) 0 280deg, transparent 0); filter: drop-shadow(0 20px 28px rgba(28,80,65,.12)); }
    .gauge::after { position: absolute; width: 74%; aspect-ratio: 1; content: ""; border: 1px solid var(--line); border-radius: 50%; }
    .gauge-center { position: relative; z-index: 1; text-align: center; }
    .gauge-value { display: block; font-size: 46px; font-weight: 760; letter-spacing: -.06em; line-height: 1; font-variant-numeric: tabular-nums; }
    .gauge-caption { display: block; margin-top: 8px; color: var(--muted); font-size: 10px; font-weight: 800; letter-spacing: .13em; text-transform: uppercase; }
    .state-badge { display: flex; min-height: 48px; align-items: center; justify-content: center; gap: 9px; color: var(--muted); border: 1px solid var(--line); border-radius: 14px; background: var(--surface-alt); font-size: 12px; font-weight: 780; letter-spacing: .06em; text-transform: uppercase; }
    .state-indicator { width: 9px; height: 9px; border-radius: 50%; background: #8b9996; }
    .history-panel { overflow: hidden; }
    .history-head { align-items: center; padding: 22px 24px; border-bottom: 1px solid var(--line); }
    .message-count { color: var(--muted); font-size: 11px; font-variant-numeric: tabular-nums; }
    .table-scroll { overflow-x: auto; }
    table { width: 100%; border-collapse: collapse; font-size: 12px; } th, td { padding: 14px 24px; text-align: left; white-space: nowrap; border-bottom: 1px solid var(--line); } th { color: var(--muted); background: color-mix(in srgb, var(--surface-alt) 75%, transparent); font-size: 9px; letter-spacing: .1em; text-transform: uppercase; } td { font-variant-numeric: tabular-nums; } tbody tr:last-child td { border-bottom: 0; }.empty-row td { padding: 28px 24px; color: var(--muted); text-align: center; }
    dialog { width: min(650px, calc(100% - 28px)); padding: 0; color: var(--text); border: 0; border-radius: 26px; background: transparent; box-shadow: 0 24px 80px rgba(0,0,0,.28); } dialog::backdrop { background: rgba(4,17,13,.48); backdrop-filter: blur(4px); }
    .connect-panel { padding: 31px; border: 1px solid var(--line); border-radius: 26px; background: var(--surface); }.dialog-head { display: flex; align-items: flex-start; justify-content: space-between; gap: 16px; margin-bottom: 23px; }.dialog-close { width: 32px; height: 32px; color: var(--muted); border: 1px solid var(--line); border-radius: 10px; background: var(--surface-alt); font-size: 20px; line-height: 1; }
    .form-grid { display: grid; grid-template-columns: .82fr 1.18fr; gap: 13px; }.field-wide { grid-column: 1 / -1; } label { display: block; margin-bottom: 7px; color: var(--muted); font-size: 11px; font-weight: 720; } input { width: 100%; height: 46px; padding: 0 13px; color: var(--text); border: 1px solid var(--line); outline: 0; border-radius: 11px; background: var(--surface-alt); font-size: 13px; } input:focus { border-color: var(--accent); box-shadow: 0 0 0 3px color-mix(in srgb, var(--accent) 15%, transparent); }.button-row { display: grid; grid-template-columns: 1fr auto; gap: 10px; margin-top: 16px; }.security-hint { margin: 15px 0 0; color: var(--muted); font-size: 11px; line-height: 1.45; }
    .toast { position: fixed; z-index: 10; right: 24px; bottom: 24px; max-width: min(390px, calc(100vw - 48px)); padding: 14px 16px; color: var(--text); border: 1px solid var(--line); border-radius: 14px; background: var(--surface); box-shadow: var(--shadow); font-size: 12px; line-height: 1.45; opacity: 0; pointer-events: none; transform: translateY(10px); transition: opacity .18s ease, transform .18s ease; }.toast.show { opacity: 1; transform: translateY(0); }.toast.error { border-color: rgba(233,109,126,.55); }
    @keyframes pulse { 50% { opacity: .5; } }
    @media (max-width: 980px) { .hero, .workspace { grid-template-columns: 1fr; }.metrics { grid-template-columns: repeat(2, minmax(0,1fr)); }.state-panel { min-height: 370px; }.hero { padding: 36px; } }
    @media (max-width: 620px) { .app { width: min(100% - 24px, 1240px); padding-top: 16px; }.topbar { align-items: flex-start; }.brand-subtitle, .settings-button span { display: none; }.hero { min-height: auto; padding: 30px 23px; }.hero-visual { min-height: 180px; }.sensor-orbit { width: 166px; }.metrics { gap: 10px; }.metric-card { min-height: 122px; padding: 16px; }.metric-value { font-size: 27px; }.chart-head { flex-direction: column; }.chart-legend { justify-content: flex-start; }.chart-wrap { height: 250px; }.form-grid { grid-template-columns: 1fr; }.field-wide { grid-column: auto; } th, td { padding-right: 16px; padding-left: 16px; } }
    @media (prefers-reduced-motion: reduce) { *,*::before,*::after { scroll-behavior: auto!important; animation-duration: .01ms!important; animation-iteration-count: 1!important; transition-duration: .01ms!important; } }
  </style>
</head>
<body>
  <main class="app">
    <header class="topbar">
      <div class="brand"><div class="brand-mark" aria-hidden="true"><svg viewBox="0 0 48 48"><path d="M17 36.5 28.8 10c1.6-3.7 5.8-5.3 9.4-3.7s5.3 5.8 3.7 9.4L30.1 42.1c-1.6 3.7-5.8 5.3-9.4 3.7s-5.3-5.8-3.7-9.3Z" fill="none" stroke="white" stroke-linejoin="round" stroke-width="3.4"></path><path d="m23.2 22.5 10.5 4.7M20 29.7l10.5 4.7" stroke="white" stroke-linecap="round" stroke-width="3.4"></path></svg></div><div><p class="brand-name">FlexMotion</p><p class="brand-subtitle">ESP32 · Sensor flex · MQTT</p></div></div>
      <div class="topbar-actions">
        <div class="connection-pill" id="connectionPill" data-status="disconnected" role="status"><span class="connection-dot"></span><span id="connectionText">Desconectado</span></div>
        <button class="icon-button" id="themeButton" type="button" aria-label="Alternar tema" title="Alternar tema"><svg class="theme-moon" viewBox="0 0 24 24" aria-hidden="true"><path d="M20.2 15.4A8.5 8.5 0 0 1 8.6 3.8 8.7 8.7 0 1 0 20.2 15.4Z"></path></svg><svg class="theme-sun" viewBox="0 0 24 24" aria-hidden="true"><circle cx="12" cy="12" r="3.7"></circle><path d="M12 2v2.1M12 19.9V22M4.9 4.9l1.5 1.5m11.2 11.2 1.5 1.5M2 12h2.1M19.9 12H22M4.9 19.1l1.5-1.5M17.6 6.4l1.5-1.5"></path></svg></button>
        <button class="settings-button" id="settingsButton" type="button"><span>⚙</span><span>Configurar MQTT</span></button>
      </div>
    </header>

    <section class="hero">
      <div>
        <p class="eyebrow">Monitoramento em tempo real</p>
        <h1>Movimento que vira dado.</h1>
        <p class="hero-description">Acompanhe a flexão do dedo com leveza e precisão — da ESP32 ao navegador, por meio do HiveMQ Cloud.</p>
        <div class="hero-actions"><button class="btn btn-primary" id="demoButton" type="button">Iniciar demonstração</button><button class="btn btn-secondary" id="heroSettingsButton" type="button">Conectar sensor</button></div>
      </div>
      <div class="hero-visual" aria-hidden="true"><div class="sensor-orbit"><svg class="hero-sensor" viewBox="0 0 180 180"><path d="M55 142.5 93.1 57c5-11.2 18.2-16.3 29.4-11.3l7.1 3.2c11.2 5 16.3 18.2 11.3 29.4l-38.1 85.5c-5 11.2-18.2 16.3-29.4 11.3l-7.1-3.2c-11.2-5-16.3-18.2-11.3-29.4Z" fill="none" stroke="#3ec4ad" stroke-linejoin="round" stroke-width="9"></path><path d="m75.8 101.9 37.2 16.6M66.8 122.1 104 138.7" fill="none" stroke="#81ead5" stroke-linecap="round" stroke-width="8"></path><path d="m120 73.5 15 6.7-13.6 30.5" fill="none" stroke="#163c34" stroke-width="10"></path></svg></div><span class="live-chip"><i></i>Leitura contínua</span></div>
    </section>

    <section class="metrics" aria-label="Medições atuais">
      <article class="metric-card"><div class="metric-top"><p class="metric-label">Nível</p><span class="metric-icon level-icon" aria-label="Indicador de nível"><svg viewBox="0 0 24 24"><path d="M4 12h3l2.2-4.3 3.2 8.6 2.5-5 1.6 2.7H20"></path></svg></span></div><p class="metric-value"><span id="levelValue">0.0</span><span class="metric-unit">/ 10</span></p></article>
      <article class="metric-card"><div class="metric-top"><p class="metric-label">Angulação</p><span class="metric-icon">∠</span></div><p class="metric-value"><span id="angleValue">0.0</span><span class="metric-unit">°</span></p></article>
      <article class="metric-card"><div class="metric-top"><p class="metric-label">Resistência</p><span class="metric-icon">Ω</span></div><p class="metric-value"><span id="resistanceValue">0.00</span><span class="metric-unit">kΩ</span></p></article>
      <article class="metric-card"><div class="metric-top"><p class="metric-label">ADC</p><span class="metric-icon adc-icon" aria-label="Conversor ADC"><svg viewBox="0 0 24 24"><rect x="7" y="7" width="10" height="10" rx="1.7"></rect><path d="M9 3v2.5m3-2.5v2.5m3-2.5v2.5M9 18.5V21m3-2.5V21m3-2.5V21M3 9h2.5m-2.5 3h2.5m-2.5 3h2.5m13-6H21m-2.5 3H21m-2.5 3H21"></path></svg></span></div><p class="metric-value"><span id="adcValue">0</span></p></article>
    </section>

    <section class="workspace">
      <article class="panel chart-panel"><div class="chart-head"><div><p class="panel-kicker">Últimas 60 amostras</p><h2>Curva de nível</h2></div><div class="chart-legend"><span><i class="dot" style="background:var(--green)"></i>Pouca flexão</span><span><i class="dot" style="background:var(--yellow)"></i>Intermediária</span><span><i class="dot" style="background:var(--red)"></i>Alta flexão</span></div></div><div class="chart-wrap"><canvas id="levelChart" aria-label="Gráfico do nível de flexão" width="808" height="305"></canvas></div></article>
      <aside class="panel state-panel"><div><p class="panel-kicker">Leitura instantânea</p><h2>Angulação da falange média <span style="color:var(--muted); font-size:.72em; font-weight:700; white-space:nowrap;">(dedo)</span></h2></div><div class="gauge-wrap"><div class="gauge" id="gauge"><div class="gauge-center"><span class="gauge-value" id="gaugeValue">0.0°</span><span class="gauge-caption">angulação</span></div></div></div><div class="state-badge" id="stateBadge"><span class="state-indicator" id="stateIndicator"></span><span id="stateText">Aguardando dados</span></div></aside>
    </section>

    <section class="panel history-panel"><div class="history-head"><div><p class="panel-kicker">Recebimento MQTT</p><h3>Histórico recente</h3></div><span class="message-count" id="messageCount">0 mensagens</span></div><div class="table-scroll"><table><thead><tr><th>Horário</th><th>Nível</th><th>Angulação</th><th>Resistência</th><th>ADC</th></tr></thead><tbody id="historyBody"><tr class="empty-row"><td colspan="5">Conecte ao MQTT ou inicie a demonstração para visualizar dados.</td></tr></tbody></table></div></section>
  </main>

  <dialog id="connectDialog" aria-labelledby="connectionTitle"><section class="connect-panel"><div class="dialog-head"><div><p class="panel-kicker">HiveMQ Cloud</p><h2 id="connectionTitle">Conectar ao sensor</h2></div><button class="dialog-close" id="closeDialogButton" type="button" aria-label="Fechar">×</button></div><form id="connectionForm"><div class="form-grid"><div><label for="host">Servidor</label><input id="host" value="f5ed40d580064617825b438740fade7a.s1.eu.hivemq.cloud" autocomplete="off"></div><div><label for="port">Porta</label><input id="port" value="8884" inputmode="numeric"></div><div><label for="username">Usuário</label><input id="username" value="landim" autocomplete="username"></div><div><label for="password">Senha</label><input id="password" type="password" placeholder="Digite a senha" autocomplete="current-password"></div><div class="field-wide"><label for="topic">Tópico base</label><input id="topic" value="landim/flexmotion" autocomplete="off"></div></div><div class="button-row"><button class="btn btn-primary" id="connectButton" type="submit">Conectar agora</button><button class="btn btn-secondary" id="cancelDialogButton" type="button">Cancelar</button></div><p class="security-hint">A senha é usada somente nesta sessão e não é gravada pelo painel.</p></form></section></dialog>
  <div class="toast" id="toast" role="status" aria-live="polite"></div>

  <script src="./FlexMotionFinal0_files/mqtt.min.js.download"></script>
  <script>
    const MAX_POINTS = 60, MAX_ROWS = 8, MAX_LEVEL = 10;
    const ui = {
      form: document.getElementById('connectionForm'), host: document.getElementById('host'), port: document.getElementById('port'), username: document.getElementById('username'), password: document.getElementById('password'), topic: document.getElementById('topic'), connectButton: document.getElementById('connectButton'), demoButton: document.getElementById('demoButton'), themeButton: document.getElementById('themeButton'), pill: document.getElementById('connectionPill'), connectionText: document.getElementById('connectionText'), level: document.getElementById('levelValue'), angle: document.getElementById('angleValue'), resistance: document.getElementById('resistanceValue'), adc: document.getElementById('adcValue'), gauge: document.getElementById('gauge'), gaugeValue: document.getElementById('gaugeValue'), stateBadge: document.getElementById('stateBadge'), stateIndicator: document.getElementById('stateIndicator'), stateText: document.getElementById('stateText'), historyBody: document.getElementById('historyBody'), messageCount: document.getElementById('messageCount'), canvas: document.getElementById('levelChart'), toast: document.getElementById('toast')
    };
    const connectionDialog = document.getElementById('connectDialog');
    let mqttClient = null, demoTimer = null, toastTimer = null, baseTopic = 'landim/flexmotion', totalMessages = 0;
    let history = [], chartPoints = [];
    const numeric = (value, fallback = 0) => Number.isFinite(Number(value)) ? Number(value) : fallback;
    const clamp = (value, min, max) => Math.min(max, Math.max(min, value));
    const currentTheme = () => document.documentElement.dataset.theme === 'dark' ? 'dark' : 'light';
    function setTheme(theme, persist = true) {
      const selected = theme === 'dark' ? 'dark' : 'light'; document.documentElement.dataset.theme = selected;
      document.querySelector('meta[name="theme-color"]').setAttribute('content', selected === 'dark' ? '#0b1212' : '#f4f7f5');
      if (persist) try { localStorage.setItem('flexmotion-theme', selected); } catch (_) {}
      drawChart();
    }
    function setConnection(status, text) { ui.pill.dataset.status = status; ui.connectionText.textContent = text; }
    function showToast(message, type = 'normal') { clearTimeout(toastTimer); ui.toast.textContent = message; ui.toast.className = `toast show${type === 'error' ? ' error' : ''}`; toastTimer = setTimeout(() => ui.toast.className = 'toast', 4300); }
    function openConnectionDialog() { typeof connectionDialog.showModal === 'function' ? connectionDialog.showModal() : connectionDialog.setAttribute('open', ''); }
    function closeConnectionDialog() { typeof connectionDialog.close === 'function' ? connectionDialog.close() : connectionDialog.removeAttribute('open'); }
    function flexState(level) { return level <= 3.3 ? { text: 'Pouca flexão', color: '#37ad78' } : level <= 6.6 ? { text: 'Flexão intermediária', color: '#e8aa32' } : { text: 'Alta flexão', color: '#e96d7e' }; }
    function resetReadingView() {
      history = []; chartPoints = []; totalMessages = 0; ui.level.textContent = '0.0'; ui.angle.textContent = '0.0'; ui.resistance.textContent = '0.00'; ui.adc.textContent = '0'; ui.gaugeValue.textContent = '0.0°'; ui.gauge.style.setProperty('--gauge-angle', '0deg'); ui.stateText.textContent = 'Aguardando dados'; ui.stateIndicator.style.background = '#8b9996'; ui.stateBadge.style.borderColor = ''; ui.messageCount.textContent = '0 mensagens'; ui.historyBody.innerHTML = '<tr class="empty-row"><td colspan="5">Aguardando dados da ESP32.</td></tr>'; drawChart();
    }
    function processReading(payload) {
      const level = clamp(numeric(payload.nivel), 0, 10);
      const angle = clamp(numeric(payload.angulo_graus), 0, 90);
      const reading = { time: new Date(), level, angle, resistance: Math.max(0, numeric(payload.resistencia_kohm)), adc: Math.max(0, Math.round(numeric(payload.adc))) };
      totalMessages++; chartPoints.push(reading); history.unshift(reading); if (chartPoints.length > MAX_POINTS) chartPoints.shift(); if (history.length > MAX_ROWS) history.pop(); updateDashboard(reading); renderHistory(); drawChart();
    }
    function updateDashboard(reading) {
      const state = flexState(reading.level); ui.level.textContent = reading.level.toFixed(1); ui.angle.textContent = reading.angle.toFixed(1); ui.resistance.textContent = reading.resistance.toFixed(2); ui.adc.textContent = String(reading.adc); ui.gaugeValue.textContent = `${reading.angle.toFixed(1)}°`; ui.gauge.style.setProperty('--gauge-angle', `${(reading.angle / 90) * 280}deg`); ui.stateText.textContent = state.text; ui.stateIndicator.style.background = state.color; ui.stateIndicator.style.boxShadow = `0 0 14px ${state.color}`; ui.stateBadge.style.borderColor = `${state.color}55`; ui.messageCount.textContent = `${totalMessages} ${totalMessages === 1 ? 'mensagem' : 'mensagens'}`;
    }
    function renderHistory() {
      ui.historyBody.innerHTML = history.length ? history.map(item => `<tr><td>${item.time.toLocaleTimeString('pt-BR', {hour:'2-digit', minute:'2-digit', second:'2-digit'})}</td><td>${item.level.toFixed(1)} / 10</td><td>${item.angle.toFixed(1)}°</td><td>${item.resistance.toFixed(2)} kΩ</td><td>${item.adc}</td></tr>`).join('') : '<tr class="empty-row"><td colspan="5">Aguardando dados da ESP32.</td></tr>';
    }
    function drawChart() {
      const canvas = ui.canvas, rect = canvas.getBoundingClientRect(); if (!rect.width || !rect.height) return;
      const dpr = Math.min(devicePixelRatio || 1, 2); canvas.width = Math.round(rect.width * dpr); canvas.height = Math.round(rect.height * dpr);
      const ctx = canvas.getContext('2d'); ctx.setTransform(dpr,0,0,dpr,0,0); ctx.clearRect(0,0,rect.width,rect.height);
      const pad = { top: 12, right: 12, bottom: 31, left: 42 }, width = rect.width - pad.left - pad.right, height = rect.height - pad.top - pad.bottom, y = value => pad.top + height - (value / MAX_LEVEL) * height;
      const dark = currentTheme() === 'dark', grid = dark ? 'rgba(215,235,226,.18)' : 'rgba(29,91,73,.20)', label = dark ? '#b4c7c0' : '#426259';
      const zones = dark
        ? [[0,3.3,'rgba(55,173,120,.13)'],[3.3,6.6,'rgba(232,170,50,.12)'],[6.6,10,'rgba(233,109,126,.12)']]
        : [[0,3.3,'rgba(55,173,120,.24)'],[3.3,6.6,'rgba(232,170,50,.22)'],[6.6,10,'rgba(233,109,126,.21)']];
      zones.forEach(([min,max,color]) => { ctx.fillStyle = color; ctx.fillRect(pad.left,y(max),width,y(min)-y(max)); });
      ctx.font = '10px Inter, system-ui, sans-serif'; ctx.textAlign = 'right'; ctx.textBaseline = 'middle'; [0,2.5,5,7.5,10].forEach(value => { const py = y(value); ctx.strokeStyle = grid; ctx.beginPath(); ctx.moveTo(pad.left,py); ctx.lineTo(pad.left+width,py); ctx.stroke(); ctx.fillStyle = label; ctx.fillText(value.toFixed(value % 1 ? 1 : 0),pad.left-9,py); });
      if (!chartPoints.length) { ctx.fillStyle = label; ctx.textAlign = 'center'; ctx.font = '12px Inter, system-ui, sans-serif'; ctx.fillText('Aguardando as primeiras amostras',pad.left+width/2,pad.top+height/2); return; }
      const x = index => chartPoints.length === 1 ? pad.left+width : pad.left + (index/(MAX_POINTS-1))*width, shift = MAX_POINTS-chartPoints.length, line = new Path2D(); chartPoints.forEach((point,index) => { const px=x(index+shift), py=y(point.level); index ? line.lineTo(px,py) : line.moveTo(px,py); });
      const firstX=x(shift), lastX=x(MAX_POINTS-1), area = new Path2D(line); area.lineTo(lastX,y(0)); area.lineTo(firstX,y(0)); area.closePath(); const gradient=ctx.createLinearGradient(0,pad.top,0,pad.top+height); gradient.addColorStop(0,'rgba(55,173,152,.25)'); gradient.addColorStop(1,'rgba(55,173,152,.005)'); ctx.fillStyle=gradient; ctx.fill(area); ctx.strokeStyle='#42bca7'; ctx.lineWidth=2.5; ctx.lineJoin='round'; ctx.lineCap='round'; ctx.stroke(line);
      const last = chartPoints.at(-1), state = flexState(last.level); ctx.fillStyle=state.color; ctx.beginPath(); ctx.arc(lastX,y(last.level),4.5,0,Math.PI*2); ctx.fill(); ctx.fillStyle=label; ctx.font='10px Inter, system-ui, sans-serif'; ctx.textBaseline='bottom'; ctx.textAlign='left'; ctx.fillText(chartPoints[0].time.toLocaleTimeString('pt-BR'),pad.left,rect.height-4); ctx.textAlign='right'; ctx.fillText(last.time.toLocaleTimeString('pt-BR'),pad.left+width,rect.height-4);
    }
    function disconnectMQTT() { if (mqttClient) { mqttClient.end(true); mqttClient = null; } }
    function stopDemo() { if (demoTimer) { clearInterval(demoTimer); demoTimer = null; } ui.demoButton.textContent = 'Iniciar demonstração'; }
    function connectMQTT() {
      stopDemo(); disconnectMQTT(); if (!window.mqtt) { showToast('A biblioteca MQTT não carregou. Verifique a conexão com a internet.', 'error'); return; }
      const host=ui.host.value.trim(), port=ui.port.value.trim()||'8884', username=ui.username.value.trim(), password=ui.password.value; baseTopic=ui.topic.value.trim().replace(/\/+$/, '');
      if (!host || !username || !password || !baseTopic) { showToast('Preencha servidor, usuário, senha e tópico para conectar.', 'error'); return; }
      resetReadingView(); setConnection('connecting','Conectando…'); ui.connectButton.disabled=true; const randomId=crypto.randomUUID ? crypto.randomUUID().slice(0,8) : Math.random().toString(16).slice(2,10);
      mqttClient=mqtt.connect(`wss://${host}:${port}/mqtt`,{username,password,clientId:`flexmotion-web-${randomId}`,clean:true,connectTimeout:12000,reconnectPeriod:2500,keepalive:30,protocolVersion:4});
      mqttClient.on('connect',()=>{ setConnection('connected','MQTT conectado'); ui.connectButton.disabled=false; ui.connectButton.textContent='Reconectar'; mqttClient.subscribe(`${baseTopic}/dados`,{qos:0},error=>{ if(error) showToast(`Não foi possível assinar o tópico: ${error.message}`, 'error'); else { closeConnectionDialog(); showToast('Conectado. Aguardando as medições da ESP32.'); } }); });
      mqttClient.on('message',(topic,message)=>{ if(topic !== `${baseTopic}/dados`) return; try { processReading(JSON.parse(message.toString())); } catch (_) { showToast('Mensagem recebida, mas o conteúdo não é um JSON válido.', 'error'); } });
      mqttClient.on('reconnect',()=>setConnection('connecting','Reconectando…')); mqttClient.on('offline',()=>setConnection('connecting','Sem conexão')); mqttClient.on('close',()=>{ if(mqttClient) setConnection('disconnected','Desconectado'); }); mqttClient.on('error',error=>{ ui.connectButton.disabled=false; setConnection('disconnected','Falha na conexão'); showToast(`Falha MQTT: ${error.message || 'verifique as credenciais'}`, 'error'); });
    }
    function toggleDemo() {
      if (demoTimer) { stopDemo(); setConnection('disconnected','Demonstração pausada'); return; }
      disconnectMQTT(); resetReadingView(); setConnection('connected','Modo demonstração'); ui.demoButton.textContent='Parar demo'; showToast('Demonstração iniciada com dados simulados.'); let phase=0;
      const generate=()=>{ phase+=.28; const level=clamp(5+Math.sin(phase)*4.2+(Math.random()-.5)*.22,0,10), angle=level*9; processReading({nivel:level,angulo_graus:angle,resistencia_kohm:10.2+level*1.65+Math.random()*.25,adc:Math.round(1200+level*230)}); }; generate(); demoTimer=setInterval(generate,900);
    }
    ui.form.addEventListener('submit',event=>{event.preventDefault();connectMQTT();}); ui.demoButton.addEventListener('click',toggleDemo); ui.themeButton.addEventListener('click',()=>setTheme(currentTheme()==='dark'?'light':'dark')); document.getElementById('settingsButton').addEventListener('click',openConnectionDialog); document.getElementById('heroSettingsButton').addEventListener('click',openConnectionDialog); document.getElementById('closeDialogButton').addEventListener('click',closeConnectionDialog); document.getElementById('cancelDialogButton').addEventListener('click',closeConnectionDialog); connectionDialog.addEventListener('click',event=>{if(event.target===connectionDialog)closeConnectionDialog();}); window.addEventListener('resize',drawChart); window.addEventListener('beforeunload',()=>{stopDemo();disconnectMQTT();}); if('ResizeObserver' in window)new ResizeObserver(drawChart).observe(ui.canvas.parentElement); setTheme(currentTheme(),false); drawChart();
  </script>


</body></html>
