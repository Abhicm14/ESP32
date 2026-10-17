# Master 350-Day ESP32 Curriculum Roadmap

> **Important Reminder for Learners**:  
> **Do not try to learn every advanced topic now. Follow the current day in order.**  
> Embedded engineering is a marathon, not a sprint. Focus on today's single concept, wire it carefully, write the code, and master it before moving forward.

---

## Overview and Board Strategy

This comprehensive curriculum is structured across **25 progressive engineering phases** spanning 350 days.

- **Primary Platform**: **ESP32-WROOM-32** (Standard DevKit V1).
- **Single-Board Coverage**: 308 of the 350 days (approximately 88%) are executed entirely on this single low-cost board.
- **Flash Memory Note**: While standard ESP32-WROOM-32 modules typically ship with 4 MB of external SPI Flash, flash capacities vary across development boards and vendors (4 MB, 8 MB, or 16 MB). Learners should verify their board configuration during Phase 1.
- **Future Material Status**: All phases beyond currently completed days are marked as **[PLANNED]** and are actively being built in public.

---

## Career Progression Tiers

```text
+-------------------+-------------------+-------------------------------------------+
| Tier              | Day Range         | Competencies Acquired                     |
+-------------------+-------------------+-------------------------------------------+
| Fresher / Entry   | Days 1 to 110     | Electronics, GPIO, ADC/DAC, PWM, Timers,  |
|                   |                   | FreeRTOS Tasks, UART, I2C, SPI Protocols  |
+-------------------+-------------------+-------------------------------------------+
| Junior Level      | Days 111 to 186   | I2S Audio, CAN/TWAI, Wi-Fi Sockets,       |
|                   |                   | HTTP REST, WebSockets, MQTT, BLE GATT     |
+-------------------+-------------------+-------------------------------------------+
| Mid-Level         | Days 187 to 238   | Hardened Security, Secure Boot V2,        |
|                   |                   | Encrypted NVS, Signed OTA, ULP Low-Power  |
+-------------------+-------------------+-------------------------------------------+
| Senior Level      | Days 239 to 308   | Kinematic Sensor Fusion, DSP Audio,       |
|                   |                   | Bare-Metal Registers, JTAG, PCB Design    |
+-------------------+-------------------+-------------------------------------------+
| Lead / Specialist | Days 309 to 350   | Vision (CAM), USB OTG (S3), Matter (C6),  |
|                   |                   | Edge AI, End-to-End Industrial Capstones  |
+-------------------+-------------------+-------------------------------------------+
```

---

## The 25 Progressive Phases

---

### Phase 1: Architecture and Foundations (Days 1 to 8) - [COMPLETED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase01_foundations/)

| Days | Topic | Technical Focus and Practical Implementation | Status |
| :---: | :--- | :--- | :---: |
| **1** | System Architecture | Dual-core Xtensa LX6 internals, memory bus architecture, peripheral interconnects | Completed |
| **2** | Environment Setup | Toolchain installation: ESP-IDF, VS Code integration, Arduino IDE environment | Completed |
| **3** | First Build & Flash | Toolchain compilation, serial flashing, bootloader inspection, monitor logs | Completed |
| **4** | Memory Organization | Memory map analysis: IRAM, DRAM, D/IRAM, RTC Fast & Slow memory regions | Completed |
| **5** | Partition Tables | Custom CSV partition tables, factory vs OTA dual-bank memory allocation | Completed |
| **6** | Build System Mastery | CMakeLists configuration, Kconfig menu options, modular component design | Completed |
| **7** | Logging Framework | ESP_LOG verbosity levels, runtime filtering, custom UART telemetry sinks | Completed |
| **8** | **Phase Project** | **System Info Reporter**: Firmware inspecting chip silicon revisions, MAC, and heap maps | Completed |

---

### Phase 2: Digital I/O Operations (Days 9 to 18) - [IN PROGRESS]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase02_digital_io/)

