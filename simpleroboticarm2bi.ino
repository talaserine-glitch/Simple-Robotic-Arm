#include <Servo.h>

Servo myServo;

// Joystick
const int horzPin = A0;
const int vertPin = A1;

// A4988
const int stepPin = 3;
const int dirPin = 4;

// Servo
const int servoPin = 9;

int servoPosition = 0;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(0);

  Serial.begin(9600);
}

void loop() {

  int horz = analogRead(horzPin);
  int vert = analogRead(vertPin);

  // =========================
  // JOYSTICK X → STEPPER
  // =========================

  if (horz > 600) {
    // Joystick RIGHT
    digitalWrite(dirPin, HIGH);

    digitalWrite(stepPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(800);
  }

  else if (horz < 400) {
    // Joystick LEFT
    digitalWrite(dirPin, LOW);

    digitalWrite(stepPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(800);
  }

  // =========================
  // JOYSTICK Y → SERVO
  // =========================

  if (vert > 600) {
    // Joystick UP → servo 90°
    myServo.write(90);
  }

  else if (vert < 400) {
    // Joystick DOWN → servo 0°
    myServo.write(0);
  }
}