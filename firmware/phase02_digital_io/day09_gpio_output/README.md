# Day 9 - GPIO Output: Turn an LED ON/OFF

Welcome to your first hands-on digital output project! In this lesson, you will wire an external LED circuit on a breadboard and control it using the professional **ESP-IDF** driver APIs.

---

## Learning Goals

By completing Day 9, you will understand:
1. How to configure an ESP32 GPIO pin as a digital output (`gpio_set_direction`).
2. How to drive a pin HIGH (3.3V) and LOW (0V) using `gpio_set_level`.
3. How to create non-blocking delays using FreeRTOS `vTaskDelay`.
4. How standard Arduino functions map directly to professional ESP-IDF C code.
5. How to compile, flash, and read serial logs with `idf.py`.

---

## Required Components

| Component | Quantity | Purpose |
| :--- | :---: | :--- |
| **ESP32-WROOM-32 DevKit** | 1 | Microcontroller board |
| **USB Data Cable** | 1 | Power, flashing, and serial monitoring |
| **Half-Size Breadboard** | 1 | Circuit assembly platform |
| **5mm LED (Red, Green, or Blue)** | 1 | Light indicator |
| **220 ohm Resistor** | 1 | Current-limiting protection |
| **Male-to-Male Jumper Wires** | 2 | Connecting breadboard to ESP32 |

---

## Exact Circuit Wiring

Make sure the ESP32 is unplugged from USB before making breadboard connections:

```text
ESP32 GPIO 4  ->  220 ohm Resistor  ->  LED Long Leg (Anode, +)
                                        LED Short Leg (Cathode, -)  ->  ESP32 GND
```

1. Insert your LED into two separate rows of the breadboard.
2. Connect one end of the **220 ohm resistor** to the row with the **LED long leg** (Anode).
3. Connect the other end of the resistor to **GPIO 4** on your ESP32 with a jumper wire.
4. Connect the **LED short leg** (Cathode / flat side) to an **ESP32 GND** pin with a jumper wire.

> **Safety Reminder**: Never connect an LED directly between GPIO and GND without the 220 ohm resistor! The resistor protects both the LED and your ESP32 GPIO driver.

---

## Arduino vs ESP-IDF Comparison

If you already have experience with Arduino, here is how the concepts translate 1-to-1 into ESP-IDF:

| Concept | Arduino C++ Function | ESP-IDF Professional C Function | Notes |
| :--- | :--- | :--- | :--- |
| **Pin Setup** | `pinMode(4, OUTPUT);` | `gpio_reset_pin(GPIO_NUM_4);`<br>`gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);` | Resets pin to default state, then sets output mode |
| **Drive High** | `digitalWrite(4, HIGH);` | `gpio_set_level(GPIO_NUM_4, 1);` | Drives pin to 3.3V |
| **Drive Low** | `digitalWrite(4, LOW);` | `gpio_set_level(GPIO_NUM_4, 0);` | Drives pin to 0V (GND) |
| **Delay** | `delay(1000);` | `vTaskDelay(pdMS_TO_TICKS(1000));` | FreeRTOS tick delay yields CPU to background tasks |
| **Program Loop**| `void setup() { ... }`<br>`void loop() { ... }` | `void app_main(void) {`<br>`    /* setup */`<br>`    while(1) { ... }`<br>`}` | Single C entry point; the `while(1)` loop runs your repeating code |
| **Serial Logs** | `Serial.println("LED ON");` | `ESP_LOGI(TAG, "LED ON");` | Formatted, colored, timestamped logging |

---

## Build, Flash and Monitor Commands

Open your terminal in this directory (`firmware/phase02_digital_io/day09_gpio_output`):

```bash
# Step 1: Build the project
idf.py build

# Step 2: Flash to your board and start serial monitor (replace COMx with your port)
idf.py -p COMx flash monitor
```

### Exiting the Monitor
To exit the serial monitor, press:
```
Ctrl + ]
```
*(Hold `Ctrl` and press the right square bracket `]`)*

---

## Expected Serial Output

When the project boots, you will see the system bootloader logs followed by your Day 9 application output:

```text
I (315) DAY_09: Day 9 started: GPIO 4 LED blink
I (325) DAY_09: LED ON
I (1325) DAY_09: LED OFF
I (2325) DAY_09: LED ON
I (3325) DAY_09: LED OFF
```

Your physical LED on the breadboard should turn ON for 1 second, then OFF for 1 second in sync with the log messages!

---

## Common Problems and Troubleshooting

- **LED Does Not Turn ON**:
  1. **Reversed LED Polarity**: Try flipping the LED around. The long leg must connect towards the resistor/GPIO 4; the short leg must connect to GND.
  2. **Wrong GPIO Pin**: Check that your wire is plugged into pin `D4` / `IO4` on your board, not physical pin 4.
  3. **Missing Resistor**: Ensure the resistor is seated firmly in the same breadboard row as the LED long leg.
  4. **Built-In LED Note**: The built-in blue/red LED on ESP32 DevKit boards is usually wired to **GPIO 2** (or not present at all), NOT GPIO 4. Always use an **external LED** on GPIO 4 for this lesson.
- **Flashing Fails / COM Port Error**:
  1. Check Device Manager to verify your COM port number.
  2. If stuck at `Connecting........_____.....`, press and hold the **BOOT** button on your ESP32 board until flashing begins.
  3. See our full **[Beginner Troubleshooting Guide](../../../docs/TROUBLESHOOTING.md)** for more tips.

---

## Small Experiments to Try

Before moving to Day 10, try these small modifications in `main/blink_example_main.c`:

1. **Change the Blink Speed**:  
   Change `pdMS_TO_TICKS(1000)` to `pdMS_TO_TICKS(200)` for a fast strobe effect. Rebuild and flash to see the difference!
2. **Change the Serial Log Message**:  
   Update the log tag or message string (for example, `ESP_LOGI(TAG, "Hello from Day 9! Pin is HIGH");`).
3. **Try an Asymmetric Heartbeat Pattern**:  
   Turn the LED ON for 100 ms, OFF for 100 ms, ON for 100 ms, and OFF for 700 ms!

---

## Day 9 Completion Checklist

- [ ] Breadboard circuit wired safely with 220 ohm resistor on GPIO 4
- [ ] Firmware compiled cleanly with `idf.py build`
- [ ] Flashed successfully to ESP32 with `idf.py flash`
- [ ] Verified serial logs and visual LED blinking
- [ ] Exited monitor using `Ctrl + ]`
- [ ] Recorded progress in **[DAILY_TRACKER.md](../../../DAILY_TRACKER.md)**!
