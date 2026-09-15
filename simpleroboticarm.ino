#include <Servo.h>
#include <Stepper.h>

// Stepper
const int stepsPerRevolution = 2048;
Stepper stepper(stepsPerRevolution, 2, 4, 3, 5);

// Servo
Servo myServo;
const int servoPin = 9;

// Joystick
const int joyX = A0;
const int joyY = A1;

void setup() {
  myServo.attach(servoPin);
  myServo.write(0);

  stepper.setSpeed(10);
}

void loop() {

  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);

  // =========================
  // LEFT / RIGHT → STEPPER
  // =========================

  if (xValue < 400) {
    stepper.step(-5);
  }
  else if (xValue > 600) {
    stepper.step(5);
  }

  // =========================
  // UP / DOWN → SERVO
  // =========================

  if (yValue < 400) {
    myServo.write(90);
  }
  else if (yValue > 600) {
    myServo.write(0);
  }

  delay(10);
}