# Start Here: Your Beginner Onboarding Guide

Welcome to your hands-on journey with the **ESP32**!

Whether you are writing your very first line of microcontroller code or transitioning from Arduino to professional firmware development, this guide will orient you quickly so you can start building with confidence.

---

## Who This Repository Is For

- **Complete beginners** who have never touched a breadboard or microcontroller before.
- **12th-pass students** wanting to explore electronics and computer engineering practically.
- **Mechanical, civil, and non-ECE students** looking to break into IoT and robotics.
- **Arduino users** ready to move to industrial, production-grade **ESP-IDF** firmware.
- **Aspiring embedded software engineers** who want to build real systems with FreeRTOS, networking, OTA updates, and secure IoT architectures.

> ### You Do NOT Need an Electronics Degree!
> Everything you need to know is taught step by step. We start with plain-English analogies (like water flowing through pipes) and build practical circuits before writing complex code. If you can plug in a USB cable and follow simple instructions, you can master this roadmap.

---

## Required Starter Hardware

To complete the foundational experiments in Phase 1 and Phase 2, you only need an inexpensive starter kit:

1. **ESP32-WROOM-32 Development Board** (30-pin or 38-pin DevKit V1)
2. **Micro-USB or USB-C Data Cable** (Make sure it is a **data cable**, not a charge-only cable!)
3. **Half-size or Full-size Solderless Breadboard**
4. **Male-to-Male Jumper Wires** (bundle of 20 to 30)
5. **Standard 5mm LEDs** (Red, Green, Blue, or Yellow)
6. **220 ohm (or 330 ohm) Resistors** (1/4 Watt, for current-limiting LEDs)
7. **Tactile Push Buttons** (4-pin momentary buttons)

> Need the full bill of materials for upcoming phases? See **[Hardware Bill of Materials (BOM)](docs/HARDWARE_BOM.md)**.

---

## Arduino IDE vs ESP-IDF: Which One Are We Learning?

You will learn **both**, but they serve distinct purposes:

| Feature | Arduino IDE / Arduino Core | ESP-IDF (Espressif IoT Development Framework) |
| :--- | :--- | :--- |
| **Primary Role** | Quick reference, rapid prototyping, beginner concepts | **The professional main path** |
| **Ease of Start** | Very simple (`pinMode`, `digitalWrite`, `delay`) | Industry standard (`gpio_set_level`, FreeRTOS tasks) |
| **Power & Control** | High-level abstraction; hides RTOS and registers | Full dual-core control, memory tuning, eFuses, deep diagnostics |
| **Our Philosophy** | **Additional learning and reference tool** | **Core engineering foundation** |

> **Important**: Arduino is an additional learning and reference path to help you grasp concepts quickly. It does **not** replace ESP-IDF in this curriculum.

---

## Recommended Beginner Learning Order

Follow this exact sequence to build rock-solid foundations:

```text
[Day 0: Electronics Basics] -> [Tool Setup: ESP-IDF] -> [Phase 1: Boot & System Info]
                                                                     |
[Phase 2 Day 10: Button Input] <- [Phase 2 Day 9: LED Blink] <-------+
```

1. **Step 1: Master Day 0 Electronics Prerequisites**  
   Read **[Day 0 - Electronics Prerequisites](Prerequisites.md)**. Learn Voltage (V), Current (I), Resistance (R), Ohm's Law, and how to safely wire an LED.
2. **Step 2: Set Up Your Development Environment**  
   Follow **[ESP-IDF Windows Setup Guide](docs/ESP_IDF_WINDOWS_SETUP.md)** to install VS Code and configure ESP-IDF.
3. **Step 3: Run Your First ESP-IDF Project**  
   Explore **[Phase 1: Architecture & Foundations](firmware/phase01_foundations/README.md)** to see how the ESP32 boots and reports system diagnostic information.
4. **Step 4: Wire and Blink Your First External LED**  
   Jump into **[Phase 2: Digital I/O](firmware/phase02_digital_io/README.md)** and execute **[Day 9: GPIO Output Blink](firmware/phase02_digital_io/day09_gpio_output/README.md)**.
5. **Step 5: Add a Button and Practice Input**  
   Move to Day 10 to learn digital input, pull-up resistors, and state reading.

---

## Critical Hardware Safety Rules

Please remember these rules before plugging any wire into your board:

> **Warning: ESP32 Uses 3.3V Logic!**  
> - ESP32 GPIO pins tolerate a maximum of **3.3V**.
> - **NEVER connect 5V directly to an ESP32 GPIO pin.** Doing so will permanently destroy the pin or the entire SoC.
> - **Always use a 220 ohm or 330 ohm resistor with LEDs.** Never connect an LED directly between GPIO and GND.
> - **NO mains AC electricity experiments for beginners!** All early experiments are strictly low-voltage DC (3.3V / 5V USB powered).

---

## The Daily Engineering Workflow

For every daily lesson, follow this consistent 9-step learning loop:

```text
Read -> Wire -> Code -> Build -> Flash -> Monitor -> Experiment -> Commit -> Document
```

1. **Read**: Review the daily concept and pin constraints.
2. **Wire**: Assemble the circuit on your breadboard with power disconnected.
3. **Code**: Write or review the firmware implementation.
4. **Build**: Compile using `idf.py build`.
5. **Flash**: Upload binary to your board using `idf.py -p COMx flash`.
6. **Monitor**: Open serial telemetry using `idf.py -p COMx monitor` (exit with `Ctrl + ]`).
7. **Experiment**: Modify blink speeds, thresholds, or log messages.
8. **Commit**: Save your work in Git with a clean, conventional commit message.
9. **Document**: Check off your progress in **[DAILY_TRACKER.md](DAILY_TRACKER.md)**!

---

## Essential Links and Resources

- **[Day 0 - Electronics Prerequisites](Prerequisites.md)**
- **[Daily Progress Tracker](DAILY_TRACKER.md)**
- **[ESP-IDF Windows Setup Guide](docs/ESP_IDF_WINDOWS_SETUP.md)**
- **[Beginner Troubleshooting Guide](docs/TROUBLESHOOTING.md)**
- **[ESP32-WROOM-32 Pin Reference](docs/ESP32_WROOM_32_REFERENCE.md)**
- **[Our Learning Method](docs/LEARNING_METHOD.md)**
- **[Full 350-Day Roadmap](docs/ROADMAP.md)**
- **[Hardware Bill of Materials](docs/HARDWARE_BOM.md)**
