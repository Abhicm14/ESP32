# ⚡ Phase 2: Digital I/O Operations (Days 9–18)

> **Platform**: `ESP32-WROOM-32`  
> **Roadmap Location**: [Master Roadmap](../../README.md#-the-350-day-execution-roadmap) | [Daily Tracker](../../DAILY_TRACKER.md)

---

## 🎯 Phase Overview & Objectives

This phase covers the core technical competencies of **Phase 2: Digital I/O Operations (Days 9–18)**. Follow each day's technical focus, build firmware experiments, and complete the milestone project at the end of the phase.

---

## 📅 Daily Execution & Checklist

| Status | Day(s) | Topic | Engineering Implementation Focus | Completed Date |
| :---: | :---: | :--- | :--- | :---: |
| [ ] | **9** | GPIO Output Drive | Internal push-pull driver circuitry, drive strength modes, sink/source limits | — |
| [ ] | **10** | GPIO Input Circuitry | Internal pull-up/pull-down configuration, input-only GPI pins (34–39) | — |
| [ ] | **11** | High-Level GPIO API | Arduino-style abstraction implementation and timing overhead analysis | — |
| [ ] | **12** | ESP-IDF Low-Level Driver | `gpio_config_t` structures, bitmasks, and direct register manipulation | — |
| [ ] | **13** | Debouncing Logic | State machines, time-threshold noise filtering, mechanical bounce rejection | — |
| [ ] | **14** | Non-blocking Timing | Asynchronous timing patterns using tick counters and non-blocking loops | — |
| [ ] | **15** | Relays & Transducers | Driving inductive relay coils via transistors, active vs passive buzzer control | — |
| [ ] | **16** | Output Shift Registers | Expanding output pins using 74HC595 over high-speed bit-banged SPI | — |
| [ ] | **17** | Capacitive Touch | Touch pad threshold configuration and calibration (Pins T0–T9) | — |
| [ ] | **18** | Phase Project | Touch-Controlled Relay System: Multi-channel isolated AC load controller with feedback | — |

---

## 🛠️ Recommended Daily Folder Structure

Keep daily exercises modular and easy to review:

```
firmware/phase02_digital_io/
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

[⬅️ Previous Phase](../phase01_foundations/README.md) | [Home](../../README.md) | [Next Phase ➡️](../phase03_analog/README.md)