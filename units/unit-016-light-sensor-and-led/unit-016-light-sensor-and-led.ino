const char pin_ldr     = A7;  // light sensor
const char pin_red_led = 11;  // red LED


int light_value = 0;          // variable to store the LDR reading
int threshold   = 500;        // limit value to decide dark/bright
void setup() {
  pinMode(pin_red_led, OUTPUT);  // LED is an output
  // pin_ldr is an input for analogRead(), no pinMode() needed here
}
void loop() {
  // 1) Read the light level from the LDR
  light_value = analogRead(pin_ldr);  // value between 0 and 1023


  // 2) Decide based on the threshold
  if (light_value < threshold) {
    // It is dark → turn LED ON
    digitalWrite(pin_red_led, HIGH);
  } else {
    // It is bright → turn LED OFF
    digitalWrite(pin_red_led, LOW);
  }


  delay(100); // small pause before next reading
}
