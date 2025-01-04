#include "main.h"
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

void gatewayredposqual(){
    //alliance stake
    chassis.setPose(-57.375, -15, 180);
    chassis.moveToPoint(-57.375, 1, 1000, {.forwards=false}, false);
    chassis.turnToHeading(-90, 750, {}, false);
    setDrive(6000, 6000);
    pros::delay(220);
    setDrive(0, 0);
    scoreAllianceStake();   
    chassis.moveToPoint(-38, 0, 750, {.forwards=false}, false);

   //corner rings
    chassis.turnToHeading(-145, 750, {}, false);
    chassis.moveToPoint(-59, -33,  1000, {}, false);
    chassis.turnToHeading(-174, 750, {}, false);
    chassis.moveToPoint(-62, -60,  1000, {}, false);
    doinker.set_value(true);
    chassis.turnToHeading(90, 750, {}, false);
    doinker.set_value(false);
    
    //turn around
    chassis.moveToPoint(-23, chassis.getPose().y, 1000, {}, false);
    chassis.turnToHeading(0, 750, {}, false);
    
    setIntake(115);
    setDrive(6000, 6000);
    pros::delay(300);
    setIntake(0);
    setDrive(-6000, -6000);
    pros::delay(100);
    setDrive(0, 0);

}

void qualredmogoside() { 
    chassis.setPose(-48,-22,270);
    clamp.set_value(true);
    chassis.moveToPose(-20, -21, 270, 1850, {.forwards = false, .maxSpeed = 65}, false);
    pros::delay(1000);
    clamp.set_value(false);
    pros::delay(500);
    setIntake(115);
    pros::delay(500);
    //hjere
    chassis.turnToHeading(180,1000);
    pros::delay(500);
    chassis.moveToPoint(-24,-46,1000,{},false);
    chassis.turnToHeading(0,1000);
    pros::delay(2000);
    for (int i = 0; i < 2; i++)
    {
        setDrive(6000,6000);
        pros::delay(200);
        setDrive(-6000, -6000);
        pros::delay(200);
    } 
    setDrive(0, 0);
    pros::delay(1000);

    //here
    chassis.moveToPoint(-24,10,2000, {.maxSpeed = 50}, false);
    // clamp.set_value(true);
    pros::delay(3000);
    setIntake(0);
}

void gatewayblueposqual(){
    chassis.setPose(57.375, -15, 180);
    chassis.moveToPoint(57.375, 1, 750, {.forwards=false}, false);
    chassis.turnToHeading(90, 750, {}, false);
    
    setDrive(6000, 6000);
    pros::delay(200);
    setDrive(0, 0);
    scoreAllianceStake();
    chassis.moveToPoint(38, 0, 750, {.forwards=false}, false); //move back
    chassis.turnToHeading(150, 750, {}, false);

    chassis.moveToPose(60, -58, 170, 1500, {.forwards = false, .maxSpeed = 65}, false);
    setIntake(127);
    pros::delay(500);
    setIntake(0);
    doinker.set_value(true);
    chassis.turnToHeading(90, 750, {}, false);
    doinker.set_value(false);

}

// // blue positive qual
void qualbluemogoside() {
    chassis.setPose(48,-22,-270);
    clamp.set_value(true);
    chassis.moveToPose(20, -21, -270, 1850, {.forwards = false, .maxSpeed = 65}, false);
    pros::delay(1000);
    //clamp
    clamp.set_value(false);
    pros::delay(500);
    setIntake(115);
    pros::delay(500);
    //me
    chassis.turnToHeading(180,1000);
    pros::delay(500);
    chassis.moveToPoint(24,-49,1000,{},false);
    chassis.turnToHeading(0,1000);
    pros::delay(2000);
    // for (int i = 0; i < 2; i++)
    // {
    //     setDrive(8000, 8000);
    //     pros::delay(200);
    //     setDrive(-8000, -8000);
    //     pros::delay(200);
    // }
    // setDrive(0, 0);
    // pros::delay(1000);
    
    chassis.moveToPoint(24,10,2000, {.maxSpeed = 50}, false);
    // clamp.set_value(true);
    pros::delay(3000);
    setIntake(0);
    //here
}

// // red negative qual
void qual5ringRed()
{
    chassis.setPose(-57.375, 15, 0);
    chassis.moveToPoint(-57.375, -2, 750, {.forwards=false}, false);
    chassis.turnToHeading(-90, 750, {}, false);
    setDrive(6000, 6000);
    pros::delay(200);
    setDrive(0, 0);
    scoreAllianceStake();

    // Get Mobile Goal
    chassis.moveToPoint(chassis.getPose().x + 2, chassis.getPose().y, 500, {.forwards=false}, false);
    chassis.turnToHeading(206, 500, {}, false);
    chassis.moveToPoint(-47, 23, 800, {.forwards=false}, false);
    chassis.turnToHeading(chassis.getPose().theta - 180, 750, {}, false);
    setIntake(127);
    chassis.moveToPose(-21, 51, 40, 1250, {}, false); // pick up ring
    setIntake(0);

    chassis.turnToHeading(5, 500, {}, false); // turn to Mobile Goal
    chassis.moveToPoint(-24, 19, 1750, {.forwards=false, .maxSpeed=80}); // go to Mobile Goal
    chassis.waitUntil(16);
    clamp.set_value(false);
    chassis.waitUntilDone();
    setIntake(127); // score 2nd ring

    chassis.moveToPoint(-21, 39, 750, {}, false);
    chassis.turnToHeading(80, 500, {}, false);
    chassis.moveToPose(-11, 42, 85, 1000, {}, false);
    chassis.moveToPoint(chassis.getPose().x - 6, chassis.getPose().y, 400, {.forwards=false}, false);

    chassis.turnToHeading(-172, 500, {}, false);
    chassis.moveToPoint(-23, 10, 1000, {.minSpeed=60});
    // chassis.turnToHeading(-189, 500, {}, false);

    // setDrive(6000, 6000);
    // arm.move_velocity(600);
    // pros::delay(1000);
    // setDrive(0, 0);
    // arm.move_velocity(0);
}

