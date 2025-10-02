#include "vex.h"
using namespace vex;

brain Brain;
controller Controller = controller(primary);
motor LFM = motor(PORT11, ratio6_1, true);
motor LMM = motor(PORT12, ratio6_1, false);
motor LBM = motor(PORT13, ratio6_1, true);
motor RFM = motor(PORT14, ratio6_1, false);
motor RMM = motor(PORT15, ratio6_1, false);
motor RBM = motor(PORT16, ratio6_1, true);

motor intakeMotorRight = motor(PORT1, ratio18_1, true);
motor intakeMotorLeft = motor(PORT2, ratio18_1, false);
motor intakeMotorTop = motor(PORT4, ratio18_1, false);

inertial inertialSensor = inertial(PORT18);

motor_group intakeFront = motor_group(intakeMotorRight,intakeMotorLeft);
motor_group intake = motor_group(intakeMotorRight,intakeMotorLeft,intakeMotorTop);
motor_group leftSide = motor_group(LFM,LMM,LBM);
motor_group rightSide = motor_group(RFM, RMM, RBM);