# ESP32 - From First LED to Production Firmware

A beginner-friendly, build-in-public ESP32-WROOM-32 learning path using Arduino and ESP-IDF - from electronics basics and GPIO to FreeRTOS, IoT, OTA, custom drivers, and production firmware.

[![ESP32](https://img.shields.io/badge/Platform-ESP32--WROOM--32-E7352C?style=for-the-badge&logo=espressif&logoColor=white)](docs/ESP32_WROOM_32_REFERENCE.md)
[![ESP-IDF](https://img.shields.io/badge/Tested%20with-ESP--IDF%20v6.1-red?style=for-the-badge&logo=espressif&logoColor=white)](docs/ESP_IDF_WINDOWS_SETUP.md)
[![FreeRTOS](https://img.shields.io/badge/Kernel-FreeRTOS%20SMP-blue?style=for-the-badge)](https://www.freertos.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](LICENSE)

---

## Our Beginner Promise

- **No Electronics Degree Required**: You do not need a degree in electrical engineering or computer science. If you know how to plug in a USB cable and follow step-by-step instructions, you can master this course.
- **Start Simple**: Every concept starts with plain-English explanations and intuitive everyday analogies (like water in pipes) before introducing formulas.
- **Learn by Building**: Theory without hands-on practice is easily forgotten. Every single day features a working physical circuit or code experiment.
- **Dual Approach (Arduino + ESP-IDF)**: Arduino provides rapid understanding and quick prototypes; ESP-IDF provides industry-standard, professional engineering skills. Both are taught side-by-side.
- **No Early Register Overload**: We intentionally start with high-level driver APIs. Register-level manipulation and low-level silicon tricks are saved for late phases when you are ready.

---

## Start Here

New to this repository? Follow these five essential steps to begin:

1. **[Start Here Onboarding Guide](START_HERE.md)** - Step-by-step introduction, starter kit components, and safety rules.
2. **[Day 0 - Electronics Prerequisites](Prerequisites.md)** - Voltage, Current, Resistance, Ohm's Law, 3.3V logic, and LED resistors.
3. **[Daily Progress Tracker](DAILY_TRACKER.md)** - Personal daily progress checklist across all 350 planned days.
4. **[Phase 1: Architecture & Foundations](firmware/phase01_foundations/README.md)** - Understand dual-core boot, memory regions, and system telemetry.
5. **[Phase 2: Digital I/O (LEDs, Buttons & Relays)](firmware/phase02_digital_io/README.md)** - Build your first external circuits and blink an LED on GPIO 4!

---

## Transparent Progress: Built in Public

This repository documents an ambitious **350-day engineering curriculum**.

- **We are building this in public**: All 350 days represent our structured master plan. We do not claim that all 350 days already have finished code in the repository.
- **Current Completion**: Phase 1 (Days 1 to 8) is complete, Day 9 is in progress, and upcoming phases are actively rolling out.
- **Track Live Status**: Check **[DAILY_TRACKER.md](DAILY_TRACKER.md)** for the exact daily status, commit logs, and notes.

---

## What You Will Build

Across this comprehensive path, you will build real-world embedded projects:

- **LED & Button Projects**: Debounced inputs, state machines, and non-blocking blinking patterns.
- **Sensors & Filters**: Temperature, IMU motion tracking, continuous DMA ADC sampling, and digital filters.
- **PWM & Motor Controllers**: Servo positioning, H-bridge DC motors, and closed-loop PID governors.
- **FreeRTOS Multitasking**: Dual-core task affinity, queues, semaphores, and inter-task event groups.
- **Wi-Fi Web Dashboards**: Captive portal provisioning, REST APIs, and real-time WebSocket control panels.
- **MQTT IoT Nodes**: Secure TLS telemetry reporting to Home Assistant and AWS IoT Core.
- **OTA Firmware Updates**: Dual-partition fail-safe flash switching with automatic crash rollback.
- **Production Capstones**: Industrial RS-485 Modbus gateways, LVGL touch panels, and LoRa mesh networks.

---

## The Learning Method

Our curriculum uses a **progressive 3-pass spiral learning method**:

1. **Day 0 (Foundation)**: Master basic circuit physics, logic levels, and multimeter diagnostics.
2. **First Pass (High-Level APIs)**: Learn what peripherals do using high-level libraries and companion Arduino sketches.
3. **Second Pass (Professional ESP-IDF Patterns)**: Master FreeRTOS multitasking, event loops, memory audits, and secure networking.
4. **Final Pass (Custom Drivers & Registers)**: Dive deep into bare-metal registers (Phase 22), JTAG diagnostics, and custom PCB hardware design.

*Read the full philosophy in **[The Learning Method](docs/LEARNING_METHOD.md)**.*

---

## Hardware Strategy

- **Primary Board**: **ESP32-WROOM-32** (Standard 30-pin or 38-pin DevKit V1).
- **88% Single-Board Focus**: 308 of the 350 days are executed on this single, affordable board!
- **Variant Boards Only in Late Phases**: Specialized boards like **ESP32-CAM**, **ESP32-S3**, and **ESP32-C6** are only needed in Phase 24 for camera vision, native USB OTG, and Zigbee/Matter protocols.

*See the full component list and purchasing tips in **[Hardware Bill of Materials (BOM)](docs/HARDWARE_BOM.md)**.*  
*Pin rules and safe GPIO pinout matrix: **[ESP32-WROOM-32 Pin Reference](docs/ESP32_WROOM_32_REFERENCE.md)**.*

---

## Engineering Career Progression

```text
  Entry / Fresher (Days 1 to 110)    -> Electronics, GPIO, ADC, FreeRTOS, UART, I2C, SPI
  Junior Level    (Days 111 to 186)  -> I2S Audio, CAN/TWAI, Sockets, HTTP, MQTT, BLE GATT
  Mid-Level       (Days 187 to 238)  -> Hardened Security, Secure Boot, Signed OTA, ULP Sleep
  Senior Level    (Days 239 to 308)  -> Sensor Fusion, DSP, Bare-Metal Registers, JTAG Debug
  Specialist      (Days 309 to 350)  -> Camera Vision, USB OTG, Matter, Edge AI & Capstones
```

*Explore all 25 phases in detail: **[Full 350-Day Roadmap](docs/ROADMAP.md)**.*

---

## Repository Structure

```text
ESP32/
|-- README.md                   # Welcome guide, quick links, and roadmap summary
|-- START_HERE.md               # Beginner onboarding, components and workflow
|-- Prerequisites.md            # Day 0: Complete electronics prerequisites
|-- DAILY_TRACKER.md            # 350-day personal progress checklist
|-- CONTRIBUTING.md             # Contribution guide and commit conventions
|-- LICENSE                     # MIT Open Source License
|-- docs/                       # Comprehensive documentation and setup guides
|   |-- HARDWARE_BOM.md         # Component list by phase
|   |-- ESP_IDF_WINDOWS_SETUP.md# Windows installation and toolchain setup
|   |-- TROUBLESHOOTING.md      # Beginner errors and solutions
|   |-- LEARNING_METHOD.md      # 3-pass spiral learning philosophy
|   |-- ROADMAP.md              # Detailed 25-phase curriculum breakdown
|   |-- ESP32_WROOM_32_REFERENCE.md # Safe GPIOs and hardware limits
|   `-- MAINTAINER_CHECKLIST.md # PR guidelines and future CI setup
`-- firmware/                   # Code examples organized by engineering phase
    |-- phase01_foundations/    # System info, bootloader, memory layout
    |-- phase02_digital_io/     # GPIO outputs, buttons, debouncing, shift registers
    `-- ...                     # Phases 03 through 25
```

---

## Contributing and Community

Contributions, corrections, and new lesson examples are warmly welcomed! Please read our **[Contributing Guidelines](CONTRIBUTING.md)** before submitting a pull request.

- Found a bug or error? Open an issue using our [Bug Report Template](.github/ISSUE_TEMPLATE/bug_report.md).
- Confusing sentence in the docs? Submit a [Documentation Correction](.github/ISSUE_TEMPLATE/documentation_correction.md).
- Have an idea for a lesson? Submit a [Lesson Request](.github/ISSUE_TEMPLATE/lesson_request.md).

---

## License and Maintainer

- **Maintainer**: [Abhishek C M](https://github.com/Abhicm14)
- **Repository**: [https://github.com/Abhicm14/ESP32](https://github.com/Abhicm14/ESP32)
- **License**: Released under the open-source **[MIT License](LICENSE)**.
