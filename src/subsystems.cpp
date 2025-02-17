#include "main.h"


//--------------------------------------------------------------------------------------------------
//Clamping Mobile Goal
// -------------------------------------------------------------------------------------------------

// bool clamp_status = true;

// void ClampTilt_Goal () {
//     if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
//         clamp_status = !clamp_status;
//         // clamp_status = true;
//         clamp.set_value(clamp_status);
//         pros::delay(250);
//         tilt.set_value(clamp_status);
//         // clamp.set_value(false);
//     }
// }

bool clampState = false;
void driveClamp()
{
    // if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2))
    // {
        clamp.set_value(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
        //clampState = !clampState;
        //clamp.set_value(clampState);
    //}
}

// void setarm() {
//     if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))
//     {
//         lbgetring(1, 5);
//     }
// }

// ideal position: 1064

int currentAngle;
int error = 1064;
const double kP = 0.06;
const int deadband = 350;
const int targetAngle = 1000;
bool hold;

void setArmLoadNew()
{
    while (true)
    {
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))
        {
            arm.set_brake_mode(MOTOR_BRAKE_HOLD);
            currentAngle = armsensor.get_angle();
            if (30000 <= currentAngle && currentAngle <= 36000) 
            {
                currentAngle = 0 - (36000 - currentAngle);
            }
            error = targetAngle - currentAngle;
            while (abs(error) > deadband)
            {
                currentAngle = armsensor.get_angle();
                if (30000 <= currentAngle && currentAngle <= 36000) 
                {
                    currentAngle = 0 - (36000 - currentAngle);
                }
                error = targetAngle - currentAngle;
                arm.move_velocity(error * kP);
               //pros::lcd::set_text(3, "Target: " + std::to_string(target));
                pros::lcd::set_text(4, "Current Angle: " + std::to_string(currentAngle));
                pros::lcd::set_text(5, "Error: " + std::to_string(error));
                pros::delay(1);
            }
            arm.move_velocity(0);
            // arm.set_brake_mode(MOTOR_BRAKE_HOLD);
            // arm.move_velocity(0);
        }
        else
        {
            // hold arm in place if in loading position
            // if (hold)
            // {
            //     // 100 too fast, 40 too fast, 20 too fast, 10 too fast, 5 too fast, 2 too fast
            //     // this is the velocity at which the arm will move upwards to hold
            //     arm.move_velocity(0);
            // }
            driveArm();
            pros::delay(1);
        }
    }
}

const int numstates = 2;
int states[numstates] = {0, 1000};
int currState = 0;


void setArmLoad1()
{
    while (true)
    {
        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B))
        {
            currState += 1;
            if (currState == 2) {
                currState = 0;
            }
            int target = states[currState];

            arm.set_brake_mode(MOTOR_BRAKE_HOLD);
            currentAngle = armsensor.get_angle();
            if (30000 <= currentAngle && currentAngle <= 36000) 
            {
                currentAngle = 0 - (36000 - currentAngle);
            }
            error = target - currentAngle;
            while (abs(error) > deadband)
            {
                currentAngle = armsensor.get_angle();
                if (30000 <= currentAngle && currentAngle <= 36000) 
                {
                    currentAngle = 0 - (36000 - currentAngle);
                }
                error = target - currentAngle;
                arm.move_velocity(error * kP);
                pros::lcd::set_text(3, "Target: " + std::to_string(currState));
                pros::lcd::set_text(4, "Current Angle: " + std::to_string(currentAngle));
                pros::lcd::set_text(5, "Error: " + std::to_string(error));
                pros::delay(1);
            }
            arm.move_velocity(0);
            // arm.set_brake_mode(MOTOR_BRAKE_HOLD);
            // arm.move_velocity(0);
        }
        else
        {
            driveArm();
            pros::delay(1);
        }
    }
}

void setarm() {
    arm.set_brake_mode(MOTOR_BRAKE_HOLD);
        currentAngle = armsensor.get_angle();
        if (30000 <= currentAngle && currentAngle <= 36000) 
        {
            currentAngle = 0 - (36000 - currentAngle);
        }
        error = targetAngle - currentAngle;
        while (abs(error) > deadband)
        {
            currentAngle = armsensor.get_angle();
            if (30000 <= currentAngle && currentAngle <= 36000) 
            {
                currentAngle = 0 - (36000 - currentAngle);
            }
            error = targetAngle - currentAngle;
            arm.move_velocity(error * kP);
            pros::delay(1);
        }
        arm.move_velocity(0);
    }

bool checkForJam = false;

void setIntake(int power)
{
    intake1.move(power);
    intake2.move(power);
}

// this function is used for turning on the intake when driving
void driveIntake() 
{
    int power = 127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)); // power = 127 if L1 is being pressed, otherwise power = 0
    setIntake(power);
    // int power2 = 110 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2));
    // intake2.move(power2);
}

bool checkforJam()
{
    if (abs(intake1.get_actual_velocity()) > 10)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void fixJam()
{
    setIntake(0);
    pros::delay(250);
    setIntake(127);
}

void antiJamTask()
{
    while (true)
    {
        if (checkForJam)
        {
            if (abs(intake1.get_actual_velocity()) < 10)
            {
                setIntake(0);
                pros::lcd::set_text(2, "JAM DETECTED: MOTOR STOPPED.");
                pros::delay(250);
                setIntake(127);
                pros::lcd::set_text(3, "WAIT COMPLETED: MOTOR SPINNING.");
            }
        }
    pros::delay(100);
    }
}

bool doink_status = false;
void doink() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
        doink_status = !doink_status;
        doinker.set_value(doink_status);
    }
}

// HOLDING L1 RAISES THE ARM, HOLDING L2 LOWERS THE ARM UNTIL YOU LET GO.
void driveArm()
{
    int arm_power = 600 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1));

    if (armsensor.get_angle() > 13500 && armsensor.get_angle() < 30800) {

        if (arm_power > 0)
        {
            arm_power = 0;
        }
    }

    arm.move_velocity(arm_power);

}
    
bool clawState = true;
void driveClaw()
{
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X))
    {
        clawState = !clawState;
        claw.set_value(clawState);
    }
}