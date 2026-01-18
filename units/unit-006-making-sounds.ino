// Define the buzzer pin
const char pin_buzzer = 6;

void setup() {
  // Set the buzzer pin as OUTPUT
  pinMode(pin_buzzer, OUTPUT);
}

void loop() {
  // 🔊 Buzzer ON
  digitalWrite(pin_buzzer, HIGH);
  delay(200);   // Beep for 200 ms

  // 🔇 Buzzer OFF
  digitalWrite(pin_buzzer, LOW);
  delay(800);   // Silence for 800 ms
}
