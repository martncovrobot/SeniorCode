
#include "vex.h"
#include "robot-config.h"
#include "functions.h"
using namespace vex;

void calibrateInertial()
{
  inertialSensor.calibrate();
  while (inertialSensor.isCalibrating())
  {
    wait(25, msec); // wait for inertial sensor to calibrate before continuing
  }
}

void spinIntake(bool isReverse) {
  if(isReverse) {
    intakeMotorRight.spin(reverse);
    intakeMotorLeft.spin(reverse);
  } else {
    intakeMotorRight.spin(forward);
    intakeMotorLeft.spin(forward);
  }
}