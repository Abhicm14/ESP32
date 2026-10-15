# ⚡ Phase 14: Bluetooth Classic & BLE (Days 169–186)

> **Platform**: `ESP32-WROOM-32`  
> **Roadmap Location**: [Master Roadmap](../../README.md#-the-350-day-execution-roadmap) | [Daily Tracker](../../DAILY_TRACKER.md)

---

## 🎯 Phase Overview & Objectives

This phase covers the core technical competencies of **Phase 14: Bluetooth Classic & BLE (Days 169–186)**. Follow each day's technical focus, build firmware experiments, and complete the milestone project at the end of the phase.

---

## 📅 Daily Execution & Checklist

| Status | Day(s) | Topic | Engineering Implementation Focus | Completed Date |
| :---: | :---: | :--- | :--- | :---: |
| [ ] | **169–173** | Bluetooth Classic | Serial Port Profile (SPP), A2DP audio sink, HID keyboard/mouse emulation | — |
| [ ] | **174–180** | BLE Core Architecture | GAP/GATT architectures, custom 128-bit UUID services, notifications, pairing security | — |
| [ ] | **181–183** | Advanced BLE & NimBLE | Apple iBeacons, BLE HID devices, NimBLE memory-optimized stack configuration | — |
| [ ] | **184–186** | Phase Project | BLE Health Sensor Hub: Real-time encrypted GATT telemetry server | — |

---

## 🛠️ Recommended Daily Folder Structure

Keep daily exercises modular and easy to review:

```
firmware/phase14_bluetooth/
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

[⬅️ Previous Phase](../phase13_mqtt/README.md) | [Home](../../README.md) | [Next Phase ➡️](../phase15_security_ota/README.md)