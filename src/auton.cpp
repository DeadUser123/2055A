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

/*
PUT GATEWAY AUTONS BELOW THIS
*/

void gatewayRedPosQual(){
    clamp.set_value(true);
    chassis.setPose(-57.375, -15, 180);
    chassis.moveToPoint(-57.375, 2, 1200, {.forwards=false}, false);
    chassis.turnToHeading(-90, 800, {}, false);
    setDrive(6000, 6000);
    pros::delay(400);
    setDrive(0, 0);
    scoreAllianceStake();
    chassis.moveToPoint(-57.375, 2, 1000, {.forwards=false}, false); // go back
    chassis.turnToHeading(180, 1000, {}, false); 
    chassis.moveToPoint(-57.375, -23, 1500, {}, false);
    chassis.turnToHeading(-90, 750, {}, false);
    chassis.moveToPoint(-23, -23, 2500, {.forwards=false, .maxSpeed=60}, true);
    chassis.waitUntil(30);
    clamp.set_value(false); // clamp mogo
    chassis.waitUntilDone(); 
    pros::delay(100);
    chassis.turnToHeading(180, 750, {}, false);
    setIntake(127);
    chassis.moveToPoint(-23, -50, 2000, {}, false);
    pros::delay(250);
    chassis.turnToHeading(0, 1000, {.maxSpeed=65}, false);
    chassis.moveToPoint(-23, 10, 3000, {.maxSpeed=70}, true);
    chassis.waitUntil(13);
    // arm.move_velocity(12000);
    setIntake(0);
    chassis.waitUntilDone();
    // arm.move_velocity(0);
//     //alliance stake
//     clamp.set_value(true);
//     chassis.setPose(-57.375, -15, 180);
//     chassis.moveToPoint(-57.375, 1, 1000, {.forwards=false}, false);
//     chassis.turnToHeading(-90, 750, {}, false);
//     setDrive(6000, 6000);
//     pros::delay(220);
//     setDrive(0, 0);
//     scoreAllianceStake();   
//     chassis.moveToPoint(-44, 0, 750, {.forwards=false}, false);

// //ring1
//     chassis.turnToHeading(-40, 750, {}, false);
//     chassis.moveToPoint(-22, -24, 1300, {.forwards=false, .maxSpeed = 50}, false);
//     pros::delay(50);
//     clamp.set_value(false);
//     pros::delay(150);
//     chassis.turnToHeading(180, 750, {}, false);
//     setIntake(127);
//     chassis.moveToPoint(-22.5, -49, 600, {.forwards=true}, false);
//     pros::delay(500);

//     chassis.turnToHeading(113, 700, {}, false);
//     setIntake(0);
//     chassis.moveToPoint(-59, -33, 750, {.forwards=false}, false);

// //to clear corner
//     chassis.turnToHeading(-167, 750, {}, false);
//     chassis.moveToPoint(-60, -53,  1000, {}, false);
//     doinker.set_value(true);
//     pros::delay(500);

// //corner clear
//     chassis.turnToHeading(78, 700, {}, false);
//     doinker.set_value(false);
//     chassis.moveToPoint(-30, -47, 1000, {}, false);
//     chassis.turnToHeading(0, 750, {}, false);
//     arm.move_velocity(600);
//     chassis.moveToPoint(-23, 1, 1000, {.forwards=true}, false);
}

void gatewayBluePosQual(){
    clamp.set_value(true);
    chassis.setPose(57.375, -15, 180);
    chassis.moveToPoint(57.375, 2, 1200, {.forwards=false}, false);
    chassis.turnToHeading(90, 800, {}, false);
    setDrive(6000, 6000);
    pros::delay(400);
    setDrive(0, 0);
    scoreAllianceStake();
    chassis.moveToPoint(57.375, 2, 90, {.forwards=false}, false); // go back
    chassis.turnToHeading(180, 750, {}, false); 
    chassis.moveToPoint(57.375, -23, 1500, {}, false);
    chassis.turnToHeading(90, 750, {}, false);
    chassis.moveToPoint(23, -23, 2500, {.forwards=false, .maxSpeed=60}, true);
    chassis.waitUntil(30);
    clamp.set_value(false); // clamp mogo
    chassis.waitUntilDone(); 
    pros::delay(100);
    chassis.turnToHeading(180, 750, {}, false);
    setIntake(127);
    chassis.moveToPoint(27, -50, 2000, {.maxSpeed=75}, false);
    pros::delay(1000);
    chassis.turnToHeading(0, 1000, {}, false);
    chassis.moveToPoint(23, 10, 3000, {.maxSpeed=60}, false);
    setIntake(0);

    // chassis.moveToPoint(44, 0, 750, {.forwards=false}, false);

    // chassis.turnToHeading(40, 760, {}, false);
    // chassis.moveToPoint(23, -24, 1400, {.forwards=false, .maxSpeed = 50}, false);
    // pros::delay(100);
    // clamp.set_value(false);
    // pros::delay(150);
    // chassis.turnToHeading(180, 750, {}, false);
    // setIntake(127);
    // chassis.moveToPoint(23, -52, 1000, {.forwards=true, .maxSpeed=70}, false);
    // pros::delay(800);
    // arm.move_velocity(600);
    // chassis.moveToPoint(chassis.getPose().x, 0, 1300, {.forwards=false}, false);
    // setIntake(0);

    //

    // chassis.setPose(57.375, -15, 180);
    // chassis.moveToPoint(57.375, 1, 750, {.forwards=false}, false);
    // chassis.turnToHeading(90, 750, {}, false);
    
    // setDrive(6000, 6000);
    // pros::delay(200);
    // setDrive(0, 0);
    // scoreAllianceStake();
    // chassis.moveToPoint(38, 0, 750, {.forwards=false}, false); //move back
    // chassis.turnToHeading(150, 750, {}, false);

    // chassis.moveToPose(60, -58, 170, 1500, {.forwards = false, .maxSpeed = 65}, false);
    // setIntake(127);
    // pros::delay(500);
    // setIntake(0);
    // doinker.set_value(true);
    // chassis.turnToHeading(90, 750, {}, false);
    // doinker.set_value(false);

}

void gatewayRedMogoRushQual()
{
    // chassis.setPose(-49, -60, 90);
    // chassis.moveToPose(-12, -60, 90, 1250);
    // chassis.turnToHeading(30, 750);
    // pros::delay(500);
    // doinker.set_value(true);
    chassis.setPose(-54, -60, 60);
    setIntake(127);
    chassis.moveToPoint(-16, -46, 1250,  {}, false); // rush to middle mogo
    setIntake(0);
    chassis.turnToHeading(50, 250, {}, false);
    doinker.set_value(true); // clamp it with doinker
    pros::delay(250);
    chassis.moveToPoint(-35, -56, 1000, {.forwards=false}, false); // move mogo backwards
    doinker.set_value(false); // let go of mogo
    pros::delay(250); 
    chassis.turnToHeading(90, 500, {}, false);
    setDrive(-12000, -12000);
    pros::delay(200);
    setDrive(0, 0);
    chassis.turnToHeading(-90, 1000, {}, false);
    setDrive(-6000, -6000); // clamp mogo
    pros::delay(1000);
    clamp.set_value(false);
    pros::delay(100);
    setDrive(0, 0);
    pros::delay(100);
    setIntake(127);
    pros::delay(250);
    chassis.moveToPose(-61, -55, -90, 2500, {}, true); // move towards pre-load ring
    chassis.waitUntil(48);
    setIntake(0);
    chassis.waitUntilDone();
    chassis.setPose(-61, chassis.getPose().y, chassis.getPose().theta); // reset position
    setDrive(-12000, -12000);
    pros::delay(300); 
    setDrive(0, 0);
    chassis.turnToHeading(90, 1000, {}, false);
    clamp.set_value(true);
    pros::delay(250);
    chassis.moveToPoint(-41, -55, 1250, {.maxSpeed=75}, false); // go towards mobile goal
    chassis.turnToHeading(180, 1000, {}, false);
    chassis.moveToPoint(-41, -23, 1500, {.forwards=false, .maxSpeed=70}, false);
    clamp.set_value(false); // clamp mobile goal
    pros::delay(250);
    chassis.turnToHeading(0, 750, {}, false); // turn towards ladder
    setIntake(127);
    pros::delay(500);
    chassis.moveToPoint(-41, 10, 2000, {.maxSpeed=60}, false); // touch ladder
    setIntake(0);
}

