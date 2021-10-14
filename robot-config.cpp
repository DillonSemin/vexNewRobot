#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor frontR = motor(PORT10, ratio18_1, true);
motor frontL = motor(PORT1, ratio18_1, false);
motor middleR = motor(PORT8, ratio18_1, true);
motor middleL = motor(PORT3, ratio18_1, false);
motor backR = motor(PORT9, ratio18_1, true);
motor backL = motor(PORT2, ratio18_1, false);
controller Controller1 = controller(primary);
sonar RangeFinderA = sonar(Brain.ThreeWirePort.A);
motor rotateArm1 = motor(PORT4, ratio18_1, false);
motor rotateArm2 = motor(PORT5, ratio18_1, true);
motor armLift = motor(PORT6, ratio18_1, false);
motor claw = motor(PORT7, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}