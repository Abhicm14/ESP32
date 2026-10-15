# ⚡ Phase 7: UART Serial Protocol (Days 83–90)

> **Platform**: `ESP32-WROOM-32`  
> **Roadmap Location**: [Master Roadmap](../../README.md#-the-350-day-execution-roadmap) | [Daily Tracker](../../DAILY_TRACKER.md)

---

## 🎯 Phase Overview & Objectives

This phase covers the core technical competencies of **Phase 7: UART Serial Protocol (Days 83–90)**. Follow each day's technical focus, build firmware experiments, and complete the milestone project at the end of the phase.

---

## 📅 Daily Execution & Checklist

| Status | Day(s) | Topic | Engineering Implementation Focus | Completed Date |
| :---: | :---: | :--- | :--- | :---: |
| [ ] | **83–84** | Protocol Setup | Baud rates, parity, framing, pin matrix remapping, ESP-IDF UART drivers | — |
| [ ] | **85–86** | Asynchronous Parsing | Event-driven ring buffers, frame delimiter state machines, checksum verification | — |
| [ ] | **87–88** | Industrial Protocols | NMEA GPS parsing, half-duplex RS-485 transceiver auto-direction, Modbus RTU | — |
| [ ] | **89–90** | Phase Project | GPS Logging Node: Custom NMEA sentence parser and RS-485 telemetry bridge | — |

---

## 🛠️ Recommended Daily Folder Structure

Keep daily exercises modular and easy to review:

```
firmware/phase07_uart/
├── README.md               # This phase roadmap and tracker
├── docs/                   # Circuit schematics, timing diagrams, notes
└── daily_projects/         # Daily firmware implementations
    ├── dayXX_topic/        # Day's firmware (ESP-IDF or Arduino)
    │   ├── main/           # Source files (main.c, CMakeLists.txt)
    │   └── CMakeLists.txt
    └── milestone_project/  # End-of-phase capstone project
```

---

## 🚀 Build & Flash Cheat Sheet

### ESP-IDF Framework
```bash
# 1. Set chip target (ESP32-WROOM-32)
idf.py set-target esp32

# 2. Configure project settings
idf.py menuconfig

# 3. Build firmware
idf.py build

# 4. Flash to board and monitor serial logs
idf.py -p COMx flash monitor
```

### Arduino Framework (Optional / Rapid Bring-up)
- Select Board: **ESP32 Dev Module**
- CPU Frequency: **240 MHz (WiFi/BT)**
- Flash Frequency: **80 MHz**
- Upload Speed: **921600**

---

[⬅️ Previous Phase](../phase06_freertos/README.md) | [Home](../../README.md) | [Next Phase ➡️](../phase08_i2c/README.md)