//qual blue negative
void qual5ringBlue() {   
    chassis.setPose(57.375, 15, 0);
    chassis.moveToPoint(57.375, -2, 750, {.forwards=false}, false);
    chassis.turnToHeading(90, 750, {}, false);
    setDrive(6000, 6000);
    pros::delay(200);
    setDrive(0, 0);
    // can reset here
    // score on alliance wall stake
    scoreAllianceStake();
    // pros::delay(15000);

    // chassis.setPose(51, 24, 90);

    //Get Mobile Goal
    chassis.moveToPoint(chassis.getPose().x - 2, chassis.getPose().y, 500, {.forwards=false}, false); // this should probably be chassis.getPose().x - 2
    chassis.turnToHeading(145, 500, {}, false); //154
    chassis.moveToPoint(47, 23, 800, {.forwards=false}, false);
    //chassis.turnToHeading(chassis.getPose().theta - 180, 750, {}, false);
    chassis.turnToHeading(154 - 180, 750, {}, false);
    setIntake(127);
    chassis.moveToPose(19, 53, -40, 1250, {}, false); // pick up ring
    pros::delay(50);
    setIntake(0);
    
    chassis.turnToHeading(-9, 500, {}, false); // turn to Mobile Goal
    //setIntake(0);
    intake2.move(60);
    chassis.moveToPoint(24, 22, 1750, {.forwards=false, .maxSpeed=80}); // go to Mobile Goal
    // chassis.moveToPose(24, 22, 0, 1750, {.forwards=false, .minSpeed=40}); // go to Mobile Goal
    chassis.waitUntil(24);
    clamp.set_value(false); // clamp Mobile Goal
    chassis.waitUntilDone();
    setIntake(127); // score 2nd ring
    pros::delay(500);

    chassis.moveToPoint(10,32,500,{.maxSpeed=75},false); //move to rings
    pros::delay(200);
    chassis.moveToPose(10,47,1,1500,{.maxSpeed=75},false);
    //chassis.turnToHeading(1,500,{},false);
    pros::delay(300);
    chassis.moveToPose(10,32,-9,500,{},false);
    pros::delay(100);
    chassis.moveToPose(24,12,0,1000,{},false);


    /*
    //chassis.turntoHeading(315, 300, {}, false);
    chassis.moveToPose(10,32,-9,1000, {.maxSpeed=75}, false); //move to mid rings
    pros::delay(1000);
    chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y + 15, 500, {.maxSpeed=75}, true);
    pros::delay(100);
    chassis.turnToHeading(chassis.getPose().theta + 10, 400, {}, false);
    pros::delay(200);
    chassis.moveToPoint(chassis.getPose().x, chassis.getPose().y - 20, 250, {.forwards=false}, true);
    chassis.turnToHeading(chassis.getPose().theta - 90, 250, {}, false);
    chassis.moveToPoint(24,12,300,{.minSpeed=90},false);
    */
    /*
    chassis.moveToPoint(21, 39, 750, {}, false);
    chassis.turnToHeading(-80, 500, {}, false);
    chassis.moveToPose(11, 42, -85, 1000, {}, false);
    chassis.moveToPoint(chassis.getPose().x + 6, chassis.getPose().y, 400, {.forwards=false}, false);
    // chassis.turnToHeading(-171, 500, {}, false);
    chassis.turnToHeading(-188, 500, {}, false);
    // chassis.moveToPose(23, 10, 1000, {.minSpeed=60});
    chassis.moveToPoint(19, 27, 1000, {.minSpeed=60});
    // setDrive(6000, 6000);
    // arm.move_velocity(600);
    // pros::delay(1000);
    // setDrive(0, 0);
    // arm.move_velocity(0);
*/
}