| Days | Topic | Technical Focus and Practical Implementation | Status |
| :---: | :--- | :--- | :---: |
| **9** | GPIO Output - Blink an LED | Output push-pull configuration, 220 ohm resistor safety, gpio_set_level | In Progress |
| **10** | GPIO Input - Read a Button | Input mode, internal pull-up/pull-down configuration, reading pin states | Planned |
| **11** | Arduino GPIO Practice | High-level abstraction practice (pinMode, digitalWrite, digitalRead) | Planned |
| **12** | ESP-IDF GPIO Practice | gpio_config_t driver configuration, pin bitmasks, multi-pin setups | Planned |
| **13** | Button Debouncing | State machines, time-threshold noise filtering, mechanical bounce rejection | Planned |
| **14** | Non-blocking Timing | Asynchronous timing patterns using tick counters and non-blocking loops | Planned |
| **15** | Relay and Buzzer Basics | Transistor driver circuits for relay coils, active and passive buzzer control | Planned |
| **16** | 74HC595 Shift Register | Expanding digital output pins using 74HC595 shift registers | Planned |
| **17** | Capacitive Touch | Touch pad threshold configuration and calibration (Pins T0 to T9) | Planned |
| **18** | **Phase Milestone Project** | **Touch-Controlled Relay System**: Multi-channel isolated load controller | Planned |

*(Note: Register-level manipulation of GPIOs is intentionally deferred to Phase 22).*

---

### Phase 3: Analog Domain (Days 19 to 26) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase03_analog/)

| Days | Topic | Technical Focus and Practical Implementation |
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

### Phase 4: PWM and Motion Control (Days 27 to 36) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase04_pwm_motor/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **27** | LEDC PWM Architecture | Channel routing, high-speed/low-speed timers, bit-resolution trade-offs |
| **28** | LED Dimming & Effects | Duty-cycle curves, logarithmic dimming, human eye gamma correction tables |
| **29** | RGB Color Mixing | HSV-to-RGB conversion routines and smooth color-space transitions |
| **30** | Servo Control | 50 Hz PWM timing, microsecond pulse-width angle mapping (500 us to 2500 us) |
| **31** | DC Motor H-Bridge | L298N/DRV8833 directional control logic and variable speed PWM regulation |
| **32** | Stepper Motor Drivers | A4988 step/dir control, acceleration/deceleration trapezoidal ramp profiles |
| **33** | Motor PWM (MCPWM) | Dedicated motor unit, complementary outputs, dead-band time insertion |
| **34** | PID Control Theory | Discrete PID algorithms, error calculations, proportional/integral/derivative tuning |
| **35** | Closed-Loop Motor Control| Quadrature optical encoder feedback handling with dynamic PID throttle tuning |
| **36** | **Phase Project** | **Closed-Loop Speed Controller**: Precision motor governor with PID velocity hold |

---

### Phase 5: Timers and Hardware Interrupts (Days 37 to 46) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase05_timers_isr/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **37** | Hardware Timers | Prescalers, 64-bit counter groups, up/down counting, auto-reload mechanics |
| **38** | Periodic Scheduling | High-precision periodic ISR execution via hardware timer alarms |
| **39** | High-Resolution Timers | Microsecond-accurate software execution schedules via esp_timer APIs |
| **40** | Watchdog Systems | Task Watchdog Timer (TWDT) and Interrupt Watchdog (IWDT) stall prevention |
| **41** | Pulse Counter (PCNT) | Hardware edge accumulation, glitch filters, 8-channel counter modules |
| **42** | Quadrature Decoding | Dual-channel quadrature pulse decoding via PCNT for optical rotary encoders |
| **43** | ISR Best Practices | Reducing interrupt latency, IRAM allocation, deferring work to tasks |
| **44 to 45**| ISR Synchronization | Signalling tasks from ISRs using FreeRTOS Semaphores and Queues from ISR |
| **46** | **Phase Project** | **Tachometer & Precision Frequency Meter**: Zero-overhead high-speed frequency analyzer |

---

