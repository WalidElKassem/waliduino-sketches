const char pin_pot    = A6; // potentiometer
const char pin_buzzer = 6;  // buzzer


int pot_value   = 0;        // to store the reading from A6
int delay_time  = 0;        // to store the time between beeps
void setup() {
  pinMode(pin_buzzer, OUTPUT);  // buzzer is an output
}
void loop() {
  // 1) Read the potentiometer value (0–1023)
  pot_value = analogRead(pin_pot);


  // 2) Convert this value to a delay time (for example 50–500 ms)
  //    When pot is low  → short delay (fast beeps)
  //    When pot is high → long delay (slow beeps)
  delay_time = map(pot_value, 0, 1023, 50, 500);


  // 3) Make one beep
  digitalWrite(pin_buzzer, HIGH);  // buzzer ON
  delay(100);                      // beep length (100 ms)
  digitalWrite(pin_buzzer, LOW);   // buzzer OFF


  // 4) Wait based on the pot position
  delay(delay_time);               // pause depends on knob position
}
