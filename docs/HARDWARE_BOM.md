# Hardware Bill of Materials (BOM)

A complete, beginner-friendly guide to all components and tools used across this 350-day learning curriculum.

> **Note: You do NOT need to buy everything at once!**  
> Start with **Section A (Required Now)**. You can acquire parts for later phases as you progress. Over 88% of the entire roadmap runs on the single standard ESP32-WROOM-32 development board.

---

## Critical Safety Warnings

Before purchasing or connecting any hardware:
1. **Never connect 5V directly to an ESP32 GPIO pin.** ESP32 silicon uses **3.3V logic**. Applying 5V to a GPIO pin can permanently burn out the pin driver or the entire microcontroller.
2. **Always use an LED current-limiting resistor (220 ohm or 330 ohm).** Never connect an LED directly between a GPIO pin and GND.
3. **No mains AC work for beginners.** High voltage (110V / 230V) is lethal. All early relay and actuator projects must use safe low-voltage DC loads (such as 5V LEDs or small 5V / 12V DC fans).

---

## Section A: Required Now (Starter Kit)

Everything in this section is needed for **Phase 1 (Foundations)** and **Phase 2 (Digital I/O)**:

| Item | Specification / Details | Approximate Cost | Why You Need It |
| :--- | :--- | :---: | :--- |
| **ESP32-WROOM-32 DevKit** | 30-pin or 38-pin DevKit V1 board (Micro-USB or USB-C) | $4 - $6 | The core dual-core microcontroller board for the curriculum. |
| **USB Data Cable** | High-quality Micro-USB or Type-C (must transfer data) | $2 - $3 | Powers the board, flashes firmware, and streams serial telemetry. |
| **Solderless Breadboard** | 400-tie point or 830-tie point breadboard | $2 - $4 | Solder-free prototyping platform for wiring circuits. |
| **Jumper Wires** | Pack of 40 Male-to-Male (dupont wires) | $2 | Connecting ESP32 pins to breadboard rows. |
| **LED Pack** | 5mm standard LEDs (Red, Green, Blue, Yellow) | $2 | Visual digital output indicators for GPIO blink exercises. |
| **220 ohm Resistors** | 1/4 Watt, 5% carbon film or metal film resistors | $1 | Current limiting for LEDs to protect ESP32 GPIO pins. |
| **Tactile Push Buttons** | 6x6mm 4-pin momentary tactile switches | $1 | Digital input triggers for reading button states. |

---

## Section B: Recommended Later (Phases 3 to 14)

These sensors and actuators are introduced progressively across analog, PWM, communication, and IoT phases:

| Component | Phases Introduced | Practical Use in Lessons |
| :--- | :---: | :--- |
| **10k ohm Potentiometer** | Phase 3 (Analog) | Rotary voltage divider for practicing 12-bit ADC sampling. |
| **Active and Passive Buzzers** | Phase 2 and Phase 4 | Audio tones, sound alerts, and PWM frequency modulation. |
| **1-Channel Relay Module (5V/3.3V)**| Phase 2 (Digital I/O) | Isolated switching of low-voltage DC auxiliary loads. |
| **74HC595 Shift Register** | Phase 2 (Digital I/O) | Output pin expansion via serial shift registers. |
| **DHT22 or BME280 Sensor** | Phase 8 (I2C) | Temperature, relative humidity, and barometric pressure sensing. |
| **MPU6050 6-DOF IMU** | Phase 8 and Phase 19 | 3-axis accelerometer and gyroscope motion tracking. |
| **0.96 inch SSD1306 I2C OLED** | Phase 8 (I2C) | 128x64 pixel graphical display for live sensor telemetry. |
| **SG90 Micro Servo Motor** | Phase 4 (PWM) | 50 Hz PWM angle positioning (0 to 180 degrees). |
| **L298N or DRV8833 H-Bridge** | Phase 4 (PWM) | Directional and speed control for DC motors using MCPWM. |
| **DS18B20 Temperature Sensor** | Phase 10 (1-Wire) | Waterproof 1-Wire digital temperature sensing. |
| **WS2812 NeoPixel LED Strip** | Phase 10 (RMT) | Individually addressable RGB LEDs controlled via ESP32 RMT peripheral. |

---

## Section C: Later Tools and Specialized Modules (Phases 15 to 23)

For advanced communication, hardware diagnostics, and industrial protocol phases:

| Tool / Module | Phases Introduced | Function |
| :--- | :---: | :--- |
| **Digital Multimeter** | Day 0 and Ongoing | Measuring voltage rails, continuity, resistor values, and current draw. |
| **Bidirectional Logic-Level Converter**| Phase 7 to 9 | Safe level shifting between 3.3V and 5.0V buses. |
| **ESP-PROG / JTAG Debugger** | Phase 21 (Diagnostics) | Hardware breakpoints, step-debugging, and memory inspection with GDB. |
| **MAX485 / RS-485 Module** | Phase 7 (UART) and Phase 25 | Industrial half-duplex differential communication (Modbus RTU). |
| **SN65HVD230 CAN Transceiver** | Phase 10 (TWAI) | Automotive 2-wire CAN bus differential transceiver. |
| **LoRa SX1278 SPI Transceiver** | Phase 9 and Phase 25 | Long-range wireless packet telemetry over 433 MHz / 868 MHz / 915 MHz. |
| **2.4 inch or 2.8 inch SPI TFT Display** | Phase 9 and Phase 17 | High-speed color LCD (ST7789 or ILI9341) with LVGL UI dashboards. |

---

## Section D: Board-Specific Architecture Expansion (Phase 24)

Only required for the specialized hardware variant lessons near the end of the roadmap:

| Board | Approximate Cost | Unique Capability Explored |
| :--- | :---: | :--- |
| **ESP32-CAM** | ~$5 | Parallel DVP camera interface, OV2640 sensor, MJPEG video streaming. |
| **ESP32-S3 DevKit** | ~$9 | Native USB OTG (CDC serial, HID keyboards), BLE 5.0, AI vector acceleration. |
| **ESP32-C6 DevKit** | ~$7 | Wi-Fi 6 (802.11ax), Zigbee 3.0, Thread, and Matter protocol stack. |

---

## Shopping Advice for Beginners

- Search for an **"ESP32 Starter Kit"** or **"37-in-1 Sensor Kit"** on electronics websites (Amazon, Robu.in, AliExpress, Adafruit, SparkFun, or local hobby shops). Starter kits often bundle 80% of Sections A and B together at a big discount.
- Always check that your USB cable is capable of data transfer; test it with your phone or external drive before troubleshooting ESP32 connection issues!