### Phase 6: FreeRTOS Core and Advanced Patterns (Days 47 to 82) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase06_freertos/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **47 to 50** | Task Management | Task creation, SMP dual-core affinity (xTaskCreatePinnedToCore), context switches |
| **51 to 54** | Task Lifecycle | Priorities, preemptive time-slicing, stack sizing, water-mark tracking (uxTaskGetStackHighWaterMark) |
| **55 to 57** | Queue Processing | Thread-safe pass-by-value, structured data queues, queue sets |
| **58 to 62** | Synchronization | Binary/counting semaphores, recursive mutexes, priority inversion solutions |
| **63 to 66** | Advanced IPC | Event groups, direct-to-task notifications (lightweight IPC), stream buffers |
| **67 to 69** | Timers & Critical Sections| FreeRTOS software timers, port spinlocks, task critical enter/exit guards |
| **70 to 72** | Memory & Diagnostics | Heap capabilities (MALLOC_CAP_8BIT), memory leak audits, vTaskList telemetry |
| **73 to 77** | Architecture Patterns | Producer-consumer pipelines, Finite State Machines (FSM), command worker pools |
| **78 to 81** | ESP32 RTOS Extensions | System Event Loop (esp_event), inter-core messaging (IPC API) |
| **82** | **Phase Project** | **Multi-Stage Sensor Pipeline**: 5-Task FreeRTOS telemetry processing engine |

---

### Phase 7: UART Serial Protocol (Days 83 to 90) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase07_uart/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **83 to 84** | Protocol Setup | Baud rates, parity, framing, pin matrix remapping, ESP-IDF UART drivers |
| **85 to 86** | Asynchronous Parsing | Event-driven ring buffers, frame delimiter state machines, checksum verification |
| **87 to 88** | Industrial Protocols | NMEA GPS parsing, half-duplex RS-485 transceiver auto-direction, Modbus RTU |
| **89 to 90** | **Phase Project** | **GPS Logging Node**: Custom NMEA sentence parser and RS-485 telemetry bridge |

---

### Phase 8: I2C Bus Infrastructure (Days 91 to 100) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase08_i2c/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **91 to 93** | Bus Dynamics & Drivers | Clock stretching, pull-up sizing, master driver configuration, SSD1306 displays |
| **94 to 97** | Sensor Integration | BME280 (Climate), MPU6050 (IMU raw registers), DS3231 (RTC), AT24C256 (EEPROM) |
| **98 to 100**| **Phase Project** | **Environment Monitor**: Multi-device driver running concurrently across dual I2C buses |

---

### Phase 9: SPI Protocol and High-Speed Interfaces (Days 101 to 110) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase09_spi/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **101 to 103**| Bus Drivers | Transaction configurations, SPI master modes (0 to 3), ILI9341 TFT display |
| **104 to 106**| Storage & Wireless | MicroSD card (SPI vs SDMMC 4-bit), LoRa SX1278 transceiver SPI setup |
| **107 to 109**| Advanced SPI & DMA | W25Q external NOR flash instructions, DMA buffer allocation and transfers |
| **110** | **Phase Project** | **Data Acquisition Hub**: High-speed DMA sensor logger saving data to SD Card |

---

### Phase 10: Advanced Peripherals (Days 111 to 124) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase10_peripherals/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **111 to 114**| I2S Audio Subsystem | Digital MEMS microphone sampling (INMP441), audio DAC streaming (MAX98357A) |
| **115** | 1-Wire Devices | DS18B20 microsecond timing sequences, multi-drop sensor enumerations |
| **116 to 118**| CAN / TWAI Bus | ISO 11898-2 transceivers, bit timing, frame filtering, automotive CAN packets |
| **119 to 122**| RMT Peripheral | Infrared NEC pulse encoders, WS2812 addressable NeoPixel timing drivers |
| **123 to 124**| **Phase Project** | **Smart Infrared & Optical Hub**: Universal IR cloner and RGB notification engine |

---

### Phase 11: Wi-Fi Networking Fundamentals (Days 125 to 142) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase11_wifi/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **125 to 128**| Connectivity Core | 802.11 MAC/PHY, Station mode, event handling, reconnect state machines |
| **129 to 132**| Access Point & Mesh | SoftAP mode, AP+STA concurrent bridge, credentials storage in NVS |
| **133 to 136**| Provisioning & Services | Captive portals, mDNS, SNTP real-time clock synchronization |
| **137 to 140**| Socket Programming | Raw TCP/UDP socket servers, peer-to-peer connectionless ESP-NOW protocol |
| **141 to 142**| **Phase Project** | **Wi-Fi Manager Framework**: Captive portal configuration with automatic failover |

