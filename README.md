# Real-Time Fan Control System 🌀

A real-time system using an ESP32 microcontroller, gas sensor (MQ135), and a fan for automated ventilation control based on gas concentration.

## Table of Contents 📋

- [🔍 Introduction](#introduction)
- [✨ Features](#features)
- [🔧 Hardware Requirements](#hardware-requirements)
- [⚙️ Setup](#setup)
- [📡 Usage](#usage)
- [🎛️ Customization](#customization)
- [⚠️ Troubleshooting](#troubleshooting)
- [📜 License](#license)

## Introduction 🔍

This project implements a real-time system to control a fan based on the gas concentration measured by an MQ135 sensor. The system utilizes an ESP32 microcontroller for processing and fan control.

## Features ✨

- Real-time gas concentration monitoring.
- Automatic fan control based on a configurable gas concentration threshold.
- Non-blocking fan spin duration for improved responsiveness.

## Hardware Requirements 🔧

- ESP32 development board.
- MQ135 gas sensor.
- DC fan (5V).
- Power supply.
- IRFZ44N transistor.
- Connecting wires, breadboard, resistors, etc.

## Setup ⚙️

1. **Connect Hardware:**
   - Connect the ESP32, MQ135 sensor, and the fan according to the hardware setup guidelines.

2. **Install Dependencies:**
   - Ensure that the required libraries for the ESP32 and MQ135 sensor are installed in your Arduino IDE.

3. **Upload Code:**
   - Upload the provided Arduino sketch to your ESP32.

## Usage 📡

- Power up the system.
- The fan will automatically turn on when the gas concentration exceeds the predefined threshold.
- The fan will turn off after the specified fan spin duration and if the gas concentration gets low.

**Watch a Demo Video:** [![Watch Demo](link_to_thumbnail_image)](https://www.youtube.com/shorts/qn2XoabOsRc)

## Customization 🎛️

- Adjust the gas concentration threshold and fan spin duration in the Arduino sketch based on your requirements.

## Troubleshooting 🔍

- **Fan Not Turning On:**
  - Check the gas sensor readings using the Serial Monitor to ensure it detects gas above the threshold.
  - Verify the connections between the ESP32, MQ135, and the fan.

## License 📜

This project is licensed under the [MIT License](LICENSE).
