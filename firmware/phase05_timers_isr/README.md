# ⚡ Phase 5: Timers & Hardware Interrupts (Days 37–46)

> **Platform**: `ESP32-WROOM-32`  
> **Roadmap Location**: [Master Roadmap](../../README.md#-the-350-day-execution-roadmap) | [Daily Tracker](../../DAILY_TRACKER.md)

---

## 🎯 Phase Overview & Objectives

This phase covers the core technical competencies of **Phase 5: Timers & Hardware Interrupts (Days 37–46)**. Follow each day's technical focus, build firmware experiments, and complete the milestone project at the end of the phase.

---

## 📅 Daily Execution & Checklist

| Status | Day(s) | Topic | Engineering Implementation Focus | Completed Date |
| :---: | :---: | :--- | :--- | :---: |
| [ ] | **37** | Hardware Timers | Prescalers, 64-bit counter groups, up/down counting, auto-reload mechanics | — |
| [ ] | **38** | Periodic Scheduling | High-precision periodic ISR execution via hardware timer alarms | — |
| [ ] | **39** | High-Resolution Timers | Microsecond-accurate software execution schedules via `esp_timer` APIs | — |
| [ ] | **40** | Watchdog Systems | Task Watchdog Timer (TWDT) and Interrupt Watchdog (IWDT) stall prevention | — |
| [ ] | **41** | Pulse Counter (PCNT) | Hardware edge accumulation, glitch filters, 8-channel counter modules | — |
| [ ] | **42** | Quadrature Decoding | Dual-channel quadrature pulse decoding via PCNT for optical rotary encoders | — |
| [ ] | **43** | ISR Best Practices | Reducing interrupt latency, IRAM allocation, deferring work to tasks | — |
| [ ] | **44–45** | ISR Synchronization | Signalling tasks from ISRs using FreeRTOS Semaphores and Queues from ISR | — |
| [ ] | **46** | Phase Project | Tachometer & Precision Frequency Meter: Zero-overhead high-speed frequency analyzer | — |

---

## 🛠️ Recommended Daily Folder Structure

Keep daily exercises modular and easy to review:

```
firmware/phase05_timers_isr/
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

[⬅️ Previous Phase](../phase04_pwm_motor/README.md) | [Home](../../README.md) | [Next Phase ➡️](../phase06_freertos/README.md)