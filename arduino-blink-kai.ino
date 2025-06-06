// Blink-KAI

#include <Arduino.h>

#if !defined(USE_LED)
// Arduino UNO R3, Nano, Pro or Pro Mini
#  if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_NANO) || defined(ARDUINO_AVR_PRO)
#    define USE_LED
#    define LED_PIN LED_BUILTIN
// Arduino Leonardo
#  elif defined(ARDUINO_AVR_LEONARDO)
#    define USE_LED
#    define LED_PIN LED_BUILTIN
// Arduino Pro Micro
#  elif defined(ARDUINO_AVR_PROMICRO)
#    define USE_LED
#    define LED_PIN 30  // has built-in LED, use pin 30 instead of TX LED
// ATtiny25/45/85
#  elif defined(ARDUINO_AVR_ATTINYX5)
#    define USE_LED
#    define LED_PIN 1  // has no built-in LED
// ATtiny13
#  elif defined(ARDUINO_attiny) && (defined(__AVR_ATtiny13__) || defined(__AVR_ATtiny13A__))
#    define USE_LED
#    define LED_PIN 1  // has no built-in LED
// Arduino UNO R4 Minima or WiFi
#  elif defined(ARDUINO_UNOR4_MINIMA) || defined(ARDUINO_UNOR4_WIFI)
#    define USE_LED
#    define LED_PIN LED_BUILTIN
// LGT8F328P
#  elif defined(ARDUINO_AVR_LARDU_328E)
#    define USE_LED
#    define LED_PIN LED_BUILTIN
// Raspberry Pi Pico
#  elif defined(ARDUINO_RASPBERRY_PI_PICO)
#    define USE_LED
#    define LED_PIN LED_BUILTIN
// Waveshare RP2040 Zero
#  elif defined(ARDUINO_WAVESHARE_RP2040_ZERO)
// has no built-in LED, but has NeoPixel
// SparkFun Pro Micro RP2040
#  elif defined(ARDUINO_SPARKFUN_PROMICRO_RP2040)
#    define USE_LED
#    define LED_PIN LED_BUILTIN
// ESP32-C3 SuperMini
#  elif defined(ARDUINO_NOLOGO_ESP32C3_SUPER_MINI)
#    define USE_LED
#    define LED_PIN LED_BUILTIN
// Seeed XIAO ESP32C3
#  elif defined(ARDUINO_XIAO_ESP32C3)
#    define USE_LED
#    define LED_PIN 8  // has no built-in LED
// Seeed XIAO ESP32C6
#  elif defined(ARDUINO_XIAO_ESP32C6)
#    define USE_LED
#    define LED_PIN LED_BUILTIN
// UIAPduino Pro Micro CH32V003
#  elif defined(ARDUINO_ARCH_CH32) && defined(CH32V003F4)
#    define USE_LED
#    define LED_PIN 2  // has no built-in LED
// CH32V003
#  elif defined(CH32V003)
#    define USE_LED
#    define LED_PIN PC1
// Fallback to LED_BUILTIN
#  elif defined(LED_BUILTIN)
#    define USE_LED
#    define LED_PIN LED_BUILTIN
#  else
#    error "No built-in LED defined for this board."
// #  define LED_PIN 1
#  endif
#endif  // !defined(USE_LED)

#ifdef USE_LED
#  ifndef LED_ON
#    define LED_ON HIGH
#  endif
#  ifndef LED_OFF
#    define LED_OFF LOW
#  endif
#endif

#if !defined(USE_NEOPIXEL)
// Waveshare RP2040 Zero
#  if defined(ARDUINO_WAVESHARE_RP2040_ZERO)
#    define USE_NEOPIXEL
#    define RGBLED_PIN PIN_NEOPIXEL
#    define RGBLED_TYPE (NEO_GRB + NEO_KHZ800)
#  endif
#endif  // !defined(USE_NEOPIXEL)

#ifdef USE_NEOPIXEL
#  include <Adafruit_NeoPixel.h>
#  define RGBLED_COUNT 1
#  define RGBLED_TYPE (NEO_GRB + NEO_KHZ800)
#  define RGBLED_BRIGHTNESS 127
#  define RGBLED_ON rgbled.Color(255, 0, 0)
#  define RGBLED_OFF rgbled.Color(0, 0, 0)
Adafruit_NeoPixel rgbled(RGBLED_COUNT, RGBLED_PIN, RGBLED_TYPE);
#endif

#define MORSE_UNIT 100

void setup() { morseSetup(); }

void loop() {
  morseBlinkDot(3);
  morseDelayBetweenLetters();
  morseBlinkDash(3);
  morseDelayBetweenWords();
}

void morseSetup() { setupLED(); }

void morseBlinkDot(int count) {
  for (int i = 0; i < count; i++) {
    turnOnLED();
    delay(MORSE_UNIT);
    turnOffLED();
    delay(MORSE_UNIT);
  }
}

void morseBlinkDash(int count) {
  for (int i = 0; i < count; i++) {
    turnOnLED();
    delay(3 * MORSE_UNIT);
    turnOffLED();
    delay(MORSE_UNIT);
  }
}

void morseDelayBetweenLetters() { delay(3 * MORSE_UNIT); }

void morseDelayBetweenWords() { delay(7 * MORSE_UNIT); }

void setupLED() {
#ifdef USE_LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LED_OFF);
#endif
#ifdef USE_NEOPIXEL
  rgbled.begin();
  rgbled.setBrightness(RGBLED_BRIGHTNESS);
  rgbled.setPixelColor(0, RGBLED_OFF);
  rgbled.show();
#endif
}

void turnOnLED() {
#ifdef USE_LED
  digitalWrite(LED_PIN, LED_ON);
#endif
#ifdef USE_NEOPIXEL
  rgbled.setPixelColor(0, RGBLED_ON);
  rgbled.show();
#endif
}

void turnOffLED() {
#ifdef USE_LED
  digitalWrite(LED_PIN, LED_OFF);
#endif
#ifdef USE_NEOPIXEL
  rgbled.setPixelColor(0, RGBLED_OFF);
  rgbled.show();
#endif
}
