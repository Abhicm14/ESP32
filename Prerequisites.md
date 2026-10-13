# 📘 DAY 1 — Essential Electronics Fundamentals for Embedded Engineers

## Phase 1 | Module 1.1 | Prerequisites Before Touching the ESP32

---

## 🎯 Today's Goal

> Before you write a single line of firmware or plug in your ESP32, you must understand the **invisible physical forces** that govern embedded hardware. Today, you will master the foundational electronics principles that firmware engineers rely on **every single day**.
> 
> **Why?** Because when your GPIO pin reads erratic garbage values, when an ADC sensor outputs unstable data, when your ESP32 brownouts and resets unexpectedly, or when an LED burns out — the root cause is almost always **electronics, not software**.

---

## 📑 TABLE OF CONTENTS

```
1.  The Big Three: Voltage, Current, Resistance
2.  Ohm's Law — The Most Important Formula in Electronics
3.  Electrical Power & Thermal Ratings
4.  Series vs Parallel Circuits — Complete Explanation with Examples
5.  Digital vs Analog Signals & ADC Resolution (How 4095 is Calculated)
6.  Logic Levels (3.3V vs 5V — ESP32 Survival Guide)
7.  Pull-Up & Pull-Down Resistors (Preventing Floating Pins)
8.  Voltage Dividers (Interfacing High-Voltage Sensors)
9.  LEDs & Current Limiting Resistors
10. Capacitors & Decoupling Power Rails
11. Switches & Debouncing (Hardware & Software)
12. Transistors & MOSFETs (High-Current Switching)
13. Diodes & Flyback Protection
14. Ground (GND) — The Universal Reference Plane
15. Reading Schematics & Circuit Symbols
16. Breadboard Architecture & Wiring Hygiene
17. Multimeter Mastery — Your Diagnostic Tool
18. Practice Problems, Review Checklist & Hands-On Project
```

---

## 1. THE BIG THREE: VOLTAGE, CURRENT, RESISTANCE

### The Water Analogy

```
    WATER TANK ANALOGY                    ELECTRICAL CIRCUIT
    ──────────────────                    ──────────────────

    ┌──────────┐                          ┌──────────┐
    │  WATER   │                          │  BATTERY │
    │  TANK    │                          │  (3.3V)  │
    │  (High)  │                          │          │
    └────┬─────┘                          └────┬─────┘
         │                                     │
         │  ← Pressure (Voltage)               │  ← Potential (Voltage)
         │                                     │
    ┌────┴─────┐                          ┌────┴─────┐
    │  NARROW  │                          │ RESISTOR │
    │  PIPE    │                          │  (Limits │
    └────┬─────┘                          │  Current)│
         │                                     │
         │  ← Flow Rate (Current)              │  ← Electron Flow (Current)
         ▼                                     ▼
    ┌──────────┐                          ┌──────────┐
    │  DRAIN   │                          │  GROUND  │
    │  (0V)    │                          │   (0V)   │
    └──────────┘                          └──────────┘
```

### Definitions & Units

| Quantity | Symbol | Unit | Core Meaning |
| :--- | :---: | :---: | :--- |
| **Voltage** | $V$ | Volt ($\text{V}$) | Electrical "pressure" pushing charge carriers through a circuit |
| **Current** | $I$ | Ampere ($\text{A}$) | Rate of electrical charge flow ($\text{1 A} = 1\text{ Coulomb/sec}$) |
| **Resistance** | $R$ | Ohm ($\Omega$) | Opposition to current flow within a material |

### Real-World ESP32 Context
* **ESP32 Core & I/O Voltage**: $3.3\text{ V}$ nominal (NOT $5\text{ V}$ like legacy 8-bit Arduino).
* **Absolute Maximum VDD**: $3.6\text{ V}$ (exceeding this permanently damages silicon gates).
* **Maximum Recommended Current per GPIO**: $\sim 20\text{ mA}$ to $40\text{ mA}$ max.
* **Total MCU Package Current**: $\sim 1.2\text{ A}$ surge peak during Wi-Fi calibration.

---

## 2. OHM'S LAW — THE FOUNDATIONAL FORMULA

$$\mathbf{V = I \times R} \qquad \mathbf{I = \frac{V}{R}} \qquad \mathbf{R = \frac{V}{I}}$$

```
            ┌─────────────────────────────────────────┐
            │                    V                    │
            │                  ╱   ╲                  │
            │                ┌────┴────┐              │
            │                │  I × R  │              │
            │                └─────────┘              │
            └─────────────────────────────────────────┘
```

### Practical Calculations for Firmware Engineers

**Example 1: Calculating an LED Resistor**
* Target: Drive a Red LED ($V_f = 2.0\text{ V}$, $I = 15\text{ mA} = 0.015\text{ A}$) from an ESP32 GPIO ($3.3\text{ V}$).
* Resistor must drop the remaining voltage:
  $$V_R = V_{source} - V_f = 3.3\text{ V} - 2.0\text{ V} = 1.3\text{ V}$$
* Calculate required resistance:
  $$R = \frac{V_R}{I} = \frac{1.3\text{ V}}{0.015\text{ A}} = 86.67\,\Omega \implies \text{Use standard } 100\,\Omega \text{ (safer, } \sim 13\text{ mA)}$$

**Example 2: Button Pull-Up Resistor Current**
* Connecting a $4.7\text{ k}\Omega$ pull-up to $3.3\text{ V}$:
  $$I = \frac{V}{R} = \frac{3.3\text{ V}}{4700\,\Omega} = 0.702\text{ mA}$$
* Result: Extremely low standby power, safe for continuous connection.

---

## 3. ELECTRICAL POWER & THERMAL RATINGS

$$\mathbf{P = V \times I} = I^2 R = \frac{V^2}{R}$$

### Power States in ESP32 Systems
* **Active Wi-Fi / BT Transmission**: $V = 3.3\text{ V}$, $I = 240\text{ mA} \implies P = 3.3 \times 0.24 = 0.792\text{ W} \approx 800\text{ mW}$.
* **Modem Sleep Mode**: $V = 3.3\text{ V}$, $I = 20\text{ mA} \implies P = 66\text{ mW}$.
* **Deep Sleep Mode**: $V = 3.3\text{ V}$, $I = 10\,\mu\text{A} \implies P = 33\,\mu\text{W}$.

### Resistor Wattage Ratings
* Standard through-hole resistors: $1/4\text{ W}$ ($250\text{ mW}$) or $1/8\text{ W}$ ($125\text{ mW}$).
* SMD 0805: $1/8\text{ W}$ ($125\text{ mW}$); SMD 0603: $1/10\text{ W}$ ($100\text{ mW}$).
* Always verify power dissipated: if $P_{resistor} > 0.125\text{ W}$, step up to a $1/2\text{ W}$ or $1\text{ W}$ package to prevent thermal failure.

