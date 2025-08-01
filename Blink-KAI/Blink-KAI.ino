// Blink-KAI

#include <Arduino.h>

// #undef LED_BUILTIN
#define LED_PIN LED_BUILTIN
// #define LED_PIN 3
// #define LED_PIN 30 // Pro Micro TX
// #define LED_PIN 17 // Pro Micro RP2040
// #define LED_PIN 8 // ESP32-C3 SuperMini
// #define LED_PIN 1 // Digispark Model A
// #define LED_PIN PIN_PB3 // ATtiny85
// #define LED_PIN PIN_PB3 // ATtiny13
// #define LED_PIN PC1 // CH32V003


#define LED_ON HIGH
#define LED_OFF LOW
// #define LED_ON LOW // Pro Micro TX
// #define LED_OFF HIGH // Pro Micro TX

// #define LED_WAIT 100
#define LED_WAIT 200
// #define LED_WAIT 1000
// #define LED_WAIT 2000

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, LED_ON);
  delay(LED_WAIT);
  digitalWrite(LED_PIN, LED_OFF);
  delay(LED_WAIT);
}
