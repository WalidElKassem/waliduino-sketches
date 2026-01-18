#include <Adafruit_NeoPixel.h>


#define PIN_NEOPIXEL A2   // NeoPixel on A2
#define NUM_PIXELS   1    // one LED


Adafruit_NeoPixel pixels(NUM_PIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);


// Color A and Color B (start and end colors)
const int R1 = 255;  // Color A: red
const int G1 = 0;


const int R2 = 0;    // Color B: blue
const int G2 = 0;
const int B2 = 255;

void setup() {
  pixels.begin();         // start NeoPixel
  pixels.setBrightness(50); // not too bright (0–255)
}

void loop() {
  // Fade from Color A (R1,G1,B1) to Color B (R2,G2,B2)
  for (int step = 0; step <= 255; step = step + 1) {
    int r = map(step, 0, 255, R1, R2);
    int g = map(step, 0, 255, G1, G2);
    int b = map(step, 0, 255, B1, B2);


    pixels.setPixelColor(0, pixels.Color(r, g, b));
    pixels.show();
    delay(20); // smaller = faster fade, bigger = slower fade
  }


  // Fade back from Color B to Color A
  for (int step = 0; step <= 255; step = step + 1) {
    int r = map(step, 0, 255, R2, R1);
    int g = map(step, 0, 255, G2, G1);
    int b = map(step, 0, 255, B2, B1);


    pixels.setPixelColor(0, pixels.Color(r, g, b));
    pixels.show();
    delay(20);
  }
}
