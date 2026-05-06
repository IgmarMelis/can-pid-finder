# 🚗 CAN PID Formula Finder

**Arduino-based CAN Bus reverse engineering tool to extract vehicle PIDs (RPM, Temperature, Speed, etc.)**

[![Support me on Ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/pss)

---

## 📋 Overview

This project helps you reverse engineer CAN Bus data from vehicles to find the correct formulas for:
- ✅ RPM (Revolutions Per Minute)
- ✅ Coolant Temperature
- ✅ Vehicle Speed
- ✅ Battery Voltage
- ✅ MIL (Malfunction Indicator Light) Status
- ✅ Oil Temperature / Other sensors

## 🔧 What's Included

1. **Arduino Sketch** (`can_debugger.ino`)
   - Reads raw CAN frames via MCP2515 module
   - Outputs data in serial format (115200 baud)
   - Compatible with 500kbps CAN Bus (standard for OBD2)

2. **Web Application** (`can_pid_finder_webapp.html`)
   - Browser-based CAN data analyzer
   - Real-time formula testing
   - Live value locking
   - No internet required (works offline)

## 📦 Requirements

### Hardware:
- Arduino Uno/Nano
- MCP2515 CAN Bus Module (8MHz crystal)
- Jumper wires
- Vehicle with OBD2 port or Can wires in the Instrument cluster connector.

### Software:
- Arduino IDE (for uploading sketch)
- Modern web browser (Chrome, Firefox, Edge)

## 🚀 Quick Start

### 1. Hardware Setup

#### MCP2515 to Arduino Connections:

| MCP2515 Pin | Arduino Pin | Description |
|-------------|-------------|-------------|
| **VCC** | **5V** | Power supply |
| **GND** | **GND** | Ground |
| **CS** | **D10** | Chip Select |
| **SO** | **D12** | MISO (SPI) |
| **SI** | **D11** | MOSI (SPI) |
| **SCK** | **D13** | Clock (SPI) |
| **INT** | **D2** | Interrupt (optional) |

#### Wiring Diagram:
