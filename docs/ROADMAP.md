# ðŸ—ºï¸ Master 350-Day ESP32 Curriculum Roadmap

> **Important Reminder for Learners**:
> **Do not try to learn every advanced topic now. Follow the current day in order.**
> Embedded engineering is a marathon, not a sprint. Focus on today's single concept, wire it carefully, write the code, and master it before moving forward.

---

## ðŸ“Š Overview & Board Strategy

This comprehensive curriculum is structured across **25 progressive engineering phases** spanning 350 days.

- **Primary Platform**: **ESP32-WROOM-32** (Standard DevKit V1).
- **Single-Board Coverage**: 308 of the 350 days ($\approx 88\%$) are executed entirely on this single low-cost board.
- **Flash Memory Note**: While standard ESP32-WROOM-32 modules typically ship with 4 MB of external SPI Flash, flash capacities vary across development boards and vendors (4 MB, 8 MB, or 16 MB). Learners should verify their board's configuration during Phase 1.
- **Future Material Status**: All phases beyond currently completed days are marked as **[PLANNED]** and are actively being built in public.

---

## ðŸ—ºï¸ Career Progression Tiers

```
  â”Œâ”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”
  â”‚                           ENGINEERING PROGRESSION TIERS                           â”‚
  â”œâ”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¬â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¬â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¤
  â”‚ Tier              â”‚ Day Range         â”‚ Competencies Acquired                     â”‚
  â”œâ”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¼â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¼â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¤
  â”‚ ðŸŸ¢ Fresher / Entryâ”‚ Days 1â€“110        â”‚ Electronics, GPIO, ADC/DAC, PWM, Timers,  â”‚
  â”‚                   â”‚                   â”‚ FreeRTOS Tasks, UART, I2C, SPI Protocols  â”‚
  â”œâ”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¼â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¼â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¤
  â”‚ ðŸ”µ Junior Level   â”‚ Days 111â€“186      â”‚ I2S Audio, CAN/TWAI, Wi-Fi Sockets,       â”‚
  â”‚                   â”‚                   â”‚ HTTP REST, WebSockets, MQTT, BLE GATT     â”‚
  â”œâ”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¼â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¼â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¤
  â”‚ ðŸŸ¡ Mid-Level      â”‚ Days 187â€“238      â”‚ Hardened Security, Secure Boot V2,        â”‚
  â”‚                   â”‚                   â”‚ Encrypted NVS, Signed OTA, ULP Low-Power  â”‚
  â”œâ”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¼â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¼â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¤
  â”‚ ðŸŸ  Senior Level   â”‚ Days 239â€“308      â”‚ Kinematic Sensor Fusion, DSP Audio,       â”‚
  â”‚                   â”‚                   â”‚ Bare-Metal Registers, JTAG, PCB Design    â”‚
  â”œâ”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¼â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¼â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”¤
  â”‚ ðŸŸ£ Lead / Special â”‚ Days 309â€“350      â”‚ Vision (CAM), USB OTG (S3), Matter (C6),  â”‚
  â”‚                   â”‚                   â”‚ Edge AI, End-to-End Industrial Capstones  â”‚
  â””â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”´â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”´â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”€â”˜
```

---

## ðŸš€ The 25 Progressive Phases

---

### Phase 1: Architecture & Foundations (Days 1â€“8) â€” [COMPLETED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase01_foundations/)

| Days | Topic | Technical Focus & Engineering Implementation | Status |
| :---: | :--- | :--- | :---: |
| **1** | System Architecture | Dual-core Xtensa LX6 internals, memory bus architecture, peripheral interconnects | Completed |
| **2** | Environment Setup | Toolchain installation: ESP-IDF, VS Code integration, Arduino IDE environment | Completed |
| **3** | First Build & Flash | Toolchain compilation, serial flashing, bootloader inspection, monitor logs | Completed |
| **4** | Memory Organization | Memory map analysis: IRAM, DRAM, D/IRAM, RTC Fast & Slow memory regions | Completed |
| **5** | Partition Tables | Custom CSV partition tables, factory vs OTA dual-bank memory allocation | Completed |
| **6** | Build System Mastery | CMakeLists configuration, Kconfig menu options, modular component design | Completed |
| **7** | Logging Framework | `ESP_LOG` verbosity levels, runtime filtering, custom UART telemetry sinks | Completed |
| **8** | **Phase Project** | **System Info Reporter**: Firmware inspecting chip silicon revisions, MAC, and heap maps | Completed |

