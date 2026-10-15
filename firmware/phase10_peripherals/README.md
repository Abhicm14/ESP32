# ⚡ Phase 10: Advanced Peripherals (Days 111–124)

> **Platform**: `ESP32-WROOM-32`  
> **Roadmap Location**: [Master Roadmap](../../README.md#-the-350-day-execution-roadmap) | [Daily Tracker](../../DAILY_TRACKER.md)

---

## 🎯 Phase Overview & Objectives

This phase covers the core technical competencies of **Phase 10: Advanced Peripherals (Days 111–124)**. Follow each day's technical focus, build firmware experiments, and complete the milestone project at the end of the phase.

---

## 📅 Daily Execution & Checklist

| Status | Day(s) | Topic | Engineering Implementation Focus | Completed Date |
| :---: | :---: | :--- | :--- | :---: |
| [ ] | **111–114** | I2S Audio Subsystem | Digital MEMS microphone sampling (INMP441), audio DAC streaming (MAX98357A) | — |
| [ ] | **115** | 1-Wire Devices | DS18B20 microsecond timing sequences, multi-drop sensor enumerations | — |
| [ ] | **116–118** | CAN / TWAI Bus | ISO 11898-2 transceivers, bit timing, frame filtering, automotive CAN packets | — |
| [ ] | **119–122** | RMT Peripheral | Infrared NEC pulse encoders, WS2812 addressable NeoPixel timing drivers | — |
| [ ] | **123–124** | Phase Project | Smart Infrared & Optical Hub: Universal IR cloner and RGB notification engine | — |

---

## 🛠️ Recommended Daily Folder Structure

Keep daily exercises modular and easy to review:

```
firmware/phase10_peripherals/
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

[⬅️ Previous Phase](../phase09_spi/README.md) | [Home](../../README.md) | [Next Phase ➡️](../phase11_wifi/README.md)