// // Latest version -- last updated Oct 6, 2024
void prog_skills_new()
{
    // Set Position
    chassis.setPose(-56, -7, -90);
    // Turn towards mobile goal
    chassis.turnToHeading(-30, 750, {});
    clamp.set_value(true);
    chassis.waitUntilDone();
    // Move towards & clamp mobile goal
    chassis.moveToPoint(-50, -19, 750, {.forwards=false, .maxSpeed=60}, false);
    chassis.moveToPoint(-48, -23, 500, {.forwards=false});
    chassis.waitUntil(3);
    clamp.set_value(false);
    pros::delay(250);
    setIntake(127); // score preload
    chassis.waitUntilDone();
    // Turn towards ring #2
    chassis.turnToHeading(90, 750, {.maxSpeed=75}, false);
    // Move towards and intake ring #2
    chassis.moveToPoint(-24, -23, 1250, {.maxSpeed=60}, false);
    // Turn towards ring #3
    chassis.turnToHeading(180, 1000, {.maxSpeed=75}, false);
    // Move towards and intake ring #3
    chassis.moveToPoint(-24, -46, 1500, {}, false);
    // Turn towards ring #4
    chassis.turnToHeading(-90, 1200, {.maxSpeed=75}, false);
    // Move towards and intake ring #4
    // chassis.moveToPoint(-44, -46, 1250, {}, false);
    // Move towards and intake ring #5
    chassis.moveToPoint(-58, -46, 2000, {.maxSpeed=80}, false);
    // Turn towards ring #6
    chassis.turnToHeading(-225, 1000, {.maxSpeed=75}, false);
    // Move towards and intake  ring #6
    chassis.moveToPoint(-47, -57, 1250, {}, false);
    // Move to corner and drop Mobile Goal
    chassis.turnToHeading(78, 1000, {.maxSpeed=75}, false);
    chassis.moveToPoint(-53, -58, 750, {.forwards=false}, false);
    clamp.set_value(true);
    pros::delay(250);

    // PART 2
    // Go to mobile goal #2 and clamp it
    chassis.moveToPoint(-48, -57, 1000, {}, false);
    chassis.turnToHeading(180, 1000, {.maxSpeed=75}, false);
    chassis.moveToPoint(-48, 13, 2000, {.forwards=false, .maxSpeed=80}, false);
    // chassis.moveToPoint(-47, 19, 1250, {.forwards=false, .maxSpeed=60}, false);
    chassis.moveToPoint(-48, 27, 1500, {.forwards=false});
    chassis.waitUntil(11);
    // pros::delay(250);
    clamp.set_value(false);
    pros::delay(250);
    chassis.waitUntilDone();
    // Turn to ring #1
    chassis.turnToHeading(97, 1000, {}, false);
    // Move to and intake ring #1
    setIntake(127);
    chassis.moveToPoint(-24, 24, 1250, {}, false);
    // Turn to ring #2
    chassis.turnToHeading(0, 1000, {}, false);
    // Move to and intake ring #2
    chassis.moveToPoint(-24, 45, 1250, {}, false);
    // Turn to ring #3
    chassis.turnToHeading(60, 500, {}, false);
    // Move to and intake ring #3
    chassis.moveToPoint(2, 58, 2000, {}, false);
    // Move to and intake ring #4
    chassis.moveToPoint(-28, 43, 1300, {.forwards=false}, false);
    chassis.turnToHeading(-90, 1000, {}, false);
    // chassis.moveToPoint(-44, 43, 1000, {}, false);
    // Move to and intake ring #5
    chassis.moveToPoint(-58, 43, 2000, {.maxSpeed=80}, false);
    // Turn to ring #6
    chassis.turnToHeading(45, 1000, {}, false);
    // Move to and intake ring #6
    chassis.moveToPoint(-44, 57, 1500, {}, false);
    // Turn to corner
    chassis.turnToHeading(107, 1000, {}, false);
    // Place mobile goal #2 in corner
    chassis.moveToPoint(-52, 59, 1000, {.forwards=false}, false);
    clamp.set_value(true);

    // PART 3
    // Move to and intake ring #1
    chassis.moveToPose(24, 47, 90, 3000, {});
    //chassis.waitUntil(40);
    chassis.waitUntilDone();
    setIntake(0);
    // Move to and clamp mobile goal #3
    chassis.turnToHeading(-30, 1000, {}, false);
    chassis.moveToPoint(39, 13, 1500, {.forwards=false, .maxSpeed=75}, false);
    chassis.moveToPoint(46, -1, 1000, {.forwards=false});
    chassis.waitUntil(8);
    clamp.set_value(false);
    pros::delay(250);
    chassis.waitUntilDone();
    // Move to and intake ring #2
    chassis.turnToHeading(-132, 750, {.maxSpeed=75}, false);
    chassis.moveToPoint(23, -23, 2000, {});
    setIntake(127);
    chassis.waitUntilDone();
    // Move to and intake ring #3
    chassis.turnToHeading(180, 1000, {}, false);
    chassis.moveToPoint(23, -46, 1500, {}, false);
    // Turn to ring #4
    chassis.turnToHeading(90, 1000, {}, false);
    // Move to and intake ring #4
    chassis.moveToPoint(50, -46, 1500, {}, false);
    // Move to and intake ring #5
    chassis.turnToHeading(190, 1000, {.maxSpeed=75}, false);
    chassis.moveToPoint(45, -57, 1250, {}, false);
    // Move to Corner #3
    chassis.turnToHeading(270, 1000, {.maxSpeed=75}, false);
    chassis.moveToPose(56, -55, 315, 1750, {.forwards=false}, false);
    clamp.set_value(true);
    setIntake(0);
    pros::delay(250);
    chassis.moveToPose(43, -23, 0, 2000, {.minSpeed=115}, false); // x, y, angle, timeout
    chassis.moveToPose(53, 10, 20, 2000, {.minSpeed=115}, false); // x, y, angle, timeout
    chassis.moveToPose(61, 80, 0, 2000, {.minSpeed=60}, false); // x, y, angle, timeout
    setDrive(-12000, -12000);
    pros::delay(500);
    setDrive(0, 0);
}


