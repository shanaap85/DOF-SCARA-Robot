# 🔩 Hardware Components

This document lists all the hardware components used in the **4-DOF SCARA Robot** project.

| Component | Specification | Quantity | Purpose |
|-----------|---------------|:--------:|---------|
| Arduino Uno | ATmega328P | 1 | Main microcontroller |
| NEMA 23 Stepper Motor | 2.8A, 1.8° Step Angle | 1 | Base rotation |
| TB6600 Stepper Driver | 9–42V | 1 | Stepper motor driver |
| PCA9685 Servo Driver | 16-Channel, I2C | 1 | Controls servo motors |
| MG996R Servo Motor | Metal Gear | 1 | Joint-2 (Elbow) |
| MG90S Servo Motor | Metal Gear | 1 | Z-axis / Pen Lift |
| MG90 Micro Servo | 9g | 1 | End Effector |
| Lead Screw | T8 × 200 mm | 1 | Vertical motion |
| Lead Screw Nut | Brass | 1 | Z-axis movement |
| Linear Rod | 8 mm × 220 mm | 2 | Vertical guide |
| LM8UU Linear Bearing | 8 mm | 4 | Smooth linear motion |
| 608ZZ Bearing | 8 × 22 × 7 mm | 4 | Rotational support |
| 625ZZ Bearing | 5 × 16 × 5 mm | 2 | Shaft support |
| Flexible Coupler | 6.35 mm × 8 mm | 1 | Connects stepper to lead screw |
| DC-DC Buck Converter | 24V → 6V, 5A | 1 | Servo power supply |
| SMPS Power Supply | 24V, 6A | 1 | Main power source |
| Forex Sheet | 5 mm | As Required | Robot frame |
| Connecting Wires | Jumper Wires | Multiple | Electrical connections |

---

## 🔌 Control System

- Arduino Uno
- PCA9685 Servo Driver
- TB6600 Stepper Driver

---

## ⚙️ Actuators

- 1 × NEMA 23 Stepper Motor
- 1 × MG996R Servo Motor
- 1 × MG90S Servo Motor
- 1 × MG90 Micro Servo

---

## 🔋 Power System

- 24V 6A Power Supply
- 24V → 6V DC-DC Buck Converter

---

## 🏗️ Mechanical Components

- Lead Screw
- Linear Rods
- Bearings
- Couplers
- Forex Sheet Structure

---

## 📌 Notes

- The robot uses a combination of **servo motors** and a **stepper motor** to achieve four degrees of freedom.
- The **PCA9685 Servo Driver** controls all servo motors via the I²C interface.
- The **TB6600 Stepper Driver** provides precise control of the NEMA 23 stepper motor for base rotation.
- A **lead screw mechanism** is used for accurate vertical (Z-axis) motion.