---

### Phase 12: HTTP Applications and Web Services (Days 143 to 156) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase12_http/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **143 to 146**| HTTP Infrastructure | URI routers, REST APIs, serving gzip-compressed web assets from LittleFS |
| **147 to 151**| Data Streaming | cJSON serialization, real-time WebSockets, Server-Sent Events (SSE) |
| **152 to 156**| **Phase Project** | **Real-Time Web Dashboard**: WebSocket control panel with HTTP basic authentication |

---

### Phase 13: MQTT and Industrial IoT Protocols (Days 157 to 168) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase13_mqtt/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **157 to 161**| MQTT Standard | Pub/Sub architecture, QoS 0/1/2, Last Will and Testament (LWT), TLS encryption |
| **162 to 164**| Ecosystem Integration | Node-RED workflows, Home Assistant MQTT auto-discovery conventions |
| **165 to 168**| **Phase Project** | **3-Node IoT Network**: Multi-node ESP-NOW sensor array routing to an MQTT cloud gateway |

---

### Phase 14: Bluetooth Classic and BLE (Days 169 to 186) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase14_bluetooth/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **169 to 173**| Bluetooth Classic | Serial Port Profile (SPP), A2DP audio sink, HID keyboard/mouse emulation |
| **174 to 180**| BLE Core Architecture | GAP/GATT architectures, custom 128-bit UUID services, notifications, pairing security |
| **181 to 183**| Advanced BLE & NimBLE | Apple iBeacons, BLE HID devices, NimBLE memory-optimized stack configuration |
| **184 to 186**| **Phase Project** | **BLE Health Sensor Hub**: Real-time encrypted GATT telemetry server |

---

### Phase 15: Storage, Security, and OTA Firmware (Days 187 to 206) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase15_security_ota/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **187 to 190**| Non-Volatile Storage | Wear leveling, encrypted NVS key-value partitions, LittleFS file systems |
| **191 to 195**| OTA Engineering | Dual-partition switching, rollback validation, signed binary verification |
| **196 to 202**| Hardened Security | Secure Boot V2, Flash Encryption, AES/SHA hardware engines, eFuse burning |
| **203 to 206**| **Phase Project** | **Production Security Device**: Tamper-resistant node with Secure Boot and signed OTA |

---

### Phase 16: Cloud Platform Integrations (Days 207 to 220) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase16_cloud/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **207 to 211**| Cloud Enterprise | AWS IoT Core device shadows & X.509 certs, Firebase Realtime Database, Azure IoT Hub |
| **212 to 215**| Analytics Platforms | ThingsBoard dashboards, InfluxDB time-series logging, Grafana visualization |
| **216 to 220**| **Phase Project** | **Multi-Cloud IoT Agent**: Concurrent AWS IoT and InfluxDB telemetry transmitter |

---

### Phase 17: Displays and Graphical UI (Days 221 to 230) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase17_displays_lvgl/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **221 to 223**| Framebuffers & Touch | TFT_eSPI sprites, double-buffering, XPT2046 resistive touch SPI drivers |
| **224 to 228**| LVGL Graphics Engine | Screens, animated widgets, memory buffers, custom input device driver binding |
| **229 to 230**| **Phase Project** | **Touch Smart Panel**: Interactive multi-screen LVGL environmental dashboard |

---

### Phase 18: Power Architecture and Low-Power Design (Days 231 to 238) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase18_low_power/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **231 to 234**| Sleep Modes | Power profiling, Modem-sleep, Light-sleep, Deep-sleep timer/touch/ext0 wake sources |
| **235 to 237**| ULP Co-Processing | RTC slow memory retention, Ultra-Low Power (ULP) FSM assembly routines |
| **238** | **Phase Project** | **Ultra-Low Power Sensor Node**: Multi-year battery sensor waking only on threshold events |

---

