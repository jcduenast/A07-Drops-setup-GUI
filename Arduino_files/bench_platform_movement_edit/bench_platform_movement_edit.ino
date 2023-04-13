// Version adjusted by: Juan Duenas - e-mail: jcduenast@unal.edu.co
// There are non-used functionalities in this version. A lighter version "clean" contains only used features
// prefix-C stands for Camera
// prefix-D stands for Drops
// prefix-S stands for Sensor
// prefix-W stands for Wave-Generator
// -> 6 additional motors added. No changes in the logic
// -> Adding end of line sensors

#include "AccelStepper.h"

#define home_switch5 40 // Not in use
#define home_switch6 42 // Not in use

AccelStepper stepperCX(1, 2, 3);    // 1 = Easy Driver interface, 2 STEP, 3 DIR
AccelStepper stepperCY(1, 6, 7);    // 1 = Easy Driver interface, 6 STEP, 7 DIR
AccelStepper stepperCZ(1, 4, 5);    // 1 = Easy Driver interface, 4 STEP, 5 DIR
AccelStepper stepperDZ(1, 8, 9);    // 1 = Easy Driver interface, 8 STEP, 9 DIR

// new
AccelStepper stepperSX(1, 14, 15);    // 1 = Easy Driver interface, 14 STEP, 15 DIR
AccelStepper stepperSY(1, 16, 17);    // 1 = Easy Driver interface, 16 STEP, 17 DIR
AccelStepper stepperSZ(1, 18, 19);    // 1 = Easy Driver interface, 18 STEP, 19 DIR

AccelStepper stepperWX(1, 24, 25);    // 1 = Easy Driver interface, 24 STEP, 25 DIR
AccelStepper stepperWY(1, 22, 23);    // 1 = Easy Driver interface, 22 STEP, 23 DIR
AccelStepper stepperWZ(1, 20, 21);    // 1 = Easy Driver interface, 20 STEP, 21 DIR
//

                                   
int ledPin = 13;                   // LED connected to digital pin 13
int inPin = 11;                    // pushbutton connected to digital pin 11. Is declared as an output why?
int val = 0;                       // variable to store the read value
int valsum =0;
int scanit=0;
int moveit=0;
int move_finishedCX=1;
int move_finishedCY=1;
int move_finishedCZ=1;
int move_finishedDZ=1;
int move_finishedSX=1;  // new
int move_finishedSY=1;  // new
int move_finishedSZ=1;  // new
int move_finishedWX=1;  // new
int move_finishedWY=1;  // new
int move_finishedWZ=1;  // new
int DZAC=1;
int N_pic=1;
// steps(eingegeben)/micrometer(gemessen)
float cfcCX=1.28;
float cfcCY=1.28;
float cfcCZ=3.2;
float cfcDZ=6.4;
const float cfcSX=0.3759398;  // new
const float cfcSY=0.3759398;  // new
const float cfcSZ=0.7462686;  // new
const float cfcWX=0.3759398;  // new
const float cfcWY=0.3759398;  // new
const float cfcWZ=0.7462686;  // new

float micron_per_scan=8;
float micron_per_scanDZ=8;

float int_posCX=0;
float int_posCY=0;
float int_posCZ=0;
float int_posCZsc=0; // What is sc? Scan?
float int_posDZ=0;
float int_posDZsc=0; // What is sc? Scan?
float int_posSX=0;  // new
float int_posSY=0;  // new
float int_posSZ=0;  // new
float int_posWX=0;  // new
float int_posWY=0;  // new
float int_posWZ=0;  // new
float scan_ende=0;
float scan_limit=0;
float scan_endeDZ=0; // why independent?
float scan_limitDZ=0;// why independent?
int help=0;

String servo;
String pos;

// these long variables are not used and will be deleted
long TravelCX;                     // Used to store the CX value entered in the Serial Monitor
long TravelCY;                     // Used to store the CY value entered in the Serial Monitor
long TravelCZ;                     // Used to store the CZ value entered in the Serial Monitor
long TravelDZ;                     // Used to store the Z value entered in the Serial Monitor
long TravelSX;                    // Used to store the SX value entered in the Serial Monitor (new)
long TravelSY;                    // Used to store the SY value entered in the Serial Monitor (new)
long TravelSZ;                    // Used to store the SZ value entered in the Serial Monitor (new)
long TravelWX;                    // Used to store the WX value entered in the Serial Monitor (new)
long TravelWY;                    // Used to store the WY value entered in the Serial Monitor (new)
long TravelWZ;                    // Used to store the WZ value entered in the Serial Monitor (new)
int move_finished1=1;             // Used to check if move is completed - What does 1 or 0 means?
long initial_homing1=-1;          // Used to Home Stepper at startup

