#include <Wire.h>
#include <Encoder.h>
#include <BricktronicsShield.h>
#include <BricktronicsMotor.h>
#include <BricktronicsUltrasonic.h>

BricktronicsMotor right(BricktronicsShield::MOTOR_1);
BricktronicsMotor left(BricktronicsShield::MOTOR_2);
BricktronicsUltrasonic us(BricktronicsShield::SENSOR_4);


void setup() {
  BricktronicsShield::begin();
  right.begin();
  left.begin();
  us.begin();
}

void loop() {
  auto distance = us.getDistance();

  if (distance > 30) {
    left.setFixedDrive(150);
    right.setFixedDrive(150);
  } else if (distance < 20 && distance > 0) {
    left.setFixedDrive(-150);
    right.setFixedDrive(-150);
  } else if (distance > 0) {
    left.brake();
    right.brake();
  }
}