#include <Servo.h>

Servo motor_servo;


const char pin_servo    = 3;  // servo signal
const char pin_trig     = 7;  // HC-SR04 Trig
const char pin_echo     = 8;  // HC-SR04 Echo
const char pin_red_led  = 11; // warning LED
void setup() {
  motor_servo.attach(pin_servo);   // attach servo to D3


  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);
  pinMode(pin_red_led, OUTPUT);


  // Optional: use Serial Monitor to see angle & distance
  // Serial.begin(9600);
}
int measureDistanceCm() {
  long duration;
  int distance_cm;


  digitalWrite(pin_trig, LOW);
  delayMicroseconds(2);


  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin_trig, LOW);


  duration = pulseIn(pin_echo, HIGH);
  distance_cm = duration * 0.034 / 2;


  return distance_cm;
}
void loop() {
  // Sweep from 0° to 180°
  for (int angle = 0; angle <= 180; angle = angle + 5) {
    motor_servo.write(angle);   // move servo
    delay(100);                 // wait for servo to reach position


    int distance_cm = measureDistanceCm();


    // Optional: show in Serial Monitor
    // Serial.print("Angle: ");
    // Serial.print(angle);
    // Serial.print("  Distance: ");
    // Serial.print(distance_cm);
    // Serial.println(" cm");


    if (distance_cm > 0 && distance_cm < 20) {
      digitalWrite(pin_red_led, HIGH);   // object close → warn
    } else {
      digitalWrite(pin_red_led, LOW);    // no object → LED off
    }
  }


  // Sweep back from 180° to 0°
  for (int angle = 180; angle >= 0; angle = angle - 5) {
    motor_servo.write(angle);
    delay(100);


    int distance_cm = measureDistanceCm();


    // Optional: Serial output again
    // Serial.print("Angle: ");
    // Serial.print(angle);
    // Serial.print("  Distance: ");
    // Serial.print(distance_cm);
    // Serial.println(" cm");


    if (distance_cm > 0 && distance_cm < 20) {
      digitalWrite(pin_red_led, HIGH);
    } else {
      digitalWrite(pin_red_led, LOW);
    }
  }
}
