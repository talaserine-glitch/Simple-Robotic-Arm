# Simple-Robotic-Arm
Simple Robotic Arm is a beginner-friendly Arduino project designed to move a small object from Point A to Point B using two motors and a joystick controller.

## Robotic arm picture

![ Robotic arm picture](roboticarm.jpg)

## 🦾 How it work 

![ 🦾 How it work](workmechanism.ino)

the robotic arm is controlled by a joystick.

• Left / Right: moves the arm using the stepper motor.

• Up / Down: controls the servo.

• The servo opens and closes the gripper to grab or release objects.



## Components

🔋electronics parts:

Arduino Uno

28BYJ-48 Stepper Motor

ULN2003 Stepper Motor Driver

SG90 Servo Motor

Analog Joystick

Breadboard

Jumper Wires

USB Cable

Resistors ( use it as wires for the grippers)

⚙️ Mechanical Parts:

lightweight cardboard or plastic material to form:

base frame for step motor

servo mounting bracket

Mechanical arm structure

Grippers

## Real Circuit

![Real circuit](realcircuit.jpg)

## Wirring


![wirring](connecting.jpg)

## The gripper structure

![The gripper structure](gripper.jbg)

## arduino code 

for 28BYJ-48 Stepper Motor and ULN2003 Stepper Motor Driver

```cpp
#include <Servo.h>
#include <Stepper.h>

// ===== STEPPER =====
const int stepsPerRevolution = 2048;

Stepper stepper(stepsPerRevolution, 2, 4, 3, 5);

// ===== SERVO =====
Servo myServo;
const int servoPin = 9;

// ===== JOYSTICK =====
const int joyX = A0;
const int joyY = A1;

int servoAngle = 90;

void setup() {
  myServo.attach(servoPin);
  myServo.write(servoAngle);

  stepper.setSpeed(10);

  Serial.begin(9600);
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
    servoAngle++;
  }
  else if (yValue > 600) {
    servoAngle--;
  }

  // Keep servo between 0 and 180 degrees
  servoAngle = constrain(servoAngle, 0, 180);

  myServo.write(servoAngle);

  delay(10);
}