---

### Phase 2: Digital I/O Operations (Days 9â€“18) â€” [IN PROGRESS]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase02_digital_io/)

| Days | Topic | Technical Focus & Engineering Implementation | Status |
| :---: | :--- | :--- | :---: |
| **9** | GPIO Output â€” Blink an LED | Output push-pull configuration, 220 Î© resistor safety, `gpio_set_level` | In Progress |
| **10** | GPIO Input â€” Read a Button | Input mode, internal pull-up/pull-down configuration, reading pin states | Planned |
| **11** | Arduino GPIO Practice | High-level abstraction practice (`pinMode`, `digitalWrite`, `digitalRead`) | Planned |
| **12** | ESP-IDF GPIO Practice | `gpio_config_t` driver configuration, pin bitmasks, multi-pin setups | Planned |
| **13** | Button Debouncing | State machines, time-threshold noise filtering, mechanical bounce rejection | Planned |
| **14** | Non-blocking Timing | Asynchronous timing patterns using tick counters and non-blocking loops | Planned |
| **15** | Relay and Buzzer Basics | Transistor driver circuits for relay coils, active and passive buzzer control | Planned |
| **16** | 74HC595 Shift Register | Expanding digital output pins using 74HC595 shift registers | Planned |
| **17** | Capacitive Touch | Touch pad threshold configuration and calibration (Pins T0â€“T9) | Planned |
| **18** | **Phase Milestone Project** | **Touch-Controlled Relay System**: Multi-channel isolated load controller | Planned |

*(Note: Register-level manipulation of GPIOs is intentionally deferred to Phase 22).*

---

### Phase 3: Analog Domain (Days 19â€“26) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase03_analog/)

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

### Phase 4: PWM & Motion Control (Days 27â€“36) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase04_pwm_motor/)

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

### Phase 5: Timers & Hardware Interrupts (Days 37â€“46) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase05_timers_isr/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **37** | Hardware Timers | Prescalers, 64-bit counter groups, up/down counting, auto-reload mechanics |
| **38** | Periodic Scheduling | High-precision periodic ISR execution via hardware timer alarms |
| **39** | High-Resolution Timers | Microsecond-accurate software execution schedules via `esp_timer` APIs |
| **40** | Watchdog Systems | Task Watchdog Timer (TWDT) and Interrupt Watchdog (IWDT) stall prevention |
| **41** | Pulse Counter (PCNT) | Hardware edge accumulation, glitch filters, 8-channel counter modules |
| **42** | Quadrature Decoding | Dual-channel quadrature pulse decoding via PCNT for optical rotary encoders |
| **43** | ISR Best Practices | Reducing interrupt latency, IRAM allocation, deferring work to tasks |
| **44â€“45**| ISR Synchronization | Signalling tasks from ISRs using FreeRTOS Semaphores and Queues from ISR |
| **46** | **Phase Project** | **Tachometer & Precision Frequency Meter**: Zero-overhead high-speed frequency analyzer |

---

### Phase 6: FreeRTOS Core & Advanced Patterns (Days 47â€“82) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase06_freertos/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **47â€“50** | Task Management | Task creation, SMP dual-core affinity (`xTaskCreatePinnedToCore`), context switches |
| **51â€“54** | Task Lifecycle | Priorities, preemptive time-slicing, stack sizing, water-mark tracking (`uxTaskGetStackHighWaterMark`) |
| **55â€“57** | Queue Processing | Thread-safe pass-by-value, structured data queues, queue sets |
| **58â€“62** | Synchronization | Binary/counting semaphores, recursive mutexes, priority inversion solutions |
| **63â€“66** | Advanced IPC | Event groups, direct-to-task notifications (lightweight IPC), stream buffers |
| **67â€“69** | Timers & Critical Sections| FreeRTOS software timers, port spinlocks, task critical enter/exit guards |
| **70â€“72** | Memory & Diagnostics | Heap capabilities (`MALLOC_CAP_8BIT`), memory leak audits, `vTaskList` telemetry |
| **73â€“77** | Architecture Patterns | Producer-consumer pipelines, Finite State Machines (FSM), command worker pools |
| **78â€“81** | ESP32 RTOS Extensions | System Event Loop (`esp_event`), inter-core messaging (IPC API) |
| **82** | **Phase Project** | **Multi-Stage Sensor Pipeline**: 5-Task FreeRTOS telemetry processing engine |

