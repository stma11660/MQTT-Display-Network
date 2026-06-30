<img width="627" height="627" alt="AI_Logo" src="https://github.com/user-attachments/assets/c0cd5391-42e5-4afc-bd62-3a2b3693bc7e" />

# MQTT Display Network

> A scalable MQTT based display network using one ESP8266/ESP32 gateway and multiple Arduino Nano display nodes.

---

Project initiated by Stephan.

Architecture and technical design developed together
with ChatGPT (OpenAI).

Everyone is welcome to contribute.


# 🇬🇧 English

## Why this project came about
MQTT Display Network was developed to display sensor data from an MQTT network easily and reliably on multiple small TFT displays. A single ESP8266 or ESP32 acts as a gateway and distributes the data via an I²C bus to any number of Arduino Nano display nodes. The goal is to provide an easy-to-understand, scalable, and resource-efficient open-source solution for Home Assistant, OpenHAB, Node-RED, and other MQTT-based systems.

## Overview

MQTT Display Network is a distributed display system.


One ESP8266 or ESP32 acts as a gateway between

```
MQTT Broker
        │
        ▼
 ESP8266 / ESP32
        │
      I²C Bus
        │
 ┌──────┼──────┬────────┐
 │      │      │
Nano1 Nano2 Nano3 ...
 │      │      │
ST7735 ST7735 ST7735
```

Each Arduino Nano only drives one display.

The gateway receives MQTT messages, converts the payload into compact binary packets and forwards them via I²C.

---

## Features

- ESP8266 and ESP32 support
- Arduino Nano display nodes
- MQTT communication
- I²C communication
- CRC protected packets
- Low memory footprint
- Easy expansion
- Open Source

---

## Hardware

### Gateway

- ESP8266 or ESP32
- Level shifter (BSS138)
- MQTT Broker

### Display Node

- Arduino Nano
- ST7735 TFT
- I²C connection

---

## Repository Structure

```
docs/
firmware/
shared/
examples/
```

---

## Current Status

Current development branch:

```
develop-v2
```

Status:

- Repository layout ✔
- Shared protocol ✔
- ESP Gateway 🚧
- Nano Firmware 🚧
- Documentation 🚧

---

## Roadmap

### Version 2.0

- ESP8266 support
- ESP32 support
- Arduino Nano support
- MQTT Gateway
- I²C Display Network
- CRC16

### Version 2.1

- OTA Update
- Web Configuration
- Logging

### Version 3.0

- RP2040 Support
- ESP32-S3
- LVGL Display Support

---

## License

MIT License

---

# 🇩🇪 Deutsch

## Warum dieses Projekt entstanden ist

MQTT Display Network wurde entwickelt, um Sensordaten aus einem MQTT-Netzwerk einfach und zuverlässig auf mehreren kleinen TFT-Displays darzustellen. Ein einzelner ESP8266 oder ESP32 fungiert als Gateway und verteilt die Daten über einen I²C-Bus an beliebig viele Arduino-Nano-Displayknoten. Das Ziel ist eine leicht verständliche, erweiterbare und ressourcenschonende Open-Source-Lösung für Home Assistant, OpenHAB, Node-RED und andere MQTT-basierte Systeme.

## Übersicht

MQTT Display Network ist ein verteiltes Displaysystem.

Ein ESP8266 oder ESP32 dient als Gateway zwischen einem MQTT-Broker und mehreren Arduino Nano Displayknoten.

Die Kommunikation erfolgt über einen gemeinsamen I²C-Bus.

Jeder Nano steuert genau ein ST7735 Display.

---

## Eigenschaften

- ESP8266 und ESP32
- Arduino Nano Displayknoten
- MQTT Kommunikation
- I²C Kommunikation
- CRC16 Prüfsumme
- geringer Speicherbedarf
- beliebig erweiterbar
- Open Source

---

## Hardware

### Gateway

- ESP8266 oder ESP32
- Pegelwandler (BSS138)
- MQTT Broker

### Display Node

- Arduino Nano
- ST7735 TFT
- I²C Anschluss

---

## Projektstruktur

```
docs/
firmware/
shared/
examples/
```

---

## Entwicklungsstand

Aktueller Entwicklungszweig:

```
develop-v2
```

Status

- Repositorystruktur ✔
- Gemeinsames Protokoll ✔
- ESP Gateway 🚧
- Nano Firmware 🚧
- Dokumentation 🚧

---

## Roadmap

### Version 2.0

- ESP8266
- ESP32
- Arduino Nano
- MQTT Gateway
- I²C Displaynetz
- CRC16

### Version 2.1

- OTA
- Webkonfiguration
- Logging

### Version 3.0

- RP2040
- ESP32-S3
- LVGL

---

## Mitmachen

Pull Requests, Verbesserungsvorschläge und Fehlermeldungen sind jederzeit willkommen.

---

© 2026 MQTT Display Network Project
