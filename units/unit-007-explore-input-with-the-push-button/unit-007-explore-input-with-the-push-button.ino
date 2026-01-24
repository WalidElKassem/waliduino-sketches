const char pin_button = 2;   // push button
const char pin_red_led = 11; // red LED
void setup() {
  pinMode(pin_red_led, OUTPUT);  // LED will be controlled by the program
  pinMode(pin_button, INPUT);    // button will be read by the program
}
void loop() {
  int button_state = digitalRead(pin_button);  // read the button: HIGH or LOW


  if (button_state == HIGH) {
    digitalWrite(pin_red_led, HIGH);  // if button is pressed → LED ON
  } else {
    digitalWrite(pin_red_led, LOW);   // if not pressed → LED OFF
  }
}

