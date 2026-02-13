#define TOUCH_PIN 4
#define RED_LED 11

void setup() {
    pinMode(TOUCH_PIN, INPUT);   
    pinMode(RED_LED, OUTPUT);
}

void loop() {
    int touchState = digitalRead(TOUCH_PIN);

    if (touchState == HIGH) {   
        digitalWrite(RED_LED, HIGH);
    } else {
        digitalWrite(RED_LED, LOW);
    }
}