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
#include <string>
using namespace vex;

competition Competition;

int autonMode;

std::string goReverse = "reverse";
std::string goForward = "forward";

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
    switch(autonMode){ //we can add more cases if we find more buttons to use (we could even use combos)
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
  intake.setVelocity(100,percent);

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
  intake.setStopping(coast);
  intake.setVelocity(100,percent);

  while (1) {


    //Intake Motor

    if(Controller.ButtonR2.pressing()==true && Controller.ButtonR1.pressing()==false){
      //if the right trigger is being pressed AND the right bumper is not then it outtakes
      spinIntake(goReverse);
    }

    else if(Controller.ButtonR1.pressing()==true && Controller.ButtonR2.pressing()==false){
      //if the right bumper is being pressed AND the right trigger is not then it intakes
      spinIntake(goForward);
    }

    else{
      //if no buttons are being pressed OR both buttons are being pressed then it stops
      intake.stop();
    }


    //DriveTrain Motors
    
    leftSide.setVelocity(Controller.Axis3.position(), percent); //percentage (decimal between 0-1) of max speed of each side is equal to current_position÷range of each analog stick
    rightSide.setVelocity(Controller.Axis2.position(), percent);

    leftSide.spin(forward); //motors always spinning, but if analog stick is centered then speed = 0 so it wont move
    rightSide.spin(forward);

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
