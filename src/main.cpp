/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Farty Marty                                               */
/*    Created:      8/20/2025, 7:57:19 AM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "robot-config.h"
#include "functions.h"
using namespace vex;
competition Competition;

int autonMode;

void pre_auton(void) {

calibrateInertial();

  while(Competition.isAutonomous()==false){
    //autonomous switcher
    //this loop ends when autonomous starts
    if(Controller.ButtonX.pressing()==true) autonMode = 1; //mode 1
    else if(Controller.ButtonA.pressing()==true) autonMode = 2; //mode 2
    else if(Controller.ButtonUp.pressing()==true) autonMode = 3; //mode 3
    else if(Controller.ButtonLeft.pressing()==true) autonMode = 4; //mode 4
    Controller.Screen.clearLine();
    Controller.Screen.setCursor(1,1);
    switch(autonMode){
      case 1: Controller.Screen.print("Auton 1"); break;
      case 2: Controller.Screen.print("Auton 2"); break;
      case 3: Controller.Screen.print("Drive Forward"); break;
      case 4: Controller.Screen.print("Skills"); break;
      default: Controller.Screen.print("Select Autonomous"); break;
    } 

    wait(0.5,seconds); //interval time
    
}
}

void autonomous(void) {
  leftSide.stop();
  rightSide.stop();
  rightSide.setStopping(hold);
  leftSide.setStopping(hold);
  rightSide.setVelocity(40,percent);
  leftSide.setVelocity(40,percent);
  intakeMotor.setVelocity(100,percent);

  switch(autonMode) {
    case 1:
    //Auton 1
    break;

    case 2:
    //Auton 2
    break;

    case 3:
    //Drive forward
    break;

    case 4:
    //Skills :)
    break;
  }

}

void usercontrol(void) {

  leftSide.setStopping(coast);
  rightSide.setStopping(coast);
  intakeMotor.setStopping(coast);
  intakeMotor.setVelocity(100,percent);

  while (1) {


//Intake Motor

    if(Controller.ButtonR2.pressing()==true && Controller.ButtonR1.pressing()==false){
      //if the right trigger is being pressed AND the right bumper is not then it outtakes
      intakeMotor.spin(reverse);
    }

    else if(Controller.ButtonR1.pressing()==true && Controller.ButtonR2.pressing()==false){
      //if the right bumper is being pressed AND the right trigger is not then it intakes
      intakeMotor.spin(forward);
    }

    else{
      //if no buttons are being pressed OR both buttons are being pressed then it stops
      intakeMotor.stop();
    }








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