void soloauton_AWP_Blue_Negative_Sig(){
    chassis.setPose(57.375, 15, 0);
    chassis.moveToPoint(57.375, -1, 1000, {.forwards=false}, false);
    chassis.turnToHeading(90, 250, {}, false);
    setDrive(6000, 6000);
    pros::delay(200);
    setDrive(0, 0);
    // can reset here
    // score on alliance wall stake
    scoreAllianceStake();

    //chassis.setPose(58, 0, 90); //reset
    setIntake(127);
    // chassis.moveToPoint(37, 18, 700, {}, false); //abt halfway
    // pros::delay(300);
    // setIntake(0);
    // chassis.waitUntilDone();
    // chassis.turnToPoint(24,24,250, {}, false);
    // pros::delay(200);
    chassis.moveToPose(24,44,0,1500,{},false);
    pros::delay(500);
    setIntake(0);
    chassis.moveToPoint(24, 24, 1500, {.forwards=false, .maxSpeed=65}, true); //mogo1
    chassis.waitUntil(20);
    pros::delay(100);
    clamp.set_value(false);
    pros::delay(50);
    chassis.waitUntilDone();
    setIntake(127);
    pros::delay(100);
    //pros::delay(300);
    // chassis.turnToHeading(0, 300, {}, false);//75
    // pros::delay(200);
    // chassis.moveToPoint(24,44,1000, {}, false); //pikcup ring
    // chassis.moveToPose(24,44,0,1000,{},false);
    //pros::delay(250);

    chassis.turnToHeading(325, 500, {}, false);
    pros::delay(200);
    chassis.moveToPose(11, 44, 300, 1000, {.maxSpeed=75}, false); //pickup rikbgn
    pros::delay(200);
    chassis.moveToPoint(46,44,700, {}, false);
    pros::delay(200);
    chassis.turnToHeading(180,300, {}, false);
    pros::delay(200);
    chassis.moveToPoint(46,-24,2000, {}, false); //switch sies
    //chassis.moveToPoint(45,-24,2400, {.forwards=false, .maxSpeed=90}, false); //switch sides
    pros::delay(100);
    //stop intake, drop gol
    setIntake(0);
    clamp.set_value(true);
    pros::delay(200);
    chassis.turnToPoint(24,-24,700, {.forwards=false, .maxSpeed=90});
    pros::delay(200);
    chassis.moveToPoint(24,-24,1000, {.forwards=false, .maxSpeed=75}, true); //mogo2
    chassis.waitUntil(22);
    clamp.set_value(false);
    pros::delay(50);
    chassis.waitUntilDone();
    pros::delay(100);
    setIntake(127);
    //pros::delay(300);
    chassis.turnToHeading(180,500, {}, false);
    pros::delay(200);
    chassis.moveToPoint(24,-44,700, {.maxSpeed=85}, false);
    pros::delay(400);
    chassis.turnToHeading(0,300, {.maxSpeed=75}, false);
    pros::delay(150);
    //clamp.set_value(true);
    //pros::delay(200);
    //tilt.set_value(true);fx
    chassis.moveToPoint(24,-6,1500, {.minSpeed=90}, false);
}

// /*
// 49, 24, 90
// 36, 24, 90
// 26, 24, 0
// 24, 44, 0
// 45, -24, 340
// 36, -24, 90
// 26, -24, 180
// 24, -44, 180
// 24, -10, 0
// */
void soloauton_AWP_Blue_Negative_L(){
    chassis.setPose(57.375, 15, 0);
    chassis.moveToPoint(57.375, -1, 500, {.forwards=false}, false);
    chassis.turnToHeading(90, 250, {.minSpeed=100}, false);
    setDrive(6000, 6000);
    pros::delay(200);
    setDrive(0, 0);
    // can reset here
    // score on alliance wall stake
    scoreAllianceStake();

    chassis.setPose(58, 0, 90);
    chassis.moveToPoint(37, 18, 700, {.forwards=false}, false);
    chassis.moveToPoint(24, 24, 1000, {.forwards=false, .maxSpeed=65}, true);
    chassis.waitUntil(14);
    pros::delay(100);
    clamp.set_value(false);
    pros::delay(50);
    chassis.waitUntilDone();

    pros::delay(100);
    setIntake(127); 
    pros::delay(300);
    chassis.turnToHeading(0, 300, {.maxSpeed=75}, false);

    pros::delay(200);
    chassis.moveToPoint(24,44,1000, {.maxSpeed=90}, false); //pikcup ring
    pros::delay(250);
    
    chassis.turnToHeading(340,300, {}, false);
    pros::delay(200);
    chassis.moveToPoint(45,-24,2400, {.forwards=false, .maxSpeed=90}, false); //switch sides
    pros::delay(100);
    //stop intake, drop gol
    setIntake(0);
    clamp.set_value(true);
    //pros::delay(100);
    //tilt.set_value(true);
    pros::delay(200);
    //chassis.turnToHeading(90,1000, {}, false);
    chassis.turnToPoint(24,-24,700, {.forwards=false, .maxSpeed=90});
    // pros::delay(300);
    //chassis.moveToPoint(36,-24,1000, {.forwards=false, .maxSpeed=60}, false);
    pros::delay(200);
    //chassis.moveToPoint(26,-24,500, {.forwards=false, .minSpeed=127}, true); //zoom
    chassis.moveToPoint(24,-24,1700, {.forwards=false, .maxSpeed=75}, true);
    chassis.waitUntil(21);
    //pros::delay(500);
    clamp.set_value(false);
    pros::delay(50);
    //tilt.set_value(false);
    //pros::delay(200);
    chassis.waitUntilDone();
    pros::delay(100);
    setIntake(127);
    pros::delay(300);
    chassis.turnToHeading(180,500, {}, false);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(24,-44,700, {.maxSpeed=85}, false);
    pros::delay(400);
    chassis.turnToHeading(0,300, {.maxSpeed=75}, false);
    pros::delay(150);
    //clamp.set_value(true);
    //pros::delay(200);
    //tilt.set_value(true);fx
    chassis.moveToPoint(24,-6,1500, {.minSpeed=90}, false);
}

