const char pin_pir     = 12; // PIR sensor
const char pin_red_led = 11; // red LED
void setup() {
  pinMode(pin_pir, INPUT);      // PIR is an input
  pinMode(pin_red_led, OUTPUT); // LED is an output
}
void loop() {
  int pir_state = digitalRead(pin_pir);  // read PIR: HIGH or LOW


  if (pir_state == HIGH) {
    // Motion detected → LED ON
    digitalWrite(pin_red_led, HIGH);
  } else {
    // No motion → LED OFF
    digitalWrite(pin_red_led, LOW);
  }
}
