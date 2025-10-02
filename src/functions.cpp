
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

void spinIntake(std::string direction) {
  if(direction == "forward" || direction == "") {
    intake.spin(forward);
  } else {
    intake.spin(reverse);
  }
}