#include <FastLED.h>

#define NUM_LEDS 32
#define DATA_PIN 7
#define BAUDRATE 500000

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(255);
  Serial.begin(BAUDRATE);

  // Kurzer Start-Check: Einmal kurz blau aufblitzen lassen
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  FastLED.show();
  delay(300);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
}

void loop() {
  // Adalight Protokoll Empfänger
  static uint8_t prefix[] = {'A', 'd', 'a'};
  static uint8_t step = 0;
  static uint16_t hi, lo, dummy;
  static uint16_t c = 0;

  while (Serial.available() > 0) {
    uint8_t b = Serial.read();

    switch (step) {
      case 0:
        if (b == prefix[0]) step++;
        break;
      case 1:
        if (b == prefix[1]) step++;
        else step = 0;
        break;
      case 2:
        if (b == prefix[2]) step++;
        else step = 0;
        break;
      case 3:
        hi = b;
        step++;
        break;
      case 4:
        lo = b;
        step++;
        break;
      case 5:
        dummy = b; // Checksumme (wird hier ignoriert)
        c = 0;
        step++;
        break;
      case 6:
        // Einlesen der RGB-Daten
        leds[c].r = b;
        step++;
        break;
      case 7:
        leds[c].g = b;
        step++;
        break;
      case 8:
        leds[c].b = b;
        c++;
        if (c >= NUM_LEDS) {
          FastLED.show();
          step = 0;
        } else {
          step = 6;
        }
        break;
    }
  }
}
