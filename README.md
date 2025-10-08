# 📡 M66 Dev Board Firmware

## 📖 Overview

Firmware for a Quectel M66-based development board designed for IoT and embedded applications with rich sensor and connectivity options.

This codebase demonstrates a multi-tasking architecture using the M66 SDK, integrating sensors, OLED display, storage, and SIM management.

---

## 🛠 Hardware Features

- 📶 Quectel M66 GSM/GPRS module  
- 🔋 Battery management with charging circuitry  
- 🖥 0.96" OLED display via I²C  
- 🛰 9-axis MEMS accelerometer/gyroscope (ICM series)  
- 🌡 Temperature & humidity sensor (SHT series)  
- 💡 Ambient light sensor  
- 💾 SPI Flash storage  
- 💽 microSD card slot  
- 📲 Dual SIM card support  
- ⚡ Pin headers for expansion  

---

## 💡 Firmware Features

- 🧵 Multi-task design:
  - Sensor reading tasks (accelerometer, gyroscope, temperature, humidity, light)
  - OLED UI task with paging
  - SIM status handling
  - SPI Flash management

- 🔢 Pure-integer GNSS RMC parser (optional if GNSS module is added externally)  
- ⏱ Semaphore-driven synchronization between producer tasks and OLED consumer  
- 🖋 Optimized OLED updates to avoid flicker using fixed-width field formatting  

---

## 🖥 Development Environment

- **Toolchain**: M66 SDK (GCC for ARM under MS-DOS environment)  
- **Build commands** (run in project root):

  ```bash
  make clean
  make new
