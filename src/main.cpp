#include "main.h"
#define expansionPiston 'A'

Motor intakeMotor {17,true,okapi::AbstractMotor::gearset::blue,okapi::AbstractMotor::encoderUnits::degrees};
Motor catapultMotor {17,true,okapi::AbstractMotor::gearset::blue,okapi::AbstractMotor::encoderUnits::degrees};

Controller controller;
pros::ADIDigitalOut expansion (expansionPiston);
ControllerButton launchCatapultButton (ControllerDigital::L1);
ControllerButton retractCatapultButton (ControllerDigital::L2);
ControllerButton intakeButton (ControllerDigital::R1);   
ControllerButton reverseIntakeButton (ControllerDigital::R2);  
//ControllerButton rollerButton (ControllerDigital::Y);
//ControllerButton reverseRollerButton (ControllerDigital::B);//may not be needed/wanted
ControllerButton expansionButton (ControllerDigital::up);
ControllerButton expansionFailsafeButton (ControllerDigital::down);

std::shared_ptr<OdomChassisController> drive =
	ChassisControllerBuilder()
		.withMotors({-20, -19}, {11, 12})
		// Green gearset, 4 in wheel diam, 11.5 im wheel track
		// 36 to 60 gear ratio
			//.withGains(
        	//{2, 0, 0}, // Distance controller gains
        	//{.4, 0, 0.2}, // Turn controller gains
        	//{0.001, 0, 0.0001}  // Angle controller gains (helps drive straight)
    		//)
		.withDimensions({AbstractMotor::gearset::blue,(60.0/33.0)},{{3.25_in, 12.25_in}, imev5BlueTPR})
		.withOdometry(StateMode::CARTESIAN)
    	.buildOdometry(); // build an odometry chassis

void on_center_button() {

}

void initialize() {
	
}

void disabled() {}

void competition_initialize() {}

void autonomous() {}

void opcontrol() {
	while (true) {
		drive->getModel()->arcade(controller.getAnalog(ControllerAnalog::leftY),controller.getAnalog(ControllerAnalog::rightX));
		
	}
}
