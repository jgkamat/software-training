
#include <Wire.h>
#include <Encoder.h>
#include <BricktronicsShield.h>
#include <BricktronicsMotor.h>
#include <BricktronicsUltrasonic.h>

BricktronicsMotor right(BricktronicsShield::MOTOR_1);
BricktronicsMotor left(BricktronicsShield::MOTOR_2);
BricktronicsUltrasonic us(BricktronicsShield::SENSOR_4);


void setup() {
  Serial.begin(9600);
  BricktronicsShield::begin();
  right.begin();
  left.begin();
  us.begin();
}

void turnRight() {
 left.setPosition(0);
  right.setPosition(0);
  right.update();
  left.update();
  left.brake();
  right.goToPositionWaitForArrival(-2000);
  Serial.print("TesT");
}

void loop() {
  auto distance = us.getDistance();
  static int count = 0;
  static bool backing = false;

  Serial.print(distance);
   //Serial.print("\n");
  /*
  if (distance > 250) {
    left.setFixedDrive(150);
    right.setFixedDrive(150);
  } else if (distance < 250 && distance > 0) {
    left.setFixedDrive(-150);
    right.setFixedDrive(-150);
  } else if (distance > 0) {
    left.brake();
    right.brake();
  }
  */
  //distance = 19;
  if ((distance < 20 || distance == 255) && !backing) {
    count++;
  } else if (!backing) {
    count = 0;
  }

  if (count > 200 && !backing) {
    backing = true;
    count = 0;
  }
  if (backing) {
    left.setFixedDrive(-255);
    right.setFixedDrive(-150);
    count++;
    if (count > 350) {
      backing = false;
      count = 0;
    }
  } else {
    left.setFixedDrive(200);
    right.setFixedDrive(255);
  }
  
}