---

### Phase 7: UART Serial Protocol (Days 83â€“90) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase07_uart/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **83â€“84** | Protocol Setup | Baud rates, parity, framing, pin matrix remapping, ESP-IDF UART drivers |
| **85â€“86** | Asynchronous Parsing | Event-driven ring buffers, frame delimiter state machines, checksum verification |
| **87â€“88** | Industrial Protocols | NMEA GPS parsing, half-duplex RS-485 transceiver auto-direction, Modbus RTU |
| **89â€“90** | **Phase Project** | **GPS Logging Node**: Custom NMEA sentence parser and RS-485 telemetry bridge |

---

### Phase 8: I2C Bus Infrastructure (Days 91â€“100) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase08_i2c/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **91â€“93** | Bus Dynamics & Drivers | Clock stretching, pull-up sizing, master driver configuration, SSD1306 displays |
| **94â€“97** | Sensor Integration | BME280 (Climate), MPU6050 (IMU raw registers), DS3231 (RTC), AT24C256 (EEPROM) |
| **98â€“100**| **Phase Project** | **Environment Monitor**: Multi-device driver running concurrently across dual I2C buses |

---

### Phase 9: SPI Protocol & High-Speed Interfaces (Days 101â€“110) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase09_spi/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **101â€“103**| Bus Drivers | Transaction configurations, SPI master modes (0â€“3), ILI9341 TFT display |
| **104â€“106**| Storage & Wireless | MicroSD card (SPI vs SDMMC 4-bit), LoRa SX1278 transceiver SPI setup |
| **107â€“109**| Advanced SPI & DMA | W25Q external NOR flash instructions, DMA buffer allocation and transfers |
| **110** | **Phase Project** | **Data Acquisition Hub**: High-speed DMA sensor logger saving data to SD Card |

---

### Phase 10: Advanced Peripherals (Days 111â€“124) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase10_peripherals/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **111â€“114**| I2S Audio Subsystem | Digital MEMS microphone sampling (INMP441), audio DAC streaming (MAX98357A) |
| **115** | 1-Wire Devices | DS18B20 microsecond timing sequences, multi-drop sensor enumerations |
| **116â€“118**| CAN / TWAI Bus | ISO 11898-2 transceivers, bit timing, frame filtering, automotive CAN packets |
| **119â€“122**| RMT Peripheral | Infrared NEC pulse encoders, WS2812 addressable NeoPixel timing drivers |
| **123â€“124**| **Phase Project** | **Smart Infrared & Optical Hub**: Universal IR cloner and RGB notification engine |

---

### Phase 11: Wi-Fi Networking Fundamentals (Days 125â€“142) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase11_wifi/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **125â€“128**| Connectivity Core | 802.11 MAC/PHY, Station mode, event handling, reconnect state machines |
| **129â€“132**| Access Point & Mesh | SoftAP mode, AP+STA concurrent bridge, credentials storage in NVS |
| **133â€“136**| Provisioning & Services | Captive portals, mDNS, SNTP real-time clock synchronization |
| **137â€“140**| Socket Programming | Raw TCP/UDP socket servers, peer-to-peer connectionless ESP-NOW protocol |
| **141â€“142**| **Phase Project** | **Wi-Fi Manager Framework**: Captive portal configuration with automatic failover |

---

