# ⚡ Phase 3: Analog Domain (Days 19–26)

> **Platform**: `ESP32-WROOM-32`  
> **Roadmap Location**: [Master Roadmap](../../README.md#-the-350-day-execution-roadmap) | [Daily Tracker](../../DAILY_TRACKER.md)

---

## 🎯 Phase Overview & Objectives

This phase covers the core technical competencies of **Phase 3: Analog Domain (Days 19–26)**. Follow each day's technical focus, build firmware experiments, and complete the milestone project at the end of the phase.

---

## 📅 Daily Execution & Checklist

| Status | Day(s) | Topic | Engineering Implementation Focus | Completed Date |
| :---: | :---: | :--- | :--- | :---: |
| [ ] | **19** | ADC Architecture | 12-bit SAR ADC mechanics, attenuation ranges (0dB to 11dB), non-linearity curves | — |
| [ ] | **20** | Analog Sampling | Multi-channel sensor acquisition: potentiometers, LDRs, NTC thermistors | — |
| [ ] | **21** | Digital Signal Filtering | Moving average, median filtering, and exponential smoothing algorithms | — |
| [ ] | **22** | High-Speed Continuous ADC | DMA-backed continuous sampling with ring buffer management | — |
| [ ] | **23** | DAC Signal Generation | True 8-bit analog voltage output on GPIO 25/26, sine, triangle, and arbitrary waves | — |
| [ ] | **24** | Sigma-Delta Modulation | Multi-channel pulse-density modulation drivers for fine analog synthesis | — |
| [ ] | **25** | Internal Sensors | Hall effect magnetic sensor acquisition, internal temperature calibration | — |
| [ ] | **26** | Phase Project | Filtered Multi-Sensor Monitor: Real-time signal smoothing and telemetry pipeline | — |

---

## 🛠️ Recommended Daily Folder Structure

Keep daily exercises modular and easy to review:

```
firmware/phase03_analog/
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

[⬅️ Previous Phase](../phase02_digital_io/README.md) | [Home](../../README.md) | [Next Phase ➡️](../phase04_pwm_motor/README.md)