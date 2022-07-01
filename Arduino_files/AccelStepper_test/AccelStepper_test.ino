// Date of start: 30.06.2022
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
String command;
String arg;

AccelStepper stepperX(1, camera_X_step, camera_X_dir);  // 1 = Easy Driver interface, 2 STEP, 3 DIR
AccelStepper stepperY(1, camera_Y_step, camera_Y_dir);  // 1 = Easy Driver interface, 6 STEP, 7 DIR
AccelStepper stepperZ(1, camera_Z_step, camera_Z_dir);  // 1 = Easy Driver interface, 4 STEP, 5 DIR
AccelStepper stepperF(1, drops_Z_step, drops_Z_dir);    // 1 = Easy Driver interface, 8 STEP, 9 DIR

// new
AccelStepper stepperXS(1, sensor_X_step, sensor_X_dir);  // 1 = Easy Driver interface, 24 STEP, 25 DIR
AccelStepper stepperYS(1, sensor_Y_step, sensor_Y_dir);  // 1 = Easy Driver interface, 27 STEP, 28 DIR
AccelStepper stepperZS(1, sensor_Z_step, sensor_Z_dir);  // 1 = Easy Driver interface, 30 STEP, 31 DIR
//

AccelStepper motors_array[] = {stepperX, stepperY, stepperZ, stepperF, stepperXS, stepperYS, stepperZS};

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
  pinMode(camera_X_step, OUTPUT);   // X-Axis
  pinMode(camera_X_dir, OUTPUT);
  digitalWrite(camera_X_step, LOW);
  digitalWrite(camera_X_dir, LOW);
  pinMode(camera_Y_step, OUTPUT);   // Y-Axis
  pinMode(camera_Y_dir, OUTPUT);
  digitalWrite(camera_Y_step, LOW);
  digitalWrite(camera_Y_dir, LOW);
  pinMode(camera_Z_step, OUTPUT);   // Z-Axis
  pinMode(camera_Z_dir, OUTPUT);
  digitalWrite(camera_Z_step, LOW);
  digitalWrite(camera_Z_dir, LOW);
  pinMode(drops_Z_step, OUTPUT);     // F-Axis
  pinMode(drops_Z_dir, OUTPUT);
  digitalWrite(drops_Z_step, LOW);
  digitalWrite(drops_Z_dir, LOW);
  pinMode(sensor_X_step, OUTPUT);   // new XS-Axis
  pinMode(sensor_X_dir, OUTPUT);
  digitalWrite(sensor_X_step, LOW);
  digitalWrite(sensor_X_dir, LOW);
  pinMode(sensor_Y_step, OUTPUT);   // new YS-Axis
  pinMode(sensor_Y_dir, OUTPUT);
  digitalWrite(sensor_Y_step, LOW);
  digitalWrite(sensor_Y_dir, LOW);
  pinMode(sensor_Z_step, OUTPUT);   // new ZS-Axis
  pinMode(sensor_Z_dir, OUTPUT);
  digitalWrite(sensor_Z_step, LOW);
  digitalWrite(sensor_Z_dir, LOW);

  // Stepper motors Speed setup
  stepperX.setMaxSpeed(30000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  stepperX.setAcceleration(2000.0);   // Set Acceleration of Stepper
  stepperY.setMaxSpeed(30000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  stepperY.setAcceleration(2000.0);   // Set Acceleration of Stepper*/
  stepperZ.setMaxSpeed(30000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  stepperZ.setAcceleration(2000.0);   // Set Acceleration of Stepper
  stepperF.setMaxSpeed(60000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  stepperF.setAcceleration(5000.0);   // Set Acceleration of Stepper

  // new --------------------------
  stepperXS.setMaxSpeed(30000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  stepperXS.setAcceleration(2000.0);   // Set Acceleration of Stepper
  stepperYS.setMaxSpeed(30000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  stepperYS.setAcceleration(2000.0);   // Set Acceleration of Stepper*/
  stepperZS.setMaxSpeed(30000.0);      // Set Max Speed of Stepper (Faster for regular movements)
  stepperZS.setAcceleration(2000.0);   // Set Acceleration of Stepper*/
}


void loop(){
  while(Serial.available()>0){              // Excecuted only if there is data to be read in the Serial buffer
    command = Serial.readStringUntil(':');  // Slices the command name out of the input
    arg = Serial.readStringUntil('&');      // gets the desired position
    Serial.println("command:"+command+"/end");
    Serial.println("arg:"+arg+"/end");
    move_to(command, arg.toFloat());
  }
}

void move_to(String cmd, float pos){
  if(cmd="RXS"){
    stepperXS.moveTo(pos);
  }
  if(cmd="MXS"){
    stepperXS.moveTo(pos + stepperXS.currentPosition());
  }
  if(command =="S"){
    stepperZ.moveTo(stepperXS.currentPosition ());
    Serial.println("STOP");
  }
}

void getPosition(){
  
}