// /*
// -49, 24, 270
// -36, 24, 270
// -26, 24
// -24, 44, 0
// -45, -24, 20
// -36, -24, 270
// -26, -24, 180
// -24, -44, 180
// -24, -10, 0
// */
void soloauton_AWP_Red_Negative_L(){
    chassis.setPose(-49,26,270);

    chassis.moveToPoint(-24, 24, 2000, {.forwards=false, .maxSpeed=65}, true);
    chassis.waitUntil(25);
    pros::delay(100);
    clamp.set_value(false);
    pros::delay(50);
    chassis.waitUntilDone();

    pros::delay(100);
    setIntake(127); 
    pros::delay(300);
    chassis.turnToHeading(0, 300, {.maxSpeed=75}, false);

    pros::delay(200);
    chassis.moveToPoint(-24,44,1000, {.maxSpeed=90}, false); //pikcup ring
    pros::delay(250);
    //chassis.turnToPoint(45,-24,1000, {}, false);
    //                                                      chassis.turnToHeading(340,700, {.maxSpeed=75}, false);
    chassis.turnToHeading(20,300, {}, false);
    pros::delay(200);
    chassis.moveToPoint(-45,-24,2400, {.forwards=false, .maxSpeed=90}, false); //switch sides
    pros::delay(100);
    //stop intake, drop gol
    setIntake(0);
    clamp.set_value(true);
    //pros::delay(100);
    //tilt.set_value(true);
    pros::delay(200);
    //chassis.turnToHeading(90,1000, {}, false);
    chassis.turnToPoint(24,-24,700, {.forwards=false, .maxSpeed=90});
    // pros::delay(300);
    //chassis.moveToPoint(36,-24,1000, {.forwards=false, .maxSpeed=60}, false);
    pros::delay(200);
    //chassis.moveToPoint(26,-24,500, {.forwards=false, .minSpeed=127}, true); //zoom
    chassis.moveToPoint(-24,-24,1700, {.forwards=false, .maxSpeed=75}, true);
    chassis.waitUntil(21);
    //pros::delay(500);
    clamp.set_value(false);
    pros::delay(50);
    //tilt.set_value(false);
    //pros::delay(200);
    chassis.waitUntilDone();
    pros::delay(100);
    setIntake(127);
    pros::delay(300);
    chassis.turnToHeading(180,500, {}, false);
    chassis.waitUntilDone();
    pros::delay(200);
    chassis.moveToPoint(-24,-44,700, {.maxSpeed=85}, false);
    pros::delay(400);
    chassis.turnToHeading(0,300, {.maxSpeed=75}, false);
    pros::delay(150);
    //clamp.set_value(true);
    //pros::delay(200);
    //tilt.set_value(true);fx
    chassis.moveToPoint(-24,-6,1500, {.minSpeed=90}, false);

}

void mogorushred() {
    chassis.setPose(-46, -57, 90);
    chassis.moveToPoint(-17, -57, 1000, {.minSpeed = 127}, false);
    chassis.turnToHeading(20,800, {}, false);
    doinker.set_value(true);
    pros::delay(280);
    chassis.moveToPose(-44,-56,90,2000, {.forwards=false, .minSpeed = 70}, false);
    pros::delay(100);
    doinker.set_value(false);
    pros::delay(500);
    chassis.turnToHeading(295,1000);
    pros::delay(500);
    chassis.moveToPoint(-18,-60,1000, {.forwards = false},false);
    clamp.set_value(false);
    pros::delay(1000);

    chassis.turnToHeading(315,800, {}, false);
    setIntake(127);
    chassis.moveToPoint(-24,-46, 1000);

    chassis.setPose(-48, -58, 67);
    intake2.move(127);
    chassis.moveToPoint(-20,-45,2000, {.minSpeed = 120}, false);
    
    //fix doinker
    doinker.set_value(true);
    pros::delay(300);

    chassis.moveToPoint(-35,-52,800, {.forwards=false}, false);
    doinker.set_value(false);

    pros::delay(800);
    intake2.move(0);
    chassis.turnToHeading(-100,500, {}, false);
    chassis.moveToPoint(-24,-50,800, {.forwards = false});
    pros::delay(950);
    clamp.set_value(false);
    pros::delay(500);
    setIntake(120);
    pros::delay(750);
    setIntake(0);
    clamp.set_value(true);
    pros::delay(800);

    chassis.turnToHeading(178, 500, {}, false);
    chassis.moveToPose(-24,-46,180,1000,{}, false);
    chassis.moveToPoint(-24,-15,800, {.forwards=false, .maxSpeed = 73}, false);
    // clamp.set_value(false);
    pros::delay(600);
    clamp.set_value(false);
    setIntake(127);


}

void mogorushblue() {

    chassis.setPose(48, -58, -67);
    intake2.move(127);
    chassis.moveToPoint(17,-51,2000, {.minSpeed = 120}, false);
    chassis.turnToHeading(-90,500, {}, false);
    doinker.set_value(true);
    pros::delay(300);

    chassis.moveToPoint(35,-48,800, {.forwards=false}, false);
    doinker.set_value(false);
    pros::delay(800);
    intake2.move(0);
    chassis.turnToHeading(-100,500, {}, false);
    chassis.moveToPoint(-24,-50,800, {.forwards = false});
    pros::delay(950);
    clamp.set_value(false);
    pros::delay(500);
    setIntake(120);
    pros::delay(750);
    setIntake(0);
    clamp.set_value(true);
    pros::delay(800);

    chassis.turnToHeading(178, 500, {}, false);
    chassis.moveToPose(-24,-46,180,1000,{}, false);
    chassis.moveToPoint(-24,-15,800, {.forwards=false, .maxSpeed = 73}, false);
    // clamp.set_value(false);
    pros::delay(600);
    clamp.set_value(false);
    setIntake(127);
}

