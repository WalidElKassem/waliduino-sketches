const char pin_pir     = 12; // PIR sensor
const char pin_red_led = 11; // red LED
const char pin_buzzer  = 6;  // buzzer
void setup() {
  pinMode(pin_pir, INPUT);       // PIR is input
  pinMode(pin_red_led, OUTPUT);  // LED is output
  pinMode(pin_buzzer, OUTPUT);   // buzzer is output
}
void loop() {
  int pir_state = digitalRead(pin_pir);  // read PIR: HIGH or LOW


  if (pir_state == HIGH) {
    // Motion detected → start alarm
    digitalWrite(pin_red_led, HIGH);  // LED ON
    digitalWrite(pin_buzzer, HIGH);   // buzzer ON


    delay(5000);                      // keep alarm on for 5 seconds


    digitalWrite(pin_red_led, LOW);   // LED OFF
    digitalWrite(pin_buzzer, LOW);    // buzzer OFF
  }
}
