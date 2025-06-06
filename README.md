# Arduino: blink-kai

This is an enhanced version of the official Arduino `Blink` sample, supporting a wide range of Arduino-compatible boards and MCUs.

## Features

- Supports various Arduino-compatible development boards and MCUs.
- Automatically detects the type of development board.
- Supports boards without built-in LEDs by allowing users to specify an external LED pin.

## Getting Started

### Prerequisites

- [Arduino CLI](https://arduino.github.io/arduino-cli/)
- Make

### Installation

Install required cores and libraries:

```bash
make install
```

### Build

Build for a specific board:

```bash
make build/uno
make build/rpipico
make build/esp32c3-supermini
```

Build for all supported boards:

```bash
make build/all
```

### Deploy

Upload to your board:

```bash
make deploy/uno
make deploy/rpipico
```

Available targets correspond to the supported boards listed above. Use the board name in lowercase with hyphens (e.g., `unor4-wifi`, `rp2040-zero`).

### Clean

Remove build artifacts:

```bash
make clean
```

## Supported Boards and MCUs

### ATmega

- Arduino UNO
- Arduino Nano
- Arduino Pro Mini
- Arduino Leonardo
- SparkFun Pro Micro

### ATtiny

- ATtiny85
- ATtiny13

### LGT8F328P

- LGT8F328P UNO
- LGT8F328P Nano

### RA4M1

- Arduino UNO R4 Minima
- Arduino UNO R4 WiFi

### RP2040

- Raspberry Pi Pico
- Waveshare RP2040-Zero
- SparkFun Pro Micro RP2040

### ESP32

- ESP32-C3 Super Mini
- Seeed XIAO ESP32C3
- Seeed XIAO ESP32C6

### CH32V

- UIAPduino Pro Micro CH32V003
- CH32V003
