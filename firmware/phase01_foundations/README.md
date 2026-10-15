# ⚡ Phase 1: Architecture & Foundations (Days 1–8)

> **Platform**: `ESP32-WROOM-32`  
> **Roadmap Location**: [Master Roadmap](../../README.md#-the-350-day-execution-roadmap) | [Daily Tracker](../../DAILY_TRACKER.md)

---

## 🎯 Phase Overview & Objectives

This phase covers the core technical competencies of **Phase 1: Architecture & Foundations (Days 1–8)**. Follow each day's technical focus, build firmware experiments, and complete the milestone project at the end of the phase.

---

## 📅 Daily Execution & Checklist

| Status | Day(s) | Topic | Engineering Implementation Focus | Completed Date |
| :---: | :---: | :--- | :--- | :---: |
| [ ] | **1** | System Architecture | Dual-core Xtensa LX6 internals, memory bus architecture, peripheral interconnects | — |
| [ ] | **2** | Environment Setup | Toolchain installation: ESP-IDF, VS Code integration, Arduino IDE environment | — |
| [ ] | **3** | First Build & Flash | Toolchain compilation, serial flashing, bootloader inspection, monitor logs | — |
| [ ] | **4** | Memory Organization | Memory map analysis: IRAM, DRAM, D/IRAM, RTC Fast & Slow memory regions | — |
| [ ] | **5** | Partition Tables | Custom CSV partition tables, factory vs OTA dual-bank memory allocation | — |
| [ ] | **6** | Build System Mastery | CMakeLists configuration, Kconfig menu options, modular component design | — |
| [ ] | **7** | Logging Framework | `ESP_LOG` verbosity levels, runtime filtering, custom UART telemetry sinks | — |
| [ ] | **8** | Phase Project | System Info Reporter: Firmware inspecting chip silicon revisions, MAC, and heap maps | — |

---

## 🛠️ Recommended Daily Folder Structure

Keep daily exercises modular and easy to review:

```
firmware/phase01_foundations/
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

[⬅️ Previous Phase](../phase01_foundations/README.md) | [Home](../../README.md) | [Next Phase ➡️](../phase02_digital_io/README.md)