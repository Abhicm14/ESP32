# ⚡ Phase 6: FreeRTOS Core & Advanced Patterns (Days 47–82)

> **Platform**: `ESP32-WROOM-32`  
> **Roadmap Location**: [Master Roadmap](../../README.md#-the-350-day-execution-roadmap) | [Daily Tracker](../../DAILY_TRACKER.md)

---

## 🎯 Phase Overview & Objectives

This phase covers the core technical competencies of **Phase 6: FreeRTOS Core & Advanced Patterns (Days 47–82)**. Follow each day's technical focus, build firmware experiments, and complete the milestone project at the end of the phase.

---

## 📅 Daily Execution & Checklist

| Status | Day(s) | Topic | Engineering Implementation Focus | Completed Date |
| :---: | :---: | :--- | :--- | :---: |
| [ ] | **47–50** | Task Management | Task creation, SMP dual-core affinity (`xTaskCreatePinnedToCore`), context switches | — |
| [ ] | **51–54** | Task Lifecycle | Priorities, preemptive time-slicing, stack sizing, water-mark tracking (`uxTaskGetStackHighWaterMark`) | — |
| [ ] | **55–57** | Queue Processing | Thread-safe pass-by-value, structured data queues, queue sets | — |
| [ ] | **58–62** | Synchronization | Binary/counting semaphores, recursive mutexes, priority inversion solutions | — |
| [ ] | **63–66** | Advanced IPC | Event groups, direct-to-task notifications (lightweight IPC), stream buffers | — |
| [ ] | **67–69** | Timers & Critical Sections | FreeRTOS software timers, port spinlocks, task critical enter/exit guards | — |
| [ ] | **70–72** | Memory & Diagnostics | Heap capabilities (`MALLOC_CAP_8BIT`), memory leak audits, `vTaskList` telemetry | — |
| [ ] | **73–77** | Architecture Patterns | Producer-consumer pipelines, Finite State Machines (FSM), command worker pools | — |
| [ ] | **78–81** | ESP32 RTOS Extensions | System Event Loop (`esp_event`), inter-core messaging (IPC API) | — |
| [ ] | **82** | Phase Project | Multi-Stage Sensor Pipeline: 5-Task FreeRTOS telemetry processing engine | — |

---

## 🛠️ Recommended Daily Folder Structure

Keep daily exercises modular and easy to review:

```
firmware/phase06_freertos/
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

[⬅️ Previous Phase](../phase05_timers_isr/README.md) | [Home](../../README.md) | [Next Phase ➡️](../phase07_uart/README.md)