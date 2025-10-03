#include "vex.h"
using namespace vex;

brain Brain;
controller Controller = controller(primary);
motor LFM = motor(PORT7, ratio6_1, true);
motor LMM = motor(PORT6, ratio6_1, false);
motor LBM = motor(PORT5, ratio6_1, true);
motor RFM = motor(PORT10, ratio6_1, false);
motor RMM = motor(PORT9, ratio6_1, true);
motor RBM = motor(PORT8, ratio6_1, false);

motor intakeMotorRight = motor(PORT4, ratio18_1, true);
motor intakeMotorLeft = motor(PORT3, ratio18_1, false);
motor intakeMotorTop = motor(PORT15, ratio18_1, false);

inertial inertialSensor = inertial(PORT18);

motor_group intakeFront = motor_group(intakeMotorRight,intakeMotorLeft);
motor_group intake = motor_group(intakeMotorRight,intakeMotorLeft,intakeMotorTop);
motor_group leftSide = motor_group(LFM,LMM,LBM);
motor_group rightSide = motor_group(RFM, RMM, RBM);
motor_group Drivetrain = motor_group(RFM, RMM, RBM, LFM,LMM,LBM);