---

## 4. SERIES vs PARALLEL CIRCUITS — COMPLETE EXPLANATION WITH EXAMPLES

---

### THE GOLDEN RULES (Memorize These)

```
╔══════════════════════════════════════════════════════════════╗
║                                                              ║
║   SERIES CIRCUIT:                                            ║
║   ✅ Current (I) is the SAME through ALL components          ║
║   ✅ Voltage (V) is DIFFERENT across each component          ║
║   ✅ Total Resistance = R1 + R2 + R3 (adds UP)              ║
║                                                              ║
║   PARALLEL CIRCUIT:                                          ║
║   ✅ Voltage (V) is the SAME across ALL components           ║
║   ✅ Current (I) is DIFFERENT through each branch            ║
║   ✅ Total Resistance = DECREASES (less than smallest R)     ║
║                                                              ║
╚══════════════════════════════════════════════════════════════╝
```

---

### PART 1: SERIES CIRCUIT — Deep Dive

#### The Water Analogy First

```
    Imagine ONE single pipe with two narrow sections:

    Water Pump (3.3V)
         │
    ┌────▼────┐
    │ NARROW  │  ← Restriction 1 (R1 = 1kΩ)
    │ SECTION │     Some pressure is "used up" here
    └────┬────┘
         │
    ┌────▼────┐
    │ NARROW  │  ← Restriction 2 (R2 = 2kΩ)
    │ SECTION │     More pressure is "used up" here
    └────┬────┘
         │
    Drain (GND)

    KEY INSIGHT:
    • The SAME amount of water flows through BOTH sections
      (water has no other path — it MUST go through both)
    • But the PRESSURE DROP is different at each section
      (wider restriction = less pressure drop)
      (narrower restriction = more pressure drop)
```

#### Real Circuit Example

```
    3.3V (ESP32 GPIO)
     │
    [R1 = 1kΩ]    ← Resistor 1
     │
     ├──── Point A (voltage here = ?)
     │
    [R2 = 2kΩ]    ← Resistor 2
     │
    GND (0V)

    Question: What is the current through R1 and R2?
              What is the voltage across R1 and R2?
```

#### Step-by-Step Calculation

**Step 1: Find Total Resistance**
```
    In series, resistances ADD UP:

    R_total = R1 + R2
    R_total = 1kΩ + 2kΩ
    R_total = 3kΩ = 3000Ω
```

