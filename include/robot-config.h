
#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H


#include "vex.h";
using namespace vex;

extern brain Brain;
extern controller Controller;
extern controller sideController;
extern motor LFM;
extern motor LMM;
extern motor LBM;
extern motor RFM;
extern motor RMM;
extern motor RBM;

extern inertial inertialSensor;

extern motor_group leftSide;
extern motor_group rightSide;




#endif