void gatewayBlueMogoRushQual()
{
    chassis.setPose(54, -60, -60);
    setIntake(127);
    chassis.moveToPoint(16, -46, 1500, {}, false); // rush to middle mogo
    setIntake(0);
    chassis.turnToHeading(-107, 500, {}, false);
    doinker.set_value(true); // grab it with doinker
    pros::delay(250);
    chassis.moveToPoint(36, -42, 1000, {.forwards=false}, false);
    doinker.set_value(false); // let go of mogo
    pros::delay(250);
    chassis.turnToHeading(90, 1000, {.direction=AngularDirection::CCW_COUNTERCLOCKWISE}, false);
    setDrive(-6000, -6000);
    pros::delay(600);
    clamp.set_value(false); // clamp mogo
    pros::delay(100);
    setDrive(0, 0);
    setIntake(127);
    chassis.moveToPose(61, -55, 90, 2000, {}, true); // pick up preload ring
    chassis.waitUntil(45); // may need to change
    setIntake(0);
    chassis.waitUntilDone();
    setDrive(-12000, -12000);
    pros::delay(300); 
    setDrive(0, 0);
    chassis.turnToHeading(-90, 1000, {}, false);
    clamp.set_value(true); // let go of mogo
    pros::delay(250);
    chassis.moveToPoint(23, -55, 1000, {}, false);
    chassis.turnToHeading(180, 750, {}, false);
    chassis.moveToPoint(23, -26, 1500, {}, false);
    clamp.set_value(false); // clamp mogo
    pros::delay(250);
    setIntake(127);
    pros::delay(250);
    chassis.turnToHeading(0, 1000, {}, false);
    chassis.moveToPoint(23, 10, 2000, {}, false); // touch ladder
    setIntake(0);
}

// put red negative qual here:

// put blue negative qual here:
/*
void gatewayRedSoloAWP()
{

}

void gatewayBlueSoloAWP()
{

}
*/
void gatewayRedPosElim()
{   
    clamp.set_value(true);
    chassis.setPose(-57.375, -15, 180);
    chassis.moveToPoint(-57.375, 1, 1000, {.forwards=false}, false);
    chassis.turnToHeading(-90, 750, {}, false);
    setDrive(6000, 6000);
    pros::delay(220);
    setDrive(0, 0);
    scoreAllianceStake();  
    chassis.turnToHeading(120, 900, {}, false);
    setIntake(80);
    chassis.moveToPoint(-46,-7, 1200, {}, false);
    pros::delay(100);
    setIntake(0);
    pros::delay(200);
    chassis.turnToHeading(305, 900, {}, false);
    chassis.moveToPoint(-24,-24, 1200, {.forwards=false}, false);
    clamp.set_value(false);
    pros::delay(400);
    setIntake(127);
    chassis.turnToHeading(-180, 800,{}, false);
    chassis.moveToPoint(-24,-52, 1000, {}, false);
    chassis.turnToHeading(320, 750,{}, false);
    chassis.moveToPoint(-52,-25, 1000, {}, false);
    chassis.turnToHeading(195, 700, {}, false);
    chassis.moveToPoint(-58,-48, 1000, {}, false);
    doinker.set_value(true);
    chassis.turnToHeading(200, 750, {}, false);


        // chassis.moveToPoint(-52,-34, 1000, {}, false);
        // chassis.turnToHeading(-160, 500,{}, false);
        // chassis.moveToPoint(-58,-46, 500,{}, false);
        // doinker.set_value(true);
        // chassis.turnToHeading(200,500, {}, false);
       


//        
//         clamp.set_value(false);
//         pros::delay(220);
    //     chassis.moveToPoint(-42, 0, 750, {.forwards=false}, false);


    // //corner rings
    //     chassis.turnToHeading(-150, 750, {}, false);
    //     chassis.moveToPoint(-59, -33,  1000, {}, false);
    //     chassis.turnToHeading(-167, 750, {}, false);    
    //     chassis.moveToPoint(-62, -54,  1000, {}, false);
    //     doinker.set_value(true);
    //     pros::delay(450);


    //     //to pick up
    //     chassis.turnToHeading(77.5, 750, {}, false);
    //     doinker.set_value(false);
    //         //pick up ring
    //     setIntake(127);
    //     chassis.moveToPoint(-30, -47, 1000, {}, false);
    //     pros::delay(500);
    //     setIntake(0);
    //     chassis.turnToHeading(180, 750, {}, false);
       
        // chassis.moveToPoint(-30, -26, 1000, {.forwards=false, .maxSpeed = 50}, false);
        // clamp.set_value(false);
        // setIntake(135);

}

void gatewayBluePosElim()
{
    clamp.set_value(true);
    chassis.setPose(57.375, -15, 180);
    // chassis.moveToPoint(57.375, 2, 1200, {.forwards=false}, false);
    // chassis.turnToHeading(90, 800, {}, false);
    // setDrive(6000, 6000);
    // pros::delay(400);
    // setDrive(0, 0);
    // scoreAllianceStake();
    // chassis.moveToPoint(57.375, 2, 90, {.forwards=false}, false); // go back
    // chassis.turnToHeading(180, 750, {}, false); 
    chassis.moveToPoint(57.375, -23, 1500, {}, false);
    chassis.turnToHeading(90, 750, {}, false);
    chassis.moveToPoint(23, -23, 2500, {.forwards=false, .maxSpeed=60}, true);
    chassis.waitUntil(30);
    clamp.set_value(false); // clamp mogo
    chassis.waitUntilDone(); 
    pros::delay(100);
    chassis.turnToHeading(180, 750, {}, false);
    setIntake(127);
    chassis.moveToPoint(27, -46, 2000, {.maxSpeed=75}, false);
    pros::delay(1000);
    chassis.turnToHeading(0, 1000, {}, false);
    chassis.moveToPoint(23, 10, 3000, {.maxSpeed=60}, true);
    chassis.waitUntil(10);
    setIntake(0);
    chassis.waitUntilDone();
}

void gatewayRedMogoRushElim()
{
    chassis.setPose(-54, -60, 60);
    setIntake(127);
    chassis.moveToPoint(-16, -46, 1250,  {}, false); // rush to middle mogo
    setIntake(0);
    chassis.turnToHeading(50, 250, {}, false);
    doinker.set_value(true); // clamp it with doinker
    pros::delay(250);
    chassis.moveToPoint(-35, -56, 1000, {.forwards=false}, false); // move mogo backwards
    doinker.set_value(false); // let go of mogo
    pros::delay(250); 
    chassis.turnToHeading(90, 500, {}, false);
    setDrive(-12000, -12000);
    pros::delay(200);
    setDrive(0, 0);
    chassis.turnToHeading(-90, 1000, {}, false);
    setDrive(-6000, -6000); // clamp mogo
    pros::delay(1000);
    clamp.set_value(false);
    pros::delay(100);
    setDrive(0, 0);
    pros::delay(100);
    setIntake(127);
    pros::delay(250);
    chassis.moveToPose(-61, -55, -90, 2500, {}, true); // move towards pre-load ring
    chassis.waitUntil(48);
    setIntake(0);
    chassis.waitUntilDone();
    chassis.setPose(-61, chassis.getPose().y, chassis.getPose().theta); // reset position
    setDrive(-12000, -12000);
    pros::delay(300); 
    setDrive(0, 0);
    chassis.turnToHeading(90, 1000, {}, false);
    clamp.set_value(true);
    pros::delay(250);
    chassis.moveToPoint(-41, -55, 1250, {.maxSpeed=75}, false); // go towards mobile goal
    chassis.turnToHeading(180, 1000, {}, false);
    chassis.moveToPoint(-41, -23, 1500, {.forwards=false, .maxSpeed=70}, false);
    clamp.set_value(false); // clamp mobile goal
    pros::delay(250);
    chassis.turnToHeading(0, 750, {}, false); // turn towards ladder
    setIntake(127);
    pros::delay(500);
    chassis.moveToPoint(-41, 10, 2000, {}, false); // touch ladder
    setIntake(0);
}

