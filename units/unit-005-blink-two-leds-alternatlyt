// Define LED pins
int pin_red_led = 11;
int pin_green_led = 9;

void setup() {
  // Set both pins as OUTPUT
  pinMode(pin_red_led, OUTPUT);
  pinMode(pin_green_led, OUTPUT);
}

void loop() {
  // 🔴 Red ON, 🟢 Green OFF
  digitalWrite(pin_red_led, HIGH);
  digitalWrite(pin_green_led, LOW);
  delay(1000); // wait 1 second

  // 🔴 Red OFF, 🟢 Green ON
  digitalWrite(pin_red_led, LOW);
  digitalWrite(pin_green_led, HIGH);
  delay(1000); // wait 1 second
}
