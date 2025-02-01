#include "main.h"
#include "EZ-Template/api.hpp"
#include "lemlib/api.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
#include "pros/vision.h"
#include "auton.hpp"
// #include "lvgl/lvgl.h"
#include <string>


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}


void color_sort_red_team() {
	double colorvalue;
	while (true) {
		colorvalue = colorsensor.get_hue();
		int distancevalue = distancesensor.get(); // gets currently measured distance in mm
		if (colorvalue >= 45 && colorvalue <= 90) 
		{
			pros::delay(22);
			//pros::lcd::set_text(4, "BLUE RING DETECTED! :(");
			//pros::delay(5);
			// int ticks = intake1.get_position();
			// int newtick = ticks + 5;
			// pros::lcd::set_text(6, "Ticks: " + std::to_string(ticks));
			// pros::lcd::set_text(7, "Newtick: " + std::to_string(newtick));
			// while ((newtick - ticks) > 100) 
			// {
			// 	setIntake(127);
			// 	ticks = intake1.get_position();
			// 	// pros::lcd::set_text(6, "Ticks: " + std::to_string(ticks));
			// 	// pros::lcd::set_text(7, "Newtick: " + std::to_string(newtick));
			// 	pros::lcd::set_text(5, "Error: " + std::to_string(newtick - ticks));
			// 	pros::delay(10);
			// }

			//pros::lcd::set_text(4, "DONE!");
			setIntake(-127);
			pros::delay(180);
			setIntake(127);
		}
	// 	else 
	// 	{
	// 		driveIntake();
	// 	}
	// 	pros::delay(5);
	// }
	}
}


void color_sort_blue_team() {
	double colorvalue;
	while (true) {
		colorvalue = colorsensor.get_hue();
		int distancevalue = distancesensor.get(); // gets currently measured distance in mm
		if (colorvalue >= 0 && colorvalue <= 20) 
		{
			pros::delay(30);
			//pros::lcd::set_text(4, "BLUE RING DETECTED! :(");
			//pros::delay(5);
			// int ticks = intake1.get_position();
			// int newtick = ticks + 5;
			// pros::lcd::set_text(6, "Ticks: " + std::to_string(ticks));
			// pros::lcd::set_text(7, "Newtick: " + std::to_string(newtick));
			// while ((newtick - ticks) > 100) 
			// {
			// 	setIntake(127);
			// 	ticks = intake1.get_position();
			// 	// pros::lcd::set_text(6, "Ticks: " + std::to_string(ticks));
			// 	// pros::lcd::set_text(7, "Newtick: " + std::to_string(newtick));
			// 	pros::lcd::set_text(5, "Error: " + std::to_string(newtick - ticks));
			// 	pros::delay(10);
			// }

			//pros::lcd::set_text(4, "DONE!");
			setIntake(-127);
			pros::delay(180);
			setIntake(127);
		}
	// 	else 
	// 	{
	// 		driveIntake();
	// 	}
	// 	pros::delay(5);
	// }
}}

/**
 * Runs initialization code. This occurs as soon as the	 program is started.
 *
 * All other competition	 modes are blo	cked by initialize; it is recommende	d
 * to keep execution t	i
		if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2))
    {
			while (armsensor.get_position() < 3300)
			{
				arm.move_velocity(-400);
				pros::delay(1);
			}me for this mode under a few seconds.
 */
