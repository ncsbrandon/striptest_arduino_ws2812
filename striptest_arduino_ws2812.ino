#include <FastLED.h>

// string settings
#define LEDS_PER_STRING 300
#define STRING1_PIN 3
#define MAX_BRIGHT 128
#define STATUS_LED_PIN 13

CRGB leds[LEDS_PER_STRING];

void setup() {
  // initialize strings memory and pins
  FastLED.addLeds<WS2812B, STRING1_PIN, RGB>(leds, LEDS_PER_STRING);

pinMode(STATUS_LED_PIN, OUTPUT);
  for (int i = 0; i < 10; i++) {
    digitalWrite(STATUS_LED_PIN, HIGH);
    delay(50);
    digitalWrite(STATUS_LED_PIN, LOW);
    delay(50);
  }
}

void loop() {
  // off
  digitalWrite(STATUS_LED_PIN, LOW);
  setString(0, 0, 0);
  delay(250);

  // red
  digitalWrite(STATUS_LED_PIN, HIGH);
  setString(MAX_BRIGHT, 0, 0);
  delay(250);

  // green
  digitalWrite(STATUS_LED_PIN, LOW);
  setString(0, MAX_BRIGHT, 0);
  delay(250);

  // blue
  digitalWrite(STATUS_LED_PIN, HIGH);
  setString(0, 0, MAX_BRIGHT);
  delay(250);

  // red + green
  digitalWrite(STATUS_LED_PIN, LOW);
  setString(MAX_BRIGHT, MAX_BRIGHT, 0);
  delay(250);

  // red + blue
  digitalWrite(STATUS_LED_PIN, HIGH);
  setString(MAX_BRIGHT, 0, MAX_BRIGHT);
  delay(250);

  // green + blue
  digitalWrite(STATUS_LED_PIN, LOW);
  setString(0, MAX_BRIGHT, MAX_BRIGHT);
  delay(250);
  
  // white
  digitalWrite(STATUS_LED_PIN, HIGH);
  setString(MAX_BRIGHT, MAX_BRIGHT, MAX_BRIGHT);
  delay(250);
}

void setString(int red, int green, int blue) {
  for (int i = 0; i < LEDS_PER_STRING; i++) {
    leds[i] = CRGB(red, green, blue);
  }
  FastLED.show();
}
