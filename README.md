# ESP32-S3 Onboard LEDs & RGB Blinking (PlatformIO)

This repository provides **PlatformIO-based examples** for controlling **ESP32-S3 onboard LEDs**, including:

* TX & RX indicator LEDs
* Built-in RGB (NeoPixel / WS2812) LED

It also highlights an important **hardware solder-jumper requirement** needed on some ESP32-S3 boards for the RGB LED to function correctly.

---

## 📌 Hardware Used

* ESP32-S3 development board (with onboard TX, RX LEDs and RGB NeoPixel)

⚠️ **Note:** Pin numbers may vary slightly depending on the ESP32-S3 board variant. Always verify using your board schematic.

---

## 🧠 Concept Overview

### TX & RX LEDs

* **TX LED → GPIO43**
* **RX LED → GPIO44**
* These pins are normally used for **UART communication**
* If UART is not initialized (for example, `Serial` is not used), these pins can be configured as **normal GPIO outputs**

### RGB LED (NeoPixel)

* Built-in RGB LED is connected to **GPIO48**
* LED type: **WS2812 / NeoPixel**
* Controlled using the **Adafruit NeoPixel** library

---

## 🟢 Example 1: TX & RX LED Blinking

### Description

This example alternately blinks the **TX and RX onboard LEDs** using GPIO pins.

### Important Notes

* Do **NOT** initialize UART (`Serial`)
* If UART is active, the LEDs may flicker due to serial activity

### Framework

* Arduino framework under **PlatformIO**

---

## 🔵 Example 2: Onboard RGB LED Blinking (PlatformIO)

### Description

This example demonstrates blinking the **onboard RGB (NeoPixel / WS2812) LED** using PlatformIO.

The RGB LED is controlled via **GPIO48**. On some ESP32-S3 boards, the RGB data line is **not connected by default** and requires a solder bridge.

---

### ⚠️ Important Hardware Note (Very Important)

On certain ESP32-S3 boards, the RGB LED **DATA pin is disconnected by default**.

Near the RGB LED, you will find two small pads marked similar to **"RGB"**.

➡️ These pads **must be solder-bridged (connected)** to link the RGB LED data line to GPIO48.

If these pads are **not connected**:

* The RGB LED will **NOT blink**
* Code will upload successfully, but the LED will remain **OFF**

---

### 📷 Reference Image (Solder Jumper)

uploaded 

*(The image shows the RGB LED and the solder jumper pads that must be connected.)*

---

## 📦 Required Library (PlatformIO)

Add the following to your `platformio.ini` file:

```ini
lib_deps =
  adafruit/Adafruit NeoPixel
```

---

## 🧪 Troubleshooting

If the RGB LED does not blink:

* ✔️ Confirm the solder jumper near "RGB" is properly connected
* ✔️ Ensure **GPIO48** is correct for your board
* ✔️ Verify the correct board is selected in PlatformIO
* ✔️ Confirm the board is powered ON

If TX/RX LEDs do not blink:

* ✔️ Ensure UART (`Serial`) is not initialized
* ✔️ Verify GPIO43 and GPIO44 pin assignments

---

## 🧪 Testing Notes

* Upload **only one example at a time**
* Reboot the board after flashing if behavior is unexpected


---

## 🎯 Learning Outcomes

* Understanding ESP32-S3 onboard LEDs
* Using UART pins as GPIO
* Controlling NeoPixel RGB LEDs
* Identifying and resolving hardware jumper issues
* Working with PlatformIO framework

---

## 📜 License

This project is open-source and free to use for learning and experimentation.