// ------- Endswitch setup -----------
const int SXmin = 27;
const int SXmax = 29;
const int SYmin = 31;
const int SYmax = 33;
const int SZmin = 35;
const int SZmax = 37;

const int WXmin = 26;
const int WXmax = 28;
const int WYmin = 30;
const int WYmax = 32;
const int WZmin = 34;
const int WZmax = 36;

bool end_stop_activated =  false;
bool endswitch_state[12] = {false} ; // [Sensor wave, X Y Z, min max], initialization unnecesary but made explicit
// -----------------------------------

const int PumSwitch = 52;           // Pin for the start/stop command to the pump / Pum: Pump Umschaltung 

void setup() {
  Serial.begin(9600);              // Start the Serial monitor with speed of 9600 Bauds    
  delay(5);                        // Wait for EasyDriver wake up
  pinMode(inPin, OUTPUT);          // Currently inPin = 11
  pinMode(2, OUTPUT);     // X-Axis
  pinMode(3, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  pinMode(4, OUTPUT);     // Z-Axis
  pinMode(5, OUTPUT);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  pinMode(6, OUTPUT);     // Y-Axis
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  pinMode(8, OUTPUT);     // DZ-Axis
  pinMode(9, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  pinMode(14, OUTPUT);   // new SX-Axis
  pinMode(15, OUTPUT);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  pinMode(16, OUTPUT);   // new SY-Axis
  pinMode(17, OUTPUT);
  digitalWrite(16, LOW);
  digitalWrite(17, LOW);
  pinMode(18, OUTPUT);   // new SZ-Axis
  pinMode(19, OUTPUT);
  digitalWrite(18, LOW);
  digitalWrite(19, LOW);
 
  pinMode(38, OUTPUT);
  digitalWrite(38, LOW);
 
  pinMode(56, OUTPUT);
  digitalWrite(56, LOW);

  pinMode(62, OUTPUT);
  digitalWrite(62, LOW);

  // Sensor inputs
  pinMode(SXmin, INPUT);
  pinMode(SXmax, INPUT);
  pinMode(SYmin, INPUT);
  pinMode(SYmax, INPUT);
  pinMode(SZmin, INPUT);
  pinMode(SZmax, INPUT);

  pinMode(PumSwitch, OUTPUT);
  digitalWrite(PumSwitch, HIGH);
  
  stepperCX.setMaxSpeed(30000.0);        // Set Max Speed of Stepper (Faster for regular movements)
  stepperCX.setAcceleration(2000.0);     // Set Acceleration of Stepper
  stepperCY.setMaxSpeed(30000.0);        // Set Max Speed of Stepper (Faster for regular movements)
  stepperCY.setAcceleration(2000.0);     // Set Acceleration of Stepper
  stepperCZ.setMaxSpeed(30000.0);        // Set Max Speed of Stepper (Faster for regular movements)
  stepperCZ.setAcceleration(2000.0);     // Set Acceleration of Stepper
  stepperDZ.setMaxSpeed(30000.0);        // Set Max Speed of Stepper (Faster for regular movements)
  stepperDZ.setAcceleration(1000.0);     // Set Acceleration of Stepper

  // new --------------------------
  stepperSX.setMaxSpeed(30000.0);       // Set Max Speed of Stepper (Faster for regular movements)
  stepperSX.setAcceleration(1000.0);    // Set Acceleration of Stepper
  stepperSY.setMaxSpeed(30000.0);       // Set Max Speed of Stepper (Faster for regular movements)
  stepperSY.setAcceleration(1000.0);    // Set Acceleration of Stepper
  stepperSZ.setMaxSpeed(10000.0);       // Set Max Speed of Stepper (Faster for regular movements)
  stepperSZ.setAcceleration(1000.0);    // Set Acceleration of Stepper
  stepperWX.setMaxSpeed(30000.0);       // Set Max Speed of Stepper (Faster for regular movements)
  stepperWX.setAcceleration(1000.0);    // Set Acceleration of Stepper
  stepperWY.setMaxSpeed(30000.0);       // Set Max Speed of Stepper (Faster for regular movements)
  stepperWY.setAcceleration(1000.0);    // Set Acceleration of Stepper
  stepperWZ.setMaxSpeed(10000.0);       // Set Max Speed of Stepper (Faster for regular movements)
  stepperWZ.setAcceleration(1000.0);    // Set Acceleration of Stepper
  //

  
}

void loop() {

  while (Serial.available()>0)  {   // Check if values are available in the Serial Buffer
  
    servo = Serial.readStringUntil(':');  // Slices the servo name out of the input
    pos = Serial.readStringUntil('&');    // gets the desired position
    int_posCX=cfcCX*pos.toFloat();
    int_posCY=cfcCY*pos.toFloat();
    int_posCZ=cfcCZ*pos.toFloat();
    int_posDZ=cfcDZ*pos.toFloat();
    int_posSX=cfcSX*pos.toFloat();       // new
    int_posSY=cfcSY*pos.toFloat();       // new
    int_posSZ=cfcSZ*pos.toFloat();       // new
    int_posWX=cfcWX*pos.toFloat();       // new
    int_posWY=cfcWY*pos.toFloat();       // new
    int_posWZ=cfcWZ*pos.toFloat();       // new
    
    Serial.print("help=");
    Serial.println(help);

//  scan_limit=int_posCZ+stepperCZ.currentPosition ();  // stores the new final position ?
//  scan_limitF=int_posDZ+stepperDZ.currentPosition (); // stores the new final position ?
    
    if(servo =="Pum"){
      digitalWrite(PumSwitch, LOW);
      delay(200);
      digitalWrite(PumSwitch, HIGH);
      Serial.println("Pump state switched");
      delay(200);
    }
    
    if(servo =="CXZ") {
      stepperCX.setCurrentPosition(0);                 // sets X-position as "home"
      scanit=0;
      moveit=0;
      Serial.println("SET ZERO CX");
      Serial.print("Pos:");
      Serial.println(stepperCX.currentPosition ());
      Serial.print("PosX: ");
      Serial.print(stepperCX.currentPosition ()/cfcCX);   
      Serial.print("| PosY: ");
      Serial.print(stepperCY.currentPosition ()/cfcCY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperCZ.currentPosition ()/cfcCZ);
      Serial.print("| micron");
      Serial.print("| PosDZ: ");
      Serial.print(stepperDZ.currentPosition ()/cfcDZ);
      Serial.println("| micron");
    }

    if(servo =="CYZ") {
      stepperCY.setCurrentPosition(0);
      scanit=0;
      moveit=0;
      Serial.println("SET ZERO CY");
      Serial.print("Pos:");
      Serial.println(stepperCY.currentPosition ());
      Serial.print("PosCX: ");
      Serial.print(stepperCX.currentPosition ()/cfcCX);   
      Serial.print("| PosCY: ");
      Serial.print(stepperCY.currentPosition ()/cfcCY);    
      Serial.print("| PosCZ: ");
      Serial.print(stepperCZ.currentPosition ()/cfcCZ);
      Serial.print("| micron");
      Serial.print("| PosDZ: ");
      Serial.print(stepperDZ.currentPosition ()/cfcDZ);
      Serial.println("| micron");
    }
    
    if(servo =="CZZ") {
      stepperCZ.setCurrentPosition(0);
      scanit=0;
      moveit=0;
      Serial.println("SET ZERO CZ");
      Serial.print("Pos:");
      Serial.println(stepperCZ.currentPosition ());
      Serial.print("PosCX: ");
      Serial.print(stepperCX.currentPosition ()/cfcCX);   
      Serial.print("| PosCY: ");
      Serial.print(stepperCY.currentPosition ()/cfcCY);    
      Serial.print("| PosCZ: ");
      Serial.print(stepperCZ.currentPosition ()/cfcCZ);
      Serial.print("| micron");
      Serial.print("| PosDZ: ");
      Serial.print(stepperDZ.currentPosition ()/cfcDZ);
      Serial.println("| micron");
    }

    if(servo =="DZZ") {
      stepperDZ.setCurrentPosition(0);
      scanit=0;
      moveit=0;
      Serial.println("SET ZERO DZ");
      Serial.print("| PosDZ: ");
      Serial.print(stepperDZ.currentPosition ()/cfcDZ);
      Serial.println("| micron");
    }

    // new -------------
    if(servo =="SXZ") {
      stepperSX.setCurrentPosition(0);                 // sends X to "home"
      scanit=0;
      moveit=0;
      Serial.println("SET ZERO SX");
    }

    if(servo =="SYZ") {
      stepperSY.setCurrentPosition(0);
      scanit=0;
      moveit=0;
      Serial.println("SET ZERO SY");
    }
    
    if(servo =="SZZ") {
      stepperSZ.setCurrentPosition(0);
      scanit=0;
      moveit=0;
      Serial.println("SET ZERO SZ");
    }
    // ---
    
    
    if(servo =="MCX") {
      scanit=0;
      moveit=1;
      stepperCX.moveTo(int_posCX);
      move_finishedCX=0;
      Serial.println("MOVE"); 
    }
    
    if(servo =="MCY") {
      scanit=0;
      moveit=1;
      stepperCY.moveTo(int_posCY);
      move_finishedCY=0;
      Serial.println("MOVE"); 
    }
    
    if(servo =="MCZ") {
      scanit=0;
      moveit=1;
      stepperCZ.moveTo(int_posCZ);
      move_finishedCZ=0;
      Serial.println("MOVE"); 
    }

    if(servo =="MDZ") {
      scanit=0;
      moveit=1;
      stepperDZ.moveTo(int_posDZ);
      move_finishedDZ=0;
      Serial.println("MOVE"); 
    }

    // new -----------------
    if(servo =="MSX") {
      scanit=0;
      moveit=1;
      stepperSX.moveTo(int_posSX);
      move_finishedSX=0;
      Serial.println("MOVE"); 
    }
    
    if(servo =="MSY") {
      scanit=0;
      moveit=1;
      stepperSY.moveTo(int_posSY);
      move_finishedSY=0;
      Serial.println("MOVE"); 
    }
    
    if(servo =="MSZ") {
      scanit=0;
      moveit=1;
      stepperSZ.moveTo(int_posSZ);
      move_finishedSZ=0;
      Serial.println("MOVE"); 
    }

    if(servo =="MWX") {
      scanit=0;
      moveit=1;
      stepperWX.moveTo(int_posWX);
      move_finishedWX=0;
      Serial.println("MOVE"); 
    }
    
    if(servo =="MWY") {
      scanit=0;
      moveit=1;
      stepperWY.moveTo(int_posWY);
      move_finishedWY=0;
      Serial.println("MOVE"); 
    }
    
    if(servo =="MWZ") {
      scanit=0;
      moveit=1;
      stepperWZ.moveTo(int_posWZ);
      move_finishedWZ=0;
      Serial.println("MOVE"); 
    }
    // ---

    if(servo =="RCX") {
      scanit=0;
      moveit=1;
      stepperCX.moveTo(int_posCX+stepperCX.currentPosition ());
      move_finishedCX=0;
      Serial.println("MOVE");
    }
    
    if(servo =="RCY") {
      scanit=0;
      moveit=1;
      stepperCY.moveTo(int_posCY+stepperCY.currentPosition ());
      move_finishedCY=0;
      Serial.println("MOVE");
    }
    
    if(servo =="RCZ") {
      scanit=0;
      moveit=1;
      stepperCZ.moveTo(int_posCZ+stepperCZ.currentPosition ());
      move_finishedCZ=0;
      Serial.println("MOVE");
    }

      if(servo =="RDZ") {
      scanit=0;
      moveit=1;
      stepperDZ.moveTo(int_posDZ+stepperDZ.currentPosition ());
      move_finishedDZ=0;
      Serial.println("MOVE");
    }

    // NEW ----------------------------
    if(servo =="RSX") {
      scanit=0;
      moveit=1;
      stepperSX.moveTo(int_posSX+stepperSX.currentPosition ());
      move_finishedSX=0;
      Serial.println("MOVE");
    }
    
    if(servo =="RSY") {
      scanit=0;
      moveit=1;
      stepperSY.moveTo(int_posSY+stepperSY.currentPosition ());
      move_finishedSY=0;
      Serial.println("MOVE");
    }
    
    if(servo =="RSZ") {
      scanit=0;
      moveit=1;
      stepperSZ.moveTo(int_posSZ+stepperSZ.currentPosition ());
      move_finishedSZ=0;
      Serial.println("MOVE");
    }

    if(servo =="RWX") {
      scanit=0;
      moveit=1;
      stepperWX.moveTo(int_posWX+stepperWX.currentPosition ());
      move_finishedWX=0;
      Serial.println("MOVE");
    }
    
    if(servo =="RWY") {
      scanit=0;
      moveit=1;
      stepperWY.moveTo(int_posWY+stepperWY.currentPosition ());
      move_finishedWY=0;
      Serial.println("MOVE");
    }
    
    if(servo =="RWZ") {
      scanit=0;
      moveit=1;
      stepperWZ.moveTo(int_posWZ+stepperWZ.currentPosition ());
      move_finishedWZ=0;
      Serial.println("MOVE");
    }
    // ---

    if(servo =="SP") {
      scan_limit=int_posCZ+stepperCZ.currentPosition ();
      scanit=1;
      moveit=0;
      Serial.println("SCAN Mode-positive started");
            DZAC=1;
    }
    
    if(servo =="SN") {
      scan_limit=-int_posCZ+stepperCZ.currentPosition ();
      scanit=1;
      moveit=0;
      Serial.println("SCAN Mode-negative started");
      DZAC=-1;
    }

    if(servo =="SPDZ") {
      scan_limitDZ=int_posDZ+stepperDZ.currentPosition ();
      scanit=1;
      moveit=0;
      Serial.println("SCAN Mode DZ-positive started");
            DZAC=1;
         
    }
    
    if(servo =="SNDZ") {
      scan_limitDZ=-int_posDZ+stepperDZ.currentPosition ();
      scanit=1;
      moveit=0;
      Serial.println("SCAN Mode DZ-negative started");
      DZAC=-1;
    }

    if(servo =="S") {
      scanit=0;
      moveit=1;
//      stepperCX.stop(); // smoother stop
      stepperCX.moveTo(stepperCX.currentPosition ());   // Full inmediate stop
      stepperCY.moveTo(stepperCY.currentPosition ());
      stepperCZ.moveTo(stepperCZ.currentPosition ());
      stepperDZ.moveTo(stepperDZ.currentPosition ());
      stepperSX.moveTo(stepperSX.currentPosition ());
      stepperSY.moveTo(stepperSY.currentPosition ());
      stepperSZ.moveTo(stepperSZ.currentPosition ());
      stepperWX.moveTo(stepperWX.currentPosition ());
      stepperWY.moveTo(stepperWY.currentPosition ());
      stepperWZ.moveTo(stepperWZ.currentPosition ());
      move_finishedCX=0;
      move_finishedCY=0;
      move_finishedCZ=0;
      move_finishedDZ=0;
      move_finishedSX=0;
      move_finishedSY=0;
      move_finishedSZ=0;
      move_finishedWX=0;
      move_finishedWY=0;
      move_finishedWZ=0;
      Serial.println("STOP");
      scan_limit=0;
    }
  }
  // --------------------- End of while(Serial) -----------------------------

  // --------------------- Endswitch stop logic -----------------------------
  if(digitalRead(SXmin)){
    if(!endswitch_state[0]){      // checks if is the first time entering the loop
      stepperSX.setSpeed(0.0);    // stops the motor
      stepperSX.moveTo(stepperSX.currentPosition());
      endswitch_state[0] = true;  // states that the motor has been stopped
      Serial.println("SXmin reached");
    }else{
      if(stepperSX.targetPosition()-stepperSX.currentPosition()<0){   // if it wants to go further back
        stepperSX.setSpeed(0.0);                                      // do not allow it
        stepperSX.moveTo(stepperSX.currentPosition ());
      }
    }
  }else if(digitalRead(SXmax)){
    if(!endswitch_state[1]){      // checks if is the first time entering the loop
      stepperSX.setSpeed(0.0);    // stops the motor
      stepperSX.moveTo(stepperSX.currentPosition());
      endswitch_state[1] = true;  // states that the motor has been stopped
      Serial.println("SXmax reached");
    }else{
      if(stepperSX.targetPosition()-stepperSX.currentPosition()>0){   // if it wants to go further forward
        stepperSX.setSpeed(0.0);                                      // do not allow it
        stepperSX.moveTo(stepperSX.currentPosition ());
      }
    }
  }else{
    endswitch_state[0] = false;
    endswitch_state[1] = false;
  }
  
  if(digitalRead(SYmin)){
    if(!endswitch_state[2]){      // checks if is the first time entering the loop
      stepperSY.setSpeed(0.0);    // stops the motor
      stepperSY.moveTo(stepperSY.currentPosition());
      endswitch_state[2] = true;  // states that the motor has been stopped
      Serial.println("SYmin reached");
    }else{
      if(stepperSY.targetPosition()-stepperSY.currentPosition()<0){   // if it wants to go further back
        stepperSY.setSpeed(0.0);                                      // do not allow it
        stepperSY.moveTo(stepperSY.currentPosition ());
      }
    }
  }else if(digitalRead(SYmax)){
    if(!endswitch_state[3]){      // checks if is the first time entering the loop
      stepperSY.setSpeed(0.0);    // stops the motor
      stepperSY.moveTo(stepperSY.currentPosition());
      endswitch_state[3] = true;  // states that the motor has been stopped
      Serial.println("SYmax reached");
    }else{
      if(stepperSY.targetPosition()-stepperSY.currentPosition()>0){   // if it wants to go further forward
        stepperSY.setSpeed(0.0);                                      // do not allow it
        stepperSY.moveTo(stepperSY.currentPosition ());
      }
    }
  }else{
    endswitch_state[2] = false;
    endswitch_state[3] = false;
  }

  if(digitalRead(SZmin)){
    if(!endswitch_state[4]){
      stepperSZ.setSpeed(0.0);    // stops the motor
      stepperSZ.moveTo(stepperSZ.currentPosition());
      endswitch_state[4] = true;  // states that the motor has been stopped
      Serial.println("SZmin reached");
    }else{
      if(stepperSZ.targetPosition()-stepperSZ.currentPosition()<0){   // if it wants to go further down
        stepperSZ.setSpeed(0.0);                                      // do not allow it
        stepperSZ.moveTo(stepperSZ.currentPosition ());
      }
    }
  }else if(digitalRead(SZmax)){
    if(!endswitch_state[5]){
      stepperSZ.setSpeed(0.0);    // stops the motor
      stepperSZ.moveTo(stepperSZ.currentPosition());
      endswitch_state[5] = true;  // states that the motor has been stopped
      Serial.println("SZmax reached");
    }else{
      if(stepperSZ.targetPosition()-stepperSZ.currentPosition()>0){   // if it wants to go further up
        stepperSZ.setSpeed(0.0);                                      // do not allow it
        stepperSZ.moveTo(stepperSZ.currentPosition ());
      }
    }
  }else{
    endswitch_state[4] = false;
    endswitch_state[5] = false;
  }
  // -------- endswitch of wave generator -------
  if(digitalRead(WXmin)){
    if(!endswitch_state[6]){      // checks if is the first time entering the loop
      stepperWX.setSpeed(0.0);    // stops the motor
      stepperWX.moveTo(stepperWX.currentPosition());
      endswitch_state[6] = true;  // states that the motor has been stopped
      Serial.println("WXmin reached");
    }else{
      if(stepperWX.targetPosition()-stepperWX.currentPosition()<0){   // if it wants to go further back
        stepperWX.setSpeed(0.0);                                      // do not allow it
        stepperWX.moveTo(stepperWX.currentPosition ());
      }
    }
  }else if(digitalRead(WXmax)){
    if(!endswitch_state[7]){      // checks if is the first time entering the loop
      stepperWX.setSpeed(0.0);    // stops the motor
      stepperWX.moveTo(stepperWX.currentPosition());
      endswitch_state[7] = true;  // states that the motor has been stopped
      Serial.println("WXmax reached");
    }else{
      if(stepperWX.targetPosition()-stepperWX.currentPosition()>0){   // if it wants to go further forward
        stepperWX.setSpeed(0.0);                                      // do not allow it
        stepperWX.moveTo(stepperWX.currentPosition ());
      }
    }
  }else{
    endswitch_state[6] = false;
    endswitch_state[7] = false;
  }
  
  if(digitalRead(WYmin)){
    if(!endswitch_state[8]){      // checks if is the first time entering the loop
      stepperWY.setSpeed(0.0);    // stops the motor
      stepperWY.moveTo(stepperWY.currentPosition());
      endswitch_state[8] = true;  // states that the motor has been stopped
      Serial.println("WYmin reached");
    }else{
      if(stepperWY.targetPosition()-stepperWY.currentPosition()<0){   // if it wants to go further back
        stepperWY.setSpeed(0.0);                          // do not allow it
        stepperWY.moveTo(stepperWY.currentPosition ());
      }
    }
  }else if(digitalRead(WYmax)){
    if(!endswitch_state[9]){      // checks if is the first time entering the loop
      stepperWY.setSpeed(0.0);    // stops the motor
      stepperWY.moveTo(stepperWY.currentPosition());
      endswitch_state[9] = true;  // states that the motor has been stopped
      Serial.println("WYmax reached");
    }else{
      if(stepperWY.targetPosition()-stepperWY.currentPosition()>0){   // if it wants to go further forward
        stepperWY.setSpeed(0.0);                                      // do not allow it
        stepperWY.moveTo(stepperWY.currentPosition ());
      }
    }
  }else{
    endswitch_state[8] = false;
    endswitch_state[9] = false;
  }

  if(digitalRead(WZmin)){
    if(!endswitch_state[10]){      // checks if is the first time entering the loop
      stepperWZ.setSpeed(0.0);    // stops the motor
      stepperWZ.moveTo(stepperWZ.currentPosition());
      endswitch_state[10] = true;  // states that the motor has been stopped
      Serial.println("WZmin reached");
    }else{
      if(stepperWZ.targetPosition()-stepperWZ.currentPosition()<0){   // if it wants to go further back
        stepperWZ.setSpeed(0.0);                          // do not allow it
        stepperWZ.moveTo(stepperWZ.currentPosition ());
      }
    }
  }else if(digitalRead(WZmax)){
    if(!endswitch_state[11]){      // checks if is the first time entering the loop
      stepperWZ.setSpeed(0.0);    // stops the motor
      stepperWZ.moveTo(stepperWZ.currentPosition());
      endswitch_state[11] = true;  // states that the motor has been stopped
      Serial.println("WYmax reached");
    }else{
      if(stepperWZ.targetPosition()-stepperWZ.currentPosition()>0){   // if it wants to go further forward
        stepperWZ.setSpeed(0.0);                                      // do not allow it
        stepperWZ.moveTo(stepperWZ.currentPosition ());
      }
    }
  }else{
    endswitch_state[10] = false;
    endswitch_state[11] = false;
  }
  // --------------------- Endswitch stop logic [END] -----------------------

  if(scanit==1 && Serial.available()==0) { 
    digitalWrite(inPin,HIGH) ;     // read the input pin
    delay(10); 
    digitalWrite(inPin,LOW);
//      delay(1500); 
    delay(125);

    if(Serial.available()==0 && servo =="SP" || Serial.available()==0 && servo =="SN") {   
      stepperCZ.runToNewPosition(stepperCZ.currentPosition ()+(DZAC)*micron_per_scan);
      val =0;         
      Serial.print("Pos: ");
      Serial.print(stepperCZ.currentPosition ()/cfcCZ);
      Serial.println(" micron");    
    }

    if(Serial.available()==0 && servo =="SPDZ" || Serial.available()==0 && servo =="SNDZ") {   
      stepperDZ.runToNewPosition(stepperDZ.currentPosition ()+(DZAC)*micron_per_scanDZ);
      val =0;         
      Serial.print("Pos: ");
      Serial.print(stepperDZ.currentPosition ()/cfcDZ);
      Serial.println(" micron");    
    }
    
//Serial.print("scan_limit: ");
//Serial.print(scan_limit);
//Serial.print("stepperCZ.currentPosition ()");
//Serial.print(stepperCZ.currentPosition ());
    
  }

  if(servo =="SP") {
    if ((stepperCZ.currentPosition () > scan_limit) && scanit==1) {
      Serial.println("scheisse!");    
      Serial.print("Pos: ");
      Serial.print(stepperCZ.currentPosition ()/cfcCZ);
      Serial.println(" micron");
      move_finishedCZ=1;                           // Reset move variable
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

  if(servo =="SN") {
    if ((stepperCZ.currentPosition () < scan_limit) && scanit==1) {
      Serial.println("scheisse!");
      Serial.print("Pos: ");
      Serial.print(stepperCZ.currentPosition ()/cfcCZ);
      Serial.println(" micron");
      move_finishedCZ=1;                           // Reset move variable
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

  if(servo =="SPDZ") {
    if ((stepperDZ.currentPosition () > scan_limitDZ) && scanit==1) {
      Serial.println("scheisse!");    
      Serial.print("Pos: ");
      Serial.print(stepperDZ.currentPosition ()/cfcDZ);
      Serial.println(" micron");
      move_finishedDZ=1;                           // Reset move variable
      moveit=0;
      scanit=0;
      help=0;
      scan_limitDZ=0;
      Serial.print("help: ");
      Serial.println(help);
      Serial.print("scan_limit: ");
      Serial.println(scan_limitDZ);
    }
  }

  if(servo =="SNDZ") {
    if ((stepperDZ.currentPosition () < scan_limitDZ) && scanit==1) {
      Serial.println("scheisse!");    
      Serial.print("Pos: ");
      Serial.print(stepperDZ.currentPosition ()/cfcDZ);
      Serial.println(" micron");
      move_finishedDZ=1;                           // Reset move variable
      moveit=0;
      scanit=0;
      help=0;
      scan_limitDZ=0;
      Serial.print("help: ");
      Serial.println(help);
      Serial.print("scan_limit: ");
      Serial.println(scan_limitDZ);
    }
  }

  if(moveit==1) {
    if (stepperCX.distanceToGo() != 0) {    
      stepperCX.run();                            // Move Stepper into position    
     // Serial.println("RunCX");
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedCX == 0) && (stepperCX.distanceToGo() == 0)) {
      Serial.print("PosCX: ");
      Serial.print(stepperCX.currentPosition ()/cfcCX);   
      Serial.print("| PosY: ");
      Serial.print(stepperCY.currentPosition ()/cfcCY);    
      Serial.print("| PosCZ: ");
      Serial.print(stepperCZ.currentPosition ()/cfcCZ);
      Serial.print("| micron");
      Serial.print("| PosDZ: ");
      Serial.print(stepperDZ.currentPosition ()/cfcDZ);
      Serial.println("| micron");
      move_finishedCX=1;                           // Reset move variable
      moveit=0;
    }
  
    if (stepperCY.distanceToGo() != 0) {    
      stepperCY.run();                            // Move Stepper into position    
      //Serial.println("RunCY");
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedCY == 0) && (stepperCY.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");    
      move_finishedCY=1;                           // Reset move variable
      moveit=0;
    }
    
    if (stepperCZ.distanceToGo() != 0) {    
      stepperCZ.run();                            // Move Stepper into position    
      //Serial.println("RunCZ");
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedCZ == 0) && (stepperCZ.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      move_finishedCZ=1;                           // Reset move variable
      moveit=0;
    }

   if (stepperDZ.distanceToGo() != 0) {    
      stepperDZ.run();                            // Move Stepper into position    
      //Serial.println("RunCZ");
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedDZ == 0) && (stepperDZ.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      move_finishedDZ=1;                           // Reset move variable
      moveit=0;
    }

  // New --------------------- Sensor movement
    if (stepperSX.distanceToGo() != 0) {    
      stepperSX.run();                            // Move Stepper into position
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedSX == 0) && (stepperSX.distanceToGo() == 0)) {
      Serial.print("| PosDZ: ");
      Serial.print(stepperDZ.currentPosition ()/cfcDZ);
      Serial.println("| micron");
      move_finishedSX=1;                           // Reset move variable
      moveit=0;
    }
  
    if (stepperSY.distanceToGo() != 0) {    
      stepperSY.run();                            // Move Stepper into position    
      //Serial.println("RunY");
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedSY == 0) && (stepperSY.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");    
      move_finishedSY=1;                           // Reset move variable
      moveit=0;
    }
    
    if (stepperSZ.distanceToGo() != 0) {    
      stepperSZ.run();                            // Move Stepper into position    
      //Serial.println("RunZ");
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedSZ == 0) && (stepperSZ.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      move_finishedSZ=1;                           // Reset move variable
      moveit=0;
    }

    // New --------------------- Wave generator movement
    if (stepperWX.distanceToGo() != 0) {    
      stepperWX.run();                            // Move Stepper into position
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedWX == 0) && (stepperWX.distanceToGo() == 0)) {
      move_finishedWX=1;                           // Reset move variable
      moveit=0;
    }
  
    if (stepperWY.distanceToGo() != 0) {    
      stepperWY.run();                            // Move Stepper into position
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedWY == 0) && (stepperWY.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");    
      move_finishedWY=1;                           // Reset move variable
      moveit=0;
    }
    
    if (stepperWZ.distanceToGo() != 0) {    
      stepperWZ.run();                            // Move Stepper into position    
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedWZ == 0) && (stepperWZ.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      move_finishedWZ=1;                           // Reset move variable
      moveit=0;
    }    
  }
}