void gatewayBlueMogoRushElim()
{

}

void gatewayRedNegElim()
{

}

void gatewayBlueNegElim()
{

}

// put skills here:



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

// red negative qual
void qual5ringRed()
{
    chassis.setPose(-57.375, 15, 0);
    chassis.moveToPoint(-57.375, -2, 750, {.forwards=false}, false);
    chassis.turnToHeading(270, 750, {}, false);
    setDrive(6000, 6000);
    pros::delay(185);
    setDrive(0, 0);
    scoreAllianceStake();

    //Get Mobile Goal
    chassis.moveToPoint(chassis.getPose().x + 6, chassis.getPose().y, 500, {.forwards=false}, false); // this should probably be chassis.getPose().x - 2
    chassis.turnToHeading(180-154, 750, {}, false);
    setIntake(127);
    chassis.moveToPoint(-35,13,750,{},false);
    pros::delay(200);
    setIntake(0);
    chassis.turnToHeading(235,750,{},false);
    pros::delay(50);

    chassis.moveToPoint(-24, 23, 1000, {.forwards=false, .maxSpeed=60}); // go to Mobile Goal
    chassis.waitUntil(15);
    clamp.set_value(false); // clamp Mobile Goal
    chassis.waitUntilDone();
    setIntake(127); // score 2nd ring
    pros::delay(500);

    chassis.moveToPose(-9,60,359,2500,{.maxSpeed=80},false); //speed added recently, test and see if it works
    pros::delay(300);
    chassis.moveToPoint(-24, 23, 1000, {.forwards=false}); //go back
    pros::delay(100);
    chassis.moveToPoint(-35,55,1000,{},false); //last ring
    
    pros::delay(250);
    chassis.moveToPoint(14,18,225,{},false);
    arm.move_velocity(600);
    pros::delay(400);
}

//qual blue negative
void qual5ringBlue() {  
    chassis.setPose(57.375, 15, 0);
    chassis.moveToPoint(57.375, -2, 750, {.forwards=false}, false);
    chassis.turnToHeading(90, 750, {}, false);
    setDrive(6000, 6000);
    pros::delay(175);
    setDrive(0, 0);
    // can reset here
    // score on alliance wall stake
    scoreAllianceStake();
    // pros::delay(15000);

    // chassis.setPose(51, 24, 90);

    //Get Mobile Goal
    chassis.moveToPoint(chassis.getPose().x - 6, chassis.getPose().y, 500, {.forwards=false}, false); // this should probably be chassis.getPose().x - 2
    //chassis.turnToHeading(145, 500, {}, false); //154
    //chassis.moveToPoint(47, 23, 800, {.forwards=false}, false);
    //chassis.turnToHeading(chassis.getPose().theta - 180, 750, {}, false);
    chassis.turnToHeading(154 - 190, 750, {}, false);
    setIntake(127);
    chassis.moveToPoint(38,13,1000,{},false);
    pros::delay(100);
    setIntake(0);
    chassis.turnToHeading(125,750,{},false);
    //chassis.moveToPose(19, 53, -40, 1250, {}, false); // pick up ring
    pros::delay(50);
    //setIntake(0);
    
    //chassis.turnToHeading(-9, 500, {}, false); // turn to Mobile Goal
    //intake2.move(60);
    // chassis.moveToPoint(24, 23, 1000, {.forwards=false, .maxSpeed=70}); // go to Mobile Goal
    // // chassis.moveToPose(24, 22, 0, 1750, {.forwards=false, .minSpeed=40}); // go to Mobile Goal
    // chassis.waitUntil(15);
    // clamp.set_value(false); // clamp Mobile Goal
    // chassis.waitUntilDone();
    // setIntake(127); // score 2nd ring
    // pros::delay(500);

    // //chassis.moveToPose(14,29,-9,500,{.maxSpeed=75},false); //move to rings
    // //pros::delay(200);
    // chassis.turnToHeading(315,500,{},false);
    // pros::delay(200);
    // chassis.moveToPose(7,62,1,2500,{.maxSpeed=80},false); //speed added recently, test and see if it works
    // //chassis.turnToHeading(1,500,{},false);
    // //pros::delay(15000);
    // pros::delay(300);
    // //chassis.moveToPose(12,35,-12,1000,{.forwards=false},false);
    // chassis.moveToPoint(24, 23, 1000, {.forwards=false});
    // pros::delay(100);
    // chassis.moveToPoint(35,55,1000,{},false);
    
    // pros::delay(250);
    // //chassis.moveToPoint(18,12,2000,{.maxSpeed=75},false);
    // chassis.moveToPoint(25,0,2000,{.maxSpeed=60},false);
    // arm.move_velocity(600);
    // pros::delay(400);
    

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
   //Mobile Goal
    chassis.setPose(-58, 1.5, 270);
    scoreAllianceStake();
    chassis.moveToPoint(-47,1.5,500, {.forwards = false, .minSpeed = 127}, true);
    chassis.turnToHeading(180,400, {}, true);
    chassis.moveToPoint(-47,26,1000, {.forwards = false, .maxSpeed = 55}, false);
    chassis.waitUntilDone();
    pros::delay(250);
    clamp.set_value(false);
    pros::delay(250);

    //First Ring
    setIntake(127);
    chassis.setPose(-47,26,180);
    pros::delay(7000);
    chassis.turnToHeading(90,900,{},false);
    pros::delay(200);
    chassis.moveToPoint(-24,26,600,{.minSpeed = 127}, false);

    //Second Ring and Wall Stake
    chassis.turnToHeading(55,400,{},false);
    chassis.moveToPoint(24,48,999,{.minSpeed = 120},false);
    setarm();
    pros::delay(500);
    chassis.turnToHeading(90,430,{.minSpeed =120},false);
    chassis.moveToPoint(0,48,500,{.forwards = false, .minSpeed = 127},true);
    // chassis.turnToHeading(0,390,{.minSpeed = 120}, false);
    // setIntake(0);
    // intake2.move(600);
    // setDrive(3900,3900);
    // pros::delay(700);
    // scoreWallStake();

    // //Four Rings Left
    // chassis.setPose(0,61,chassis.getPose().theta);
    // chassis.moveToPoint(0,48,500,{.forwards = false, .minSpeed = 127},true);
    // setIntake(127);
    // chassis.turnToHeading(270,400,{.minSpeed = 120},false);
    // chassis.moveToPoint(-25,48,500,{.minSpeed = 120}, true);
    // chassis.moveToPoint(-59,48,800,{.maxSpeed = 75}, false);
    // chassis.waitUntilDone();
    // chassis.turnToHeading(45,399,{.minSpeed = 120}, true);
    // chassis.moveToPoint(-45,61,700,{.minSpeed = 115},false);

    // //Put Mobile Goal in Corner
    // chassis.moveToPoint(-49,58,600,{},false);
    // chassis.turnToHeading(90,400,{.minSpeed = 127}, true);
    // chassis.moveToPoint(-57,60,500,{.maxSpeed = 85}, false);
    // clamp.set_value(true);

    // //Second Goal
    // chassis.moveToPoint(-47,51,600,{.minSpeed = 127},false);
    // chassis.turnToHeading(0,400,{.minSpeed = 120}, false);
    // //chassis.moveToPose(-47,51,0,500,{.minSpeed = 127}, false);
    // chassis.moveToPoint(-47,22,700,{.maxSpeed = 50},false);
    // pros::delay(100);
    // clamp.set_value(false);
    // pros::delay(300);

    // //Get First Ring
    // chassis.turnToHeading(90,500,{.minSpeed = 120}, true);
    // chassis.moveToPoint(-26,-22,500,{.minSpeed = 127},false);

    // //Ring and Wallstake
    // chassis.turnToHeading(125,500,{.minSpeed = 110},false);
    // chassis.moveToPoint(24,-48,999,{.minSpeed = 120},false);
    // //chassis.moveToPose(24,-46,90,1200,{},false);
    // setarm();
    // pros::delay(500);
    // chassis.turnToHeading(90,430,{.minSpeed =120},false);
    // chassis.moveToPoint(0,-48,500,{.forwards = false, .minSpeed = 127},true);
    // chassis.turnToHeading(180,390,{.minSpeed = 120}, false);
    // setIntake(0);
    // intake2.move(600);
    // setDrive(3900,3900);
    // pros::delay(700);
    // scoreWallStake();

    // //Four Rings Left
    // chassis.setPose(0,-61,chassis.getPose().theta);
    // chassis.moveToPoint(0,-47,500,{.forwards = false, .minSpeed = 127},true);
    // setIntake(127);
    // chassis.turnToHeading(270,400,{.minSpeed = 120},false);
    // chassis.moveToPoint(-25,-47,500,{.minSpeed = 120}, true);
    // chassis.moveToPoint(-59,-47,800,{.maxSpeed = 75}, false);
    // chassis.waitUntilDone();
    // chassis.turnToHeading(135,399,{.minSpeed = 120}, true);
    // chassis.moveToPoint(-52,-54,700,{.minSpeed = 115},false);
    // pros::delay(500);

    // //Put Goal in Corner
    // chassis.turnToHeading(45,500,{.minSpeed = 100}, false);
    // chassis.moveToPoint(-56,-57,600,{.forwards = false, .maxSpeed = 40}, false);
    // clamp.set_value(true);

    // //Middle Ring
    // chassis.turnToPoint(1,1,390,{},false);


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

    chassis.setPose(48, -33, -112);
    setIntake(127);
    chassis.moveToPoint(17,-44, 2000, {.minSpeed = 120}, false);
    //chassis.turnToHeading(-100, 100, {}, false);
    //chassis.turnToHeading(-90,500, {}, false);
    doinker.set_value(true);      
    pros::delay(150);
    setIntake(0);
    pros::delay(150);

    chassis.moveToPoint(34,-40,1200, {.forwards=false}, false);
    setIntake(0);
    doinker.set_value(false);
    pros::delay(300);
    chassis.moveToPoint(39, -38, 1000, {.forwards = false}, false);
    chassis.turnToHeading(93,500, {}, false);
    //pros::delay(3000);
    chassis.moveToPoint(17,-38.4,800, {.forwards = false, .maxSpeed = 50}, false);
    chassis.waitUntilDone();
    pros::delay(200);
    clamp.set_value(false);
    pros::delay(300);
    setIntake(127);
    pros::delay(300);
    chassis.turnToHeading(-50, 500, {}, false);
    setDrive(-6000,-6000);
    pros::delay(300);
    setDrive(0,0);
    clamp.set_value(true);
    pros::delay(100);

    chassis.turnToHeading(65, 500, {}, false); //54
    setIntake(127);
    chassis.moveToPoint(46,-23,1200, {}, false);
    // setIntake(0);
    pros::delay(350);
    setIntake(0);
    chassis.turnToHeading(90,600,{},false);
    chassis.moveToPoint(24,-22,1300,{.forwards = false, .maxSpeed = 60}, false);
    pros::delay(100);
    clamp.set_value(false);
    pros::delay(250);
    setIntake(127);
    pros::delay(300);
    chassis.turnToHeading(100, 500, {}, false);

    chassis.moveToPoint(57,-22,750,{},false);
    chassis.turnToHeading(160, 500, {}, false);
    setDrive(5500,5500);
    pros::delay(2200);
    setDrive(-8000,-8000);
    pros::delay(380);
    setDrive(0,0);

    // chassis.turnToHeading(155, 500, {}, false);
    // //setIntake(-127);
    // chassis.moveToPoint(58,-56,1200,{.maxSpeed=30}, false);
    // pros::delay(500);
    // //chassis.moveToPoint();
    doinker.set_value(true);
    pros::delay(50);
    // pros::delay(500);
    chassis.turnToHeading(0, 600, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE}, false);
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

