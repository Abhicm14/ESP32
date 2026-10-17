# ESP32 â€” From First LED to Production Firmware

A beginner-friendly, build-in-public ESP32-WROOM-32 learning path using Arduino and ESP-IDF â€” from electronics basics and GPIO to FreeRTOS, IoT, OTA, custom drivers, and production firmware.

[![ESP32](https://img.shields.io/badge/Platform-ESP32--WROOM--32-E7352C?style=for-the-badge&logo=espressif&logoColor=white)](docs/ESP32_WROOM_32_REFERENCE.md)
[![ESP-IDF](https://img.shields.io/badge/Tested%20with-ESP--IDF%20v6.1-red?style=for-the-badge&logo=espressif&logoColor=white)](docs/ESP_IDF_WINDOWS_SETUP.md)
[![FreeRTOS](https://img.shields.io/badge/Kernel-FreeRTOS%20SMP-blue?style=for-the-badge)](https://www.freertos.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](LICENSE)

---

## ðŸŒŸ Our Beginner Promise

- **No Electronics Degree Required**: You don't need a degree in electrical engineering or computer science. If you know how to plug in a USB cable and follow step-by-step instructions, you can master this course.
- **Start Simple**: Every concept starts with plain-English explanations and intuitive everyday analogies (like water in pipes) before introducing formulas.
- **Learn by Building**: Theory without hands-on practice is easily forgotten. Every single day features a working physical circuit or code experiment.
- **Dual Approach (Arduino + ESP-IDF)**: Arduino provides rapid understanding and quick prototypes; ESP-IDF provides industry-standard, professional engineering skills. Both are taught side-by-side.
- **No Early Register Overload**: We intentionally start with high-level driver APIs. Register-level manipulation and low-level silicon tricks are saved for late phases when you are ready.

---

## ðŸš€ Start Here

New to this repository? Follow these five essential steps to begin:

1. ðŸ§­ **[Start Here Onboarding Guide](START_HERE.md)** â€” Step-by-step introduction, starter kit components, and safety rules.
2. ðŸ”Œ **[Day 0 â€” Electronics Prerequisites](Prerequisites.md)** â€” Voltage, Current, Resistance, Ohm's Law, 3.3V logic, and LED resistors.
3. ðŸ“… **[Daily Progress Tracker](DAILY_TRACKER.md)** â€” Personal daily progress checklist across all 350 planned days.
4. ðŸ›ï¸ **[Phase 1: Architecture & Foundations](firmware/phase01_foundations/README.md)** â€” Understand dual-core boot, memory regions, and system telemetry.
5. ðŸ’¡ **[Phase 2: Digital I/O (LEDs, Buttons & Relays)](firmware/phase02_digital_io/README.md)** â€” Build your first external circuits and blink an LED on GPIO 4!

---

## ðŸ“Š Transparent Progress: Built in Public

This repository documents an ambitious **350-day engineering curriculum**.

- **We are building this in public**: All 350 days represent our structured master plan. We do not claim that all 350 days already have finished code in the repository.
- **Current Completion**: Phase 1 (Days 1â€“8) is complete, Day 9 is in progress, and upcoming phases are actively rolling out.
- **Track Live Status**: Check **[DAILY_TRACKER.md](DAILY_TRACKER.md)** for the exact daily status, commit logs, and notes.

---

## ðŸ› ï¸ What You Will Build

Across this comprehensive path, you will build real-world embedded projects:

- ðŸ’¡ **LED & Button Projects**: Debounced inputs, state machines, and non-blocking blinking patterns.
- ðŸŽ›ï¸ **Sensors & Filters**: Temperature, IMU motion tracking, continuous DMA ADC sampling, and digital filters.
- âš™ï¸ **PWM & Motor Controllers**: Servo positioning, H-bridge DC motors, and closed-loop PID governors.
- ðŸ§µ **FreeRTOS Multitasking**: Dual-core task affinity, queues, semaphores, and inter-task event groups.
- ðŸŒ **Wi-Fi Web Dashboards**: Captive portal provisioning, REST APIs, and real-time WebSocket control panels.
- ðŸ“¡ **MQTT IoT Nodes**: Secure TLS telemetry reporting to Home Assistant and AWS IoT Core.
- ðŸ”„ **OTA Firmware Updates**: Dual-partition fail-safe flash switching with automatic crash rollback.
- ðŸ­ **Production Capstones**: Industrial RS-485 Modbus gateways, LVGL touch panels, and LoRa mesh networks.

---

## ðŸŽ“ The Learning Method

Our curriculum uses a **progressive 3-pass spiral learning method**:

1. **Day 0 (Foundation)**: Master basic circuit physics, logic levels, and multimeter diagnostics.
2. **First Pass (High-Level APIs)**: Learn what peripherals do using high-level libraries and companion Arduino sketches.
3. **Second Pass (Professional ESP-IDF Patterns)**: Master FreeRTOS multitasking, event loops, memory audits, and secure networking.
4. **Final Pass (Custom Drivers & Registers)**: Dive deep into bare-metal registers (Phase 22), JTAG diagnostics, and custom PCB hardware design.

ðŸ“– *Read the full philosophy in **[The Learning Method](docs/LEARNING_METHOD.md)**.*

---

## ðŸ§° Hardware Strategy

- **Primary Board**: **ESP32-WROOM-32** (Standard 30-pin or 38-pin DevKit V1).
- **88% Single-Board Focus**: 308 of the 350 days are executed on this single, affordable board!
- **Variant Boards Only in Late Phases**: Specialized boards like **ESP32-CAM**, **ESP32-S3**, and **ESP32-C6** are only needed in Phase 24 for camera vision, native USB OTG, and Zigbee/Matter protocols.

ðŸ›’ *See the full component list and purchasing tips in **[Hardware Bill of Materials (BOM)](docs/HARDWARE_BOM.md)**.*
ðŸ“Œ *Pin rules and safe GPIO pinout matrix: **[ESP32-WROOM-32 Pin Reference](docs/ESP32_WROOM_32_REFERENCE.md)**.*

---

## ðŸ—ºï¸ Engineering Career Progression

```
  ðŸŸ¢ Entry / Fresher (Days 1â€“110)    â”€â”€â–º Electronics, GPIO, ADC, FreeRTOS, UART, I2C, SPI
  ðŸ”µ Junior Level   (Days 111â€“186)   â”€â”€â–º I2S Audio, CAN/TWAI, Sockets, HTTP, MQTT, BLE GATT
  ðŸŸ¡ Mid-Level      (Days 187â€“238)   â”€â”€â–º Hardened Security, Secure Boot, Signed OTA, ULP Sleep
  ðŸŸ  Senior Level   (Days 239â€“308)   â”€â”€â–º Sensor Fusion, DSP, Bare-Metal Registers, JTAG Debug
  ðŸŸ£ Specialist     (Days 309â€“350)   â”€â”€â–º Camera Vision, USB OTG, Matter, Edge AI & Capstones
```

ðŸ—ºï¸ *Explore all 25 phases in detail: **[Full 350-Day Roadmap](docs/ROADMAP.md)**.*

---

## ðŸ“ Repository Structure

```
ESP32/
â”œâ”€â”€ README.md                   # Welcome guide, quick links, and roadmap summary
â”œâ”€â”€ START_HERE.md               # Beginner onboarding, components & workflow
â”œâ”€â”€ Prerequisites.md            # Day 0: Complete electronics prerequisites
â”œâ”€â”€ DAILY_TRACKER.md            # 350-day personal progress checklist
â”œâ”€â”€ CONTRIBUTING.md             # Contribution guide and commit conventions
â”œâ”€â”€ LICENSE                     # MIT Open Source License
â”œâ”€â”€ docs/                       # Comprehensive documentation & setup guides
â”‚   â”œâ”€â”€ HARDWARE_BOM.md         # Component list by phase
â”‚   â”œâ”€â”€ ESP_IDF_WINDOWS_SETUP.md# Windows installation & toolchain setup
â”‚   â”œâ”€â”€ TROUBLESHOOTING.md      # Beginner errors and solutions
â”‚   â”œâ”€â”€ LEARNING_METHOD.md      # 3-pass spiral learning philosophy
â”‚   â”œâ”€â”€ ROADMAP.md              # Detailed 25-phase curriculum breakdown
â”‚   â”œâ”€â”€ ESP32_WROOM_32_REFERENCE.md # Safe GPIOs and hardware limits
â”‚   â””â”€â”€ MAINTAINER_CHECKLIST.md # PR guidelines and future CI setup
â””â”€â”€ firmware/                   # Code examples organized by engineering phase
    â”œâ”€â”€ phase01_foundations/    # System info, bootloader, memory layout
    â”œâ”€â”€ phase02_digital_io/     # GPIO outputs, buttons, debouncing, shift registers
    â””â”€â”€ ...                     # Phases 03 through 25
```

---

## ðŸ¤ Contributing & Community

Contributions, corrections, and new lesson examples are warmly welcomed! Please read our **[Contributing Guidelines](CONTRIBUTING.md)** before submitting a pull request.

- Found a bug or error? Open an issue using our [Bug Report Template](.github/ISSUE_TEMPLATE/bug_report.md).
- Confusing sentence in the docs? Submit a [Documentation Correction](.github/ISSUE_TEMPLATE/documentation_correction.md).
- Have an idea for a lesson? Submit a [Lesson Request](.github/ISSUE_TEMPLATE/lesson_request.md).

---

## ðŸ“„ License & Maintainer

- **Maintainer**: [Abhishek C M](https://github.com/Abhicm14)
- **Repository**: [https://github.com/Abhicm14/ESP32](https://github.com/Abhicm14/ESP32)
- **License**: Released under the open-source **[MIT License](LICENSE)**.