void initialize() {
	chassis.calibrate();
	pros::lcd::set_text(5, "chassis calibrated");
	pros::lcd::initialize();
	pros::lcd::set_text(4, "pros initialized");
	// imu.reset();
	

	drive_LB.set_brake_mode(MOTOR_BRAKE_HOLD);
	drive_LM.set_brake_mode(MOTOR_BRAKE_HOLD);
	drive_LF.set_brake_mode(MOTOR_BRAKE_HOLD);

    drive_RB.set_brake_mode(MOTOR_BRAKE_HOLD);
	drive_RM.set_brake_mode(MOTOR_BRAKE_HOLD);
    drive_RF.set_brake_mode(MOTOR_BRAKE_HOLD);

	arm.set_brake_mode(MOTOR_BRAKE_HOLD);

	pros::lcd::register_btn1_cb(on_center_button);

	armsensor.set_position(0);
	armsensor.reset_position();

	// lvgl_init();
	armsensor.set_position(0);
	// colorsensor.set_led_pwm(100); // turn on colorsensor LED -- TURN ON for colorsort
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	pros::Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
			pros::lcd::set_text(5, "X: "  +  std::to_string(chassis.getPose().x)); // print the x position
            pros::lcd::set_text(6, "Y: " + std::to_string(chassis.getPose().y)); // print the y position
        	pros::lcd::set_text(7, "Angle: " + std::to_string(chassis.getPose().theta)); // print the heading
			// pros::lcd::set_text(1, "Angle 2: " + std::to_string(imu.get_heading()));
            // delay to save resources
            pros::delay(20);
        }
    });

	//pros::rtos::Task my_task_fn(color_sort_red_team);
	// pros::rtos::Task my_task_fn(color_sort_blue_team);

	// set position to x:0, y:0, heading:0
	//skillsauton();
	// PIDTest();
	//skillsprog(); // 	FOR GATEWAY
	// gatewayRedPosQual(); 
	// gatewayBluePosQual();
	//gatewayRedPosElim();
	//gatewayBluePosElim();
	//gatewayRedMogoRushQual(); // slot 1
	// gatewayBlueMogoRushQual();
	//intake();
	//gatewaytestblueneg();
	//ethanredpositivequal();
	//qual5ringBlue(); // slot 5
	// gatewayblueneg();
	//mogorushblue();
	//qual5ringRed(); //slot 3
	// qualredmogoside(); //slot 1
	// qualbluemogoside(); //slot 2 
	// newskillsprog(); // slot 8
	// soloauton_AWP_Blue_Negative_Sig();
	// mogorushred(); // slot 3
	mogorushblue(); // slot 6
	//testredpos();
	//testbluepos();	
	

// 	Auton selector;
//     switch (selector::auton) {
//         case 1:
// 			soloauton_AWP_Blue_Negative();
//             // Safe 5 Triball Auton
//             // offense_auton_safe();
//             break;

//         case 2:
//             // 
//             // offense_last_min();
//             // offense_auton_midrush_new();
//             break;

//         case 3:
//             // offense_auton_6balls_v2();
//             break;
        
//         case -1:
//             // Safe
//             // defense_awp();
//             break;
        
//         case -2:
//             // Midrush
//             // defense_last_min();
//             break;

//         case -3:
//             // Max Potential
//             // defense_auton_max_potential();
//             break;

//         case 0:
//             prog_skills_new();
//             break;
//     } 
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::lcd::initialize();
	pros::lcd::register_btn0_cb(on_center_button);
	pros::lcd::set_text(5, "Intiailized");

	drive_LB.set_brake_mode(MOTOR_BRAKE_BRAKE);
	drive_LM.set_brake_mode(MOTOR_BRAKE_BRAKE);
    drive_LF.set_brake_mode(MOTOR_BRAKE_BRAKE);

    drive_RB.set_brake_mode(MOTOR_BRAKE_BRAKE);
	drive_RM.set_brake_mode(MOTOR_BRAKE_BRAKE);
    drive_RF.set_brake_mode(MOTOR_BRAKE_BRAKE);
	
	arm.set_brake_mode(MOTOR_BRAKE_HOLD);

	armsensor.set_position(0);
	armsensor.reset_position();

	
	pros::rtos::Task my_task_2(setArmLoadNew);
	pros::rtos::Task my_task(color_sort_blue_team);

	// pros::Task screen_task([&]() {
    //     while (true) {
    //         // print robot location to the brain screen
	// 		pros::lcd::set_text(5, "X: "  +  std::to_string(chassis.getPose().x)); // print the x position
    //         pros::lcd::set_text(6, "Y: " + std::to_string(chassis.getPose().y)); // print the y position
    //     	//pros::lcd::set_text(7, "Angle: " + std::to_string(chassis.getPose().theta)); // print the heading
    //         // delay to save resources
    //         pros::delay(20);
    //     }
    // });

	my_opcontrol();
}
