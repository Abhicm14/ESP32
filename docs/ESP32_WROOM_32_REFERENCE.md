# ðŸ“Œ ESP32-WROOM-32 Hardware & GPIO Quick Reference

A clear, beginner-friendly reference for the **ESP32-WROOM-32** development board. Keep this open whenever you wire breadboard circuits!

---

## âš¡ Fundamental Operating Limits

- **Operating Voltage**: **3.3 V DC** (Power pins include 3V3, 5V/VIN via on-board regulator, and GND).
- **GPIO Logic Level**: **3.3 V ONLY**.
  - High logic = 3.3 V
  - Low logic = 0 V
  - âš ï¸ **Never connect 5 V directly to any GPIO pin!**
- **Recommended GPIO Output Current**: 5â€“12 mA continuous per pin.
- **Flash Size**: Varies by board and vendor (typically **4 MB**, though some variants have 8 MB or 16 MB). Inspect your board during Phase 1 boot logs.

---

## ðŸŸ¢ Recommended Beginner GPIO Pins

These pins are general-purpose, safe, and do not interfere with standard boot modes:

```text
GPIO 4, 5, 16, 17, 18, 19, 21, 22, 23, 25, 26, 27, 32, 33
```

- **Output & Input**: All of these pins can be configured as digital outputs (`GPIO_MODE_OUTPUT`) or digital inputs (`GPIO_MODE_INPUT`).
- **Internal Pull-up / Pull-down**: Supported on all of these pins.
- **DAC Pins**: **GPIO 25** and **GPIO 26** feature true 8-bit digital-to-analog converters (DAC).
- **Default I2C Pins**: Typically **GPIO 21** (SDA) and **GPIO 22** (SCL).
- **Default SPI Pins**: Typically **GPIO 18** (SCK), **GPIO 19** (MISO), and **GPIO 23** (MOSI).

---

## ðŸ”µ Input-Only GPIO Pins (GPI)

```text
GPIO 34, GPIO 35, GPIO 36 (VP), GPIO 39 (VN)
```

- **Input ONLY**: These pins **cannot output signals**. Do not attempt to drive LEDs, relays, or buzzers with them.
- **No Internal Pull-up or Pull-down Resistors**: If you connect a button or switch to these pins, you **must wire an external resistor** (e.g., 10 kÎ©) to 3.3V or GND to prevent a floating input.
- **Great for**: Reading analog sensors (potentiometers, light sensors, temperature sensors) via ADC1.

---

## âš ï¸ Important Hardware Warnings

### 1. The SPI Flash Pins (GPIO 6â€“11) â€” NEVER USE!
- **Pins**: `GPIO 6`, `GPIO 7`, `GPIO 8`, `GPIO 9`, `GPIO 10`, `GPIO 11`.
- **Warning**: These pins are connected internally to the SPI flash memory chip that stores your firmware code.
- **What happens if used**: If you connect wires or components to any of these pins, your board will crash immediately or refuse to boot.

---

### 2. Strapping / Boot Pins (GPIO 0, 2, 12, 15) â€” USE WITH CAUTION
- The ESP32 checks the voltage level on these pins during the first millisecond of power-on to decide how to boot:
  - **GPIO 0**: Must be HIGH for normal SPI Flash boot. Pulled LOW to enter serial flashing mode.
  - **GPIO 2**: Must be LOW or floating during flashing; often connected to on-board LED.
  - **GPIO 12**: Selects flash voltage (MTDI). If pulled HIGH externally at boot on 3.3V flash modules, the chip may fail to boot.
  - **GPIO 15**: Outputs boot debug logs on UART0; must be HIGH for silent boot.
- **Beginner Advice**: Avoid using GPIO 0, 2, 12, and 15 for external circuits until you are comfortable with boot strapping behavior.

---

### 3. ADC2 Wi-Fi Conflict
- The ESP32 has two separate analog-to-digital converter blocks: **ADC1** and **ADC2**.
- **ADC2 Channels**: Shared with the internal Wi-Fi radio subsystem (`GPIO 0`, `2`, `4`, `12`, `13`, `14`, `15`, `25`, `26`, `27`).
- **Rule**: Whenever Wi-Fi is active, **ADC2 readings become unavailable or inaccurate**.
- **Best Practice**: Always use **ADC1 pins (GPIO 32, 33, 34, 35, 36, 39)** for analog sensor reading whenever your project uses Wi-Fi.

---

## ðŸ“‹ Quick Pin Summary Table

| GPIO Number | Safe for Beginners? | Input? | Output? | Internal Pull-Up? | Special Function / Notes |
| :---: | :---: | :---: | :---: | :---: | :--- |
| **0** | âš ï¸ Caution | Yes | Yes | Yes | Strapping pin (Boot mode); BOOT button |
| **2** | âš ï¸ Caution | Yes | Yes | Yes | Strapping pin; often on-board LED |
| **4** | âœ… Yes | Yes | Yes | Yes | Great beginner output/input (Day 9 LED) |
| **5** | âœ… Yes | Yes | Yes | Yes | Safe general GPIO |
| **6â€“11**| âŒ NEVER | â€” | â€” | â€” | Connected to internal SPI Flash chip |
| **12** | âš ï¸ Caution | Yes | Yes | Yes | Strapping pin (Flash voltage) |
| **13, 14** | âœ… Yes | Yes | Yes | Yes | Safe general GPIO |
| **15** | âš ï¸ Caution | Yes | Yes | Yes | Strapping pin (UART debug) |
| **16, 17** | âœ… Yes | Yes | Yes | Yes | Safe general GPIO (UART2 default) |
| **18, 19** | âœ… Yes | Yes | Yes | Yes | VSPI clock and MISO |
| **21, 22** | âœ… Yes | Yes | Yes | Yes | Default I2C SDA and SCL |
| **23** | âœ… Yes | Yes | Yes | Yes | VSPI MOSI |
| **25, 26** | âœ… Yes | Yes | Yes | Yes | True 8-bit DAC channels (DAC1, DAC2) |
| **27** | âœ… Yes | Yes | Yes | Yes | Safe general GPIO / ADC2 |
| **32, 33** | âœ… Yes | Yes | Yes | Yes | ADC1 channels (safe with Wi-Fi) |
| **34, 35** | âœ… Yes (Input only) | Yes | âŒ No | âŒ No | Input only; requires external pull-up |
| **36, 39** | âœ… Yes (Input only) | Yes | âŒ No | âŒ No | Input only (VP/VN); requires external pull-up |
