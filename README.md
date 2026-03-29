# 💡 8x8x8 LED Matrix Cube

A 3D LED display consisting of **512 LEDs (8×8×8)** capable of creating stunning light animations and visual effects using multiplexing and microcontroller control.

---

## 🚀 Features
- ✨ 3D light animations and patterns  
- ⚡ Multiplexing-based control  
- 🔄 Custom programmable effects  
- 🧠 Great for learning embedded systems  

---

## 🛠️ Components Used
- Microcontroller (Arduino Uno / ESP32)  
- 512 LEDs  
- Shift Registers (74HC595)  
- Transistors (for layer control)  
- Resistors  
- Power Supply  

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
