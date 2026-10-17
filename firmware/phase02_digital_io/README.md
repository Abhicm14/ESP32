# Phase 2 - Digital I/O: LEDs, Buttons, Buzzers, Relays, and Touch

> **Platform**: `ESP32-WROOM-32`  
> **Roadmap Location**: [Master Roadmap](../../docs/ROADMAP.md) | [Daily Tracker](../../DAILY_TRACKER.md) | [Start Here](../../START_HERE.md)

---

## What is GPIO? (The Plain-English Explanation)

**GPIO** stands for **General Purpose Input/Output**.

Think of GPIO pins as the physical hands, eyes, and voice of your ESP32:
- When a pin is an **Output**, the ESP32 can send voltage out to light up an LED, trigger a relay, or beep a buzzer.
- When a pin is an **Input**, the ESP32 can sense whether an external switch or push button is pressed by reading the incoming voltage.

---

## Hardware Safety Box

> ### Critical Rules for Digital I/O
> 1. **3.3V Logic Only**: ESP32 GPIO pins only tolerate up to **3.3V**. Connecting 5V directly to any GPIO pin will permanently destroy the pin or the chip!
> 2. **Always Use a 220 ohm Resistor with LEDs**: An LED has very low dynamic resistance when conducting. Connecting an LED directly without a resistor creates a short circuit and burns the pin.
> 3. **Never Use GPIO 6 to 11**: These pins connect directly to the on-module SPI Flash chip that holds your firmware.
> 4. **Input-Only Pins**: `GPIO 34`, `35`, `36`, and `39` cannot output voltage and lack internal pull-up resistors.
>
> Check our **[ESP32-WROOM-32 GPIO & Pinout Reference](../../docs/ESP32_WROOM_32_REFERENCE.md)** before plugging in wires!

---

## Daily Execution Plan (Complete in Order!)

> **Important**: Complete each daily project in order. Each lesson builds directly upon concepts from the day before.

| Day | Lesson Title | Practical Implementation Focus | Status / Link |
| :---: | :--- | :--- | :---: |
| **Day 9** | **GPIO Output - Blink an LED** | External LED wiring on GPIO 4, 220 ohm resistor, `gpio_set_level`, FreeRTOS `vTaskDelay` | [Open Lesson](day09_gpio_output/README.md) |
| **Day 10** | **GPIO Input - Read a Button** | Momentary push button, internal pull-up resistor, active-low reading | Planned |
| **Day 11** | **Arduino GPIO Practice - pinMode, digitalWrite, digitalRead** | Comparing Arduino abstractions to understand high-level timing and syntax | Planned |
| **Day 12** | **ESP-IDF GPIO Practice - gpio_set_level, gpio_get_level, gpio_config_t** | Professional `gpio_config_t` structs, pin bitmasks, multi-pin initialization | Planned |
| **Day 13** | **Button Debouncing** | Rejecting mechanical switch contact bounce using state machines and time delays | Planned |
| **Day 14** | **Non-Blocking LED Patterns** | Asynchronous state machines and tick counters without blocking delays | Planned |
| **Day 15** | **Relay and Buzzer Basics** | Driving inductive relay coils with transistors; active vs passive buzzers | Planned |
| **Day 16** | **74HC595 Shift Register** | Expanding output pins: controlling 8 LEDs using only 3 ESP32 control pins | Planned |
| **Day 17** | **Capacitive Touch** | Using ESP32 built-in touch sensor pads (T0 to T9) as touch buttons | Planned |
| **Day 18** | **Phase Milestone Project** | **Touch-Controlled Relay System**: Multi-channel isolated appliance controller | Planned |

> *Note on Advanced Registers*: Direct register-level manipulation of GPIOs is intentionally deferred to **Phase 22 (Register-Level Development)** so beginners can focus on building working circuits with clean, standard ESP-IDF drivers first.

---

## Repository Directory Layout

Each day's implementation lives in its own self-contained directory:

```text
firmware/phase02_digital_io/
|-- README.md                           # This Phase 2 guide
|-- day09_gpio_output/                  # Day 9: External LED blink
|   |-- CMakeLists.txt
|   |-- main/
|   |   |-- CMakeLists.txt
|   |   `-- blink_example_main.c
|   `-- README.md
|-- day10_gpio_input/                   # Day 10: Button input
|-- day11_arduino_gpio_practice/        # Day 11: Arduino comparison
|-- day12_esp_idf_gpio_practice/        # Day 12: gpio_config_t multi-pin
|-- day13_button_debouncing/            # Day 13: Software debouncing
|-- day14_non_blocking_led/             # Day 14: Non-blocking timers
|-- day15_relay_buzzer/                 # Day 15: Transistors, relays, buzzers
|-- day16_74hc595_shift_register/       # Day 16: Pin expansion
|-- day17_capacitive_touch/             # Day 17: Touch pad sensing
`-- day18_phase_project/                # Day 18: Milestone project
```

---

## Tested with ESP-IDF v6.1 Command Cheat Sheet

Always run commands inside the project directory (for example, inside `day09_gpio_output/`):

```bash
# 1. Build the firmware binary
idf.py build

# 2. Flash binary to board (replace COMx with your port, for example COM3)
idf.py -p COMx flash

# 3. Open serial telemetry monitor (115200 baud)
idf.py -p COMx monitor

# 4. Flash and monitor in a single step
idf.py -p COMx flash monitor
```

### Exiting the Monitor
To exit the serial monitor and return to the command prompt:
```
Ctrl + ]
```
*(Hold `Ctrl` and press the right square bracket `]`)*

---

[Previous Phase (Phase 1: Foundations)](../phase01_foundations/README.md) | [Home](../../README.md) | [Next Phase (Phase 3: Analog)](../phase03_analog/README.md)
