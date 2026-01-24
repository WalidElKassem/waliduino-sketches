#include <Wire.h>
#include <U8g2lib.h>

// OLED object (works with SH1106 & SSD1306)
U8G2_SH1106_128X64_NONAME_F_HW_I2C display(U8G2_R0, U8X8_PIN_NONE);

const char pin_pot = A6;   // potentiometer

int pot_value = 0;         // value from 0 to 1023
void setup() {
  display.begin();

  // Draw static text (header)
  display.clearBuffer();
  display.setFont(u8g2_font_6x12_tr);
  display.drawStr(10, 15, "Potentiometer");
  display.drawStr(10, 30, "Value:");
  display.sendBuffer();
}
void loop() {
  // 1) Read potentiometer (0–1023)
  pot_value = analogRead(pin_pot);

  // 2) Clear screen and redraw everything
  display.clearBuffer();

  // 3) Redraw static labels
  display.setFont(u8g2_font_6x12_tr);
  display.drawStr(10, 15, "Potentiometer");
  display.drawStr(10, 30, "Value:");

  // 4) Draw the value (big font)
  display.setFont(u8g2_font_ncenB14_tr);
  display.setCursor(10, 55);
  display.print(pot_value);

  // 5) Send buffer to screen
  display.sendBuffer();

  delay(100); // update ~10 times per second
}
