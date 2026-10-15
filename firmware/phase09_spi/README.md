# ⚡ Phase 9: SPI Protocol & High-Speed Interfaces (Days 101–110)

> **Platform**: `ESP32-WROOM-32`  
> **Roadmap Location**: [Master Roadmap](../../README.md#-the-350-day-execution-roadmap) | [Daily Tracker](../../DAILY_TRACKER.md)

---

## 🎯 Phase Overview & Objectives

This phase covers the core technical competencies of **Phase 9: SPI Protocol & High-Speed Interfaces (Days 101–110)**. Follow each day's technical focus, build firmware experiments, and complete the milestone project at the end of the phase.

---

## 📅 Daily Execution & Checklist

| Status | Day(s) | Topic | Engineering Implementation Focus | Completed Date |
| :---: | :---: | :--- | :--- | :---: |
| [ ] | **101–103** | Bus Drivers | Transaction configurations, SPI master modes (0–3), ILI9341 TFT display | — |
| [ ] | **104–106** | Storage & Wireless | MicroSD card (SPI vs SDMMC 4-bit), LoRa SX1278 transceiver SPI setup | — |
| [ ] | **107–109** | Advanced SPI & DMA | W25Q external NOR flash instructions, DMA buffer allocation and transfers | — |
| [ ] | **110** | Phase Project | Data Acquisition Hub: High-speed DMA sensor logger saving data to SD Card | — |

---

## 🛠️ Recommended Daily Folder Structure

Keep daily exercises modular and easy to review:

```
firmware/phase09_spi/
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

[⬅️ Previous Phase](../phase08_i2c/README.md) | [Home](../../README.md) | [Next Phase ➡️](../phase10_peripherals/README.md)