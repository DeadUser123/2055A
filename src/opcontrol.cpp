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
// #include "globals.cpp"

void my_opcontrol()
{
    // pros::rtos::Task my_task(my_task_fn);
    while (true)
    {
        // if (receiver.connected()){pros::lcd::set_text(1, "Connected + " + receiveMessage()); } else {pros::lcd::set_text(1, "Not connected, receiver");}
        if (transmitter.connected()){pros::lcd::set_text(1, "Connected, Transmitting");transmitMessage("the answer is alwasy 42.3 lol");} else {pros::lcd::set_text(1, "Not connected, am transmitter");}

        setDriveMotors(); // sets motors based on joystick inputs
        driveIntake(); // sets intake based on L1 input -- comment this when running colorsort task
        driveClamp();
        doink();
        hang();
        // istherearobot();
        // pros::lcd::set_text(5, "X: "  +  std::to_string(chassis.getPose().x)); // print the x position
        // pros::lcd::set_text(6, "Y: " + std::to_string(chassis.getPose().y)); // print the y position
        // pros::lcd::set_text(7, "Angle: " + std::to_string(chassis.getPose().theta)); // print the heading
        pros::lcd::set_text(5,"d: "+std::to_string(distancesensor.get()));
        // pros::lcd::set_text(6,"confidence: "+std::to_string(distancesensor.get_confidence()));
        // pros::lcd::set_text(7,"size: "+std::to_string(distancesensor.get_object_size()));
        pros::lcd::set_text(6,"velocity: "+std::to_string(distancesensor.get_object_velocity()));

        // if (istherearobot()==false) {
        //     pros::lcd::set_text(7,":)");
        // }
        // else if (istherearobot()==true) {
        //     pros::lcd::set_text(7,"smth");
        // }

        // if (distancesensor.get_object_velocity()<0.09) {
        //     pros::lcd::set_text(7,":)");
        // }
        // else if (distancesensor.get_object_velocity()>0.09) {
        //     pros::lcd::set_text(1,"......................................................................................");
        //     pros::lcd::set_text(2,"........................................................................................");
        //     // pros::lcd::set_text(3,"");
        //     // pros::lcd::set_text(4,"");
        //     pros::lcd::set_text(5,"........................................................................................");
        //     pros::lcd::set_text(6,"........................................................................................");
        //     pros::lcd::set_text(7,"........................................................................................");

        // }

        // pros::lcd::set_text(5,"x: "+std::to_string(gpssensor.get_position_x()));
        // pros::lcd::set_text(6,"y: "+std::to_string(gpssensor.get_position_y()));
        // pros::screen::print(TEXT_MEDIUM, 1, "X Position: %3f", gpssensor.get_position_x());
        // pros::screen::print(TEXT_MEDIUM, 2, "Y Position: %3f", gpssensor.get_position_y());

        pros::delay(1);
    }
}

