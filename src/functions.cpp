
#include "vex.h"
#include "robot-config.h"
#include "functions.h"
#include <string>
using namespace vex;

void calibrateInertial()
{
  inertialSensor.calibrate();
  while (inertialSensor.isCalibrating())
  {
    wait(25, msec); // wait for inertial sensor to calibrate before continuing
  }
}

void spinIntake(vex::directionType dir) {
    intake.spin(dir);
}

void spinIntakeFront(vex::directionType dir) {
    intakeFront.spin(dir);
}

void drive(vex::directionType direction, double inches) {

}

void driveSeconds(vex::directionType direction, double sec) {
  Drivetrain.spinFor(direction, sec, seconds);
}