#include <FastLED.h>

#define LEDS_PER_STRING 300
#define STRING_COUNT 4
#define STRING1_INDEX 0
#define STRING1_PIN 3
#define STRING2_INDEX 1
#define STRING2_PIN 5
#define STRING3_INDEX 2
#define STRING3_PIN 6
#define STRING4_INDEX 3
#define STRING4_PIN 8

#define STATUS_LED_PIN LED_BUILTIN

#define MAX_BRIGHT 128

CRGB leds[STRING_COUNT][LEDS_PER_STRING];
unsigned int level = 0;

void setup() {
  // wakeup blink
  pinMode(STATUS_LED_PIN, OUTPUT);
  for (int i = 0; i < 8; i++) {
    digitalWrite(STATUS_LED_PIN, HIGH);
    delay(50);
    digitalWrite(STATUS_LED_PIN, LOW);
    delay(50);
  }

  // initialize strings memory and pins
  FastLED.addLeds<WS2812B, STRING1_PIN, GRB>(leds[STRING1_INDEX], LEDS_PER_STRING);
  FastLED.addLeds<WS2812B, STRING2_PIN, GRB>(leds[STRING2_INDEX], LEDS_PER_STRING);
  FastLED.addLeds<WS2812B, STRING3_PIN, GRB>(leds[STRING3_INDEX], LEDS_PER_STRING);
  FastLED.addLeds<WS2812B, STRING4_PIN, GRB>(leds[STRING4_INDEX], LEDS_PER_STRING);
}

void loop() {
  // level spinner
  level++;
  if (level > MAX_BRIGHT)
    level = 0;

  // set the LED color
  for (int i = 0; i < LEDS_PER_STRING; i++) {
    leds[STRING1_INDEX][i] = CRGB(level, 0, MAX_BRIGHT - level);
    leds[STRING2_INDEX][i] = CRGB(level, 0, MAX_BRIGHT - level);
    leds[STRING3_INDEX][i] = CRGB(level, 0, MAX_BRIGHT - level);
    leds[STRING4_INDEX][i] = CRGB(level, 0, MAX_BRIGHT - level);
  }

  // show
  FastLED.show();

  // delay
  digitalWrite(STATUS_LED_PIN, LOW);
  delay(50);
  digitalWrite(STATUS_LED_PIN, HIGH);
}