// FOR PIKES PEAK
void skillsprog() 
{

    //Get Mobile 
    chassis.setPose(-54, -1.5, 90);
    setIntake(100);
    pros::delay(200);
    setIntake(0);
    chassis.moveToPoint(-41,-1.5,800, {.maxSpeed = 120}, true);
    chassis.turnToHeading(180,500, {}, true);
    chassis.moveToPoint(-41,22,1200, {.forwards = false, .maxSpeed = 65}, true);
    chassis.waitUntil(20);
    clamp.set_value(false);
    chassis.waitUntilDone();
    pros::delay(150);

    //First Goal
    chassis.turnToHeading(90,520, {}, false);
    setIntake(127);
    chassis.moveToPoint(-18,20,900, {}, false);
    chassis.swingToHeading(55, DriveSide::RIGHT, 1000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE}, false);
    //chassis.turnToHeading(35, 450, {}, true);
    //chassis.moveToPoint(-11,34.5,1000,{},false);
    chassis.moveToPoint(29, 40, 1800, {}, true); //29,44.4
    // chassis.waitUntil(5);
    setarm();
    chassis.waitUntilDone();
    pros::delay(500);
    // //chassis.moveToPose(25,48,90,2900,{}, false);

    // // //Wall Stake
    chassis.setPose(24,49,chassis.getPose().theta);
    chassis.turnToHeading(80,600,{}, false);
    // pros::delay(200);
    // setIntake(-50);
    // pros::delay(100);
    // setIntake(0);
    // arm.move(60);
    // pros::delay(300);
    // arm.move_velocity(0);

    chassis.moveToPoint(-2.5, 38, 1900,{.forwards = false}, false);
    pros::delay(200);
    setIntake(-50);
    pros::delay(100);
    setIntake(0);
    arm.move(60);
    pros::delay(300);
    arm.move_velocity(0);
     //4.75
    //chassis.moveToPoint(0,44,0,2000,{.forwards = false},false);
    chassis.turnToHeading(0, 500, {}, false);
    setIntake(127);

    setDrive(5500,5500);
    pros::delay(1400);
    setDrive(0,0);
    //chassis.moveToPose(0,70, 0, 1800,{},false);
    scoreWallStake();
    
    chassis.setPose(0,63.2,chassis.getPose().theta);
    chassis.moveToPoint(0,51,700,{.forwards=false},false);
    arm.move(-12000);
    pros::delay(850);
    chassis.turnToHeading(270,500,{},false);
    chassis.moveToPoint(-46,51,1300,{.maxSpeed=60},false);
    pros::delay(750);
    chassis.moveToPoint(-59,51,1300,{.maxSpeed=85},false);
    chassis.setPose(-57.5,47.5,chassis.getPose().theta);

    pros::delay(250);
    chassis.turnToHeading(33,600,{},false);
    chassis.moveToPoint(-48,59,700);
    pros::delay(100);
    chassis.turnToHeading(90,400);
    chassis.moveToPoint(-55,59,700,{.forwards = false},false);
    chassis.turnToHeading(135,500,{},false);
    clamp.set_value(true);
    setIntake(0);

    //chassis.moveToPoint(-51,50,600,{},true);
    // // //pros::delay(1000);
    // // setIntake(0);
    //chassis.turnToHeading(0,450,{},false);

    chassis.moveToPose(-51,52.5,chassis.getPose().theta,1500,{}, false);
    chassis.turnToHeading(0,500,{},false);
    //chassis.swingToHeading(0, DriveSide::RIGHT, 400, {.direction = AngularDirection::CW_CLOCKWISE}, false);
    // chassis.moveToPose(-48.5,-10,0,1500,{.forwards=false},false);
    // chassis.moveToPose(-48.5,-24,0,1000,{.forwards=false},false);
    chassis.moveToPoint(-48.5,-13,1500,{.forwards = false},false);
    chassis.moveToPoint(-48.5,-23,1300,{.forwards = false, .maxSpeed = 55},false);
    chassis.setPose(-46,-22,0);
    pros::delay(400);
    clamp.set_value(false);
    pros::delay(100);

    chassis.turnToHeading(90,600,{},false);
    setIntake(127);
    chassis.moveToPoint(-24,-23,700,{},false);
    chassis.swingToHeading(135, DriveSide::LEFT, 1000, {.direction = AngularDirection::CW_CLOCKWISE}, false);
    chassis.moveToPoint(23.5,-38,1300,{},false); //23.5, -45
    setarm();
    pros::delay(200);
    
    chassis.turnToHeading(100,500,{},false);
    chassis.moveToPoint(1,-37,900,{.forwards = false}, false);
    setIntake(-50);
    pros::delay(100);
    setIntake(0);
    arm.move(60);
    pros::delay(300);
    arm.move_velocity(0);
    chassis.turnToHeading(180,600);
    setIntake(127);
    chassis.moveToPoint(chassis.getPose().x,-69,1000,{.maxSpeed = 60}, false);
   
    scoreWallStake();

    chassis.setPose(0,-58,chassis.getPose().theta);
    chassis.moveToPoint(0,-44,500,{.forwards = false}, false);
    arm.move(-12000);
    pros::delay(850);
    chassis.turnToHeading(270,400);
    chassis.moveToPoint(-47,-50,1000,{.maxSpeed = 60},false);
    pros::delay(500);
    chassis.moveToPoint(-58,-50,1500,{.maxSpeed = 62},false);
    chassis.turnToHeading(140,500,{},false);
    chassis.moveToPoint(-46,-58,1000,{},false);
    chassis.turnToHeading(90,500,{},false);
    chassis.moveToPoint(-57,-58,1000,{.forwards = false}, false);
    chassis.turnToHeading(45,500,{},false);

    clamp.set_value(true);
    chassis.moveToPoint(-46.2,-46,800,{}, false);
    chassis.turnToHeading(90,500,{},false);
    chassis.moveToPoint(0,-45,1600, {}, false);
    chassis.turnToHeading(45,500,{},false);
    setIntake(110);
    chassis.moveToPoint(23,-23,700, {}, false);
    chassis.waitUntilDone();
    pros::delay(500);

    chassis.turnToHeading(225,500,{},false);
    setIntake(0);
    chassis.moveToPoint(40, 1.5, 1500, {.forwards = false, .maxSpeed = 60}, false);
    pros::delay(200);
    clamp.set_value(false);
    pros::delay(200);

    chassis.turnToHeading(180,500,{},false);
    chassis.swingToHeading(180, DriveSide::RIGHT, 1000, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE}, false);
    setIntake(127);
    chassis.moveToPoint(44,-45,1600,{.maxSpeed = 65},false);
    chassis.moveToPoint(44,-54,1600,{.maxSpeed = 95},false);
    // //chassis.moveToPoint(44,-45,800,{.forwards = false},false);
    chassis.turnToHeading(270,500,{},false);
    chassis.moveToPoint(52,-54,800,{.forwards = false},false);
    // pros::delay(300);

    // chassis.turnToHeading(0,500,{},false);
    // chassis.moveToPoint(58,-54,800,{.forwards = false},false);
    clamp.set_value(true);
    pros::delay(200);
    // chassis.moveToPoint(58,-41,800,{},false);
    // chassis.turnToHeading(180,900,{},false);

    chassis.moveToPoint(58,55,3000,{.forwards = false},false);
    chassis.turnToHeading(225,600,{},false);
    setDrive(6000,6000);
    pros::delay(600);
    setDrive(0,0);

    chassis.turnToHeading(45,900,{},false);
    setDrive(-7000,-7000);
    pros::delay(1000);
    setDrive(3000,3000);


    















    // chassis.turnToPoint(1,1,500,{},false);
    // setIntake(90);
    // chassis.moveToPoint(1,1,1600,{.minSpeed = 120}, false);
    // pros::delay(150);
    // setIntake(0);
    // // chassis.moveToPoint(24,24,600,{.minSpeed = 127}, false);

    // chassis.turnToHeading(135,500,{},false);
    // chassis.moveToPoint(27,-27,1000,{}, true);
    // setIntake(80);
    // chassis.turnToHeading(225,600,{},false);
    // chassis.moveToPoint(45,-1,1000,{.forwards = false},false);
    // pros::delay(200);
    // clamp.set_value(false);
    // pros::delay(200);
    // setIntake(127);

    // chassis.turnToHeading(180,600,{},false);
    // chassis.moveToPoint(45,-50,1600,{},false);
}