void newskillsprog() {
    chassis.setPose(-59, 0, 270);
    scoreAllianceStake();
    chassis.moveToPose(-47, 0, 270, 820, {.forwards=false}, false);
    chassis.turnToHeading(0,500);
    chassis.moveToPoint(-47, -25, 2000, {.forwards=false, .maxSpeed=60});
    chassis.waitUntil(22);
    clamp.set_value(false);
    chassis.waitUntilDone();
    setIntake(127);

    // Turn towards ring #2
    chassis.turnToHeading(90, 750, {.maxSpeed=75}, false);
    // Move towards and intake ring #2
    chassis.moveToPoint(-24, -23, 1250, {.maxSpeed=60}, false);
    // Turn towards ring #3
    chassis.turnToHeading(180, 1000, {.maxSpeed=75}, false);
    // Move towards and intake ring #3
    chassis.moveToPoint(-24, -46, 1500, {}, false);
    // Turn towards ring #4
    chassis.turnToHeading(-90, 1200, {.maxSpeed=75}, false);
    // Move towards and intake ring #4
    // chassis.moveToPoint(-44, -46, 1250, {}, false);
    // Move towards and intake ring #5
    chassis.moveToPoint(-58, -46, 2000, {.maxSpeed=80}, false);
    // Turn towards ring #6
    chassis.turnToHeading(-225, 1000, {.maxSpeed=75}, false);
    // Move towards and intake  ring #6
    chassis.moveToPoint(-47, -57, 1250, {}, false);
    // Move to corner and drop Mobile Goal
    chassis.turnToHeading(78, 1000, {.maxSpeed=75}, false);
    chassis.moveToPoint(-55, -58, 1250, {.forwards=false}, false);
    clamp.set_value(true);
    pros::delay(250);

    // PART 2
    // Go to mobile goal #2 and clamp it
    chassis.moveToPoint(-48, -57, 1000, {}, false);
    chassis.turnToHeading(180, 1000, {.maxSpeed=75}, false);
    chassis.moveToPoint(-48, 13, 2000, {.forwards=false, .maxSpeed=80}, false);
    // chassis.moveToPoint(-47, 19, 1250, {.forwards=false, .maxSpeed=60}, false);
    chassis.moveToPoint(-48, 27, 1500, {.forwards=false});
    chassis.waitUntil(11);
    // pros::delay(250);
    clamp.set_value(false);
    pros::delay(250);
    chassis.waitUntilDone();
    // Turn to ring #1
    chassis.turnToHeading(97, 1000, {}, false);
    // Move to and intake ring #1
    setIntake(127);
    chassis.moveToPoint(-24, 24, 1250, {}, false);
    // Turn to ring #2
    chassis.turnToHeading(0, 1000, {}, false);
    // Move to and intake ring #2
    chassis.moveToPoint(-24, 45, 1250, {}, false);
    // Turn to ring #3
    chassis.turnToHeading(60, 500, {}, false);
    // Move to and intake ring #3
    chassis.moveToPoint(2, 58, 2000, {}, false);
    // Move to and intake ring #4
    chassis.moveToPoint(-28, 43, 1300, {.forwards=false}, false);
    chassis.turnToHeading(-90, 1000, {}, false);
    // chassis.moveToPoint(-44, 43, 1000, {}, false);
    // Move to and intake ring #5
    chassis.moveToPoint(-58, 43, 2000, {.maxSpeed=80}, false);
    // Turn to ring #6
    chassis.turnToHeading(45, 1000, {}, false);
    // Move to and intake ring #6
    chassis.moveToPoint(-44, 57, 1500, {}, false);
    // Turn to corner
    chassis.turnToHeading(107, 1000, {}, false);
    // Place mobile goal #2 in corner
    chassis.moveToPoint(-55, 60, 1000, {.forwards=false}, false);
    clamp.set_value(true);

    // PART 3
    // Move to and intake ring #1
    chassis.moveToPose(24, 47, 90, 3000, {});
    //chassis.waitUntil(40);
    chassis.waitUntilDone();
    setIntake(0);
    // Move to and clamp mobile goal #3
    chassis.turnToHeading(-30, 1000, {}, false);
    chassis.moveToPoint(39, 13, 1500, {.forwards=false, .maxSpeed=75}, false);
    chassis.moveToPoint(46, -1, 1000, {.forwards=false});
    chassis.waitUntil(8);
    clamp.set_value(false);
    pros::delay(250);
    chassis.waitUntilDone();
    // Move to and intake ring #2
    chassis.turnToHeading(-132, 750, {.maxSpeed=75}, false);
    chassis.moveToPoint(23, -23, 2000, {});
    setIntake(127);
    chassis.waitUntilDone();
    // Move to and intake ring #3
    chassis.turnToHeading(180, 1000, {}, false);
    chassis.moveToPoint(23, -46, 1500, {}, false);
    // Turn to ring #4
    chassis.turnToHeading(90, 1000, {}, false);
    // Move to and intake ring #4
    chassis.moveToPoint(50, -46, 1500, {}, false);
    // Move to and intake ring #5
    chassis.turnToHeading(190, 1000, {.maxSpeed=75}, false);
    chassis.moveToPoint(45, -57, 1250, {}, false);
    // Move to Corner #3
    chassis.turnToHeading(270, 1000, {.maxSpeed=75}, false);
    chassis.moveToPose(56, -55, 315, 1750, {.forwards=false}, false);
    clamp.set_value(true);
    setIntake(0);
    pros::delay(250);
    chassis.moveToPose(43, -23, 0, 2000, {.minSpeed=115}, false); // x, y, angle, timeout
    chassis.moveToPose(53, 10, 20, 2000, {.minSpeed=115}, false); // x, y, angle, timeout
    chassis.moveToPose(61, 80, 0, 2000, {.minSpeed=60}, false); // x, y, angle, timeout
    setDrive(-12000, -12000);
    pros::delay(500);
    setDrive(0, 0);

    chassis.turnToHeading(90, 400, {}, false);
    setIntake(127);
    chassis.moveToPoint(-24, -22, 800, {}, false);

    chassis.turnToHeading(45, 500, {}, false);
    chassis.moveToPoint(0,1,900, {}, false);
    chassis.turnToHeading(135, 500, {}, false);
    
    // chassis.moveToPoint(24,-23,900, {}, false);
    // chassis.turnToHeading(180, 500);
    // pros::delay(300);
    // chassis.moveToPoint(24,-46,900, {}, true);
    // setarm();
    // pros::delay(800);
    // setIntake(0);
    // intake2.move(127);

    // chassis.moveToPose(0,-58,270, 1000, {}, false);
    
}

