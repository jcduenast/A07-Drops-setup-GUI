// Date of start: 30.06.2022
// Using blocking instructions instead of non blicking ones
#include "AccelStepper.h"

// pin-out declaration
// define prefix for camera
const int camera_X_step = 2;
const int camera_X_dir  = 3;
const int camera_Y_step = 6;
const int camera_Y_dir  = 7;
const int camera_Z_step = 4;
const int camera_Z_dir  = 5;

// drops height motor
const int drops_Z_step = 8;
const int drops_Z_dir  = 9;

// sensor motors
const int sensor_X_step = 14;
const int sensor_X_dir  = 15;
const int sensor_Y_step = 16;
const int sensor_Y_dir  = 17;
const int sensor_Z_step = 18;
const int sensor_Z_dir  = 19;

// sensor endswitch
const int sensor_x_home = 22;
const int sensor_x_end  = 23;
const int sensor_y_home = 24;
const int sensor_y_end  = 25;
const int sensor_z_home = 26;
const int sensor_z_end  = 27;

// Serial comms variables
String command = "";
String arg = "";

// Control variables
bool moving = false;
float steps;

// Units transformation variables
// steps(eingegeben)/micrometer(gemessen)
const float um2st_SX = 0.3759398;
const float um2st_SY = 0.3759398;
const float um2st_SZ = 0.3759398;
const float um2st_CX = 0.1;
const float um2st_CY = 0.1;
const float um2st_CZ = 0.1;
const float um2st_DZ = 0.1;

// AccelStepper motor(interface, pin1, pin2, ...)
// AccelStepper::DRIVER -> pin1: step, pin2: direction
AccelStepper stepperCameraX(AccelStepper::DRIVER, camera_X_step, camera_X_dir);  // 1 = Easy Driver interface, 2 STEP, 3 DIR
AccelStepper stepperCameraY(AccelStepper::DRIVER, camera_Y_step, camera_Y_dir);  // 1 = Easy Driver interface, 6 STEP, 7 DIR
AccelStepper stepperCameraZ(AccelStepper::DRIVER, camera_Z_step, camera_Z_dir);  // 1 = Easy Driver interface, 4 STEP, 5 DIR
AccelStepper stepperDropsZ(AccelStepper::DRIVER, drops_Z_step, drops_Z_dir);     // 1 = Easy Driver interface, 8 STEP, 9 DIR
AccelStepper stepperSensorX(AccelStepper::DRIVER, sensor_X_step, sensor_X_dir);  // 1 = Easy Driver interface, 24 STEP, 25 DIR
AccelStepper stepperSensorY(AccelStepper::DRIVER, sensor_Y_step, sensor_Y_dir);  // 1 = Easy Driver interface, 27 STEP, 28 DIR
AccelStepper stepperSensorZ(AccelStepper::DRIVER, sensor_Z_step, sensor_Z_dir);  // 1 = Easy Driver interface, 30 STEP, 31 DIR



