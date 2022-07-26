// Date of start: 27.06.2022
// Tested on:

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

                                   
int ledPin = 13;        // LED connected to digital pin 13
int inPin = 11;         // pushbutton connected to digital pin 11. Is declared as an output why?
int val = 0;            // variable to store the read value
int valsum =0;
int scanit=0;           // Apparently related to inPin, used as flag
int moveit=0;
int move_finishedX=1;
int move_finishedY=1;
int move_finishedZ=1;
int move_finishedF=1;
int move_finishedXS=1;  // new
int move_finishedYS=1;  // new
int move_finishedZS=1;  // new
int FAC=1;
int N_pic=1;

// steps(eingegeben)/micrometer(gemessen)
float cfcX=1.28;
float cfcY=1.28;
float cfcZ=3.2;
float cfcF=6.4;
float cfcXS=0.3759398;  // new
float cfcYS=0.3759398;  // new
float cfcZS=0.7462686;  // new
float micron_per_scan=8;
float micron_per_scanF=8;

float int_posX=0;
float int_posY=0;
float int_posZ=0;
float int_posZsc=0; // What is sc? Scan?
float int_posF=0;
float int_posFsc=0; // What is sc? Scan?
float int_posXS=0;  // new
float int_posYS=0;  // new
float int_posZS=0;  // new
float scan_ende=0;
float scan_limit=0;
float scan_endeF=0; // why independent?
float scan_limitF=0;// why independent?
int help=0;

String command;
String pos;


long TravelX;                       // Used to store the X value entered in the Serial Monitor
long TravelY;                       // Used to store the Y value entered in the Serial Monitor
long TravelZ;                       // Used to store the Z value entered in the Serial Monitor
long TravelF;                       // Used to store the Z value entered in the Serial Monitor
long TravelXS;                      // Used to store the XS value entered in the Serial Monitor (new)
long TravelYS;                      // Used to store the YS value entered in the Serial Monitor (new)
long TravelZS;                      // Used to store the ZS value entered in the Serial Monitor (new)
int move_finished1=1;               // Used to check if move is completed - What does 1 or 0 means?
long initial_homing1=-1;            // Used to Home Stepper at startup


