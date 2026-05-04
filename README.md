<div align="center">

```
                     ╔═══════════════════════════════════════════════════════════════╗
                     ║                                                               ║
                     ║           ██████╗ ██████╗  ██████╗ ████████╗███████╗          ║
                     ║          ██╔═══██╗██╔══██╗██╔═══██╗╚══██╔══╝╚══███╔╝          ║
                     ║          ██║   ██║██████╔╝██║   ██║   ██║     ███╔╝           ║
                     ║          ██║   ██║██╔══██╗██║   ██║   ██║    ███╔╝            ║
                     ║          ╚██████╔╝██████╔╝╚██████╔╝   ██║   ███████╗          ║
                     ║           ╚═════╝ ╚═════╝  ╚═════╝    ╚═╝   ╚══════╝          ║
                     ║                                                               ║
                     ║              [ Embedded C · Robotics · Programs ]             ║
                     ╚═══════════════════════════════════════════════════════════════╝
```

<img src="https://img.shields.io/badge/Language-Embedded%20C-blue?style=for-the-badge&logo=c&logoColor=white"/>
<img src="https://img.shields.io/badge/Platform-AVR%20Microcontroller-red?style=for-the-badge&logo=arduino&logoColor=white"/>
<img src="https://img.shields.io/badge/Program-OBotz%20Levels%205%2C%206%2C%20%26%207-orange?style=for-the-badge"/>
<img src="https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge"/>

---

*A collection of Embedded C programs written during the OBotz Robotics Program — covering microcontroller programming, sensor integration, motor control, and autonomous robot systems.*

</div>

---

## 🤖 About This Repository

This repo contains all programs, reference guides, and notes written during the **OBotz Robotics Program** — a 7-level STEM curriculum focused on teaching robotics through hands-on experimentation and real-world embedded systems programming.

Levels 5, 6, and 7 of the program dive deep into **Embedded C** on AVR microcontroller boards (Uniko Dvi, Uniko Trini, and Uniko Chatur), moving from autonomous robot logic all the way to full embedded system applications like robotic arms, AC systems, and electronic lock systems.

---

## 📋 Table of Contents

