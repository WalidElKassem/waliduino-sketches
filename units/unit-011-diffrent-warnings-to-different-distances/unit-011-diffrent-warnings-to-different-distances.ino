const char pin_trig    = 7;
const char pin_echo    = 8;
const char pin_buzzer  = 6;
const char pin_red_led = 11;
void setup() {
  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);
  pinMode(pin_buzzer, OUTPUT);
  pinMode(pin_red_led, OUTPUT);


  // Optional: for debugging
  // Serial.begin(9600);
}
void loop() {
  long duration;
  int distance_cm;


  // Make sure Trig is LOW
  digitalWrite(pin_trig, LOW);
  delayMicroseconds(2);


  // Send a 10 µs pulse on Trig
  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);


  // Read echo time
  duration = pulseIn(pin_echo, HIGH);


  // Convert time to distance in cm (approximate)
  distance_cm = duration * 0.034 / 2;


  // Optional: see the value in Serial Monitor
  // Serial.print("Distance: ");
  // Serial.print(distance_cm);
  // Serial.println(" cm");
 if (distance_cm > 0 && distance_cm < 10) {
    // Very close → strong warning: LED + buzzer
    digitalWrite(pin_red_led, HIGH);
    digitalWrite(pin_buzzer, HIGH);


  } else if (distance_cm >= 10 && distance_cm < 30) {
    // Medium distance → only LED ON
    digitalWrite(pin_red_led, HIGH);
    digitalWrite(pin_buzzer, LOW);


  } else {
    // Far away or no object → everything OFF
    digitalWrite(pin_red_led, LOW);
    digitalWrite(pin_buzzer, LOW);
  }


  delay(100); // small pause before next measurement
}
