# ⚡ Phase 4: PWM & Motion Control (Days 27–36)

> **Platform**: `ESP32-WROOM-32`  
> **Roadmap Location**: [Master Roadmap](../../README.md#-the-350-day-execution-roadmap) | [Daily Tracker](../../DAILY_TRACKER.md)

---

## 🎯 Phase Overview & Objectives

This phase covers the core technical competencies of **Phase 4: PWM & Motion Control (Days 27–36)**. Follow each day's technical focus, build firmware experiments, and complete the milestone project at the end of the phase.

---

## 📅 Daily Execution & Checklist

| Status | Day(s) | Topic | Engineering Implementation Focus | Completed Date |
| :---: | :---: | :--- | :--- | :---: |
| [ ] | **27** | LEDC PWM Architecture | Channel routing, high-speed/low-speed timers, bit-resolution trade-offs | — |
| [ ] | **28** | LED Dimming & Effects | Duty-cycle curves, logarithmic dimming, human eye gamma correction tables | — |
| [ ] | **29** | RGB Color Mixing | HSV-to-RGB conversion routines and smooth color-space transitions | — |
| [ ] | **30** | Servo Control | 50 Hz PWM timing, microsecond pulse-width angle mapping ($500\,\mu\text{s} \dots 2500\,\mu\text{s}$) | — |
| [ ] | **31** | DC Motor H-Bridge | L298N/DRV8833 directional control logic and variable speed PWM regulation | — |
| [ ] | **32** | Stepper Motor Drivers | A4988 step/dir control, acceleration/deceleration trapezoidal ramp profiles | — |
| [ ] | **33** | Motor PWM (MCPWM) | Dedicated motor unit, complementary outputs, dead-band time insertion | — |
| [ ] | **34** | PID Control Theory | Discrete PID algorithms, error calculations, proportional/integral/derivative tuning | — |
| [ ] | **35** | Closed-Loop Motor Control | Quadrature optical encoder feedback handling with dynamic PID throttle tuning | — |
| [ ] | **36** | Phase Project | Closed-Loop Speed Controller: Precision motor governor with PID velocity hold | — |

---

## 🛠️ Recommended Daily Folder Structure

Keep daily exercises modular and easy to review:

```
firmware/phase04_pwm_motor/
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

[⬅️ Previous Phase](../phase03_analog/README.md) | [Home](../../README.md) | [Next Phase ➡️](../phase05_timers_isr/README.md)