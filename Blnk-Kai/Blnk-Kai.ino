// Blink-Kai

#include <Arduino.h>

// #undef LED_BUILTIN
#if defined(LED_BUILTIN)
#define LED_PIN LED_BUILTIN
#else
// #define LED_PIN 3
// #define LED_PIN 30 // Pro Micro TX
// #define LED_PIN A3 // Pro Micro with 5P probe
// #define LED_PIN PB1 // Digispark
// #define LED_PIN 17 // Pro Micro RP2040
// #define LED_PIN 8 // ESP32-C3 SuperMini/ESP33-C3 OLED SuperMini
// #define LED_PIN PD4 // nanoCH32V003 on Bread Board
#endif

#define LED_ON HIGH
#define LED_OFF LOW
// #define LED_ON LOW
// #define LED_OFF HIGH

#if !defined(LED_WAIT)
#define LED_WAIT 100
// #define LED_WAIT 200
#define LED_WAIT 1000
// #define LED_WAIT 3000
#endif

void setup()
{
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_PIN, LED_ON);
  delay(LED_WAIT);
  digitalWrite(LED_PIN, LED_OFF);
  delay(LED_WAIT);
}