// void ethanskills() {
//     chassis.setPose(-57, -1, -90);
//     scoreAllianceStake();
//     chassis.turnToHeading(120, 500)
//     chassis.moveToPoint(-25, 22, 1000)
//     chassis.setIntake(60)
//   
//     chassis.turntoHeading(90, 300)
//     chassis.setPose(-36, 25, 300)
//     chassissetIntake(0)
//     clamp.set_value(false)
//     chassis.setIntake(127)
//     
//     chassis.turntoHeading(45, 200)
//     chassis.setPose(-10,60, 1000)
//     chassis.turntoHeading(20, 100)
//     chassis.setIntake(127)
//     chassis.setPose()
//     
// }

void skillsprog() 
{
    //Get Mobile Goal
    chassis.setPose(-56, 1, 270);
    scoreAllianceStake();
    chassis.moveToPoint(-45.2,1,500, {.forwards = false, .maxSpeed = 120}, true);
    chassis.turnToHeading(180,500, {}, true);
    chassis.moveToPoint(-45.2,28,800, {.forwards = false, .maxSpeed = 55}, false);
    pros::delay(300);
    clamp.set_value(false);
    pros::delay(400);

    //First Goal
    chassis.turnToHeading(90,520, {}, false);
    setIntake(127);
    chassis.moveToPoint(-22,24,500, {}, false);
    chassis.turnToHeading(40, 600, {}, false);
    chassis.moveToPoint(24, 48, 1300, {}, false);
    //chassis.moveToPose(27,51,66,1900,{}, false);

    // //Wall Stake
    pros::delay(600);
    chassis.turnToHeading(300,600,{}, false);
    //pros::delay(300);
    chassis.moveToPoint(1.8,56.7,900, {}, false);
    pros::delay(100);
    setarm();
    // pros::delay(500);
    chassis.turnToHeading(0, 500, {}, false);
    chassis.turnToPoint(0,72,900,{}, false);
    // // setIntake(0);
    //chassis.moveToPoint(1,72,300,{.maxSpeed = 40}, true);
    setDrive(3000,3000);
    pros::delay(200);
    for (int i = 0; i<4; i++)
    {
        setIntake(127);
        pros::delay(200);
        setIntake(-10);
        pros::delay(90);
    }
    pros::delay(200);
    arm.move(127);
    pros::delay(1000);

    chassis.setPose(0,61,chassis.getPose().theta);
    chassis.moveToPoint(0,48,700,{.forwards=false},false);
    arm.move(-127);
    pros::delay(600);
    setIntake(127);
    chassis.turnToHeading(270,500,{},false);
    chassis.moveToPoint(-46,48,1200,{.maxSpeed=95},false);
    pros::delay(200);
    chassis.moveToPoint(-58,48,900,{.maxSpeed=75},false);
    //chassis.setPose(-58,48,chassis.getPose().theta);
    //chassis.setPose(-60,48,270);
    chassis.turnToHeading(43,600,{},false);
    chassis.moveToPoint(-47,61,700);
    pros::delay(100);
    chassis.turnToHeading(115,400);
    chassis.moveToPoint(-57,61,500,{.forwards = false},false);
    pros::delay(900);
    clamp.set_value(true);

    chassis.moveToPoint(-49,57,600,{},true);
    //pros::delay(1000);
    setIntake(0);
    chassis.turnToHeading(0,450,{},false);

    chassis.moveToPoint(-49,-3,1500,{.forwards = false, .minSpeed=120}, false);
    chassis.moveToPoint(-49,-25,800,{.forwards=false, .maxSpeed = 45},false);
    pros::delay(400);
    clamp.set_value(false);
    pros::delay(500);

    chassis.turnToHeading(90,400,{},false);
    setIntake(127);
    chassis.moveToPoint(-22,-20,700,{},false);
    pros::delay(600);
    chassis.turnToHeading(129,400,{},false);
    chassis.moveToPoint(24,-41,1300,{},false);

    chassis.turnToHeading(240,500,{},false);
    chassis.moveToPoint(0,-53,1500,{},false);
    pros::delay(100);
    setarm();
    chassis.turnToHeading(180, 500, {}, false);
    chassis.turnToHeading(180, 500, {}, false);
    //  chassis.turnToPoint(0,-72,900,{}, false);
    setDrive(2000,2000);
    pros::delay(200);
    // for (int i = 0; i<3; i++)
    // {
    //     setIntake(127);
    //     pros::delay(300);
    //     setIntake(0);
    //     pros::delay(90);
    // }
    pros::delay(200);
    arm.move(127);
    pros::delay(1000);
    arm.move(-127);
    pros::delay(900);

    chassis.setPose(0,-58,chassis.getPose().theta);
    chassis.moveToPoint(0,-50,500,{.forwards = false}, false);
    chassis.turnToHeading(270,400);
    chassis.moveToPoint(-47,-50,1000,{.maxSpeed = 83},false);
    pros::delay(500);
    chassis.moveToPoint(-58,-50,1000,{.maxSpeed = 60},false);
    pros::delay(700);
    chassis.turnToHeading(135,500,{},false);
    chassis.moveToPoint(-46,-58,1000,{},false);
    chassis.turnToHeading(80,500,{},false);

    chassis.moveToPoint(-53,-59,700,{.forwards = false}, false);
    clamp.set_value(true);

    chassis.turnToPoint(1,1,500,{},false);
}

