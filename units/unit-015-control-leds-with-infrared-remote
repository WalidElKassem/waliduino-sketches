#include <IRremote.h>

// Pins
const byte pin_ir_receiver = 5;
const byte pin_red_led     = 11;
const byte pin_yellow_led  = 10;
const byte pin_green_led   = 9;

// YOUR REAL REMOTE CODES
const byte CODE_RED_BUTTON    = 0x45; // Button 1
const byte CODE_YELLOW_BUTTON = 0x46; // Button 2
const byte CODE_GREEN_BUTTON  = 0x47; // Button 3

void setup() {
  pinMode(pin_red_led, OUTPUT);
  pinMode(pin_yellow_led, OUTPUT);
  pinMode(pin_green_led, OUTPUT);

  IrReceiver.begin(pin_ir_receiver);
}

void loop() {
  if (IrReceiver.decode()) {

    byte command = IrReceiver.decodedIRData.command;

    if (command == CODE_RED_BUTTON) {
      digitalWrite(pin_red_led, HIGH);
      digitalWrite(pin_yellow_led, LOW);
      digitalWrite(pin_green_led, LOW);
    }
    else if (command == CODE_YELLOW_BUTTON) {
      digitalWrite(pin_red_led, LOW);
      digitalWrite(pin_yellow_led, HIGH);
      digitalWrite(pin_green_led, LOW);
    }
    else if (command == CODE_GREEN_BUTTON) {
      digitalWrite(pin_red_led, LOW);
      digitalWrite(pin_yellow_led, LOW);
      digitalWrite(pin_green_led, HIGH);
    }

    IrReceiver.resume();
  }
}
