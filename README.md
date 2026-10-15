# ⚡ ESP32 — 350-Day Firmware Architecture & Industrial IoT Master Plan

[![ESP32](https://img.shields.io/badge/Platform-ESP32--WROOM--32-E7352C?style=for-the-badge&logo=espressif&logoColor=white)](https://www.espressif.com/)
[![ESP-IDF](https://img.shields.io/badge/Framework-ESP--IDF%20v5.x-red?style=for-the-badge&logo=espressif&logoColor=white)](https://docs.espressif.com/projects/esp-idf/en/latest/)
[![FreeRTOS](https://img.shields.io/badge/Kernel-FreeRTOS%20SMP-blue?style=for-the-badge)](https://www.freertos.org/)
[![Curriculum](https://img.shields.io/badge/Roadmap-350%20Days%20Progressive-success?style=for-the-badge)](#-the-350-day-execution-roadmap)
[![Prerequisites](https://img.shields.io/badge/Day%201-Electronics%20Foundations-orange?style=for-the-badge)](Prerequisites.md)
[![Daily Tracker](https://img.shields.io/badge/Daily%20Tracker-350%20Days%20Log-purple?style=for-the-badge)](DAILY_TRACKER.md)

> A rigorous, hands-on, 350-day engineering curriculum designed to take you from foundational circuit physics to bare-metal registers, hardened FreeRTOS multitasking, secure dual-partition OTA, and production industrial IoT gateways.

---

## 📘 Quick Navigation

* 📅 **[Daily Progress Tracker (350-Day Log)](DAILY_TRACKER.md)** — Check off daily exercises, track percentage completion, and record notes.
* 📖 **[Day 1 Electronics Prerequisites (Zero-to-Hero Guide)](Prerequisites.md)** — Master Voltage, Current, Resistance, Ohm's Law, Series vs. Parallel, 12-bit ADC 4095 calculation, 3.3V vs 5V logic levels, pull-ups, debouncing, and multimeter safety.
* 🔧 **[Hardware Specifications & Pinout Matrix](#-hardware-specifications--chip-profile)** — Detailed silicon limits, strapping pins, and ADC channel allocations.
* 📊 **[Capability Matrix (ESP32-WROOM-32)](#-topic-capability-breakdown)** — What is natively supported vs variant board requirements.
* 🚀 **[The 350-Day Daily Roadmap](#-the-350-day-execution-roadmap)** — All 25 structured engineering phases and milestone capstones.
* 🗺️ **[Career Progression Map](#-engineering-progression-map)** — Entry $\to$ Mid $\to$ Senior $\to$ Lead $\to$ Specialist tiers.
* 💻 **[Development Environment](#-toolchains--development-environment)** — ESP-IDF and Arduino IDE setup.

---

## 🔧 Hardware Specifications & Chip Profile

The core curriculum is anchored on the standard **ESP32-WROOM-32** module. 308 of the 350 days ($\approx 85\%$) are executed entirely on this single low-cost board.

| Feature / Domain | Silicon Specification Details | Firmware Engineering Significance |
| :--- | :--- | :--- |
| **CPU Architecture** | Dual-Core Xtensa 32-bit LX6 @ 240 MHz | Symmetric Multiprocessing (SMP), Core 0 (Protocol) / Core 1 (Application) |
| **SRAM** | 520 KB Internal SRAM | Shared instruction/data memory with heap capability management |
| **Flash Memory** | 4 MB SPI Flash (External on module) | Memory-mapped cached instruction execution; custom partition tables |
| **Wi-Fi Subsystem** | 802.11 b/g/n (2.4 GHz, up to 150 Mbps) | Full TCP/IP stack (LwIP), Station, SoftAP, ESP-NOW, and Mesh modes |
| **Bluetooth Subsystem**| Bluetooth Classic (BR/EDR) + BLE 4.2 | SPP, A2DP audio sink, GAP/GATT custom 128-bit profiles |
| **ADC** | 12-bit SAR ADC (18 channels, 2 blocks) | $0 \dots 4095$ counts ($0.8\text{ mV}$ step size); ADC2 shared with Wi-Fi |
| **DAC** | 2 channels, 8-bit (GPIO 25, GPIO 26) | True analog voltage synthesis ($0\text{V} \dots 3.3\text{V}$), sine/triangle waveforms |
| **Hardware Timers** | 4× 64-bit General Purpose Timers | 16-bit prescalers, hardware auto-reload, microsecond ISR execution |
| **Touch Sensing** | 10 Capacitive Touch Channels (T0–T9) | Capacitive pad sensing with wake-up from Deep Sleep capability |
| **Serial Buses** | 3× UART, 2× SPI (HSPI/VSPI), 2× I2C, 2× I2S | Configurable pin matrix routing; DMA support on SPI and I2S |
| **Special Peripherals**| 1× CAN/TWAI, 8× RMT, 8× PCNT, 16× LEDC | Automotive networks, pulse generation (WS2812/IR), rotary decoding |
| **Security Hardware** | AES-128/256, SHA-2, RSA-4096, RNG | Secure Boot V2, Flash Encryption, hardware crypto accelerators, eFuses |
| **Low-Power Engine** | ULP (Ultra-Low Power) FSM Co-processor | Runs assembly tasks while dual-core CPU is in Deep Sleep ($10\,\mu\text{A}$) |

---

### ⚠️ Critical GPIO Pinout Rules

Understanding hardware constraints prevents destroyed silicon and erratic firmware boot failures:

| Pin Group | GPIO Pin Numbers | Critical Engineering Rule |
| :--- | :--- | :--- |
| **Input-Only Pins** | `GPIO 34`, `GPIO 35`, `GPIO 36 (VP)`, `GPIO 39 (VN)` | **NO internal pull-up or pull-down resistors!** Cannot output signals. Must use external resistors for buttons. |
| **Strapping Pins** | `GPIO 0`, `GPIO 2`, `GPIO 5`, `GPIO 12`, `GPIO 15` | Sampled during boot to enter flashing/running modes. Do NOT pull high/low arbitrarily on power-up! |
| **Internal SPI Flash**| `GPIO 6`, `GPIO 7`, `GPIO 8`, `GPIO 9`, `GPIO 10`, `GPIO 11` | **NEVER USE.** Connected directly to the integrated SPI flash chip. Connecting to external wires crashes the MCU immediately. |
| **ADC2 Wi-Fi Conflict**| `GPIO 0`, `2`, `4`, `12`, `13`, `14`, `15`, `25`, `26`, `27` | ADC2 channels **cannot be used while Wi-Fi is active**. Use ADC1 (`GPIO 32–39`) for analog sensor inputs when Wi-Fi is on. |
| **DAC Pins** | `GPIO 25` (DAC1), `GPIO 26` (DAC2) | Only pins capable of true 8-bit analog voltage output. |

---

## 📊 Topic Capability Breakdown

| Domain / Technology | ESP32-WROOM-32 Support | Technical Architecture Notes |
| :--- | :---: | :--- |
| **Architecture & Toolchains** | ✅ Full | Native ESP-IDF CMake build system, Arduino core |
| **Digital I/O & Expanders** | ✅ Full | GPIO matrix, bit-banging, shift registers (74HC595), PCA9555 |
| **Analog Operations & Filtering** | ✅ Full | 12-bit SAR ADC, 2-ch 8-bit DAC, moving average & Kalman filters |
| **PWM & Motion Control** | ✅ Full | LEDC PWM (16 ch), MCPWM (dead-band time for H-bridges), PID loops |
| **Timers, PCNT & Interrupts** | ✅ Full | 64-bit timers, 8-ch Pulse Counter, low-latency IRAM ISRs |
| **FreeRTOS Multitasking** | ✅ Full | Dual-core task affinity (`xTaskCreatePinnedToCore`), queues, semaphores |
| **Serial Protocols** | ✅ Full | UART (RS-485/Modbus), I2C, SPI (DMA), 1-Wire, CAN/TWAI, RMT (WS2812/IR) |
| **Audio Subsystem** | ✅ Full | I2S microphone (INMP441), I2S DAC amplifier (MAX98357A), ESP-DSP |
| **Wi-Fi Networking** | ✅ Full | Station, SoftAP, ESP-NOW, raw TCP/UDP BSD sockets, mesh networking |
| **IoT Application Protocols** | ✅ Full | HTTP/REST, WebSockets, Server-Sent Events, MQTT (TLS/QoS), CoAP |
| **Bluetooth Dual-Mode** | ✅ Full | Classic Bluetooth (SPP, A2DP), BLE 4.2 GATT server/client |
| **Storage & Security** | ✅ Full | Encrypted NVS, LittleFS, Secure Boot V2, Flash Encryption, eFuses |
| **OTA Firmware Updates** | ✅ Full | Dual-partition switching, rollback verification, signed binary OTA |
| **Displays & Graphical UI** | ✅ Full | SPI TFT displays (ST7789, ILI9341), I2C OLED (SSD1306), LVGL 8/9 |
| **Power Management** | ✅ Full | Modem-sleep, Light-sleep, Deep-sleep with ULP FSM co-processing |
| **Parallel DVP Camera** | ❌ Unsupported | Requires **ESP32-CAM** module (integrated camera header & PSRAM) |
| **Native USB OTG** | ❌ Unsupported | Requires **ESP32-S2** or **ESP32-S3** (integrated USB PHY) |
| **Wi-Fi 6 / Zigbee / Thread / Matter** | ❌ Unsupported | Requires **ESP32-C6** or **ESP32-H2** (IEEE 802.15.4 radio) |

---

## 🧩 Specialized Board Requirements (Phase 24+)

To complete the final 15% of advanced topics in Phase 24, small low-cost variant boards can be acquired:

* **ESP32-CAM (~$5)**: Camera DVP interface, OV2640 sensor drivers, frame-buffer manipulation, MJPEG HTTP streaming.
* **ESP32-S3 DevKit (~$9)**: Native USB OTG (CDC serial, HID keyboards, MSC flash drive), BLE 5.0, Vector instructions for AI acceleration (ESP-DL), Speech recognition (ESP-SR).
* **ESP32-C6 DevKit (~$7)**: Wi-Fi 6 (802.11ax), Zigbee 3.0, Thread mesh, and Matter over Thread protocol stack.

---

## 🚀 The 350-Day Execution Roadmap

---

### Phase 1: Architecture & Foundations (Days 1–8)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **1** | System Architecture | Dual-core Xtensa LX6 internals, memory bus architecture, peripheral interconnects |
| **2** | Environment Setup | Toolchain installation: ESP-IDF, VS Code integration, Arduino IDE environment |
| **3** | First Build & Flash | Toolchain compilation, serial flashing, bootloader inspection, monitor logs |
| **4** | Memory Organization | Memory map analysis: IRAM, DRAM, D/IRAM, RTC Fast & Slow memory regions |
| **5** | Partition Tables | Custom CSV partition tables, factory vs OTA dual-bank memory allocation |
| **6** | Build System Mastery | CMakeLists configuration, Kconfig menu options, modular component design |
| **7** | Logging Framework | `ESP_LOG` verbosity levels, runtime filtering, custom UART telemetry sinks |
| **8** | **Phase Project** | **System Info Reporter**: Firmware inspecting chip silicon revisions, MAC, and heap maps |

---

### Phase 2: Digital I/O Operations (Days 9–18)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **9** | GPIO Output Drive | Internal push-pull driver circuitry, drive strength modes, sink/source limits |
| **10** | GPIO Input Circuitry | Internal pull-up/pull-down configuration, input-only GPI pins (34–39) |
| **11** | High-Level GPIO API | Arduino-style abstraction implementation and timing overhead analysis |
| **12** | ESP-IDF Low-Level Driver | `gpio_config_t` structures, bitmasks, and direct register manipulation |
| **13** | Debouncing Logic | State machines, time-threshold noise filtering, mechanical bounce rejection |
| **14** | Non-blocking Timing | Asynchronous timing patterns using tick counters and non-blocking loops |
| **15** | Relays & Transducers | Driving inductive relay coils via transistors, active vs passive buzzer control |
| **16** | Output Shift Registers | Expanding output pins using 74HC595 over high-speed bit-banged SPI |
| **17** | Capacitive Touch | Touch pad threshold configuration and calibration (Pins T0–T9) |
| **18** | **Phase Project** | **Touch-Controlled Relay System**: Multi-channel isolated AC load controller with feedback |

---

### Phase 3: Analog Domain (Days 19–26)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **19** | ADC Architecture | 12-bit SAR ADC mechanics, attenuation ranges (0dB to 11dB), non-linearity curves |
| **20** | Analog Sampling | Multi-channel sensor acquisition: potentiometers, LDRs, NTC thermistors |
| **21** | Digital Signal Filtering | Moving average, median filtering, and exponential smoothing algorithms |
| **22** | High-Speed Continuous ADC | DMA-backed continuous sampling with ring buffer management |
| **23** | DAC Signal Generation | True 8-bit analog voltage output on GPIO 25/26, sine, triangle, and arbitrary waves |
| **24** | Sigma-Delta Modulation | Multi-channel pulse-density modulation drivers for fine analog synthesis |
| **25** | Internal Sensors | Hall effect magnetic sensor acquisition, internal temperature calibration |
| **26** | **Phase Project** | **Filtered Multi-Sensor Monitor**: Real-time signal smoothing and telemetry pipeline |

---

### Phase 4: PWM & Motion Control (Days 27–36)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **27** | LEDC PWM Architecture | Channel routing, high-speed/low-speed timers, bit-resolution trade-offs |
| **28** | LED Dimming & Effects | Duty-cycle curves, logarithmic dimming, human eye gamma correction tables |
| **29** | RGB Color Mixing | HSV-to-RGB conversion routines and smooth color-space transitions |
| **30** | Servo Control | 50 Hz PWM timing, microsecond pulse-width angle mapping ($500\,\mu\text{s} \dots 2500\,\mu\text{s}$) |
| **31** | DC Motor H-Bridge | L298N/DRV8833 directional control logic and variable speed PWM regulation |
| **32** | Stepper Motor Drivers | A4988 step/dir control, acceleration/deceleration trapezoidal ramp profiles |
| **33** | Motor PWM (MCPWM) | Dedicated motor unit, complementary outputs, dead-band time insertion |
| **34** | PID Control Theory | Discrete PID algorithms, error calculations, proportional/integral/derivative tuning |
| **35** | Closed-Loop Motor Control| Quadrature optical encoder feedback handling with dynamic PID throttle tuning |
| **36** | **Phase Project** | **Closed-Loop Speed Controller**: Precision motor governor with PID velocity hold |

---

### Phase 5: Timers & Hardware Interrupts (Days 37–46)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **37** | Hardware Timers | Prescalers, 64-bit counter groups, up/down counting, auto-reload mechanics |
| **38** | Periodic Scheduling | High-precision periodic ISR execution via hardware timer alarms |
| **39** | High-Resolution Timers | Microsecond-accurate software execution schedules via `esp_timer` APIs |
| **40** | Watchdog Systems | Task Watchdog Timer (TWDT) and Interrupt Watchdog (IWDT) stall prevention |
| **41** | Pulse Counter (PCNT) | Hardware edge accumulation, glitch filters, 8-channel counter modules |
| **42** | Quadrature Decoding | Dual-channel quadrature pulse decoding via PCNT for optical rotary encoders |
| **43** | ISR Best Practices | Reducing interrupt latency, IRAM allocation, deferring work to tasks |
| **44–45**| ISR Synchronization | Signalling tasks from ISRs using FreeRTOS Semaphores and Queues from ISR |
| **46** | **Phase Project** | **Tachometer & Precision Frequency Meter**: Zero-overhead high-speed frequency analyzer |

---

### Phase 6: FreeRTOS Core & Advanced Patterns (Days 47–82)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **47–50** | Task Management | Task creation, SMP dual-core affinity (`xTaskCreatePinnedToCore`), context switches |
| **51–54** | Task Lifecycle | Priorities, preemptive time-slicing, stack sizing, water-mark tracking (`uxTaskGetStackHighWaterMark`) |
| **55–57** | Queue Processing | Thread-safe pass-by-value, structured data queues, queue sets |
| **58–62** | Synchronization | Binary/counting semaphores, recursive mutexes, priority inversion solutions |
| **63–66** | Advanced IPC | Event groups, direct-to-task notifications (lightweight IPC), stream buffers |
| **67–69** | Timers & Critical Sections| FreeRTOS software timers, port spinlocks, task critical enter/exit guards |
| **70–72** | Memory & Diagnostics | Heap capabilities (`MALLOC_CAP_8BIT`), memory leak audits, `vTaskList` telemetry |
| **73–77** | Architecture Patterns | Producer-consumer pipelines, Finite State Machines (FSM), command worker pools |
| **78–81** | ESP32 RTOS Extensions | System Event Loop (`esp_event`), inter-core messaging (IPC API) |
| **82** | **Phase Project** | **Multi-Stage Sensor Pipeline**: 5-Task FreeRTOS telemetry processing engine |

---

### Phase 7: UART Serial Protocol (Days 83–90)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **83–84** | Protocol Setup | Baud rates, parity, framing, pin matrix remapping, ESP-IDF UART drivers |
| **85–86** | Asynchronous Parsing | Event-driven ring buffers, frame delimiter state machines, checksum verification |
| **87–88** | Industrial Protocols | NMEA GPS parsing, half-duplex RS-485 transceiver auto-direction, Modbus RTU |
| **89–90** | **Phase Project** | **GPS Logging Node**: Custom NMEA sentence parser and RS-485 telemetry bridge |

---

### Phase 8: I2C Bus Infrastructure (Days 91–100)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **91–93** | Bus Dynamics & Drivers | Clock stretching, pull-up sizing, master driver configuration, SSD1306 displays |
| **94–97** | Sensor Integration | BME280 (Climate), MPU6050 (IMU raw registers), DS3231 (RTC), AT24C256 (EEPROM) |
| **98–100**| **Phase Project** | **Environment Monitor**: Multi-device driver running concurrently across dual I2C buses |

---

### Phase 9: SPI Protocol & High-Speed Interfaces (Days 101–110)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **101–103**| Bus Drivers | Transaction configurations, SPI master modes (0–3), ILI9341 TFT display |
| **104–106**| Storage & Wireless | MicroSD card (SPI vs SDMMC 4-bit), LoRa SX1278 transceiver SPI setup |
| **107–109**| Advanced SPI & DMA | W25Q external NOR flash instructions, DMA buffer allocation and transfers |
| **110** | **Phase Project** | **Data Acquisition Hub**: High-speed DMA sensor logger saving data to SD Card |

---

### Phase 10: Advanced Peripherals (Days 111–124)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **111–114**| I2S Audio Subsystem | Digital MEMS microphone sampling (INMP441), audio DAC streaming (MAX98357A) |
| **115** | 1-Wire Devices | DS18B20 microsecond timing sequences, multi-drop sensor enumerations |
| **116–118**| CAN / TWAI Bus | ISO 11898-2 transceivers, bit timing, frame filtering, automotive CAN packets |
| **119–122**| RMT Peripheral | Infrared NEC pulse encoders, WS2812 addressable NeoPixel timing drivers |
| **123–124**| **Phase Project** | **Smart Infrared & Optical Hub**: Universal IR cloner and RGB notification engine |

---

### Phase 11: Wi-Fi Networking Fundamentals (Days 125–142)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **125–128**| Connectivity Core | 802.11 MAC/PHY, Station mode, event handling, reconnect state machines |
| **129–132**| Access Point & Mesh | SoftAP mode, AP+STA concurrent bridge, credentials storage in NVS |
| **133–136**| Provisioning & Services | Captive portals, mDNS, SNTP real-time clock synchronization |
| **137–140**| Socket Programming | Raw TCP/UDP socket servers, peer-to-peer connectionless ESP-NOW protocol |
| **141–142**| **Phase Project** | **Wi-Fi Manager Framework**: Captive portal configuration with automatic failover |

---

### Phase 12: HTTP Applications & Web Services (Days 143–156)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **143–146**| HTTP Infrastructure | URI routers, REST APIs, serving gzip-compressed web assets from LittleFS |
| **147–151**| Data Streaming | cJSON serialization, real-time WebSockets, Server-Sent Events (SSE) |
| **152–156**| **Phase Project** | **Real-Time Web Dashboard**: WebSocket control panel with HTTP basic authentication |

---

### Phase 13: MQTT & Industrial IoT Protocols (Days 157–168)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **157–161**| MQTT Standard | Pub/Sub architecture, QoS 0/1/2, Last Will and Testament (LWT), TLS encryption |
| **162–164**| Ecosystem Integration | Node-RED workflows, Home Assistant MQTT auto-discovery conventions |
| **165–168**| **Phase Project** | **3-Node IoT Network**: Multi-node ESP-NOW sensor array routing to an MQTT cloud gateway |

---

### Phase 14: Bluetooth Classic & BLE (Days 169–186)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **169–173**| Bluetooth Classic | Serial Port Profile (SPP), A2DP audio sink, HID keyboard/mouse emulation |
| **174–180**| BLE Core Architecture | GAP/GATT architectures, custom 128-bit UUID services, notifications, pairing security |
| **181–183**| Advanced BLE & NimBLE | Apple iBeacons, BLE HID devices, NimBLE memory-optimized stack configuration |
| **184–186**| **Phase Project** | **BLE Health Sensor Hub**: Real-time encrypted GATT telemetry server |

---

### Phase 15: Storage, Security, & OTA Firmware (Days 187–206)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **187–190**| Non-Volatile Storage | Wear leveling, encrypted NVS key-value partitions, LittleFS file systems |
| **191–195**| OTA Engineering | Dual-partition switching, rollback validation, signed binary verification |
| **196–202**| Hardened Security | Secure Boot V2, Flash Encryption, AES/SHA hardware engines, eFuse burning |
| **203–206**| **Phase Project** | **Production Security Device**: Tamper-resistant node with Secure Boot and signed OTA |

---

### Phase 16: Cloud Platform Integrations (Days 207–220)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **207–211**| Cloud Enterprise | AWS IoT Core device shadows & X.509 certs, Firebase Realtime Database, Azure IoT Hub |
| **212–215**| Analytics Platforms | ThingsBoard dashboards, InfluxDB time-series logging, Grafana visualization |
| **216–220**| **Phase Project** | **Multi-Cloud IoT Agent**: Concurrent AWS IoT and InfluxDB telemetry transmitter |

---

### Phase 17: Displays & Graphical UI (Days 221–230)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **221–223**| Framebuffers & Touch | TFT_eSPI sprites, double-buffering, XPT2046 resistive touch SPI drivers |
| **224–228**| LVGL Graphics Engine | Screens, animated widgets, memory buffers, custom input device driver binding |
| **229–230**| **Phase Project** | **Touch Smart Panel**: Interactive multi-screen LVGL environmental dashboard |

---

### Phase 18: Power Architecture & Low-Power Design (Days 231–238)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **231–234**| Sleep Modes | Power profiling, Modem-sleep, Light-sleep, Deep-sleep timer/touch/ext0 wake sources |
| **235–237**| ULP Co-Processing | RTC slow memory retention, Ultra-Low Power (ULP) FSM assembly routines |
| **238** | **Phase Project** | **Ultra-Low Power Sensor Node**: Multi-year battery sensor waking only on threshold events |

---

### Phase 19: Comprehensive Sensor Fusion (Days 239–248)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **239–242**| Advanced Kinematics | Madgwick 6-DOF IMU quaternion fusion, 1D Kalman filtering, vibration telemetry |
| **243–247**| Specialized Sensors | HX711 strain gauges, BME680 indoor air quality VOC gas, MAX30102 pulse oximetry |
| **248** | **Phase Project** | **Biometric Health Monitor**: Real-time heart rate, SpO₂, and motion telemetry |

---

### Phase 20: Audio Processing & DSP (Days 249–258)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **249–252**| Digital Audio | ES8388 codec drivers, MP3 software decoding, web radio streaming |
| **253–256**| ESP-DSP Engine | Xtensa assembly-optimized vector routines, FIR/IIR digital filters, FFT spectrums |
| **257–258**| **Phase Project** | **Smart Audio Equalizer**: Real-time FFT audio visualizer with Bluetooth A2DP audio |

---

### Phase 21: Testing, Diagnostics & CI/CD (Days 259–268)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **259–263**| Advanced Diagnostics | JTAG via ESP-PROG, GDB hardware breakpoints, post-mortem core dump ELF analysis |
| **264–268**| Automated Testing & CI | Unity framework unit testing, automated build & test pipelines via GitHub Actions |

---

### Phase 22: Register-Level Development (Days 269–300)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **269–285**| Bare-Metal Drivers | Bypassing HALs to write direct register drivers for GPIO, Hardware Timers, UART, I2C, SPI |
| **286–295**| Network Bare-Metal | Custom HTTP, WebSockets, and MQTT packet generators constructed over raw BSD sockets |
| **296–300**| **Phase Project** | **Custom-Built IoT Stack**: Complete application built entirely without vendor HAL abstractions |

---

### Phase 23: Hardware Design & Mass Production (Days 301–308)
*Platform: ESP32-WROOM-32*

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **301–304**| PCB & Manufacturing | KiCad schematic design, 2.4 GHz PCB antenna keep-out rules, mass flashing setups |
| **305–308**| Industrial Deployment | Self-test firmware suites, factory provisioning key workflows, ESP-Insights diagnostics |

---

### Phase 24: Board-Specific Architecture Expansion (Days 309–342)
*Requires specialized low-cost hardware variants*

| Sub-Phase | Variant Hardware | Technical Focus & Deliverable Projects |
| :--- | :--- | :--- |
| **24A: Days 309–316** | **ESP32-CAM (~$5)** | OV2640 camera initialization, frame-buffer capture, MJPEG HTTP video streaming |
| **24B: Days 317–328** | **ESP32-S3 DevKit (~$9)** | Native USB OTG (CDC serial, HID keyboards, MSC flash storage), BLE 5.0, ESP-SR speech |
| **24C: Days 329–336** | **ESP32-C6 DevKit (~$7)** | IEEE 802.15.4 MAC layer, Zigbee 3.0 clusters, OpenThread border routers, Matter |
| **24D: Days 337–342** | **Edge AI Applications** | Edge Impulse models, gesture recognition, acoustic anomaly vibration classification |

---

### Phase 25: Industrial Capstone Systems (Days 343–350)
*Final Integrated Production Engineering*

| Capstone Project | Architecture & Technologies Integrated |
| :--- | :--- |
| **1. Industrial Modbus Gateway** | RS-485 Modbus RTU interface transmitting encrypted telemetry to AWS IoT over MQTTS with captive-portal fallback |
| **2. Smart Touch Panel Controller** | LVGL interactive touch interface linked to Home Assistant via encrypted WebSockets |
| **3. Distributed Mesh-LoRa Node** | Multi-node ESP-NOW mesh cluster forwarding field telemetry via long-range LoRa SX1278 uplink |
| **4. Commercial Secure Product Node** | Fully hardened production device featuring Secure Boot V2, Flash Encryption, CI/CD automated test builds, and runtime field crash telemetry |

---

## 🗺️ Engineering Progression Map

```
  ┌───────────────────────────────────────────────────────────────────────────────────┐
  │                           ENGINEERING PROGRESSION TIERS                           │
  ├───────────────────┬───────────────────┬───────────────────────────────────────────┤
  │ Tier              │ Day Range         │ Competencies Acquired                     │
  ├───────────────────┼───────────────────┼───────────────────────────────────────────┤
  │ 🟢 Entry Level    │ Days 1–110        │ Electronics, GPIO, ADC/DAC, FreeRTOS,     │
  │                   │                   │ Timers, UART, I2C, SPI Bus Protocols      │
  ├───────────────────┼───────────────────┼───────────────────────────────────────────┤
  │ 🔵 Mid Level      │ Days 111–186      │ I2S Audio, CAN/TWAI, Wi-Fi Sockets,       │
  │                   │                   │ HTTP REST, WebSockets, MQTT, BLE GATT     │
  ├───────────────────┼───────────────────┼───────────────────────────────────────────┤
  │ 🟡 Senior Level   │ Days 187–238      │ Hardened Security, Secure Boot V2,        │
  │                   │                   │ Encrypted NVS, Signed OTA, ULP Low-Power  │
  ├───────────────────┼───────────────────┼───────────────────────────────────────────┤
  │ 🟠 Lead Level     │ Days 239–308      │ Kinematic Sensor Fusion, DSP Audio,       │
  │                   │                   │ Bare-Metal Registers, JTAG, PCB Design    │
  ├───────────────────┼───────────────────┼───────────────────────────────────────────┤
  │ 🟣 Specialist     │ Days 309–350      │ Vision (CAM), USB OTG (S3), Matter (C6),  │
  │                   │                   │ Edge AI, End-to-End Industrial Capstones  │
  └───────────────────┴───────────────────┴───────────────────────────────────────────┘
```

---

## 💻 Toolchains & Development Environment

### 1. ESP-IDF (Official Espressif IoT Development Framework)
* **Version**: Recommended **ESP-IDF v5.1+**
* **Editor**: Visual Studio Code with the official **Espressif IDF Extension**
* **Build System**: CMake & Ninja
* **Features**: Full access to FreeRTOS SMP, low-level registers, eFuses, and hardware cryptographic subsystems.

### 2. Arduino IDE (Rapid Prototyping)
* **Version**: Arduino IDE 2.x with the official **ESP32 Arduino Board Package** (by Espressif Systems).
* **Usage**: Ideal for rapid hardware validation and initial peripheral driver bring-up.

---

## 📁 Repository Structure

```
ESP32/
├── Prerequisites.md            # Zero-to-hero Day 1 Electronics Fundamentals
├── DAILY_TRACKER.md            # 350-Day personal daily progress & checklist
├── README.md                   # 350-Day Curriculum & Technical Roadmap
└── firmware/                   # Progressive phase source code repositories
    ├── phase01_foundations/    # System info, memory maps, partition tables
    ├── phase02_digital_io/     # GPIO register drivers, shift registers, touch
    ├── phase03_analog/         # ADC calibration, digital filters, DAC waves
    ├── phase04_pwm_motor/      # LEDC, MCPWM, servo, and PID controllers
    ├── phase05_timers_isr/     # Hardware timers, PCNT tachometer, IRAM ISRs
    ├── phase06_freertos/       # Dual-core tasks, queues, semaphores, event groups
    ├── phase07_uart/           # NMEA GPS parsers, RS-485 Modbus RTU
    ├── phase08_i2c/            # BME280, MPU6050, DS3231 bus drivers
    ├── phase09_spi/            # High-speed display, DMA, MicroSD logging
    ├── phase10_peripherals/    # I2S audio, CAN/TWAI, WS2812 RMT drivers
    ├── phase11_wifi/           # Station, SoftAP, captive portal, ESP-NOW
    ├── phase12_http/           # REST APIs, WebSockets dashboard, LittleFS
    ├── phase13_mqtt/           # Secure MQTT, TLS, Home Assistant discovery
    ├── phase14_bluetooth/      # Classic Bluetooth SPP, custom BLE GATT
    ├── phase15_security_ota/   # Secure Boot V2, Flash Encrypt, dual-bank OTA
    ├── phase16_cloud/          # AWS IoT Core shadows, InfluxDB telemetry
    ├── phase17_displays_lvgl/  # Animated LVGL user interface dashboards
    ├── phase18_low_power/      # Deep-sleep optimization, ULP FSM assembly
    ├── phase19_sensor_fusion/  # Madgwick IMU fusion, biometric health sensors
    ├── phase20_audio_dsp/      # ESP-DSP FFT filter algorithms, audio codecs
    ├── phase21_ci_cd/          # Unity testing, GDB post-mortem, GitHub Actions
    ├── phase22_bare_metal/     # Direct register-level peripheral drivers
    ├── phase23_manufacturing/  # KiCad hardware design, factory test firmware
    ├── phase24_variant_boards/ # ESP32-CAM, ESP32-S3, ESP32-C6, Edge AI
    └── phase25_capstones/      # Industrial Modbus, Smart Panel, LoRa Mesh
```

---

## 🚀 Getting Started

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Abhicm14/ESP32.git
   cd ESP32
   ```

2. **Master the Prerequisites**:
   * Open and review [`Prerequisites.md`](Prerequisites.md).
   * Ensure complete clarity on voltage dividers, pull-up resistors, 12-bit ADC calculations, and multimeter diagnostics before wiring live hardware.

3. **Follow the Daily Plan**:
   * Each day targets one focused concept with hands-on firmware implementation.
   * Consolidate each block by building the end-of-phase Milestone Project.

---

## 👨‍💻 Maintainer & Engineering Profile

* **Architect & Developer**: [Abhishek C M](https://github.com/Abhicm14)
* **GitHub**: [@Abhicm14](https://github.com/Abhicm14)
* **Primary Repository**: [`https://github.com/Abhicm14/ESP32`](https://github.com/Abhicm14/ESP32)

---

*Engineered with precision for embedded systems professionals and IoT hardware architects.* ⚡
