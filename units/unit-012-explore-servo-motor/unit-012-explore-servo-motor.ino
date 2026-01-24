#include <Servo.h>
Servo motor_servo;         // create a servo object
const char pin_servo = 3;  // servo signal on pin D3
void setup() {
  motor_servo.attach(pin_servo);  // connect the servo object to pin D3
  motor_servo.write(0);         // move servo to 90° (middle position)
}
void loop() {
  // No code here yet
}
