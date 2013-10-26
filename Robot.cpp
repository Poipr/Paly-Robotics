#include "WPILib.h"
#define PORT_DRIVE_VIC_1 5
#define PORT_DRIVE_VIC_2 10
#define PORT_DRIVE_VIC_3 2
#define PORT_DRIVE_VIC_4 1
#define PORT_JS_DRIVE 1
#define PORT_JS_TURN 2
#define PORT_JS_OPERATOR 3

class MyRobot : public IterativeRobot {
  Victor leftVic1;
  Victor leftVic2;
  Victor rightVic1;
  Victor rightVic2;
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
    speedStick(PORT_JS_SPEED),
    turnStick(PORT_JS_TURN),
    operatorStick(PORT_JS_OPERATOR)
  {
  
  }
  
  void AutonomousInit(){
    t.start();
  }

  void AutonomousPeriod(){
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

  void TeleopPeriod(){
    
  }

  void TeleopDisabled(){
    
  }
};

START_ROBOT_CLASS(MyRobot);