void setup() {
  Serial.begin(9600);               // Start the Serial monitor with speed of 9600 Bauds    
  delay(5);                         // Wait for EasyDriver wake up
  pinMode(inPin, OUTPUT);           // Currently inPin = 11

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

void loop() {

  while (Serial.available()>0)  {   // Check if values are available in the Serial Buffer
    command = Serial.readStringUntil(':');  // Slices the command name out of the input
    pos = Serial.readStringUntil('&');    // gets the desired position
    int_posX=cfcX*pos.toFloat();
    int_posY=cfcY*pos.toFloat();
    int_posZ=cfcZ*pos.toFloat();
    int_posF=cfcF*pos.toFloat();
    int_posXS=cfcXS*pos.toFloat();       // new
    int_posYS=cfcYS*pos.toFloat();       // new
    int_posZS=cfcZS*pos.toFloat();       // new

    if(command =="XZ") {
      stepperX.setCurrentPosition(0);                 // sends X to "home"
      scanit=0;
      moveit=0;
      Serial.println("SET ZERO X");
      Serial.print("Pos:");
      Serial.println(stepperX.currentPosition ());
      Serial.print("PosX: ");
      Serial.print(stepperX.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperY.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.print("| micron");
      Serial.print("| PosF: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println("| micron");
    }

    if(command =="YZ") {
      stepperY.setCurrentPosition(0);
      scanit=0;
      moveit=0;
      Serial.println("SET ZERO Y");
      Serial.print("Pos:");
      Serial.println(stepperY.currentPosition ());
      Serial.print("PosX: ");
      Serial.print(stepperX.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperY.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.print("| micron");
      Serial.print("| PosF: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println("| micron");
    }
    
    if(command =="ZZ") {
      stepperZ.setCurrentPosition(0);
      scanit=0;
      moveit=0;
      Serial.println("SET ZERO Z");
      Serial.print("Pos:");
      Serial.println(stepperZ.currentPosition ());
      Serial.print("PosX: ");
      Serial.print(stepperX.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperY.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.print("| micron");
      Serial.print("| PosF: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println("| micron");
    }

    if(command =="FZ") {
      stepperF.setCurrentPosition(0);
      scanit=0;
      moveit=0;
      Serial.println("SET ZERO F");
      Serial.print("Pos:");
      Serial.println(stepperF.currentPosition ());
      Serial.print("PosX: ");
      Serial.print(stepperX.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperY.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.print("| micron");
      Serial.print("| PosF: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println("| micron");
    }

    // new -------------
    if(command =="XSZ") {
      stepperXS.setCurrentPosition(0);                 // sends X to "home"
      scanit=0;
      moveit=0;
      Serial.println("SET ZERO XS");
      Serial.print("Pos:");
      Serial.println(stepperXS.currentPosition ());
      Serial.print("PosX: ");
      Serial.print(stepperXS.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperYS.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZS.currentPosition ()/cfcZ);
      Serial.print("| micron");
    }

    if(command =="YSZ") {
      stepperYS.setCurrentPosition(0);
      scanit=0;
      moveit=0;
      Serial.println("SET ZERO YS");
      Serial.print("Pos:");
      Serial.println(stepperYS.currentPosition ());
      Serial.print("PosX: ");
      Serial.print(stepperXS.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperYS.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZS.currentPosition ()/cfcZ);
      Serial.print("| micron");
    }
    
    if(command =="ZSZ") {
      stepperZS.setCurrentPosition(0);
      scanit=0;
      moveit=0;
      Serial.println("SET ZERO ZS");
      Serial.print("Pos:");
      Serial.println(stepperZS.currentPosition ());
      Serial.print("PosX: ");
      Serial.print(stepperXS.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperYS.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZS.currentPosition ()/cfcZ);
      Serial.print("| micron");
    }
    // ---
    
    
    if(command =="MX") {
      scanit=0;
      moveit=1;
      stepperX.moveTo(int_posX);
      move_finishedX=0;
      Serial.println("MOVE"); 
    }
    
    if(command =="MY") {
      scanit=0;
      moveit=1;
      stepperY.moveTo(int_posY);
      move_finishedY=0;
      Serial.println("MOVE"); 
    }
    
    if(command =="MZ") {
      scanit=0;
      moveit=1;
      stepperZ.moveTo(int_posZ);
      move_finishedZ=0;
      Serial.println("MOVE"); 
    }

    if(command =="MF") {
      scanit=0;
      moveit=1;
      stepperF.moveTo(int_posF);
      move_finishedF=0;
      Serial.println("MOVE"); 
    }

    // new -----------------
    if(command =="MXS") {
      scanit=0;
      moveit=1;
      stepperXS.moveTo(int_posXS);
      move_finishedXS=0;
      Serial.println("MOVE"); 
    }
    
    if(command =="MYS") {
      scanit=0;
      moveit=1;
      stepperYS.moveTo(int_posYS);
      move_finishedYS=0;
      Serial.println("MOVE"); 
    }
    
    if(command =="MZS") {
      scanit=0;
      moveit=1;
      stepperZS.moveTo(int_posZS);
      move_finishedZS=0;
      Serial.println("MOVE"); 
    }
    // ---

    if(command =="RX") {
      scanit=0;
      moveit=1;
      stepperX.moveTo(int_posX+stepperX.currentPosition ());
      move_finishedX=0;
      Serial.println("MOVE");
    }
    
    if(command =="RY") {
      scanit=0;
      moveit=1;
      stepperY.moveTo(int_posY+stepperY.currentPosition ());
      move_finishedY=0;
      Serial.println("MOVE");
    }
    
    if(command =="RZ") {
      scanit=0;
      moveit=1;
      stepperZ.moveTo(int_posZ+stepperZ.currentPosition ());
      move_finishedZ=0;
      Serial.println("MOVE");
    }

      if(command =="RF") {
      scanit=0;
      moveit=1;
      stepperF.moveTo(int_posF+stepperF.currentPosition ());
      move_finishedF=0;
      Serial.println("MOVE");
    }

    // NEW ----------------------------
    if(command =="RXS") {
      scanit=0;
      moveit=1;
      stepperXS.moveTo(int_posXS+stepperXS.currentPosition ());
      move_finishedXS=0;
      Serial.println("MOVE");
    }
    
    if(command =="RYS") {
      scanit=0;
      moveit=1;
      stepperYS.moveTo(int_posYS+stepperYS.currentPosition ());
      move_finishedYS=0;
      Serial.println("MOVE");
    }
    
    if(command =="RZS") {
      scanit=0;
      moveit=1;
      stepperZS.moveTo(int_posZS+stepperZS.currentPosition ());
      move_finishedZS=0;
      Serial.println("MOVE");
    }
    // ---

    if(command =="SP") {
      scan_limit=int_posZ+stepperZ.currentPosition ();
      scanit=1;
      moveit=0;
      Serial.println("SCAN Mode-positive started");
            FAC=1;
    }
    
    if(command =="SN") {
      scan_limit=-int_posF+stepperF.currentPosition ();
      scanit=1;
      moveit=0;
      Serial.println("SCAN Mode-negative started");
      FAC=-1;
    }

    if(command =="SPF") {
      scan_limitF=int_posF+stepperF.currentPosition ();
      scanit=1;
      moveit=0;
      Serial.println("SCAN Mode F-positive started");
            FAC=1;
         
    }
    
    if(command =="SNF") {
      scan_limitF=-int_posF+stepperF.currentPosition ();
      scanit=1;
      moveit=0;
      Serial.println("SCAN Mode F-negative started");
      FAC=-1;
    }

    if(command =="S") {
      scanit=0;
      moveit=1;
      stepperZ.moveTo(stepperZ.currentPosition ());
      stepperX.moveTo(stepperX.currentPosition ());
      stepperY.moveTo(stepperY.currentPosition ());
      stepperF.moveTo(stepperF.currentPosition ());
      move_finishedX=0;
      move_finishedY=0;
      move_finishedZ=0;
      move_finishedF=0;
      Serial.println("STOP");
      scan_limit=0;
    }
  }


  if(scanit==1 && Serial.available()==0) {
    digitalWrite(inPin,HIGH) ;     // read the input pin
    delay(10); 
    digitalWrite(inPin,LOW);
    delay(1500); 

    if(Serial.available()==0 && command =="SP" || Serial.available()==0 && command =="SN") {   
      stepperZ.runToNewPosition(stepperZ.currentPosition ()+(FAC)*micron_per_scan);
      val =0;         
      Serial.print("Pos: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.println(" micron");    
    } 

    if(Serial.available()==0 && command =="SPF" || Serial.available()==0 && command =="SNF") {   
      stepperF.runToNewPosition(stepperF.currentPosition ()+(FAC)*micron_per_scanF);
      val =0;         
      Serial.print("Pos: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println(" micron");    
    }     
  }

  if(command =="SP") {
    if ((stepperZ.currentPosition () > scan_limit) && scanit==1) {
      Serial.println("scheisse!");    
      Serial.print("Pos: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.println(" micron");
      move_finishedZ=1;                           // Reset move variable
      moveit=0;
      scanit=0;
      help=0;
      scan_limit=0;
      Serial.print("help: ");
      Serial.println(help);
      Serial.print("scan_limit: ");
      Serial.println(scan_limit);
    }
  }

  if(command =="SN") {
    if ((stepperZ.currentPosition () < scan_limit) && scanit==1) {
      Serial.println("scheisse!");
      Serial.print("Pos: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.println(" micron");
      move_finishedZ=1;                           // Reset move variable
      moveit=0;
      scanit=0;
      help=0;
      scan_limit=0;
      Serial.print("help: ");
      Serial.println(help);
      Serial.print("scan_limit: ");
      Serial.println(scan_limit);
    }
  }

  if(command =="SPF") {
    if ((stepperF.currentPosition () > scan_limitF) && scanit==1) {
      Serial.println("scheisse!");    
      Serial.print("Pos: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println(" micron");
      move_finishedF=1;                           // Reset move variable
      moveit=0;
      scanit=0;
      help=0;
      scan_limitF=0;
      Serial.print("help: ");
      Serial.println(help);
      Serial.print("scan_limit: ");
      Serial.println(scan_limitF);
    }
  }

  if(command =="SNF") {
    if ((stepperF.currentPosition () < scan_limitF) && scanit==1) {
      Serial.println("scheisse!");    
      Serial.print("Pos: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println(" micron");
      move_finishedF=1;                           // Reset move variable
      moveit=0;
      scanit=0;
      help=0;
      scan_limitF=0;
      Serial.print("help: ");
      Serial.println(help);
      Serial.print("scan_limit: ");
      Serial.println(scan_limitF);
    }
  }

  if(moveit==1) { // a command to move the motors was received
    if (stepperX.distanceToGo() != 0) {    
      // stepperX.run();                            // Move Stepper into position    
     // Serial.println("RunX");
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedX == 0) && (stepperX.distanceToGo() == 0)) {
      Serial.print("PosX: ");
      Serial.print(stepperX.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperY.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.print("| micron");
      Serial.print("| PosF: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println("| micron");
      move_finishedX=1;                           // Reset move variable
      moveit=0;
    }
  
    if (stepperY.distanceToGo() != 0) {    
      // stepperY.run();                            // Move Stepper into position    
      //Serial.println("RunY");
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedY == 0) && (stepperY.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");    
      Serial.print("PosX: ");
      Serial.print(stepperX.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperY.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.print("| micron");
      Serial.print("| PosF: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println("| micron");
      move_finishedY=1;                           // Reset move variable
      moveit=0;
    }
    
    if (stepperZ.distanceToGo() != 0) {    
      // stepperZ.run();                            // Move Stepper into position    
      //Serial.println("RunZ");
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedZ == 0) && (stepperZ.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      Serial.print("PosX: ");
      Serial.print(stepperX.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperY.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.print("| micron");
      Serial.print("| PosF: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println("| micron");
      move_finishedZ=1;                           // Reset move variable
      moveit=0;
    }



   if (stepperF.distanceToGo() != 0) {    
      // stepperF.run();                            // Move Stepper into position    
      //Serial.println("RunZ");
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedF == 0) && (stepperF.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      Serial.print("PosX: ");
      Serial.print(stepperX.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperY.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.print("| micron");
      Serial.print("| PosF: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println("| micron");
      move_finishedF=1;                           // Reset move variable
      moveit=0;
    }


  // New --------------------- Sensor movement
    if (stepperXS.distanceToGo() != 0) {    
      // stepperXS.run();                            // Move Stepper into position
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedXS == 0) && (stepperXS.distanceToGo() == 0)) {
      Serial.print("PosX: ");
      Serial.print(stepperX.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperY.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.print("| micron");
      Serial.print("| PosF: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println("| micron");
      move_finishedXS=1;                           // Reset move variable
      moveit=0;
    }
  
    if (stepperYS.distanceToGo() != 0) {    
      // stepperYS.run();                            // Move Stepper into position    
      //Serial.println("RunY");
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedYS == 0) && (stepperYS.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");    
      Serial.print("PosX: ");
      Serial.print(stepperX.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperY.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.print("| micron");
      Serial.print("| PosF: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println("| micron");
      move_finishedYS=1;                           // Reset move variable
      moveit=0;
    }
    
    if (stepperZS.distanceToGo() != 0) {    
      // stepperZS.run();                            // Move Stepper into position    
      //Serial.println("RunZ");
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedZS == 0) && (stepperZS.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      Serial.print("PosX: ");
      Serial.print(stepperX.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperY.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.print("| micron");
      Serial.print("| PosF: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println("| micron");
      move_finishedZS=1;                           // Reset move variable
      moveit=0;
    }
    
  }

  // new - Testing endswitch sensors | endswitches are connected to 5v
  if(digitalRead(sensor_x_home)==HIGH) {
    scanit=0;
    moveit=1;
    stepperZ.moveTo(stepperZ.currentPosition ());
    stepperX.moveTo(stepperX.currentPosition ());
    stepperY.moveTo(stepperY.currentPosition ());
    stepperF.moveTo(stepperF.currentPosition ());
    move_finishedX=0;
    move_finishedY=0;
    move_finishedZ=0;
    move_finishedF=0;
    Serial.println("STOP");
    scan_limit=0;
  }
}

void run_motors(){  // if this line works, the variable moveit can be safely removed
  for(int i = 0; i < sizeof(motors_array); i++){
    if (motors_array[i].distanceToGo() != 0){
      motors_array[i].run();
    }
  }
}
