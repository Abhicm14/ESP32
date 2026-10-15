# ⚡ Phase 13: MQTT & Industrial IoT Protocols (Days 157–168)

> **Platform**: `ESP32-WROOM-32`  
> **Roadmap Location**: [Master Roadmap](../../README.md#-the-350-day-execution-roadmap) | [Daily Tracker](../../DAILY_TRACKER.md)

---

## 🎯 Phase Overview & Objectives

This phase covers the core technical competencies of **Phase 13: MQTT & Industrial IoT Protocols (Days 157–168)**. Follow each day's technical focus, build firmware experiments, and complete the milestone project at the end of the phase.

---

## 📅 Daily Execution & Checklist

| Status | Day(s) | Topic | Engineering Implementation Focus | Completed Date |
| :---: | :---: | :--- | :--- | :---: |
| [ ] | **157–161** | MQTT Standard | Pub/Sub architecture, QoS 0/1/2, Last Will and Testament (LWT), TLS encryption | — |
| [ ] | **162–164** | Ecosystem Integration | Node-RED workflows, Home Assistant MQTT auto-discovery conventions | — |
| [ ] | **165–168** | Phase Project | 3-Node IoT Network: Multi-node ESP-NOW sensor array routing to an MQTT cloud gateway | — |

---

## 🛠️ Recommended Daily Folder Structure

Keep daily exercises modular and easy to review:

```
firmware/phase13_mqtt/
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

[⬅️ Previous Phase](../phase12_http/README.md) | [Home](../../README.md) | [Next Phase ➡️](../phase14_bluetooth/README.md)