void setup() {
  Serial.begin(9600);               // Start the Serial monitor with speed of 9600 Bauds    
  delay(5);                         // Wait for EasyDriver wake up

  // End-Switch pin configuration
  pinMode(sensor_x_home, INPUT);
  pinMode(sensor_x_end, INPUT);
  pinMode(sensor_y_home, INPUT);
  pinMode(sensor_y_end, INPUT);
  pinMode(sensor_z_home, INPUT);
  pinMode(sensor_z_end, INPUT);

  // Steppermotors pin configuration
  // apparently, the pinMode and digitalWrite are not necesary
//  pinMode(camera_X_step, OUTPUT);
//  pinMode(camera_X_dir, OUTPUT);
//  digitalWrite(camera_X_step, LOW);
//  digitalWrite(camera_X_dir, LOW);
//  pinMode(camera_Y_step, OUTPUT);
//  pinMode(camera_Y_dir, OUTPUT);
//  digitalWrite(camera_Y_step, LOW);
//  digitalWrite(camera_Y_dir, LOW);
//  pinMode(camera_Z_step, OUTPUT);
//  pinMode(camera_Z_dir, OUTPUT);
//  digitalWrite(camera_Z_step, LOW);
//  digitalWrite(camera_Z_dir, LOW);
//  pinMode(drops_Z_step, OUTPUT);
//  pinMode(drops_Z_dir, OUTPUT);
//  digitalWrite(drops_Z_step, LOW);
//  digitalWrite(drops_Z_dir, LOW);
//  pinMode(sensor_X_step, OUTPUT);
//  pinMode(sensor_X_dir, OUTPUT);
//  digitalWrite(sensor_X_step, LOW);
//  digitalWrite(sensor_X_dir, LOW);
//  pinMode(sensor_Y_step, OUTPUT);
//  pinMode(sensor_Y_dir, OUTPUT);
//  digitalWrite(sensor_Y_step, LOW);
//  digitalWrite(sensor_Y_dir, LOW);
//  pinMode(sensor_Z_step, OUTPUT);
//  pinMode(sensor_Z_dir, OUTPUT);
//  digitalWrite(sensor_Z_step, LOW);
//  digitalWrite(sensor_Z_dir, LOW);

  // Stepper motors Speed setup
  stepperCameraX.setMaxSpeed(30000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  stepperCameraX.setAcceleration(2000.0);   // Set Acceleration of Stepper
  stepperCameraY.setMaxSpeed(30000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  stepperCameraY.setAcceleration(2000.0);   // Set Acceleration of Stepper
  stepperCameraZ.setMaxSpeed(30000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  stepperCameraZ.setAcceleration(2000.0);   // Set Acceleration of Stepper
  stepperDropsZ.setMaxSpeed(60000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  stepperDropsZ.setAcceleration(5000.0);   // Set Acceleration of Stepper
  stepperSensorX.setMaxSpeed(30000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  stepperSensorX.setAcceleration(2000.0);   // Set Acceleration of Stepper
  stepperSensorY.setMaxSpeed(30000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  stepperSensorY.setAcceleration(2000.0);   // Set Acceleration of Stepper
  stepperSensorZ.setMaxSpeed(30000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  stepperSensorZ.setAcceleration(2000.0);   // Set Acceleration of Stepper
}


void loop(){
  while(Serial.available()>0){              // Excecuted only if there is data to be read in the Serial buffer
    command = Serial.readStringUntil(':');  // Slices the command name out of the input
    arg = Serial.readStringUntil('&');      // gets the desired position
    Serial.println("command:"+command+"| arg:"+arg);
  }

  if(command.charAt(0)=='M'){             // Absolute position, move to
    if(command.charAt(1)=='S'){           // Sensor will move
      switch (command.charAt(2)){
        case 'X':                         // Motor of the X axis of the sensor will move
          steps = arg.toFloat()*um2st_SX; // Conversion from um to steps
          stepperSensorX.moveTo(steps);   // Command to move to absolute position
          break;
        case 'Y':
          steps = arg.toFloat()*um2st_SY;
          stepperSensorY.moveTo(steps);
          break;
        case 'Z':
          steps = arg.toFloat()*um2st_SZ;
          stepperSensorZ.moveTo(steps);
          break;
        default:
          break;
      }
    }

//    if(command.charAt(1)=='C'){           // Camera will move
//      switch (command.charAt(2)){
//        case 'X':                         // Motor of the X axis of the camera will move
//          steps = arg.toFloat()*um2st_CX; // Conversion from um to steps
//          stepperCameraX.moveTo(steps);
//          break;
//        case 'Y':
//          steps = arg.toFloat()*um2st_CY;
//          stepperCameraY.moveTo(steps);
//          break;
//        case 'Z':
//          steps = arg.toFloat()*um2st_CZ;
//          stepperCameraZ.moveTo(steps);
//          break;
//        default:
//          break;
//      }
//    }
//
//    if(command.charAt(1)=='D'){           // Drops will move
//      switch (command.charAt(2)){
//        case 'Z':                         // Motor of the Z axis of the Drops will move
//          steps = arg.toFloat()*um2st_CZ; // Conversion from um to steps
//          stepperCameraZ.moveTo(steps);
//          break;
//        default:
//          break;
//      }
//    }
    moving = true;
    command = "";
  }
  
//  if(command == "RSX"){
//    float steps = arg.toFloat();
//    stepperSensorX.move(steps);
//    moving = true;
//    command = "";
//  }
//
//  if(command == "RCX"){
//    float steps = arg.toFloat();
//    stepperSensorX.move(steps);
//    moving = true;
//    command = "";
//  }
//  
  if(stepperSensorX.run() or stepperSensorY.run() or stepperSensorZ.run()){
    Serial.println("Sensor updating whut?");
  }

  if(stepperCameraX.run() | stepperCameraY.run() | stepperCameraZ.run()){
    Serial.println("Camera updating");
  }

  if(stepperDropsZ.run()){
    Serial.println("Drops updating");
  }
}