- [Program Overview](#-program-overview)
- [Concepts Covered](#-concepts-covered)
- [Key Functions](#-key-functions)
- [Hardware & Components](#-hardware--components)
- [About OBotz](#-about-obotz)

---

## 🎯 Program Overview

| Level | Focus | Microcontroller |
|-------|-------|-------|
| **Level 5** | Autonomous Robots using Embedded C   | ATMega 32  |
| **Level 6** | Embedded Systems & Industrial Robots | ATMega 324 |
| **Level 7** | Embedded Systems & Humanoid Robots   | ATMega 328 |

The programs in this repository span both levels, with increasing complexity — from basic register manipulation and ADC conversions to full ISR interrupt-driven control systems for servo arms, stepper motors, and wireless Bluetooth communication.

---

## 🧠 Concepts Covered

### Core Embedded C Concepts

```
┌─────────────────────────────────────────────────────────────┐
│  Registers & Macros        │  DDRx, PORTx, PINx, ADMUX      │
│  Bit Masking               │  setbit(), clearbit(), bitn()  │
│  ADC Conversions           │  Analog-to-Digital (10-bit)    │
│  Timers & PWM              │  TIMER0, TIMER1, Duty Cycle    │
│  ISR Interrupts            │  Timer Overflow & Compare      │
│  External Interrupts       │  INT2_vect trigger handling    │
│  Initialization Params     │  ADMUX, ADCSRA, TCCR config    │
└─────────────────────────────────────────────────────────────┘
```

### Communication & Protocols

- **USART / Serial Communication** — TX/RX pins, baud rate configuration, UDR/UCSRA/UCSRB/UCSRC registers
- **Bluetooth (HC-05)** — Data Mode vs AT Command Mode, pairing, UBRR baud rate calculation
- **IR Remote Decoding** — 32-bit keycode reading via ISR and timer counting

### Number Systems

- Binary (Base 2) ↔ Hexadecimal (Base 16) conversions
- 8-bit register manipulation (`0b00010010`, `0x12`)
- Thermistor Steinhart-Hart equation for temperature conversion

---

## ⚙️ Key Functions

### IR Remote Reader
Reads 32-bit keycodes from an IR remote using a dual-ISR approach — one ISR increments a timer, the other captures pulse widths and decodes bit values.
```c
ISR(TIMER0_OVF_vect) { x++; TCNT0 = 125; }
ISR(INT2_vect)       { /* Decode 32-bit keycode from pulse timing */ }
```

### Servo Motor Control (up to 3 motors)
Uses `TIMER1_COMPA_vect` ISR to generate precise PWM signals for up to 3 independent servo motors on PORTB pins 5, 6, and 7.
```c
void angle1(int a) { count_angle1 = a + 46; }  // Motor 1
void angle2(int b) { count_angle2 = b + 46; }  // Motor 2
void angle3(int c) { count_angle3 = c + 46; }  // Motor 3
```

### Stepper Motor Control
Implements clockwise and anti-clockwise rotation through sequential 4-phase bit patterns on PORTD.
```c
void clkstepper()   { /* PORTD = 0b01110000 → 10110000 → 11010000 → 11100000 */ }
void antistepper()  { /* Reverse sequence for opposite direction */ }
```

---

## 🔧 Hardware & Components

| Component | Description |
|-----------|-------------|
| **Uniko Dvi** | AVR-based microcontroller board (Level 5) |
| **Uniko Trini** | Modular board with plug-n-play peripherals (Level 6) |
| **Uniko Chatur** | AVR-based microcontroller board (Level 7) |
| **Servo Motors** | Angle-controlled via PWM (1–3 motors) |
| **Stepper Motors** | Step-direction control via PORTD |
| **IR Remote + TSOP** | 32-bit NEC protocol decoding |
| **HC-05 Bluetooth** | Wireless serial at 9600 bps |
| **Thermistor** | Temperature via Steinhart-Hart formula |
| **7-Segment Display (SSD)** | Binary-coded digit display |
| **Dot Matrix (5×5)** | Row/column binary LED grid |
| **Joystick** | Analog XY input via ADC |
| **Keypad** | 4×4 matrix, analog value detection |

---

## 📡 Reference Values

### Thermistor Formula
```c
float c1 = 0.001125307752122;
float c2 = 0.000234711863267;
float c3 = 0.000000085663516;

R2  = (100000 / (1023 - ADCW)) * ADCW;
T   = 1.0 / (c1 + c2*log(R2) + c3*pow(log(R2), 3));
Tc  = T - 273.15;   // Temperature in °C
```

### USART Baud Rate Formula
```c
UBRR = (F_CPU / (16 × Baud Rate)) - 1
     = (16,000,000 / (16 × 9600)) - 1
     = 103  →  0x67
```

### SSD Binary Values (0–9)
```c
int number[] = {
  0b11110110, 0b01100000, 0b11010101, 0b11110001, 0b01100011,
  0b10110011, 0b10110111, 0b11100000, 0b11110111, 0b11110011
};
```

### Dot Matrix (5×5 LED Grid)
```c
// Column Values: 0b00010000, 0b00001000, 0b00000100, 0b00000010, 0b00000001
// Row Values:    0b11101111, 0b11110111, 0b11111011, 0b11111101, 0b11111110
```

---

## 🏫 About OBotz

**OBotz** is a multi-disciplinary STEM robotics program designed to take students from zero to advanced embedded systems programming across 7 progressive levels. The curriculum balances electronics, mechanics, and software — building real problem-solving and engineering skills through hands-on project work.

> *"We cannot always build the future for our youth, but we can build our youth for the future."*

🌐 [obotz.com](https://obotz.com) &nbsp;|&nbsp; 🇨🇦  [obotz.ca](https://obotz.ca)

---

<div align="center">

Made by **Abhinav Bathala** &nbsp;·&nbsp; OBotz Levels 5, 6, & 7

</div>