void skillsauton() {
    //Mobile Goal
    chassis.setPose(-58, 1.5, 270);
    setIntake(100);
    pros::delay(200);
    setIntake(0);
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

void PIDTest() {
    setarm();
    pros::delay(127);
    setIntake(127);
    //chassis.moveToPose(-47,-180, 2500);    
}

void gatewaytestblueneg() {

    chassis.setPose(-49,13,235);
    setIntake(90);
    chassis.moveToPoint(-58.2 ,7.7 , 800, {.maxSpeed = 100}, false);
    chassis.waitUntilDone();
    scoreAllianceStake();
    //setIntake(0);

    chassis.turnToHeading(240,600,{},false);
    chassis.moveToPoint(-43.4, 17.7, 1000, {.forwards = false}, true);
    chassis.moveToPoint(-23.5, 25, 1000, {.forwards = false}, false);
    pros::delay(200);
    clamp.set_value(false);
    pros::delay(100);

    chassis.turnToHeading(50,600,{},false);
    setIntake(127);
    chassis.moveToPoint(-13.5, 33.3, 1000, {}, false);
    chassis.swingToHeading(0, DriveSide::RIGHT, 900, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE}, false);

    chassis.moveToPoint(-8.5, 44, 1000, {}, false);
    chassis.turnToHeading(13,600,{},false);

    chassis.moveToPoint(-14, 27, 1000, {}, false);
    chassis.turnToHeading(330,600,{},false);

    chassis.moveToPoint(-23, 4, 1000, {}, false);

    chassis.moveToPose(-47, 22, 180, 2000, {}, false);

    chassis.moveToPoint(-47, 1, 800, {.maxSpeed = 95}, false);
    pros::delay(200);
    chassis.moveToPoint(-47, -10, 800, {}, false);

}

void gatewayblueneg() {
    chassis.setPose(57.375, 15, 0);
    chassis.moveToPoint(57.375, 2, 1200, {.forwards=false}, false);
    chassis.turnToHeading(90, 800, {}, false);
    setDrive(6000, 6000);
    pros::delay(200);
    setDrive(0, 0);
    scoreAllianceStake();
    chassis.moveToPoint(57.375, 2, 1000, {.forwards=false}, false); // go back
    chassis.turnToHeading(0, 1000, {}, false); 
    chassis.moveToPoint(57.375, 23, 1500, {}, false);
    chassis.turnToHeading(90, 750, {}, false);
    chassis.moveToPoint(23, 23, 2500, {.forwards=false, .maxSpeed=60}, true);
    chassis.waitUntil(30);
    clamp.set_value(false); // clamp mogo
    chassis.waitUntilDone(); 
    pros::delay(100);
    chassis.turnToHeading(0, 750, {}, false);
    setIntake(127);
    chassis.moveToPoint(23, 47, 2000, {.maxSpeed=75}, false);
    pros::delay(250);
    chassis.turnToHeading(190, 1000, {}, false);
    chassis.moveToPoint(21, 16, 3000, {.maxSpeed=70}, true);
    arm.move_velocity(600);
    pros::delay(400);
}

