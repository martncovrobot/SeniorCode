
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