**Step 2: Find Total Current (using Ohm's Law)**
```
    I_total = V_total / R_total
    I_total = 3.3V / 3000Ω
    I_total = 0.0011A
    I_total = 1.1 mA

    ⭐ THIS IS THE KEY POINT:
    This 1.1 mA flows through R1 AND through R2.
    There is NO other path. The current has no choice.

    I_through_R1 = 1.1 mA  ← SAME
    I_through_R2 = 1.1 mA  ← SAME
```

**Step 3: Find Voltage Across Each Resistor**
```
    Voltage across R1:
    V_R1 = I × R1
    V_R1 = 1.1mA × 1kΩ
    V_R1 = 0.0011 × 1000
    V_R1 = 1.1V

    Voltage across R2:
    V_R2 = I × R2
    V_R2 = 1.1mA × 2kΩ
    V_R2 = 0.0011 × 2000
    V_R2 = 2.2V

    ⭐ THIS IS THE KEY POINT:
    The voltage is DIFFERENT across each resistor!
    R1 gets 1.1V, R2 gets 2.2V.
    The bigger resistor gets more voltage.
```

**Step 4: Verify (Voltages Must Add Up to Source)**
```
    V_R1 + V_R2 = V_total
    1.1V + 2.2V = 3.3V ✅ CORRECT!

    This is Kirchhoff's Voltage Law (KVL):
    "All voltage drops in a loop must add up to the source voltage"
```

#### Visual Summary — Series

```
    3.3V
     │
    [R1 = 1kΩ]
     │  V_R1 = 1.1V  ← DIFFERENT voltage
     │  I    = 1.1mA ← SAME current
     │
    [R2 = 2kΩ]
     │  V_R2 = 2.2V  ← DIFFERENT voltage
     │  I    = 1.1mA ← SAME current
     │
    GND (0V)

    Voltage:  3.3V → 2.2V → 0V  (drops step by step)
    Current:  1.1mA everywhere   (never changes)
```

#### Voltage at Point A (Between Resistors)

```
    3.3V
     │
    [R1 = 1kΩ]   ← drops 1.1V
     │
     ├──── Point A = 3.3V - 1.1V = 2.2V
     │
    [R2 = 2kΩ]   ← drops 2.2V
     │
    GND = 0V

    This is EXACTLY how a voltage divider works!
    You'll use this concept to read 12V with ESP32's 3.3V ADC.
```

#### Practical ESP32 Example — Series

```
    Scenario: LED + Current Limiting Resistor (SERIES!)

    3.3V (ESP32 GPIO)
     │
    [R = 220Ω]    ← Current limiting resistor
     │
    [LED]          ← LED (Vf = 2.0V)
     │
    GND

    This is a SERIES circuit! LED + Resistor are in series.

    Step 1: Voltage across resistor
    V_R = V_source - V_LED = 3.3V - 2.0V = 1.3V

    Step 2: Current through circuit (SAME through both!)
    I = V_R / R = 1.3V / 220Ω = 5.9mA

    Step 3: Verify
    I through resistor = 5.9mA ← SAME
    I through LED      = 5.9mA ← SAME
    V across resistor  = 1.3V  ← DIFFERENT
    V across LED       = 2.0V  ← DIFFERENT
    Total V            = 1.3 + 2.0 = 3.3V ✅
```

---

### PART 2: PARALLEL CIRCUIT — Deep Dive

#### The Water Analogy First

```
    Imagine a pipe that SPLITS into two branches:

    Water Pump (3.3V)
         │
    ┌────┴────┐
    │         │
    │  BRANCH 1    BRANCH 2
    │  (Wide)      (Narrow)
    │  R1 = 1kΩ    R2 = 2kΩ
    │  More water  Less water
    │  flows here  flows here
    │         │
    └────┬────┘
         │
    Drain (GND)

    KEY INSIGHT:
    • The PRESSURE (voltage) at the split is the SAME
      for both branches (they both connect to the same point)
    • But the WATER FLOW (current) is DIFFERENT
      (wide pipe = more flow, narrow pipe = less flow)
    • Total water = Branch 1 flow + Branch 2 flow
```

#### Real Circuit Example

```
    3.3V (ESP32 3V3 pin)
     │
     ├────────────┬────────────┐
     │            │            │
    [R1 = 1kΩ]  [R2 = 2kΩ]  [R3 = 3kΩ]
     │            │            │
     ├────────────┴────────────┤
     │
    GND (0V)

    Question: What is the voltage across each resistor?
              What is the current through each resistor?
```

#### Step-by-Step Calculation

**Step 1: Find Voltage Across Each Resistor**
```
    ⭐ THIS IS THE KEY POINT:
    In parallel, ALL components connect to the SAME two points.
    So they ALL see the SAME voltage!

    V_R1 = 3.3V  ← SAME
    V_R2 = 3.3V  ← SAME
    V_R3 = 3.3V  ← SAME

    Why? Because the top of all resistors connects to 3.3V
    and the bottom of all resistors connects to GND (0V).
    The difference is 3.3V - 0V = 3.3V for ALL of them.
```

**Step 2: Find Current Through Each Resistor (using Ohm's Law)**
```
    Current through R1:
    I_R1 = V / R1 = 3.3V / 1kΩ = 3.3mA

    Current through R2:
    I_R2 = V / R2 = 3.3V / 2kΩ = 1.65mA

    Current through R3:
    I_R3 = V / R3 = 3.3V / 3kΩ = 1.1mA

    ⭐ THIS IS THE KEY POINT:
    The current is DIFFERENT through each resistor!
    Smaller resistor = MORE current (less resistance to flow)
    Larger resistor = LESS current (more resistance to flow)
```

**Step 3: Find Total Current**
```
    I_total = I_R1 + I_R2 + I_R3
    I_total = 3.3mA + 1.65mA + 1.1mA
    I_total = 6.05mA

    This is Kirchhoff's Current Law (KCL):
    "Total current entering a junction = total current leaving"

    The ESP32 power supply must provide 6.05mA total.
```

**Step 4: Find Total Resistance**
```
    1/R_total = 1/R1 + 1/R2 + 1/R3
    1/R_total = 1/1000 + 1/2000 + 1/3000
    1/R_total = 0.001 + 0.0005 + 0.000333
    1/R_total = 0.001833

    R_total = 1 / 0.001833
    R_total = 545Ω

    ⭐ Notice: 545Ω is LESS than the smallest resistor (1kΩ)!
    Adding resistors in parallel ALWAYS decreases total resistance.
    Think of it like adding more lanes to a highway — more paths
    for traffic means less overall congestion.

    Verify: I_total = V / R_total = 3.3 / 545 = 6.05mA ✅
```

#### Visual Summary — Parallel

```
    3.3V ──┬──────────┬──────────┬──
           │          │          │
        [1kΩ]      [2kΩ]      [3kΩ]
         │           │          │
      V=3.3V      V=3.3V     V=3.3V   ← SAME voltage
      I=3.3mA     I=1.65mA   I=1.1mA  ← DIFFERENT current
           │          │          │
    GND ───┴──────────┴──────────┴──

    Total current from supply: 6.05mA
    Total resistance: 545Ω (less than any individual R!)
```

#### Practical ESP32 Example — Parallel

```
    Scenario: Three LEDs on the same 3.3V supply (PARALLEL!)

    3.3V (ESP32 3V3 pin)
     │
     ├────[220Ω]────[Red LED]────┐
     │                           │
     ├────[100Ω]────[Blue LED]───┤
     │                           │
     ├────[150Ω]────[Green LED]──┤
     │                           │
    GND ─────────────────────────┘

    Each LED branch is in PARALLEL.

    Voltage across each branch: 3.3V (SAME for all!)

    Current through Red LED branch:
      V_R = 3.3 - 2.0 = 1.3V
      I = 1.3 / 220 = 5.9mA

    Current through Blue LED branch:
      V_R = 3.3 - 3.0 = 0.3V
      I = 0.3 / 100 = 3.0mA

    Current through Green LED branch:
      V_R = 3.3 - 2.2 = 1.1V
      I = 1.1 / 150 = 7.3mA

    Total current from ESP32 3V3 pin:
      I_total = 5.9 + 3.0 + 7.3 = 16.2mA ✅ (safe, under 240mA)

    ⚠️ What if you connected all 3 LEDs in SERIES instead?
      Total Vf = 2.0 + 3.0 + 2.2 = 7.2V
      But ESP32 only provides 3.3V!
      7.2V > 3.3V → LEDs won't light up at all! ❌
      This is why parallel is used for multiple LEDs on low voltage.
```

---

### PART 3: SIDE-BY-SIDE COMPARISON

#### Same Components, Different Configuration

Let's use **two 1kΩ resistors** with a **3.3V source** in both cases:

```
    ┌─────────── SERIES ───────────┐  ┌────────── PARALLEL ──────────┐
    │                              │  │                              │
    │  3.3V                        │  │  3.3V                        │
    │   │                          │  │   │                          │
    │  [1kΩ]  ← R1                │  │   ├──[1kΩ]──┐               │
    │   │  V=1.65V, I=1.65mA     │  │   │ V=3.3V   │               │
    │  [1kΩ]  ← R2                │  │   │ I=3.3mA  │               │
    │   │  V=1.65V, I=1.65mA     │  │   ├──[1kΩ]──┤               │
    │  GND                         │  │   │ V=3.3V   │               │
    │                              │  │   │ I=3.3mA  │               │
    │  R_total = 1k + 1k = 2kΩ   │  │   └─────────┘               │
    │  I_total = 3.3/2k = 1.65mA │  │  GND                         │
    │                              │  │                              │
    │  V_R1 = 1.65V ← DIFFERENT  │  │  R_total = 500Ω              │
    │  V_R2 = 1.65V ← DIFFERENT  │  │  I_total = 3.3/500 = 6.6mA  │
    │  I_R1 = 1.65mA ← SAME      │  │                              │
    │  I_R2 = 1.65mA ← SAME      │  │  V_R1 = 3.3V ← SAME         │
    │                              │  │  V_R2 = 3.3V ← SAME         │
    │                              │  │  I_R1 = 3.3mA ← DIFFERENT   │
    │                              │  │  I_R2 = 3.3mA ← DIFFERENT   │
    └──────────────────────────────┘  └──────────────────────────────┘
```

---

### PART 4: THE ULTIMATE COMPARISON TABLE

```
┌──────────────────┬───────────────────────┬───────────────────────┐
│   Property       │   SERIES              │   PARALLEL            │
├──────────────────┼───────────────────────┼───────────────────────┤
│                  │                       │                       │
│  VOLTAGE (V)     │  SPLITS across each   │  SAME across all      │
│                  │  component            │  components           │
│                  │  V_total = V1+V2+V3   │  V1 = V2 = V3 = V    │
│                  │                       │                       │
├──────────────────┼───────────────────────┼───────────────────────┤
│                  │                       │                       │
│  CURRENT (I)     │  SAME through all     │  SPLITS between       │
│                  │  components           │  branches             │
│                  │  I1 = I2 = I3 = I     │  I_total = I1+I2+I3   │
│                  │                       │                       │
├──────────────────┼───────────────────────┼───────────────────────┤
│                  │                       │                       │
│  RESISTANCE (R)  │  ADDS UP              │  DECREASES            │
│                  │  R = R1+R2+R3         │  1/R = 1/R1+1/R2+1/R3│
│                  │  (Always increases)   │  (Always less than    │
│                  │                       │   smallest R)         │
│                  │                       │                       │
├──────────────────┼───────────────────────┼───────────────────────┤
│                  │                       │                       │
│  IF ONE COMPONENT│  ALL stop working     │  Others keep working  │
│  BREAKS (open)   │  (like old Christmas  │  (like house lights)  │
│                  │   lights)             │                       │
│                  │                       │                       │
├──────────────────┼───────────────────────┼───────────────────────┤
│                  │                       │                       │
│  PATHS FOR       │  ONE path only        │  MULTIPLE paths       │
│  CURRENT         │                       │                       │
│                  │                       │                       │
├──────────────────┼───────────────────────┼───────────────────────┤
│                  │                       │                       │
│  ESP32 EXAMPLE   │  LED + Resistor       │  Multiple sensors on  │
│                  │  Voltage Divider      │  same I2C bus         │
│                  │  Daisy-chain SPI      │  Multiple LEDs on 3V3 │
│                  │                       │  Pull-up resistors    │
│                  │                       │                       │
└──────────────────┴───────────────────────┴───────────────────────┘
```

---

### PART 5: REAL ESP32 SCENARIOS

#### Scenario 1: Voltage Divider (SERIES) — Reading 12V Battery

```
    12V Car Battery
     │
    [R1 = 27kΩ]   ← Series resistor 1
     │
     ├──── Vout → ESP32 GPIO 34 (ADC, max 3.3V)
     │
    [R2 = 10kΩ]   ← Series resistor 2
     │
    GND

    This is SERIES! R1 and R2 are in series.

    Same current through both:
    I = 12V / (27k + 10k) = 12 / 37000 = 0.324mA

    Different voltage across each:
    V_R1 = 0.324mA × 27kΩ = 8.76V  ← drops across R1
    V_R2 = 0.324mA × 10kΩ = 3.24V  ← drops across R2

    Check: 8.76 + 3.24 = 12V ✅

    Vout = V_R2 = 3.24V → Safe for ESP32 ADC! ✅
    (Just under 3.3V limit)
```

#### Scenario 2: I2C Bus (PARALLEL) — Multiple Sensors

```
    3.3V          3.3V          3.3V
     │              │              │
    [4.7kΩ]       [4.7kΩ]        │
     │              │              │
     ├── SDA ───────┼──────────────┤── ESP32 GPIO 21
     │              │              │
     ├── SCL ───────┼──────────────┤── ESP32 GPIO 22
     │              │              │
    [BME280]      [MPU6050]     [OLED]
    Addr: 0x76    Addr: 0x68    Addr: 0x3C
     │              │              │
    GND            GND            GND

    All three devices are in PARALLEL on the I2C bus!

    Voltage: SAME for all devices (3.3V on SDA and SCL)
    Current: DIFFERENT — each device draws its own current
             BME280: ~0.5mA
             MPU6050: ~3.9mA
             OLED: ~20mA
             Total from ESP32 3V3: ~24.4mA

    This is why I2C works — all devices see the same
    signal voltage, but each responds only to its own address.
```

#### Scenario 3: LED Strip (MIXED Series + Parallel)

```
    12V Power Supply
     │
     ├──[R]──[LED]──[LED]──[LED]──┐   ← Branch 1 (3 LEDs in SERIES)
     │                             │
     ├──[R]──[LED]──[LED]──[LED]──┤   ← Branch 2 (3 LEDs in SERIES)
     │                             │
     ├──[R]──[LED]──[LED]──[LED]──┤   ← Branch 3 (3 LEDs in SERIES)
     │                             │
    GND ───────────────────────────┘
              ↑
         All branches in PARALLEL

    Within each branch: SERIES
      • Same current through all 3 LEDs in that branch
      • Voltage splits: 12V = V_R + V_LED1 + V_LED2 + V_LED3

    Between branches: PARALLEL
      • Same voltage (12V) across each branch
      • Current splits: I_total = I_branch1 + I_branch2 + I_branch3

    This is how real LED strips work!
```

---

### 🧠 QUICK MEMORY TRICK

```
    SERIES = "Single path"
      • S = Same Current
      • V = Varies (voltage splits)

    PARALLEL = "Parallel paths"
      • P = Parallel Voltage (same)
      • I = Individual currents (different)

    Or remember:
    
    "In a SERIES of waterfalls, the same river flows through each,
     but the height (voltage) drops at each fall."
    
    "In PARALLEL rivers from the same lake, the water level (voltage)
     is the same, but each river carries a different flow (current)."
```

---

### 📝 PRACTICE PROBLEMS

#### Problem 1 (Series)
You connect $R_1 = 470\,\Omega$ and $R_2 = 1\text{ k}\Omega$ in series to ESP32 GPIO ($3.3\text{ V}$).
1. Find total resistance ($R_{total}$).
2. Find current through each resistor ($I_1, I_2$).
3. Find voltage across each resistor ($V_1, V_2$).
4. Verify voltages add up to $3.3\text{ V}$.

#### Problem 2 (Parallel)
You connect $R_1 = 1\text{ k}\Omega$ and $R_2 = 4.7\text{ k}\Omega$ in parallel to ESP32 $3\text{V}3$ pin.
1. Find voltage across each resistor.
2. Find current through each resistor.
3. Find total current drawn from $3\text{V}3$.
4. Find equivalent parallel resistance.

#### Problem 3 (ESP32 Real-World)
You want to connect two LEDs in parallel to one ESP32 GPIO ($3.3\text{ V}$, max safe current $40\text{ mA}$):
- Red LED: $V_f = 2.0\text{ V}$, target $15\text{ mA}$.
- Green LED: $V_f = 2.2\text{ V}$, target $10\text{ mA}$.
1. Calculate the current-limiting resistor for each branch.
2. Calculate total current from the GPIO pin.
3. Is it safe for the ESP32 pin?

---

## 5. DIGITAL vs ANALOG SIGNALS & ADC RESOLUTION (HOW 4095 IS CALCULATED)

### Fundamental Signal Comparison

| Feature | Digital Signals | Analog Signals |
| :--- | :--- | :--- |
| **Values** | Exactly 2 discrete binary states (`HIGH` / `LOW`, `1` / `0`) | Continuous infinite voltage range ($0.00\text{ V} \dots 3.30\text{ V}$) |
| **ESP32 Peripherals**| General Purpose I/O (GPIO), SPI, I2C, UART | Analog-to-Digital Converter (ADC), DAC |
| **Real Examples** | Pushbuttons, relays, limit switches, clock lines | Temperature (NTC), Potentiometers, LDRs, Battery levels |
| **Firmware API** | `gpio_get_level()`, `digitalRead()`, `gpio_set_level()` | `adc1_get_raw()`, `analogRead()` |

---

### How 4095 is Calculated — ADC Resolution Explained

#### THE SHORT ANSWER

```
    ESP32 ADC = 12-bit resolution

    Highest value = 2^12 - 1 = 4096 - 1 = 4095

    That's it. But let's understand WHY.
```

---

#### STEP 1: What Does "Bit" Mean?

A **bit** is the smallest unit of digital information. It can only be **0** or **1**.

```
    1 bit  =  0 or 1                    (2 possibilities)
    2 bits =  00, 01, 10, 11           (4 possibilities)
    3 bits =  000, 001, 010, ... 111   (8 possibilities)
```

Each bit you add **doubles** the number of possible values.

---

#### STEP 2: Counting in Binary

Let's count from 0 using different numbers of bits:

##### 1-Bit Counter
```
    Binary    Decimal
    ──────    ───────
      0    →    0
      1    →    1
    
    Total values = 2 (0 and 1)
    Highest value = 1
    Formula: 2^1 - 1 = 2 - 1 = 1 ✅
```

##### 2-Bit Counter
```
    Binary    Decimal
    ──────    ───────
      00   →    0
      01   →    1
      10   →    2
      11   →    3
    
    Total values = 4 (0, 1, 2, 3)
    Highest value = 3
    Formula: 2^2 - 1 = 4 - 1 = 3 ✅
```

##### 3-Bit Counter
```
    Binary    Decimal
    ──────    ───────
      000  →    0
      001  →    1
      010  →    2
      011  →    3
      100  →    4
      101  →    5
      110  →    6
      111  →    7
    
    Total values = 8 (0 through 7)
    Highest value = 7
    Formula: 2^3 - 1 = 8 - 1 = 7 ✅
```

##### 4-Bit Counter
```
    Binary       Decimal
    ────────     ───────
      0000   →     0
      0001   →     1
       ...          ...
      1111   →    15
    
    Total values = 16 (0 through 15)
    Highest value = 15
    Formula: 2^4 - 1 = 16 - 1 = 15 ✅
```

---

#### STEP 3: See the Pattern?

```
    ┌──────────┬──────────────┬───────────────┬──────────────┐
    │  Bits    │  Total Values│ Highest Value │  Formula     │
    │  (n)     │  (2^n)       │ (2^n - 1)     │              │
    ├──────────┼──────────────┼───────────────┼──────────────┤
    │  1       │  2           │  1            │  2^1 - 1     │
    │  2       │  4           │  3            │  2^2 - 1     │
    │  3       │  8           │  7            │  2^3 - 1     │
    │  4       │  16          │  15           │  2^4 - 1     │
    │  5       │  32          │  31           │  2^5 - 1     │
    │  6       │  64          │  63           │  2^6 - 1     │
    │  7       │  128         │  127          │  2^7 - 1     │
    │  8       │  256         │  255          │  2^8 - 1     │
    │  9       │  512         │  511          │  2^9 - 1     │
    │  10      │  1024        │  1023         │  2^10 - 1    │
    │  11      │  2048        │  2047         │  2^11 - 1    │
    │  12      │  4096        │  4095         │  2^12 - 1    │ ← ESP32!
    │  13      │  8192        │  8191         │  2^13 - 1    │
    │  14      │  16384       │  16383        │  2^14 - 1    │
    │  16      │  65536       │  65535        │  2^16 - 1    │
    └──────────┴──────────────┴───────────────┴──────────────┘
```

---

#### STEP 4: Why 2^n - 1 and Not Just 2^n?

This is the most common confusion. Here's why:

```
    With 12 bits, you have 4096 DIFFERENT combinations:
    
    0000 0000 0000  →  This is the 1st value  (decimal 0)
    0000 0000 0001  →  This is the 2nd value  (decimal 1)
    0000 0000 0010  →  This is the 3rd value  (decimal 2)
         ...
    1111 1111 1111  →  This is the 4096th value (decimal 4095)
    
    You count from 0, not from 1!
    
    Think of it like a building with 4096 rooms:
      Room numbers: 0, 1, 2, 3, ... 4095
      Total rooms:  4096
      Highest room number: 4095 (NOT 4096!)
    
    Just like your fingers:
      You have 10 fingers
      You count: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
      Highest single digit: 9 (NOT 10!)
      Formula: 10^1 - 1 = 9
```

---

#### STEP 5: Apply to ESP32 ADC

```
    ESP32 has a 12-bit SAR ADC.
    
    "12-bit" means the ADC converts the analog voltage
    into a 12-digit binary number.
    
    Smallest binary:  0000 0000 0000  =  0
    Largest binary:   1111 1111 1111  =  4095
    
    So the ADC output range is: 0 to 4095
    
    Total steps: 4096 (from 0 to 4095 inclusive)
```

---

#### STEP 6: What Does 4095 Actually Mean in Volts?

The ADC maps the input voltage range to the digital range 0-4095.

```
    ESP32 ADC with 11dB attenuation (default):
      Input voltage range: 0V to 3.3V
      Digital output range: 0 to 4095
    
    So:
      0V    → ADC reads 0
      3.3V  → ADC reads 4095
      1.65V → ADC reads ~2048 (halfway)
    
    The mapping formula:
    
    ┌─────────────────────────────────────────────────────┐
    │                                                     │
    │   Voltage = (ADC_Value / 4095) × V_max             │
    │                                                     │
    │   ADC_Value = (Voltage / V_max) × 4095             │
    │                                                     │
    └─────────────────────────────────────────────────────┘
    
    Example 1: ADC reads 2048
      Voltage = (2048 / 4095) × 3.3
      Voltage = 0.5001 × 3.3
      Voltage = 1.65V ✅ (halfway)
    
    Example 2: ADC reads 1000
      Voltage = (1000 / 4095) × 3.3
      Voltage = 0.2442 × 3.3
      Voltage = 0.806V
    
    Example 3: You measure 2.5V, what will ADC read?
      ADC = (2.5 / 3.3) × 4095
      ADC = 0.7576 × 4095
      ADC = 3102
```

---

#### STEP 7: Resolution — How Precise Is It?

```
    Resolution = Smallest voltage change the ADC can detect
    
    Resolution = V_max / (2^n - 1)
    Resolution = 3.3V / 4095
    Resolution = 0.000806V
    Resolution = 0.806 mV per step
    
    This means:
      ADC value 0    = 0.000V
      ADC value 1    = 0.000806V  (0.806 mV)
      ADC value 2    = 0.001612V  (1.612 mV)
      ...
      ADC value 4095 = 3.300V
    
    Each step is ~0.8 millivolts.
    Any voltage change smaller than 0.8mV is INVISIBLE to the ADC.
```

---

#### STEP 8: Compare Different ADC Resolutions

```
    ┌────────────┬───────┬──────────┬──────────────┬─────────────┐
    │  Device    │ Bits  │ Max Value│ Steps        │ Resolution  │
    │            │       │          │              │ (at 3.3V)   │
    ├────────────┼───────┼──────────┼──────────────┼─────────────┤
    │ Arduino    │ 10    │ 1023     │ 1024         │ 3.22 mV     │
    │ Uno        │       │          │              │             │
    ├────────────┼───────┼──────────┼──────────────┼─────────────┤
    │ ESP32      │ 12    │ 4095     │ 4096         │ 0.806 mV    │
    │            │       │          │              │             │
    ├────────────┼───────┼──────────┼──────────────┼─────────────┤
    │ ESP32-S3   │ 12    │ 4095     │ 4096         │ 0.806 mV    │
    │            │       │          │              │             │
    ├────────────┼───────┼──────────┼──────────────┼─────────────┤
    │ External   │ 16    │ 65535    │ 65536        │ 0.050 mV    │
    │ ADS1115    │       │          │              │ (50 μV!)    │
    ├────────────┼───────┼──────────┼──────────────┼─────────────┤
    │ External   │ 24    │ 16777215 │ 16777216     │ 0.000197 mV │
    │ HX711      │       │          │              │ (0.2 μV!)   │
    │ (Load Cell)│       │          │              │             │
    └────────────┴───────┴──────────┴──────────────┴─────────────┘
    
    More bits = more steps = finer resolution = more precise!
    
    ESP32 (12-bit) is 4× more precise than Arduino Uno (10-bit):
      4096 steps vs 1024 steps
```

---

#### STEP 9: Code Example — Reading and Converting

```c
// ESP32 ADC Reading with Voltage Conversion (ESP-IDF / Arduino core)

void setup() {
    Serial.begin(115200);
    
    // Configure ADC
    analogReadResolution(12);       // 12-bit: 0-4095
    analogSetAttenuation(ADC_11db);  // 0-3.3V full dynamic range
}

void loop() {
    int adcRaw = analogRead(34);    // Read GPIO 34 (ADC1_CH6)
    
    // Convert to voltage
    // Formula: Voltage = (ADC / 4095.0) * 3.3
    float voltage = (adcRaw / 4095.0f) * 3.3f;
    
    // Convert to percentage
    float percent = (adcRaw / 4095.0f) * 100.0f;
    
    Serial.printf("ADC: %4d / 4095  |  Voltage: %.3f V  |  %5.1f%%\n",
                   adcRaw, voltage, percent);
    
    delay(500);
}

// Sample Output:
// ADC:    0 / 4095  |  Voltage: 0.000 V  |    0.0%
// ADC: 1024 / 4095  |  Voltage: 0.825 V  |   25.0%
// ADC: 2048 / 4095  |  Voltage: 1.650 V  |   50.0%
// ADC: 3072 / 4095  |  Voltage: 2.476 V  |   75.0%
// ADC: 4095 / 4095  |  Voltage: 3.300 V  |  100.0%
```

---

#### STEP 10: Why Not Use 4096 in the Formula?

```
    Common mistake:
      ❌ voltage = (adcRaw / 4096.0) * 3.3   ← WRONG
      ✅ voltage = (adcRaw / 4095.0) * 3.3   ← CORRECT
    
    Why?
    
    Think of a ruler:
    
    0cm    1cm    2cm    3cm    4cm
    |------|------|------|------|
    
    There are 4 intervals (spaces) but 5 marks (0,1,2,3,4).
    
    Similarly:
    0V to 3.3V has 4095 intervals but 4096 marks (0 to 4095).
    
    When ADC reads 4095, that IS 3.3V:
      (4095 / 4095) × 3.3 = 1.0 × 3.3 = 3.3V ✅
    
    If you used 4096:
      (4095 / 4096) × 3.3 = 0.9998 × 3.3 = 3.299V ❌ (slightly wrong)
    
    Note: In practice, the difference is tiny (0.8mV),
    and ESP32 ADC has non-linearity near 0V and 3.3V anyway.
    So both work in real life, but 4095 is mathematically correct.
```

---

#### 🧠 QUICK REFERENCE CARD

```
    ┌───────────────────────────────────────────────────────┐
    │                                                       │
    │   ADC Resolution Formula:                             │
    │                                                       │
    │   Max Digital Value = 2^n - 1                         │
    │                                                       │
    │   Where n = number of bits                            │
    │                                                       │
    │   ESP32:  n = 12                                      │
    │           2^12 - 1 = 4096 - 1 = 4095                 │
    │                                                       │
    │   Voltage Conversion:                                 │
    │   V = (ADC_Value / 4095) × V_max                     │
    │                                                       │
    │   ADC from Voltage:                                   │
    │   ADC = (V / V_max) × 4095                           │
    │                                                       │
    │   Resolution (smallest step):                         │
    │   Step = V_max / 4095 = 3.3 / 4095 = 0.806 mV       │
    │                                                       │
    └───────────────────────────────────────────────────────┘
```

---

#### 📝 PRACTICE PROBLEMS

```
    1. If ESP32 ADC reads 1500, what is the voltage?
    
    2. If you measure 2.0V on a multimeter, what should
       the ESP32 ADC read (approximately)?
    
    3. If you change to 10-bit resolution (analogReadResolution(10)),
       what is the new max value? What is the new resolution?
    
    4. A 16-bit ADC (ADS1115) with 5V reference:
       What is the max value? What is the resolution?
```

---

## 6. LOGIC LEVELS (3.3V vs 5V — ESP32 SURVIVAL GUIDE)

⚠️ **ESP32 IS NOT 5V TOLERANT.**

| Scenario | Direct Electrical Result | Survival Action |
| :--- | :--- | :--- |
| **$5\text{ V}$ Sensor output $\to$ ESP32 GPIO** | **Permanent Silicon Destruction** (ESD/Gate punch-through) | Must use Bi-directional Level Shifter or Voltage Divider |
| **ESP32 $3.3\text{ V}$ GPIO $\to$ $5\text{ V}$ Input** | Often read as `HIGH` if $V_{IH} < 3.0\text{ V}$, but unreliable | Use 74HCT series buffer or level shifter |
| **$3.3\text{ V}$ Sensor $\to$ ESP32 GPIO** | ✅ **100% Safe & Native** | Direct wire connection |

---

## 7. PULL-UP & PULL-DOWN RESISTORS (PREVENTING FLOATING PINS)

### The Floating Pin Phenomenon
An open CMOS GPIO gate possesses near-infinite input impedance ($> 10^{12}\,\Omega$). Without a defined reference voltage, it acts as an antenna picking up electromagnetic interference (60Hz/50Hz mains noise, Wi-Fi RF waves, static electricity), oscillating wildly between `0` and `1`.

```
    PULL-UP CONFIGURATION (Active LOW)      PULL-DOWN CONFIGURATION (Active HIGH)
    ──────────────────────────────────      ─────────────────────────────────────
              3.3V                                    3.3V
               │                                       │
            [4.7kΩ]  ← Pull-up Resistor             [Pushbutton]
               │                                       │
     GPIO ─────┼                               GPIO ───┼
               │                                       │
          [Pushbutton]                              [10kΩ]   ← Pull-down Resistor
               │                                       │
              GND                                     GND

     • Button open: GPIO reads 3.3V (HIGH)   • Button open: GPIO reads 0V (LOW)
     • Button pressed: GPIO reads 0V (LOW)   • Button pressed: GPIO reads 3.3V (HIGH)
```

### ESP32 Internal Resistor Hardware
* GPIO 0–33 have internal programmable pull-ups ($\sim 45\text{ k}\Omega$) and pull-downs.
* **CRITICAL NOTICE**: **GPIO 34, 35, 36 (VP), and 39 (VN) are INPUT-ONLY**. They have **NO internal pull-up or pull-down resistors**. You MUST supply external resistors for these pins!

---

## 8. VOLTAGE DIVIDERS (BRIDGING HIGH VOLTAGES TO ESP32 ADC)

A voltage divider is fundamentally a **series circuit** used to scale down high sensor voltages into the ESP32's safe $0\text{ V} \dots 3.3\text{ V}$ window.

```
                  V_in (e.g. 12V Battery)
                     │
                    [R1]
                     │
                     ├──── V_out (To ESP32 ADC Pin, ≤ 3.3V)
                     │
                    [R2]
                     │
                    GND
```

$$\mathbf{V_{out} = V_{in} \times \frac{R_2}{R_1 + R_2}}$$

### Rule of Thumb for Resistor Selection
* Keep total resistance ($R_1 + R_2$) between $10\text{ k}\Omega$ and $100\text{ k}\Omega$.
  * Too low ($< 1\text{ k}\Omega$): Draws excessive current, draining batteries and heating resistors.
  * Too high ($> 500\text{ k}\Omega$): ADC sampling capacitor cannot charge fast enough, causing skewed conversions.

---

## 9. LEDs & CURRENT LIMITING RESISTORS

An LED is a non-linear diode with a fixed forward voltage drop ($V_f$). If connected directly to $3.3\text{ V}$ without a resistor, current skyrockets to infinity according to Shockley's equation, instantly melting the LED junction or blowing the ESP32 GPIO output buffer.

```
    ESP32 GPIO (3.3V) ────[ Resistor R ]────►| (LED) ──── GND
```

$$\mathbf{R = \frac{V_{GPIO} - V_f}{I_f}}$$

### Typical LED Forward Voltages ($V_f$) at $15\text{ mA}$
* **Red / Amber**: $1.8\text{ V} \dots 2.0\text{ V} \implies R = (3.3 - 2.0) / 0.015 = 86\,\Omega \to \text{Use } 100\,\Omega$
* **Yellow / Green**: $2.1\text{ V} \dots 2.3\text{ V} \implies R = (3.3 - 2.2) / 0.015 = 73\,\Omega \to \text{Use } 100\,\Omega$
* **Blue / White**: $2.9\text{ V} \dots 3.2\text{ V} \implies R = (3.3 - 3.0) / 0.015 = 20\,\Omega \to \text{Use } 47\,\Omega \dots 100\,\Omega$

---

## 10. CAPACITORS & DECOUPLING POWER RAILS

Capacitors store electrical charge statically and oppose sudden changes in voltage ($\mathbf{I = C \frac{dV}{dt}}$).

### Types & Roles in Embedded Design
1. **Ceramic Capacitors (0.1µF / 100nF)**: Ultra-low Equivalent Series Resistance (ESR). Place directly against ESP32 VDD pins to filter high-frequency digital switching noise.
2. **Electrolytic / Tantalum Capacitors (10µF to 100µF)**: Bulk charge reservoirs. Placed on $3.3\text{ V}$ rails to buffer intense current spikes when the ESP32 powers on its 2.4 GHz RF power amplifier.

```
    3.3V Rail ──┬──────────────────┬──────────────────► ESP32 VDD Pin
                │                  │
            [10µF Bulk]        [100nF Ceramic]
            (Electrolytic)     (High-freq noise)
                │                  │
    GND Rail ───┴──────────────────┴──────────────────► ESP32 GND Pin
```

---

## 11. SWITCHES & DEBOUNCING (HARDWARE & SOFTWARE)

Mechanical metal switch contacts vibrate and bounce on a microscopic scale for $5\text{ ms} \dots 20\text{ ms}$ before settling into solid contact. To a 240 MHz MCU, a single button press looks like 50 distinct button pushes!

```
    Ideal Push:        HIGH ───────┐               ┌───────
                                   └───────────────┘ LOW

    Real Bounce:       HIGH ──┐ ┌─┐ ┌─┐ ┌─────────┐ ┌─┐ ───
                              └─┘ └─┘ └─┘         └─┘ └─┘ LOW
                              ▲ Bouncing (~10ms)  ▲ Releasing (~10ms)
```

### Mitigation Strategies
1. **Software Debounce**: In FreeRTOS, verify switch state after a non-blocking $20\text{ ms}$ delay (`vTaskDelay(pdMS_TO_TICKS(20))`).
2. **Hardware RC Filter**: $10\text{ k}\Omega$ resistor + $100\text{ nF}$ ceramic capacitor form a hardware low-pass filter ($\tau = R \times C = 1\text{ ms}$).

---

## 12. TRANSISTORS & MOSFETS (HIGH-CURRENT SWITCHING)

ESP32 pins provide digital logic signals ($< 40\text{ mA}$), not raw actuator muscle. To control motors, solenoids, relays, or high-power LED strips, use transistors as electronic switches.

```
                     +12V Load Supply
                            │
                       [Solenoid / Motor]
                            │
    ESP32 GPIO ────[1kΩ]───┤ NPN / N-Ch MOSFET (Drain/Collector)
                           │
                          GND (Source/Emitter)
```

* **NPN BJT (e.g. 2N2222, BC547)**: Current-controlled switch. Ideal for small loads up to $500\text{ mA}$.
* **Logic-Level N-Channel MOSFET (e.g. IRLZ44N, AO3400)**: Voltage-controlled switch. Requires a gate threshold ($V_{GS(th)}$) well below $3.3\text{ V}$. Handles $5\text{ A} \dots 30\text{ A}$ with negligible power loss.

---

## 13. DIODES & FLYBACK PROTECTION

Inductors (solenoids, relays, DC motor coils) store energy in magnetic fields ($E = \frac{1}{2} L I^2$). When current is cut abruptly by an off-switching transistor, the collapsing magnetic field induces a massive reverse high-voltage spike ($\mathbf{V = -L \frac{dI}{dt}}$), reaching hundreds of volts and instantly puncturing switching transistors.

```
                 +12V Rail
                    │
            ┌───────┴───────┐
            │               │
       ▲ ───┤ Coil / Motor  ├───► 
       │    │               │
  Flyback   └───────┬───────┘
   Diode            │
 (1N4007)           ├── Switch (MOSFET / Transistor)
                    │
                   GND
```

* **Flyback Diode Rule**: Connect a general-purpose silicon diode (1N4007, 1N4148, or Schottky SS34) in **reverse bias** directly across inductive terminals. The spike safely recirculates through the diode coil loop until dissipated.

---

## 14. GROUND (GND) — THE UNIVERSAL REFERENCE PLANE

* Voltage is never absolute — it is always a **differential potential measurement relative to a reference point**. That reference is **Ground ($0\text{ V}$)**.
* **Common Ground Rule**: When connecting an ESP32 to external sensors, power supplies, or motor drivers, **all GND lines must be physically bonded together**. If GND is not shared, floating return loops will corrupt UART/I2C/SPI signals or destroy GPIO buffers.

---

## 15. READING SCHEMATICS & CIRCUIT SYMBOLS

```
    Resistor          Capacitor (Non-pol)      Polarized Cap          Diode
      ──[   ]──              ──||──                 ──|(──             ──►|──
    or ──/\/\/──
    
      Switch               Ground                  MOSFET (N-Ch)        VCC Rail
       ──/ ──                ──┬──                  ──┬─►               ───┬───
                              ─┴─                     │                    │
```

---

## 16. BREADBOARD ARCHITECTURE & WIRING HYGIENE

* **Power Rails**: Horizontal top and bottom rows (+ and -).
* **Terminal Strips**: Vertical 5-pin columns connected internally. The center divider separates dual IC pinouts.
* **Prototyping Golden Rules**:
  * Keep wire jumpers flush against the board to prevent accidental dislodging.
  * Standardize colors: **Red = 3.3V / 5V**, **Black = GND**, **Blue/Yellow/Green = Signals**.
  * Never wire circuits with power applied. Power on only after double-checking polarity.

---

## 17. MULTIMETER MASTERY — YOUR PRIMARY DIAGNOSTIC TOOL

1. **Continuity Mode (Beeper)**: Verify direct solder connections and detect ground-to-VCC shorts before powering boards.
2. **DC Voltage Mode**: Check battery voltage, measure rail sag during Wi-Fi transmission, and verify divider outputs.
3. **Resistance Mode**: Verify resistor codes before soldering and measure sensor resistance changes (LDR / Thermistor).
4. **Current Mode (Amps)**: Must be connected in **series** (breaking the wire loop). Never place probes across a battery in current mode!

---

## 18. DAY 1 REVIEW CHECKLIST & HANDS-ON PROJECT

### Self-Assessment Checklist
- [ ] Memorized the Golden Rules of Series vs Parallel circuits.
- [ ] Confident in calculating total resistance, branch currents, and voltage drops.
- [ ] Mastered the mathematical derivation of 12-bit ADC output ($0 \dots 4095$).
- [ ] Know how to map raw ADC counts to physical voltage: `(raw / 4095.0) * 3.3`.
- [ ] Understand why $5\text{ V}$ input kills the ESP32 and how to use voltage dividers to read higher voltages safely.
- [ ] Can select proper current-limiting resistors for any color LED.
- [ ] Know why pull-up/pull-down resistors prevent floating CMOS inputs.
- [ ] Understand why decoupling capacitors prevent ESP32 Wi-Fi brownout resets.

---

### Hands-On Laboratory Project: Calibrated Voltage Telemetry & LED Indicator

#### Hardware Requirements
1. ESP32 DevKit board
2. 1x Red LED ($V_f \approx 2.0\text{ V}$)
3. 1x $220\,\Omega$ resistor (Series current-limiting)
4. 1x $10\text{ k}\Omega$ Potentiometer (Configured as an adjustable analog voltage divider)
5. Breadboard and jumper wires

#### Circuit Hookup
1. **LED Circuit (Series)**: Connect GPIO 2 $\to$ $220\,\Omega$ resistor $\to$ LED Anode $\to$ LED Cathode $\to$ GND.
2. **Potentiometer Circuit (Voltage Divider)**:
   * Pin 1 (Outer leg) $\to$ ESP32 $3\text{V}3$
   * Pin 2 (Wiper / Center) $\to$ ESP32 GPIO 34 (ADC1 Channel 6)
   * Pin 3 (Outer leg) $\to$ ESP32 GND

#### Test Firmware (ESP-IDF / Arduino)

```c
#include <Arduino.h>

const int POT_PIN = 34;   // ADC1 Channel 6
const int LED_PIN = 2;    // Status LED

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    
    // Configure ESP32 12-bit ADC full-scale (0 - 3.3V)
    analogReadResolution(12);
    analogSetAttenuation(ADC_11db);
    
    Serial.println("\n--- ESP32 Electronics Fundamentals Laboratory Active ---");
}

void loop() {
    int rawADC = analogRead(POT_PIN);
    
    // Accurate 12-bit voltage conversion
    float voltage = (rawADC / 4095.0f) * 3.3f;
    float percentage = (rawADC / 4095.0f) * 100.0f;
    
    // Threshold comparison: Turn LED ON when voltage exceeds 1.65V (midpoint)
    if (voltage >= 1.65f) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }
    
    Serial.printf("ADC Raw: %4d / 4095  |  Voltage: %.3f V  |  Level: %5.1f%%  |  LED: %s\n",
                  rawADC, voltage, percentage, (voltage >= 1.65f) ? "ACTIVE [ON]" : "IDLE [OFF]");
                  
    delay(250);
}
```

---

*Now you have the solid electronics foundation necessary to tackle hardware registers, FreeRTOS tasks, and low-level firmware without burning silicon!* ⚡