void skillsprog2() {
    //Mobile Goal
    chassis.setPose(-58, 1.5, 270);
    scoreAllianceStake();
    chassis.moveToPoint(-47,1.5,500, {.forwards = false, .minSpeed = 127}, true);
    chassis.turnToHeading(180,400, {}, true);
    chassis.moveToPoint(-47,25,600, {.forwards = false, .maxSpeed = 65}, false);
    chassis.waitUntilDone();
    clamp.set_value(false);
    pros::delay(250);

    //First Ring
    setIntake(127);
    chassis.turnToHeading(90,390,{.minSpeed = 120},true);
    chassis.moveToPoint(-26,25,500,{.minSpeed = 127}, false);

    //Second Ring and Wall Stake
    chassis.turnToHeading(55,400,{.minSpeed = 120},false);
    chassis.moveToPoint(24,48,999,{.minSpeed = 120},false);
    //chassis.moveToPose(24,48,90,1300,{},false);
    setarm();
    pros::delay(500);
    chassis.turnToHeading(90,430,{.minSpeed =120},false);
    chassis.moveToPoint(0,48,500,{.forwards = false, .minSpeed = 127},true);
    chassis.turnToHeading(0,390,{.minSpeed = 120}, false);
    setIntake(0);
    intake2.move(600);
    setDrive(3900,3900);
    pros::delay(700);
    scoreWallStake();

    //Four Rings Left
    chassis.setPose(0,61,chassis.getPose().theta);
    chassis.moveToPoint(0,48,500,{.forwards = false, .minSpeed = 127},true);
    setIntake(127);
    chassis.turnToHeading(270,400,{.minSpeed = 120},false);
    chassis.moveToPoint(-25,48,500,{.minSpeed = 120}, true);
    chassis.moveToPoint(-59,48,800,{.maxSpeed = 75}, false);
    chassis.waitUntilDone();
    chassis.turnToHeading(45,399,{.minSpeed = 120}, true);
    chassis.moveToPoint(-45,61,700,{.minSpeed = 115},false);

    //Put Mobile Goal in Corner
    chassis.moveToPoint(-49,58,600,{},false);
    chassis.turnToHeading(90,400,{.minSpeed = 127}, true);
    chassis.moveToPoint(-57,60,500,{.maxSpeed = 85}, false);
    clamp.set_value(true);

    //Second Goal
    chassis.moveToPoint(-47,51,600,{.minSpeed = 127},false);
    chassis.turnToHeading(0,400,{.minSpeed = 120}, false);
    //chassis.moveToPose(-47,51,0,500,{.minSpeed = 127}, false);
    chassis.moveToPoint(-47,22,700,{.maxSpeed = 50},false);
    pros::delay(100);
    clamp.set_value(false);
    pros::delay(300);

    //Get First Ring
    chassis.turnToHeading(90,500,{.minSpeed = 120}, true);
    chassis.moveToPoint(-26,-22,500,{.minSpeed = 127},false);

    //Ring and Wallstake
    chassis.turnToHeading(125,500,{.minSpeed = 110},false);
    chassis.moveToPoint(24,-48,999,{.minSpeed = 120},false);
    //chassis.moveToPose(24,-46,90,1200,{},false);
    setarm();
    pros::delay(500);
    chassis.turnToHeading(90,430,{.minSpeed =120},false);
    chassis.moveToPoint(0,-48,500,{.forwards = false, .minSpeed = 127},true);
    chassis.turnToHeading(180,390,{.minSpeed = 120}, false);
    setIntake(0);
    intake2.move(600);
    setDrive(3900,3900);
    pros::delay(700);
    scoreWallStake();

    //Four Rings Left
    chassis.setPose(0,-61,chassis.getPose().theta);
    chassis.moveToPoint(0,-47,500,{.forwards = false, .minSpeed = 127},true);
    setIntake(127);
    chassis.turnToHeading(270,400,{.minSpeed = 120},false);
    chassis.moveToPoint(-25,-47,500,{.minSpeed = 120}, true);
    chassis.moveToPoint(-59,-47,800,{.maxSpeed = 75}, false);
    chassis.waitUntilDone();
    chassis.turnToHeading(135,399,{.minSpeed = 120}, true);
    chassis.moveToPoint(-52,-54,700,{.minSpeed = 115},false);
    pros::delay(500);

    //Put Goal in Corner
    chassis.turnToHeading(45,500,{.minSpeed = 100}, false);
    chassis.moveToPoint(-56,-57,600,{.forwards = false, .maxSpeed = 40}, false);
    clamp.set_value(true);

    //Middle Ring
    chassis.turnToPoint(1,1,390,{},false);


}