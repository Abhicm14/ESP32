# ⚡ Phase 11: Wi-Fi Networking Fundamentals (Days 125–142)

> **Platform**: `ESP32-WROOM-32`  
> **Roadmap Location**: [Master Roadmap](../../README.md#-the-350-day-execution-roadmap) | [Daily Tracker](../../DAILY_TRACKER.md)

---

## 🎯 Phase Overview & Objectives

This phase covers the core technical competencies of **Phase 11: Wi-Fi Networking Fundamentals (Days 125–142)**. Follow each day's technical focus, build firmware experiments, and complete the milestone project at the end of the phase.

---

## 📅 Daily Execution & Checklist

| Status | Day(s) | Topic | Engineering Implementation Focus | Completed Date |
| :---: | :---: | :--- | :--- | :---: |
| [ ] | **125–128** | Connectivity Core | 802.11 MAC/PHY, Station mode, event handling, reconnect state machines | — |
| [ ] | **129–132** | Access Point & Mesh | SoftAP mode, AP+STA concurrent bridge, credentials storage in NVS | — |
| [ ] | **133–136** | Provisioning & Services | Captive portals, mDNS, SNTP real-time clock synchronization | — |
| [ ] | **137–140** | Socket Programming | Raw TCP/UDP socket servers, peer-to-peer connectionless ESP-NOW protocol | — |
| [ ] | **141–142** | Phase Project | Wi-Fi Manager Framework: Captive portal configuration with automatic failover | — |

---

## 🛠️ Recommended Daily Folder Structure

Keep daily exercises modular and easy to review:

```
firmware/phase11_wifi/
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

[⬅️ Previous Phase](../phase10_peripherals/README.md) | [Home](../../README.md) | [Next Phase ➡️](../phase12_http/README.md)