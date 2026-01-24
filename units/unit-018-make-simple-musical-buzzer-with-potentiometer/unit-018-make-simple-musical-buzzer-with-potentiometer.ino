// Pins
const char pin_pot    = A6; // Potentiometer
const char pin_buzzer = 6;  // Buzzer

// Variables
int pot_value = 0;   // 0–1023
int tone_freq = 0;   // Frequency in Hz

void setup() {
  pinMode(pin_buzzer, OUTPUT);
}

void loop() {
  // 1) Read potentiometer
  pot_value = analogRead(pin_pot);

  // 2) Map pot value to frequency (200–2000 Hz)
  tone_freq = map(pot_value, 0, 1023, 200, 2000);

  // 3) Play the tone
  tone(pin_buzzer, tone_freq);

  delay(20); // small delay for stability
}
