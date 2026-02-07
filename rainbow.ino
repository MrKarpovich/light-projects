#include <FastLED.h>

#define NUM_LEDS 300
#define DATA_PIN 13
#define BRIGHTNESS 100

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  static uint16_t hue = 0;
  
  // Плавный градиент через синусоиду (без артефактов даже на 300 диодах)
  for (int i = 0; i < NUM_LEDS; i++) {
    // Синусоида даёт плавные переходы без скачков
    uint8_t h = (hue + i * 2) % 256;
    leds[i] = CHSV(h, 255, 255);
  }
  
  FastLED.show();
  hue += 1;  // Медленное смещение цвета
  
  delay(25);  // Плавная скорость
}
