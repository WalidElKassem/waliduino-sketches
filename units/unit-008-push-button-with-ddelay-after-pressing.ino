const char pin_button = 2;   // push button
const char pin_red_led = 11; // red LED
void setup() {
  pinMode(pin_red_led, OUTPUT);  // LED will be controlled by the program
  pinMode(pin_button, INPUT);    // button will be read by the program
}
void loop() {
  int button_state = digitalRead(pin_button);  // read button


  if (button_state == HIGH) {
    // Button is pressed → start action
    digitalWrite(pin_red_led, HIGH);  // LED ON
    delay(1000);                      // wait 1 second
    digitalWrite(pin_red_led, LOW);   // LED OFF
  }
}
