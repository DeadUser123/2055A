 #include "main.h"
#include "api.h"
#include "pros/adi.hpp"
#include "pros/gps.h"
#include "pros/imu.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/optical.hpp"
#include "pros/vision.hpp"
#include "lemlib/api.hpp"

void my_opcontrol()
{
    // pros::rtos::Task my_task(my_task_fn);
    while (true)
    {
        setDriveMotors(); // sets motors based on joystick inputs
        // driveIntake(); // sets intake based on L1 input -- comment this when running colorsort task
        driveClamp();
        doink();
        pros::lcd::set_text(5, "X: "  +  std::to_string(chassis.getPose().x)); // print the x position
        pros::lcd::set_text(6, "Y: " + std::to_string(chassis.getPose().y)); // print the y position
        pros::lcd::set_text(7, "Angle: " + std::to_string(chassis.getPose().theta)); // print the heading
        pros::delay(1);
    }
}

