// Blink-KAI

#include <Arduino.h>

// #undef LED_BUILTIN
#define LED_PIN LED_BUILTIN
// #define LED_PIN 17 // Pro Micro RP2040
// #define LED_PIN 30 // Pro Micro TX
// #define LED_PIN 1 // Digispark Model A
// #define LED_PIN 1 // ATtinyX5
// #define LED_PIN 1 // ATtiny13
// #define LED_PIN 8 // ESP32-C3 SuperMini
// #define LED_PIN PC1 // CH32V003

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  blink(100, 3);
  delay(200);
  blink(300, 3);
  delay(200);
}

void blink(unsigned long duration, size_t count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(duration);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
}