### Phase 12: HTTP Applications & Web Services (Days 143â€“156) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase12_http/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **143â€“146**| HTTP Infrastructure | URI routers, REST APIs, serving gzip-compressed web assets from LittleFS |
| **147â€“151**| Data Streaming | cJSON serialization, real-time WebSockets, Server-Sent Events (SSE) |
| **152â€“156**| **Phase Project** | **Real-Time Web Dashboard**: WebSocket control panel with HTTP basic authentication |

---

### Phase 13: MQTT & Industrial IoT Protocols (Days 157â€“168) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase13_mqtt/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **157â€“161**| MQTT Standard | Pub/Sub architecture, QoS 0/1/2, Last Will and Testament (LWT), TLS encryption |
| **162â€“164**| Ecosystem Integration | Node-RED workflows, Home Assistant MQTT auto-discovery conventions |
| **165â€“168**| **Phase Project** | **3-Node IoT Network**: Multi-node ESP-NOW sensor array routing to an MQTT cloud gateway |

---

### Phase 14: Bluetooth Classic & BLE (Days 169â€“186) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase14_bluetooth/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **169â€“173**| Bluetooth Classic | Serial Port Profile (SPP), A2DP audio sink, HID keyboard/mouse emulation |
| **174â€“180**| BLE Core Architecture | GAP/GATT architectures, custom 128-bit UUID services, notifications, pairing security |
| **181â€“183**| Advanced BLE & NimBLE | Apple iBeacons, BLE HID devices, NimBLE memory-optimized stack configuration |
| **184â€“186**| **Phase Project** | **BLE Health Sensor Hub**: Real-time encrypted GATT telemetry server |

---

### Phase 15: Storage, Security, & OTA Firmware (Days 187â€“206) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase15_security_ota/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **187â€“190**| Non-Volatile Storage | Wear leveling, encrypted NVS key-value partitions, LittleFS file systems |
| **191â€“195**| OTA Engineering | Dual-partition switching, rollback validation, signed binary verification |
| **196â€“202**| Hardened Security | Secure Boot V2, Flash Encryption, AES/SHA hardware engines, eFuse burning |
| **203â€“206**| **Phase Project** | **Production Security Device**: Tamper-resistant node with Secure Boot and signed OTA |

---

### Phase 16: Cloud Platform Integrations (Days 207â€“220) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase16_cloud/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **207â€“211**| Cloud Enterprise | AWS IoT Core device shadows & X.509 certs, Firebase Realtime Database, Azure IoT Hub |
| **212â€“215**| Analytics Platforms | ThingsBoard dashboards, InfluxDB time-series logging, Grafana visualization |
| **216â€“220**| **Phase Project** | **Multi-Cloud IoT Agent**: Concurrent AWS IoT and InfluxDB telemetry transmitter |

---

### Phase 17: Displays & Graphical UI (Days 221â€“230) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase17_displays_lvgl/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **221â€“223**| Framebuffers & Touch | TFT_eSPI sprites, double-buffering, XPT2046 resistive touch SPI drivers |
| **224â€“228**| LVGL Graphics Engine | Screens, animated widgets, memory buffers, custom input device driver binding |
| **229â€“230**| **Phase Project** | **Touch Smart Panel**: Interactive multi-screen LVGL environmental dashboard |

---

### Phase 18: Power Architecture & Low-Power Design (Days 231â€“238) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase18_low_power/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **231â€“234**| Sleep Modes | Power profiling, Modem-sleep, Light-sleep, Deep-sleep timer/touch/ext0 wake sources |
| **235â€“237**| ULP Co-Processing | RTC slow memory retention, Ultra-Low Power (ULP) FSM assembly routines |
| **238** | **Phase Project** | **Ultra-Low Power Sensor Node**: Multi-year battery sensor waking only on threshold events |

---

### Phase 19: Comprehensive Sensor Fusion (Days 239â€“248) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase19_sensor_fusion/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **239â€“242**| Advanced Kinematics | Madgwick 6-DOF IMU quaternion fusion, 1D Kalman filtering, vibration telemetry |
| **243â€“247**| Specialized Sensors | HX711 strain gauges, BME680 indoor air quality VOC gas, MAX30102 pulse oximetry |
| **248** | **Phase Project** | **Biometric Health Monitor**: Real-time heart rate, SpOâ‚‚, and motion telemetry |

