const char pin_trig   = 7;
const char pin_echo   = 8;
const char pin_buzzer = 6;
const char pin_red_led = 11;


void setup() {
  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);
  pinMode(pin_buzzer, OUTPUT);
  pinMode(pin_red_led, OUTPUT);
}


void loop() {
  long duration;
  int distance_cm;


  digitalWrite(pin_trig, LOW);
  delayMicroseconds(2);


  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);


  duration = pulseIn(pin_echo, HIGH);
  distance_cm = duration * 0.034 / 2;


  if (distance_cm > 0 && distance_cm < 15) {
    digitalWrite(pin_buzzer, HIGH);
    digitalWrite(pin_red_led, HIGH);
  } else {
    digitalWrite(pin_buzzer, LOW);
    digitalWrite(pin_red_led, LOW);
  }


  delay(100);
}
