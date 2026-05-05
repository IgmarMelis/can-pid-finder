# 🚗 CAN PID Formula Finder

**Arduino-based CAN Bus reverse engineering tool to extract vehicle PIDs (RPM, Temperature, Speed, etc.)**

[![ko-fi](https://ko-fi.com/img/githubbutton-sm.svg)](https://ko-fi.com/pss)

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
- Vehicle with OBD2 port

### Software:
- Arduino IDE (for uploading sketch)
- Modern web browser (Chrome, Firefox, Edge)

## 🚀 Quick Start

### 1. Hardware Setup