void ppblueneg() {
    
    //get mogo, score preload
    chassis.setPose(51,24,90);
    chassis.moveToPoint(28,24,1500,{.forwards=false,.maxSpeed=70},false);
    chassis.waitUntil(17);
    clamp.set_value(false);
    pros::delay(150);
    setIntake(127);
    pros::delay(100);
    //setIntake(-50);
    

   /*
    //kevin code that doesnt work with this
    chassis.setPose(57,16,125);
    arm.move(420);
    pros::delay(700);

    chassis.moveToPoint(28,24,1500,{.forwards=false,.maxSpeed=70},false);
    chassis.waitUntil(30);
    clamp.set_value(false);
    pros::delay(150);
    setIntake(127);
    pros::delay(100);
    setIntake(-50);
    */

    //go mid
    chassis.turnToHeading(315,500,{},false);
    setIntake(127);
    pros::delay(100);
    chassis.moveToPose(12.5,62,1,2500,{.maxSpeed=80},false);
    pros::delay(300);
    setIntake(0);
    //pros::delay(15000);

    //go back, get 3rd ring
    chassis.moveToPoint(24, 26, 1000, {.forwards=false});
    setIntake(-50);
    pros::delay(100);
    setIntake(127);
    chassis.moveToPoint(35,55,750,{},false);
    pros::delay(100);
    chassis.moveToPoint(35,30,500,{},false);
    pros::delay(250);
    //pros::delay(15000);

    /*
    //go corner
    chassis.moveToPoint(65,62,2000,{},false);//test maxspeed
    chassis.moveToPoint(68,58,3000,{.maxSpeed=20},false);
    //possibly turn a little bit here
    pros::delay(300);
    chassis.moveToPoint(chassis.getPose().x-3,chassis.getPose().y-1,500,{},false);
    pros::delay(500);
    chassis.moveToPoint(35,30,750,{.forwards=false,.maxSpeed=50},false);
    pros::delay(200);
    chassis.moveToPoint(65,62,2000,{},false);//test maxspeed
    chassis.moveToPoint(68,58,3000,{.maxSpeed=40},false);
    */

    
    //go corner
    //chassis.moveToPose(72,62,90,2000,{.maxSpeed=80},false);
    chassis.moveToPoint(65,58,2000,{},false);//test maxspeed, y coord 62
    chassis.moveToPoint(68,58,3000,{.maxSpeed=20},false);
    pros::delay(300);
    chassis.moveToPoint(chassis.getPose().x-3,chassis.getPose().y-1,500,{},false);
    pros::delay(500);
    chassis.moveToPoint(35,55,1000,{.forwards=false},false);
    pros::delay(150);
    

    /*
    //go for mid ring
    chassis.turnToHeading(150,300,{},false);
    pros::delay(100);
    chassis.moveToPoint(54,21,1000,{},false);
    pros::delay(100);
    doinker.set_value(true);
    chassis.moveToPoint(chassis.getPose().x - 12, chassis.getPose().y, 750, {.forwards=false,.maxSpeed=80}, false);
    pros::delay(200);
    doinker.set_value(false);
    pros::delay(100);
    chassis.moveToPoint(chassis.getPose().x + 14, chassis.getPose().y, 750, {}, false);

    //chassis.moveToPoint(60,9,750,{},false); //test maxspeed

    //if theres time, touch ladder
    */

}

void testbluepos() {
    chassis.setPose(57.375, 15, 0);
    chassis.moveToPoint(57.375, -2, 750, {.forwards=false}, false);
    chassis.turnToHeading(90, 750, {}, false);
    setDrive(6000, 6000);
    pros::delay(185);
    setDrive(0, 0);
    scoreAllianceStake();

    //Get Mobile Goal
    chassis.moveToPoint(chassis.getPose().x - 6, chassis.getPose().y, 500, {.forwards=false}, false); // this should probably be chassis.getPose().x - 2
    chassis.turnToHeading(154-180, 750, {}, false);
    setIntake(127);
    chassis.moveToPoint(35,13,750,{},false);
    pros::delay(200);
    setIntake(0);
    chassis.turnToHeading(125,750,{},false);
    pros::delay(50);

    chassis.moveToPoint(24, 23, 1000, {.forwards=false, .maxSpeed=60}); // go to Mobile Goal
    chassis.waitUntil(15);
    clamp.set_value(false); // clamp Mobile Goal
    chassis.waitUntilDone();
    setIntake(127); // score 2nd ring
    pros::delay(500);

    chassis.turnToHeading(180, 750, {}, false);
    clamp.set_value(true);
    chassis.moveToPoint(22.5, -49, 600, {.forwards=true}, false);
    pros::delay(150);
    setIntake(0);

    chassis.turnToPoint(0,46,400,{.forwards=false},false);
    chassis.moveToPoint(0,46,1000,{.forwards=false},false);
    chassis.waitUntil(23);
    clamp.set_value(false);
    pros::delay(100);
    setIntake(127);
    pros::delay(500);

    chassis.moveToPoint(24,-49,600,{},false);
    pros::delay(100);
    chassis.turnToHeading(0,500,{},false);
    pros::delay(200);
    chassis.moveToPoint(24,0,1000,{},false);
}

void testredpos() {
    chassis.setPose(-57.375, 15, 0);
    chassis.moveToPoint(-57.375, -2, 750, {.forwards=false}, false);
    chassis.turnToHeading(270, 750, {}, false);
    setDrive(6000, 6000);
    pros::delay(185);
    setDrive(0, 0);
    scoreAllianceStake();

    //Get Mobile Goal
    chassis.moveToPoint(chassis.getPose().x + 6, chassis.getPose().y, 500, {.forwards=false}, false); // this should probably be chassis.getPose().x - 2
    chassis.turnToHeading(180-154, 750, {}, false);
    setIntake(127);
    chassis.moveToPoint(-35,13,750,{},false);
    pros::delay(200);
    setIntake(0);
    chassis.turnToHeading(235,750,{},false);
    pros::delay(50);

    chassis.moveToPoint(-24, 23, 1000, {.forwards=false, .maxSpeed=60}); // go to Mobile Goal
    chassis.waitUntil(15);
    clamp.set_value(false); // clamp Mobile Goal
    chassis.waitUntilDone();
    setIntake(127); // score 2nd ring
    pros::delay(500);

    chassis.turnToHeading(180, 750, {}, false);
    clamp.set_value(true);
    chassis.moveToPoint(-22.5, -49, 600, {.forwards=true}, false);
    pros::delay(150);
    setIntake(0);

    chassis.turnToPoint(0,46,400,{.forwards=false},false);
    chassis.moveToPoint(0,46,1000,{.forwards=false},false);
    chassis.waitUntil(23);
    clamp.set_value(false);
    pros::delay(100);
    setIntake(127);
    pros::delay(500);

    chassis.moveToPoint(-24,-49,600,{},false);
    pros::delay(100);
    chassis.turnToHeading(0,500,{},false);
    pros::delay(200);
    chassis.moveToPoint(-24,0,1000,{},false);
}

void intake() {
    setIntake(127);
    pros::delay(3000);
    setIntake(0);
    pros::delay(1000);
    //setIntake(127);

}

void pikepeakringrushblue() {

    // chassis.setPose(50,31,-75);
    // setIntake(127);
    // chassis.moveToPoint(8,42,1300,{},false); //10
    // pros::delay(100);
    // setIntake(0);

    // chassis.moveToPoint(34.7,33.6,1300,{.forwards = false},false);
    // chassis.turnToHeading(45,600,{},false);
    // chassis.moveToPoint(20,26,1300,{.forwards = false, .maxSpeed = 60},false);
    // pros::delay(50);
    // clamp.set_value(false);
    // pros::delay(155);

    // setIntake(127);
    // chassis.turnToHeading(213,600,{},false);
    // pros::delay(500);
    // setIntake(0);
    // chassis.moveToPoint(7.8,13.6,1500,{},false); //9.2,14.3
    // doinker.set_value(true);



}

void peakpikesredpos4ringred() {
    
    // chassis.setPose(-57,-13,310);
    // //scoreAllianceStake();

    // chassis.moveToPoint(-43.8,-23.5, 800, {.forwards = false}, false);
    // chassis.turnToHeading(270, 550, {}, false);

    chassis.setPose(-50,-22.5,270);
    chassis.moveToPoint(-23,-23.5, 1000, {.forwards = false, .maxSpeed = 68}, false);
    pros::delay(105);
    clamp.set_value(false);
    pros::delay(125);
    //pros::delay(8000);
    setIntake(127);

    // chassis.turnToHeading(35, 600, {}, false);

    // // //Get Mobile Goal
    // chassis.moveToPoint(-14.9,-10.3, 700, {}, false); //-15.6,-11.6
    // chassis.turnToHeading(36, 500, {}, false); //42
    // pros::delay(200);
    // doinker.set_value(true);
    // pros::delay(300);

    // // chassis.turnToHeading(45, 500, {}, false);
    // chassis.moveToPoint(-35,-34.8,1500,{.forwards = false, .maxSpeed = 100},false);
    // doinker.set_value(false);
    // chassis.turnToHeading(72, 600, {}, false);

    // setIntake(127);
    // chassis.moveToPoint(-19.5,-28.9, 600,{},false);
    // chassis.turnToHeading(90, 500, {}, false);

    // chassis.moveToPoint(-23.5, chassis.getPose().y, 800, {.forwards = false}, false);
    chassis.turnToHeading(180, 600, {}, false);
    chassis.moveToPoint(-23.5, -45, 800, {.minSpeed = 127}, false);
    chassis.moveToPoint(-23.5, -25, 800, {.forwards = false}, false);
    pros::delay(300);
    // //chassis.moveToPoint(chassis.getPose().x, -36.6, 800, {.forwards = false}, false);

    chassis.turnToHeading(90, 700, {}, false);
    chassis.moveToPoint(-67,-32, 800, {.forwards = false}, false);
    chassis.turnToHeading(190, 700, {}, false);

    setDrive(5000,5000);
    pros::delay(2050);

    // // chassis.setPose(-56,-58,chassis.getPose().theta);

    setDrive(-9000,-9000);
    pros::delay(300);
    setDrive(0,0);

    // // // chassis.turnToHeading(260, 600, {}, false);
    // pros::delay(50);
    doinker.set_value(true);
    // // pros::delay(100);

    chassis.turnToHeading(90, 1800, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE}, false);
    chassis.moveToPoint(-35, chassis.getPose().y, 1000, {}, true);
    clamp.set_value(true);
    setIntake(-127);
    doinker.set_value(false);
    chassis.turnToHeading(270, 1800, {}, false);

}

