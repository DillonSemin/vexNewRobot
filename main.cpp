/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       dillonsemin                                               */
/*    Created:      Mon Oct 11 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// frontR               motor         10              
// frontL               motor         1               
// middleR              motor         8               
// middleL              motor         3               
// backR                motor         9               
// backL                motor         2               
// Controller1          controller                    
// RangeFinderA         sonar         A, B            
// rotateArm1           motor         4               
// rotateArm2           motor         5               
// armLift              motor         6               
// claw                 motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

bool spinForward = true;
int values[18][2] = {};
int i = 0;
int driveMode = 0;
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while(true)
  {
    if(driveMode == 0)
    {
      frontR.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
      middleR.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
      backR.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);

      frontL.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      middleL.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      backL.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    }
    if(driveMode == 1)
    {
      frontR.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      backR.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      frontL.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      backL.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);

      middleR.spin(vex::directionType::fwd, Controller1.Axis3.value() - Controller1.Axis1.value() + 50, vex::velocityUnits::pct);
      middleL.spin(vex::directionType::rev, Controller1.Axis3.value() + Controller1.Axis1.value() + 50, vex::velocityUnits::pct);
    }
    if(Controller1.ButtonA.pressing())
    {
      driveMode = 0;
    }
    if(Controller1.ButtonB.pressing())
    {
      driveMode = 1;
    }
    while(Controller1.ButtonRight.pressing())
    {
      rotateArm1.spin(forward);
      rotateArm2.spin(forward);
    }
    while(Controller1.ButtonLeft.pressing())
    {
      rotateArm1.spin(reverse);
      rotateArm2.spin(reverse);
    }
    while(Controller1.ButtonUp.pressing())
    {
      armLift.spin(forward);
    }
    while(Controller1.ButtonDown.pressing())
    {
      armLift.spin(reverse);
    }
    while(Controller1.ButtonL1.pressing())
    {
      claw.spin(forward);
    }
    while(Controller1.ButtonL2.pressing())
    {
      claw.spin(reverse);
    }
    rotateArm1.stop();
    /*
    if(spinForward){
      rotateRangeFinder.spinFor(forward, 20, degrees, false);
      if(rotateRangeFinder.position(degrees) >= 180){
        spinForward = false;
      }
    }
    else{
      rotateRangeFinder.spinFor(reverse, 20, degrees, false);
      if(rotateRangeFinder.position(degrees) < -180){
        spinForward = true;
      }
    }
    values[i][0] = rotateRangeFinder.position(degrees);
    values[i][1] = RangeFinderA.value();
    i++;
    if(i > 17){
      i = 0;
    }

    Brain.Screen.clearLine(0);
    Brain.Screen.clearLine(1);
    Brain.Screen.setCursor(1,1);
    for(int i = 0; i < 9; i++){
      Brain.Screen.print(values[i][1]);
      Brain.Screen.print(",");
    }
    Brain.Screen.setCursor(2,1);
    for(int i = 9; i < 18; i++){
      Brain.Screen.print(values[i][1]);
      Brain.Screen.print(",");
    }
    */
  }
}
