#include <Adafruit_NeoPixel.h>


#define PIN_NEOPIXEL A2   // NeoPixel data pin on A2
#define NUM_PIXELS   1    // number of NeoPixel LEDs on the board


Adafruit_NeoPixel pixels(NUM_PIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);
void setup() {
  pixels.begin();          // start the NeoPixel library
  pixels.setBrightness(50); // set brightness (0–255), 50 is not too bright


  // Set the NeoPixel to a solid color (for example: red)
  pixels.setPixelColor(0, pixels.Color(255, 0, 0)); // R, G, B
  pixels.show();           // send the color to the LED
}


void loop() {
  // Nothing here for now – LED keeps its color
}
