const char pin_trig   = 7; // Trig pin of HC-SR04
const char pin_echo   = 8; // Echo pin of HC-SR04
const char pin_buzzer = 6; // Buzzer pin
void setup() {
  pinMode(pin_trig, OUTPUT);   // Trig is an output (we send a pulse)
  pinMode(pin_echo, INPUT);    // Echo is an input (we read the pulse)
  pinMode(pin_buzzer, OUTPUT); // Buzzer is an output


  // Optional: for debugging later via Serial Monitor
  // Serial.begin(9600);
}
void loop() {
  long duration;
  int distance_cm;


  // 1) Make sure Trig is LOW
  digitalWrite(pin_trig, LOW);
  delayMicroseconds(2);


  // 2) Send a short HIGH pulse (10 microseconds)
  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);


  // 3) Measure the length of the echo pulse on Echo pin
  duration = pulseIn(pin_echo, HIGH);


  // 4) Convert time to distance (approximate)
  distance_cm = duration * 0.034 / 2;


  // Optional: show value in Serial Monitor
  // Serial.print("Distance: ");
  // Serial.print(distance_cm);
  // Serial.println(" cm");


  // 5) Decide: beep or not beep
  if (distance_cm > 0 && distance_cm < 15) {   // object closer than 15 cm
    digitalWrite(pin_buzzer, HIGH);            // buzzer ON
  } else {
    digitalWrite(pin_buzzer, LOW);             // buzzer OFF
  }


  delay(100); // small pause before next measurement
}
