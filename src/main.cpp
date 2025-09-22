/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Farty Marty                                               */
/*    Created:      8/20/2025, 7:57:19 AM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
using namespace vex;
competition Competition;

void pre_auton(void) {

  /*
calibrateInertial();

  while(Competition.isAutonomous()==false){
    //autonomous switcher
    //this loop ends when autonomous starts
    if(Controller.ButtonX.pressing()==true) autonMode = 1; //blue ring / red goal
    else if(Controller.ButtonA.pressing()==true) autonMode = 2; // red ring / blue goal
    else if(Controller.ButtonUp.pressing()==true) autonMode = 3; // drive forward
    else if(Controller.ButtonLeft.pressing()==true) autonMode = 4; //skills
    Controller.Screen.clearLine();
    Controller.Screen.setCursor(1,1);
    switch(autonMode){
      case 1: Controller.Screen.print("RedGoal/BlueRing"); break;
      case 2: Controller.Screen.print("BlueGoal/RedRing"); break;
      case 3: Controller.Screen.print("Drive Forward"); break;
      case 4: Controller.Screen.print("Skills"); break;
      default: Controller.Screen.print("Select Autonomous"); break;
    }
    
    wait(0.5,seconds); //interval time
    */

}

void autonomous(void) {
}

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
