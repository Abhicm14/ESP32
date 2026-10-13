# ESP32 — Real-Time Firmware & FreeRTOS Architecture

A dedicated repository for real-time firmware development, multi-tasking architectures, and synchronization mechanisms using **FreeRTOS** on the **ESP32** microcontroller (ESP-IDF / Arduino core).

---

## 🎯 Architecture & Core FreeRTOS Concepts

This repository is designed to house firmware implementations and architectural patterns for:

* **Task Management**: Creating, deleting, suspending, prioritizing tasks (`xTaskCreatePinnedToCore`, `vTaskDelay`, `vTaskDelayUntil`).
* **Inter-Task Communication (Queues)**: Safely exchanging messages, sensor telemetry, and events across tasks (`xQueueCreate`, `xQueueSend`, `xQueueReceive`).
* **Synchronization (Semaphores & Mutexes)**:
  * Binary Semaphores (task-to-task signaling & ISR synchronization with `xSemaphoreGiveFromISR`).
  * Counting Semaphores (resource counting).
  * Mutexes & Recursive Mutexes (shared peripheral access, preventing race conditions, and priority inheritance).
* **Event Groups**: Multi-event synchronization, waiting for combinations of bits (`xEventGroupWaitBits`).
* **Task Notifications**: Lightweight, ultra-fast alternative to binary semaphores and queues (`xTaskNotifyGive`, `ulTaskNotifyTake`).
* **Software Timers**: Periodic and one-shot non-blocking timers (`xTimerCreate`, `xTimerStart`).
* **Dual-Core Optimization**: Pinning critical real-time tasks to Core 0 vs background/networking tasks to Core 1 on the Xtensa dual-core ESP32.

---

## 📂 Recommended Directory Layout

```plaintext
ESP32/
├── 01_Task_Creation/         # Task creation, priority preemption, core pinning
├── 02_Queues/                # Queue messaging between sensor tasks & processing tasks
├── 03_Semaphores_Mutexes/    # Shared bus protection (I2C/SPI), race condition resolution
├── 04_Event_Groups/          # Wi-Fi / MQTT connection & state synchronization
├── 05_Software_Timers/       # Periodic health-check and watchdog timers
└── 06_Integrated_Projects/   # Real-world industrial IoT firmware implementations
```

---

## 🛠️ Toolchains & Frameworks Supported

* **ESP-IDF** (Espressif IoT Development Framework)
* **Arduino IDE** (with ESP32 board support package)