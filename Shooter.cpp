#include "WPILib.h"
#define PORT_DRIVE_VIC_1 5
#define PORT_DRIVE_VIC_2 10
#define PORT_DRIVE_VIC_3 2
#define PORT_DRIVE_VIC_4 1
#define PORT_JS_SPEED 1
#define PORT_JS_TURN 2
#define PORT_JS_OPERATOR 3
#define PORT_SHOOTER_1 3
#define PORT_SHOOTER_2 4

enum shooterState {
  IDLE,
  SPIN_UP,
  EXTENDING,
  RECEDING
};

class MyRobot : public IterativeRobot {
  Victor leftVic1;
  Victor leftVic2;
  Victor rightVic1;
  Victor rightVic2;
  Victor shooter1;
  Victor shooter2;
  Joystick speedStick;
  Joystick turnStick;
  Joystick operatorStick;
  Timer t;

public:
  MyRobot() : 
    leftVic1(PORT_DRIVE_VIC_1),
    leftVic2(PORT_DRIVE_VIC_2),
    rightVic1(PORT_DRIVE_VIC_3),
    rightVic2(PORT_DRIVE_VIC_4),
    shooter1(PORT_SHOOTER_1),
    shooter2(PORT_SHOOTER_2),
    speedStick(PORT_JS_SPEED),
    turnStick(PORT_JS_TURN),
    operatorStick(PORT_JS_OPERATOR)
  {
  
  }
  
  void AutonomousInit(){
    t.Start();
  }

  void AutonomousPeriodic(){
    if (t.Get() < 2.0){
    leftVic1.Set(0.5);
    leftVic2.Set(0.5);
    rightVic1.Set(-0.5);
    rightVic2.Set(-0.5);
    } else if (t.Get() < 4.0){
    leftVic1.Set(0.5);
    leftVic2.Set(0.5);
    rightVic1.Set(-0.1);
    rightVic2.Set(-0.1);
    } else if (t.Get() < 6.0){
    leftVic1.Set(0.5);
    leftVic2.Set(0.5);
    rightVic1.Set(-0.5);
    rightVic2.Set(-0.5);
    } else if (t.Get() < 8.0){
    leftVic1.Set(1.0);
    leftVic2.Set(1.0);
    rightVic1.Set(1.0);
    rightVic2.Set(1.0);
    }
  }

  void AutonomousDisabled(){
    leftVic1.Set(0.0);
    leftVic2.Set(0.0);
    rightVic1.Set(0.0);
    rightVic2.Set(0.0);
  }

  void TeleopInit(){
    
  }

  void TeleopPeriodic(){
    leftVic1.Set(speedStick.GetY()-turnStick.GetX());
    leftVic2.Set(speedStick.GetY()-turnStick.GetX());
    rightVic1.Set(turnStick.GetX()-speedStick.GetY());
    rightVic2.Set(turnStick.GetX()-speedStick.GetY());
    
    if (shooterState == IDLE){
      if (/*Sense if the trigger is pressed*/) {
        shooterState = SPIN_UP;
      }
    }
    else if (shooterState == SPIN_UP){
      // Spin the motors up to speed
      if (/*Do something to decide when to go to the Extending state*/) {
        shooterState = EXTENDING;
      }
    }
    else if (shooterState == EXTENDING){
      // Extend the Solenoid
      if (/*Sense when the solenoid is done extending*/) {
        shooterState = RECEDING;
      }
    }
    else if (shooterState == RECEDING){
      // Pull back the solenoid
      if (/*Sense when the solenoid is done being pulled back*/) {
        shooterState = IDLE;
      }
    }

  void TeleopDisabled(){
    leftVic1.Set(0.0);
    leftVic2.Set(0.0);
    rightVic1.Set(0.0);
    rightVic2.Set(0.0);
  }
};

START_ROBOT_CLASS(MyRobot);