### Phase 19: Comprehensive Sensor Fusion (Days 239 to 248) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase19_sensor_fusion/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **239 to 242**| Advanced Kinematics | Madgwick 6-DOF IMU quaternion fusion, 1D Kalman filtering, vibration telemetry |
| **243 to 247**| Specialized Sensors | HX711 strain gauges, BME680 indoor air quality VOC gas, MAX30102 pulse oximetry |
| **248** | **Phase Project** | **Biometric Health Monitor**: Real-time heart rate, SpO2, and motion telemetry |

---

### Phase 20: Audio Processing and DSP (Days 249 to 258) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase20_audio_dsp/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **249 to 252**| Digital Audio | ES8388 codec drivers, MP3 software decoding, web radio streaming |
| **253 to 256**| ESP-DSP Engine | Xtensa assembly-optimized vector routines, FIR/IIR digital filters, FFT spectrums |
| **257 to 258**| **Phase Project** | **Smart Audio Equalizer**: Real-time FFT audio visualizer with Bluetooth A2DP audio |

---

### Phase 21: Testing, Diagnostics and CI/CD (Days 259 to 268) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase21_ci_cd/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **259 to 263**| Advanced Diagnostics | JTAG via ESP-PROG, GDB hardware breakpoints, post-mortem core dump ELF analysis |
| **264 to 268**| Automated Testing & CI | Unity framework unit testing, automated build & test pipelines via GitHub Actions |

---

### Phase 22: Register-Level Development (Days 269 to 300) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase22_bare_metal/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **269 to 285**| Bare-Metal Drivers | Bypassing HALs to write direct register drivers for GPIO, Hardware Timers, UART, I2C, SPI |
| **286 to 295**| Network Bare-Metal | Custom HTTP, WebSockets, and MQTT packet generators constructed over raw BSD sockets |
| **296 to 300**| **Phase Project** | **Custom-Built IoT Stack**: Complete application built entirely without vendor HAL abstractions |

---

### Phase 23: Hardware Design and Mass Production (Days 301 to 308) - [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase23_manufacturing/)

| Days | Topic | Technical Focus and Practical Implementation |
| :---: | :--- | :--- |
| **301 to 304**| PCB & Manufacturing | KiCad schematic design, 2.4 GHz PCB antenna keep-out rules, mass flashing setups |
| **305 to 308**| Industrial Deployment | Self-test firmware suites, factory provisioning key workflows, ESP-Insights diagnostics |

---

### Phase 24: Board-Specific Architecture Expansion (Days 309 to 342) - [PLANNED]
*Requires specialized low-cost hardware variants* | [Directory](../firmware/phase24_variant_boards/)

| Sub-Phase | Variant Hardware | Technical Focus and Deliverable Projects |
| :--- | :--- | :--- |
| **24A: Days 309 to 316** | **ESP32-CAM (~$5)** | OV2640 camera initialization, frame-buffer capture, MJPEG HTTP video streaming |
| **24B: Days 317 to 328** | **ESP32-S3 DevKit (~$9)** | Native USB OTG (CDC serial, HID keyboards, MSC flash storage), BLE 5.0, ESP-SR speech |
| **24C: Days 329 to 336** | **ESP32-C6 DevKit (~$7)** | IEEE 802.15.4 MAC layer, Zigbee 3.0 clusters, OpenThread border routers, Matter |
| **24D: Days 337 to 342** | **Edge AI Applications** | Edge Impulse models, gesture recognition, acoustic anomaly vibration classification |

---

### Phase 25: Industrial Capstone Systems (Days 343 to 350) - [PLANNED]
*Final Integrated Production Engineering* | [Directory](../firmware/phase25_capstones/)

| Capstone Project | Architecture and Technologies Integrated |
| :--- | :--- |
| **1. Industrial Modbus Gateway** | RS-485 Modbus RTU interface transmitting encrypted telemetry to AWS IoT over MQTTS with captive-portal fallback |
| **2. Smart Touch Panel Controller** | LVGL interactive touch interface linked to Home Assistant via encrypted WebSockets |
| **3. Distributed Mesh-LoRa Node** | Multi-node ESP-NOW mesh cluster forwarding field telemetry via long-range LoRa SX1278 uplink |
| **4. Commercial Secure Product Node** | Fully hardened production device featuring Secure Boot V2, Flash Encryption, CI/CD automated test builds, and runtime field crash telemetry |
