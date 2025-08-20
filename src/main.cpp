/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Martin.Disibio                                            */
/*    Created:      8/20/2025, 7:57:19 AM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
using namespace vex;
competition Competition;

void pre_auton(void) {
}

void autonomous(void) {
}
//testing ssh key auth
void usercontrol(void) {
  while (1) {
    wait(20, msec);
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
