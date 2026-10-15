# ⚡ Phase 24: Board-Specific Architecture Expansion (Days 309–342)

> **Platform**: `ESP32-WROOM-32`  
> **Roadmap Location**: [Master Roadmap](../../README.md#-the-350-day-execution-roadmap) | [Daily Tracker](../../DAILY_TRACKER.md)

---

## 🎯 Phase Overview & Objectives

This phase covers the core technical competencies of **Phase 24: Board-Specific Architecture Expansion (Days 309–342)**. Follow each day's technical focus, build firmware experiments, and complete the milestone project at the end of the phase.

---

## 📅 Daily Execution & Checklist

| Status | Day(s) | Topic | Engineering Implementation Focus | Completed Date |
| :---: | :---: | :--- | :--- | :---: |
| [ ] | **24A: Days 309–316** | ESP32-CAM (~$5) | OV2640 camera initialization, frame-buffer capture, MJPEG HTTP video streaming | — |
| [ ] | **24B: Days 317–328** | ESP32-S3 DevKit (~$9) | Native USB OTG (CDC serial, HID keyboards, MSC flash storage), BLE 5.0, ESP-SR speech | — |
| [ ] | **24C: Days 329–336** | ESP32-C6 DevKit (~$7) | IEEE 802.15.4 MAC layer, Zigbee 3.0 clusters, OpenThread border routers, Matter | — |
| [ ] | **24D: Days 337–342** | Edge AI Applications | Edge Impulse models, gesture recognition, acoustic anomaly vibration classification | — |

---

## 🛠️ Recommended Daily Folder Structure

Keep daily exercises modular and easy to review:

```
firmware/phase24_variant_boards/
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

[⬅️ Previous Phase](../phase23_manufacturing/README.md) | [Home](../../README.md) | [Next Phase ➡️](../phase25_capstones/README.md)