# ESP32 Real-Time Network Latency Monitor

An embedded firmware solution designed for the ESP32 microcontroller to continuously monitor network stability and ping latency utilizing public DNS servers. 

## Features
* **Real-time Latency Tracking:** Measures ping response times from Google and Cloudflare DNS over Wi-Fi.
* **I2C Display Integration:** Renders live performance metrics on a 0.96" SSD1306 OLED display.
* **Fault Handling:** Features connection-drop indicators to alert users of network loss.

## Hardware Components
* ESP32 Development Board
* 0.96" I2C OLED Display (SSD1306)
* Jumper Wires & Breadboard

## Circuit & Pin Configuration
* **VCC** -> 3.3V
* **GND** -> GND
* **SDA** -> GPIO 21 (ESP32)
* **SCL** -> GPIO 22 (ESP32)

## How to Run
1. Open the `.ino` file in the Arduino IDE.
2. Install the `Adafruit SSD1306` and `ESP32 Ping` libraries.
3. Update the Wi-Fi credentials in the code.
4. Upload to your ESP32 board.