void peakpikesredneg3ringqual() {

    // chassis.setPose(-57,16,235);
    // arm.move(420);
    // pros::delay(700);
    // arm.move(-600);
    // pros::delay(700);
    // //chassis.turnToHeading(252, 600, {}, false);
    // setIntake(127);

    chassis.setPose(-48,-22,270);
    chassis.moveToPoint(-24,-22,1000, {.forwards = false, .maxSpeed = 65}, false);
    pros::delay(135);
    clamp.set_value(false);
    pros::delay(125);
    setIntake(127);

    chassis.turnToHeading(180, 600, {}, false);
    chassis.moveToPoint(-24, -42.3, 1500, {.minSpeed = 120}, false);
    pros::delay(900);
    chassis.turnToHeading(0, 600, {}, false);
    setIntake(0);
    chassis.moveToPoint(-24, 2, 1500, {.maxSpeed = 65}, false);




    // chassis.turnToHeading(37, 600, {}, false);
    // chassis.moveToPoint(-12.3,38.8, 1500, {}, false); //38.8
    // pros::delay(500);
    // chassis.moveToPoint(-23, 24, 1200, {.forwards = false}, false);

    // chassis.turnToHeading(0, 500, {}, false);
    // chassis.moveToPoint(-24, 48, 1000, {.minSpeed = 120}, false);
    // pros::delay(200);

    // chassis.moveToPoint(-23, 24, 1500, {.forwards = false}, false);
    // setIntake(0);
    // chassis.turnToHeading(180, 600, {}, false);
    // chassis.moveToPoint(-24, 1, 1500, {.maxSpeed = 65}, false);
    
    // chassis.turnToHeading(45, 600, {}, false);
    // chassis.moveToPoint(-47, 24, 1500, {.forwards = false}, false);
    // chassis.turnToHeading(180, 600, {}, false);
    // chassis.moveToPoint(-47, -4, 800, {.maxSpeed = 90}, false);

    // chassis.turnToHeading(75, 600, {}, false);
    // chassis.moveToPoint(-24, 1.3, 1000, {.maxSpeed = 70}, true);
    // scoreWallStake();

}

void peakpikesblueneg5ringelim() {

    chassis.setPose(51,24,90);
    chassis.moveToPoint(28,24,1500,{.forwards=false,.maxSpeed=60},false);
    chassis.waitUntil(17);
    clamp.set_value(false);
    pros::delay(150);
    setIntake(127);
    pros::delay(100);
    setIntake(-50); //if anyone asks abt this antijam, it is 100% necessary

    //go mid
    chassis.turnToHeading(315,500,{},false);
    setIntake(127);
    pros::delay(100);
    chassis.moveToPose(12,60,1,2500,{.maxSpeed=80},false); //DO y=62 IF FIRST STAGE ShiTs ITSELF
    setIntake(-50);
    pros::delay(300);
    setIntake(127);
    //setIntake(0);
    //pros::delay(15000);

    //go back, get 3rd ring
    chassis.moveToPoint(24, 26, 1000, {.forwards=false});
    //setIntake(-127);
    pros::delay(100);
    setIntake(127);
    chassis.moveToPoint(35,55,750,{},false);
    pros::delay(100);
    chassis.moveToPoint(35,30,750,{},false);
    pros::delay(250);
    //chassis.turnToHeading(75,300,{},false);
    //pros::delay(15000);

    //go corner
    //chassis.moveToPose(72,62,90,2000,{.maxSpeed=80},false);
    chassis.moveToPoint(50,53,1500,{.maxSpeed=90},false);//test maxspeed
    pros::delay(1000);
    setDrive(6000,4000);
    pros::delay(1000);
    //chassis.moveToPoint(72,58,1000,{.maxSpeed=20},false);
    setDrive(0,0);
    pros::delay(200);
    chassis.moveToPoint(chassis.getPose().x-3,chassis.getPose().y-1,500,{},false);
    pros::delay(200);
    chassis.moveToPoint(35,55,1000,{.forwards=false},true);
    pros::delay(150);

    arm.move_velocity(600);
    chassis.moveToPoint(9,14,2000,{},false);
    /*
    //go for mid ring
    chassis.turnToHeading(150,300,{},false);
    pros::delay(100);
    chassis.moveToPoint(54,21,1000,{},false);
    pros::delay(100);
    doinker.set_value(true);
    pros::delay(15000);
    pros::delay(500);
    chassis.moveToPoint(chassis.getPose().x - 12, chassis.getPose().y, 750, {.forwards=false,.maxSpeed=80}, false);
    pros::delay(200);
    doinker.set_value(false);
    pros::delay(100);
    chassis.moveToPoint(chassis.getPose().x + 14, chassis.getPose().y, 750, {}, false);

    //chassis.moveToPoint(60,9,750,{},false); //test maxspeed*/



    
}

void peakpikesblueneg3ringqual() {

    // chassis.setPose(57,16,125);
    // arm.move(420);
    // pros::delay(700);
    // arm.move(-600);
    // pros::delay(700);
    //chassis.turnToHeading(108, 600, {}, false);

    chassis.setPose(49, 25, 90);
    chassis.moveToPoint(24, 25, 1500, {.forwards = false, .maxSpeed = 61}, false);
    pros::delay(135);
    clamp.set_value(false);
    pros::delay(125);

    setIntake(127);
    chassis.turnToHeading(-40, 600, {}, false);
    pros::delay(150);
    chassis.moveToPoint(11.6, 37.6, 700, {}, false); //10.6, 38.8
   // chassis.moveToPoint(13.3, 34.5, 700, {}, false); //10.6, 38.8
    pros::delay(500);
    chassis.moveToPoint(23, 24, 1500, {.forwards = false}, false);

    chassis.turnToHeading(0, 500, {}, false);
    chassis.moveToPoint(23, 47, 1000, {.maxSpeed = 80}, false);
    pros::delay(500);

    chassis.moveToPoint(23, 24, 1500, {.forwards = false}, false);
    setIntake(0);
    chassis.turnToHeading(180, 600, {}, false);
    chassis.moveToPoint(24, 1, 1500, {.maxSpeed = 55}, false);

}

void peakpikesredpos3ringqual() {

    chassis.setPose(-57,-12,305);
    scoreAllianceStake();

    chassis.moveToPoint(-23, -22, 1500, {.forwards = false, .maxSpeed = 65}, false);
    pros::delay(135);
    clamp.set_value(false);
    pros::delay(125);

    setIntake(127);
    chassis.turnToHeading(180, 600, {}, false);
    chassis.moveToPoint(-24, -42, 1500, {.minSpeed = 127}, false);
    chassis.moveToPoint(-23, -38, 1500, {.forwards = false, .maxSpeed = 65}, false);

    chassis.turnToHeading(245, 600, {}, false);
    chassis.moveToPoint(-54,-57, 2900, {.maxSpeed = 100}, false); 
    chassis.turnToHeading(250, 800, {}, false);
    setDrive(4000,4000);
    pros::delay(900);
    setDrive(0,0);
    setDrive(-4000,-4000);
    pros::delay(250);
    setDrive(0,0);
    setDrive(4000,4000);
    pros::delay(600);
    setDrive(0,0);

    pros::delay(200);

    chassis.setPose(-55,-61,chassis.getPose().theta);
    chassis.moveToPoint(-23, -46, 1500, {.forwards = false}, false); 
    chassis.turnToHeading(0, 800, {}, false);
    chassis.moveToPoint(-24, 1.5, 1300, {.maxSpeed = 65}, false); 

}

