#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <ESPping.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
// Notice we use 0x3C here because that's what your scanner found!
#define SCREEN_ADDRESS 0x3C 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const char* ssid = "Harsha_m35";
const char* password = "Harsha124";

void setup() {
  Serial.begin(115200);
  
  // Start OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) { 
    for(;;); // Don't proceed if screen fails
  }
  
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(20, 20);
  display.println("Connecting...");
  display.display();

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  display.clearDisplay();
  display.setCursor(20, 20);
  display.println("WiFi Connected!");
  display.display();
  delay(1500);
}

void loop() {
  display.clearDisplay();
  
  // Header
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("NETWORK MONITOR");
  display.drawLine(0, 10, 128, 10, WHITE);
  
  // Perform the Ping (To Google DNS)
  bool success = Ping.ping("155.133.233.98", 3);
  
  if(success) {
    int avg_time = Ping.averageTime();
    
    // Display Latency
    display.setTextSize(1);
    display.setCursor(0, 25);
    display.print("Target: Google");
    
    display.setTextSize(2);
    display.setCursor(0, 40);
    display.print(avg_time);
    display.print(" ms");
  } else {
    display.setCursor(0, 35);
    display.setTextSize(1);
    display.println("Connection Lost!");
  }
  
  display.display();
  delay(2000); // Wait 2 seconds before next ping
}