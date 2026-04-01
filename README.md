# 💡 8x8x8 LED Matrix Cube

A 3D LED display consisting of **512 LEDs (8×8×8)** capable of creating stunning light animations and visual effects using multiplexing and microcontroller control.

---

## 🚀 Features
- ✨ 3D light animations and patterns  
- ⚡ Multiplexing-based control  
- 🔄 Custom programmable effects  
- 🧠 Great for learning embedded systems  

---

## 🧰 Components

| Component | Quantity | Specification | Purpose |
|---|---|---|---|
| Green LEDs | 512 | 5mm, 20mA | Core display elements |
| Arduino UNO / Nano / STM32 | 1 | ATmega328P / ARM Cortex | Microcontroller |
| Transistors (BC547 / 2N2222) | 16 | NPN, 45V, 800mA | Layer switching |
| Resistors | 64 | 220Ω–470Ω, 1/4W | Current limiting for LEDs |
| Shift Registers (74HC595) | 9 | 8-bit serial-in, parallel-out | Column control |
| Power Supply | 1 | 5V, 2A+(USB) & 12v,1A(External adapter) | USB or External adapter |
| PCB / Breadboard | 1 | — | Circuit assembly |
| Jumper Wires | As needed | — | Connections |

---

## ⚙️ Working Principle
The cube uses **multiplexing**, where each layer of LEDs is turned on and off rapidly.  
A microcontroller controls rows, columns, and layers to create the illusion of a fully lit 3D display.

---

## 🔌 Circuit Overview
- LEDs are arranged in 8 layers  
- Each layer is controlled using transistors  
- Shift registers handle column control  
- Microcontroller sends signals to manage animations  

---

## 📜 License

This project is licensed under the MIT License.

---