void peakpikesbluepos3ringqual() {

    // chassis.setPose(57,-13,50);
    // scoreAllianceStake();

    // chassis.moveToPoint(43.2, -21.9, 1500, {.forwards = false}, false); //46.5,-20.3
    // chassis.turnToHeading(90, 600, {}, false);
    // chassis.moveToPoint(24, -22, 1500, {.forwards = false, .maxSpeed = 60}, false);
    // pros::delay(135);
    // clamp.set_value(false);
    // pros::delay(125);
    
    //temp
    chassis.setPose(-57,16,233);
    arm.move(600);
    pros::delay(700);
    arm.move(-600);
    pros::delay(700);
    //chassis.turnToHeading(252, 600, {}, false);
    setIntake(127);

    // chassis.setPose(48,-22,90);

    chassis.moveToPoint(-46,24,1700, {.forwards = false}, false);
    // chassis.turnToHeading(270, 600, {}, false);
    chassis.moveToPoint(-23, 24, 1500, {.forwards = false, .maxSpeed = 65}, false);
    pros::delay(335);
    clamp.set_value(false);
    pros::delay(125);

    chassis.turnToHeading(0, 600, {}, false);
    setIntake(127);
    chassis.moveToPoint(-23, 44, 1500, {.minSpeed = 127}, false);
    pros::delay(600);
    //chassis.moveToPoint(chassis.getPose().x, 40, 1500, {.forwards = false, .maxSpeed = 65}, false);
    //chassis.swingToHeading(270, DriveSide::RIGHT, 800, {.direction = AngularDirection::CCW_COUNTERCLOCKWISE}, false);

    //chassis.turnToHeading(180, 600, {}, false);
    pros::delay(100);
    chassis.moveToPoint(-23, 25, 1500, {.forwards = false}, false);
    chassis.turnToHeading(90, 600, {}, false);
    scoreWallStake();
    chassis.moveToPoint(-11, 25, 1500, {.forwards = false}, false);


    //chassis.moveToPoint(-24, 4, 1400, {.minSpeed = 127}, false); 
    // chassis.turnToHeading(180, 800, {}, false);
    // // setDrive(5000,5000);
    // // pros::delay(2000);
    // // setDrive(0,0);
    // // pros::delay(400);

    // // chassis.setPose(55,-58,chassis.getPose().theta);
    // chassis.moveToPoint(-23, 2, 1900, {.maxSpeed = 65}, false); 
    // chassis.turnToHeading(0, 800, {}, false);
    // chassis.moveToPoint(24, 1.5, 1300, {.maxSpeed = 65}, false); 

}

void peakpikesredpos3ringqualmogo() 
{

    chassis.setPose(-50,-22.5,270);
    chassis.moveToPoint(-23,-23.5, 1000, {.forwards = false, .maxSpeed = 68}, false);
    pros::delay(105);
    clamp.set_value(false);
    pros::delay(125);

    setIntake(127);
    chassis.turnToHeading(180, 600, {}, false);
    chassis.moveToPoint(-24, -41, 1500, {.minSpeed = 127}, false);
    pros::delay(500);
    chassis.moveToPoint(-24, -30, 1500, {.forwards = false, .maxSpeed = 65}, false);
    chassis.turnToHeading(0, 600, {}, false);

    // chassis.turnToHeading(0, 600, {}, false);
    chassis.moveToPoint(-24, 1, 1500, {.maxSpeed = 65}, false);



    //temp
    // chassis.turnToHeading(245, 600, {}, false);
    // chassis.moveToPoint(-54,-57, 2900, {.maxSpeed = 100}, false); 
    // chassis.turnToHeading(265, 800, {}, false); //260
    // setDrive(9000,9000);
    // pros::delay(2000);
    // setDrive(0,0);

    // setDrive(-4000,-4000);
    // pros::delay(250);
    // setDrive(0,0);

    // setDrive(7000,7000);
    // pros::delay(750);
    // setDrive(0,0);

    // pros::delay(200);

    // chassis.setPose(-55,-61,chassis.getPose().theta);
    // chassis.moveToPoint(-23, -46, 1500, {.forwards = false}, false); 
    // chassis.turnToHeading(0, 800, {}, false);
    // chassis.moveToPoint(-24, 1, 1300, {.maxSpeed = 65}, false); 


}

void ppbluepos3ring() {

    chassis.setPose(51,-24,90);
    chassis.moveToPoint(28,-24,1500,{.forwards=false,.maxSpeed=70},false);
    chassis.waitUntil(17);
    clamp.set_value(false);
    pros::delay(150);
    setIntake(127);
    pros::delay(100);

    chassis.turnToHeading(180,750,{},false);
    pros::delay(100);
    chassis.moveToPoint(23,-45,1000,{},false);
    pros::delay(350);
    //chassis.moveToPoint(31,-40,500,{},false);
    chassis.turnToHeading(110,500,{},false);
    pros::delay(200);
    chassis.moveToPoint(53,-60,1000,{},false);
    chassis.moveToPoint(63,-62,2000,{.maxSpeed=20},false);
    pros::delay(350);
    chassis.moveToPoint(60,-61,750,{},false);

}

void blueposelim() {

    chassis.setPose(48,-22,90);
    chassis.moveToPoint(23, -22, 1400, {.forwards = false, .earlyExitRange = 65}, false);

    chassis.turnToHeading(330, 700, {}, false);
    pros::delay(100);
    chassis.moveToPoint(16.6, -11.9, 1000, {}, false);
    chassis.turnToHeading(270, 700, {}, false);
    pros::delay(100);

    chassis.moveToPoint(13,-11.9, 1000, {}, false);
    chassis.turnToHeading(278, 600, {}, false);
    pros::delay(200);

    doinker.set_value(true);
    pros::delay(50);


}

void skillsdriver() {

    chassis.setPose(-54, -1.5, 90);
    setIntake(100);
    pros::delay(200);
    setIntake(0);
    chassis.moveToPoint(-41,-1.5,800, {.maxSpeed = 120}, true);
    chassis.turnToHeading(180,500, {}, true);
    chassis.moveToPoint(-41,22,1200, {.forwards = false, .maxSpeed = 65}, true);
    chassis.waitUntil(20);
    clamp.set_value(false);
    chassis.waitUntilDone();

}

void peakpikesredneg5ringelim() {

    chassis.setPose(-51,24,270);
    chassis.moveToPoint(-28,24,1500,{.forwards=false,.maxSpeed=60},false);
    chassis.waitUntil(17);
    clamp.set_value(false);
    pros::delay(150);
    setIntake(127);
    pros::delay(100);
    setIntake(-50);

    chassis.turnToHeading(45,500,{},false);
    setIntake(127);
    pros::delay(100);
    chassis.moveToPose(-12,61.5,1,2500,{.maxSpeed=80},false); //DO y=62 IF FIRST STAGE ShiTs ITSELF
    setIntake(-50);
    pros::delay(300);
    setIntake(127);
    //setIntake(0);
    //pros::delay(15000);

    //go back, get 3rd ring
    chassis.moveToPoint(-24, 26, 1000, {.forwards=false});
    //setIntake(-127);
    pros::delay(100);
    setIntake(127);
    chassis.moveToPoint(-35,55,750,{},false);
    pros::delay(100);
    chassis.moveToPoint(-35,30,750,{},false);
    pros::delay(250);

    chassis.moveToPoint(-50,53,1500,{.maxSpeed=90},false);//test maxspeed
    pros::delay(1000);
    setDrive(6000,4000);
    pros::delay(1000);
    //chassis.moveToPoint(72,58,1000,{.maxSpeed=20},false);
    setDrive(0,0);
    pros::delay(200);
    chassis.moveToPoint(chassis.getPose().x-3,chassis.getPose().y-1,500,{},false);
    pros::delay(200);
    chassis.moveToPoint(-35,55,1000,{.forwards=false},true);
    pros::delay(150);

    arm.move_velocity(600);
    chassis.moveToPoint(-9,14,2000,{},false);



}