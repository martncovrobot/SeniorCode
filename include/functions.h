
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "vex.h";
#include <string>
using namespace vex;

void calibrateInertial();
void spinIntake(vex::directionType dir);
void spinIntakeFront(vex::directionType dir);
void drive(vex::directionType direction, double inches);
void driveSeconds(vex::directionType direction, double seconds);

#endif