---

### Phase 20: Audio Processing & DSP (Days 249â€“258) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase20_audio_dsp/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **249â€“252**| Digital Audio | ES8388 codec drivers, MP3 software decoding, web radio streaming |
| **253â€“256**| ESP-DSP Engine | Xtensa assembly-optimized vector routines, FIR/IIR digital filters, FFT spectrums |
| **257â€“258**| **Phase Project** | **Smart Audio Equalizer**: Real-time FFT audio visualizer with Bluetooth A2DP audio |

---

### Phase 21: Testing, Diagnostics & CI/CD (Days 259â€“268) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase21_ci_cd/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **259â€“263**| Advanced Diagnostics | JTAG via ESP-PROG, GDB hardware breakpoints, post-mortem core dump ELF analysis |
| **264â€“268**| Automated Testing & CI | Unity framework unit testing, automated build & test pipelines via GitHub Actions |

---

### Phase 22: Register-Level Development (Days 269â€“300) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase22_bare_metal/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **269â€“285**| Bare-Metal Drivers | Bypassing HALs to write direct register drivers for GPIO, Hardware Timers, UART, I2C, SPI |
| **286â€“295**| Network Bare-Metal | Custom HTTP, WebSockets, and MQTT packet generators constructed over raw BSD sockets |
| **296â€“300**| **Phase Project** | **Custom-Built IoT Stack**: Complete application built entirely without vendor HAL abstractions |

---

### Phase 23: Hardware Design & Mass Production (Days 301â€“308) â€” [PLANNED]
*Platform: ESP32-WROOM-32* | [Directory](../firmware/phase23_manufacturing/)

| Days | Topic | Technical Focus & Engineering Implementation |
| :---: | :--- | :--- |
| **301â€“304**| PCB & Manufacturing | KiCad schematic design, 2.4 GHz PCB antenna keep-out rules, mass flashing setups |
| **305â€“308**| Industrial Deployment | Self-test firmware suites, factory provisioning key workflows, ESP-Insights diagnostics |

---

### Phase 24: Board-Specific Architecture Expansion (Days 309â€“342) â€” [PLANNED]
*Requires specialized low-cost hardware variants* | [Directory](../firmware/phase24_variant_boards/)

| Sub-Phase | Variant Hardware | Technical Focus & Deliverable Projects |
| :--- | :--- | :--- |
| **24A: Days 309â€“316** | **ESP32-CAM (~$5)** | OV2640 camera initialization, frame-buffer capture, MJPEG HTTP video streaming |
| **24B: Days 317â€“328** | **ESP32-S3 DevKit (~$9)** | Native USB OTG (CDC serial, HID keyboards, MSC flash storage), BLE 5.0, ESP-SR speech |
| **24C: Days 329â€“336** | **ESP32-C6 DevKit (~$7)** | IEEE 802.15.4 MAC layer, Zigbee 3.0 clusters, OpenThread border routers, Matter |
| **24D: Days 337â€“342** | **Edge AI Applications** | Edge Impulse models, gesture recognition, acoustic anomaly vibration classification |

---

### Phase 25: Industrial Capstone Systems (Days 343â€“350) â€” [PLANNED]
*Final Integrated Production Engineering* | [Directory](../firmware/phase25_capstones/)

| Capstone Project | Architecture & Technologies Integrated |
| :--- | :--- |
| **1. Industrial Modbus Gateway** | RS-485 Modbus RTU interface transmitting encrypted telemetry to AWS IoT over MQTTS with captive-portal fallback |
| **2. Smart Touch Panel Controller** | LVGL interactive touch interface linked to Home Assistant via encrypted WebSockets |
| **3. Distributed Mesh-LoRa Node** | Multi-node ESP-NOW mesh cluster forwarding field telemetry via long-range LoRa SX1278 uplink |
| **4. Commercial Secure Product Node** | Fully hardened production device featuring Secure Boot V2, Flash Encryption, CI/CD automated test builds, and runtime field crash telemetry |
