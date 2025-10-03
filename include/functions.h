
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "vex.h";
#include <string>
using namespace vex;

void calibrateInertial();
void spinIntake(vex::directionType dir);
void drive(vex::directionType direction, double inches);

#endif