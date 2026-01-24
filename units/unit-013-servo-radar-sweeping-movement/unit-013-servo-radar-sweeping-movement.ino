#include <Servo.h>


Servo motor_servo;          // create a servo object
const char pin_servo = 3;   // servo signal on pin D3
void setup() {
  motor_servo.attach(pin_servo);   // connect servo to pin D3
  motor_servo.write(90);          // move to middle (optional start position)
}
void loop() {
  // Sweep from 0° to 180°
  for (int angle = 0; angle <= 180; angle = angle + 1) {
    motor_servo.write(angle);   // move servo to 'angle'
    delay(20);                  // wait 20 ms for smooth movement
  }


  // Sweep back from 180° to 0°
  for (int angle = 180; angle >= 0; angle = angle - 1) {
    motor_servo.write(angle);   // move servo back
    delay(20);                  // wait 20 ms again
  }
}
