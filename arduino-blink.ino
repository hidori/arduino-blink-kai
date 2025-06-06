#include <Arduino.h>

#define LED_PIN LED_BUILTIN
// #define LED_PIN 30  // Arduino Pro Micro
// #define LED_PIN 1  // Digispark
// #define LED_PIN 8  // Seeed XIAO ESP32C3
// #define LED_PIN 2  // UIAPduino Pro Micro CH32V003
// #define LED_PIN PC1 // CH32V003
// #define LED_PIN 17  // ProMicro RP2040
// #define LED_PIN 1

#define LED_ON HIGH
#define LED_OFF LOW
// #define LED_ON LOW
// #define LED_OFF HIGH

#define LED_DURATION1 100
#define LED_DURATION2 500
#define LED_WAIT 500

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LED_OFF);
}

void loop() {
  digitalWrite(LED_PIN, LED_ON);
  delay(LED_DURATION1);
  digitalWrite(LED_PIN, LED_OFF);
  delay(LED_WAIT);

  digitalWrite(LED_PIN, LED_ON);
  delay(LED_DURATION2);
  digitalWrite(LED_PIN, LED_OFF);
  delay(LED_WAIT);
}
