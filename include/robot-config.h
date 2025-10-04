
#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H


#include "vex.h";
using namespace vex;

extern brain Brain;
extern controller Controller;
extern motor intakeMotorLeft;
extern motor intakeMotorRight;
extern motor intakeMotorTop;
extern motor LFM;
extern motor LMM;
extern motor LBM;
extern motor RFM;
extern motor RMM;
extern motor RBM;

extern inertial inertialSensor;

extern motor_group intake;
extern motor_group intakeFront;
extern motor_group leftSide;
extern motor_group rightSide;
extern motor_group Drivetrain;




#endif;