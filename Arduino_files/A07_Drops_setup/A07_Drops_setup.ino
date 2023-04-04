// Version adjusted by: Juan Duenas - e-mail: jcduenast@unal.edu.co
// This is the clean version of the firmware
// prefix-C stands for Camera-rig
// prefix-D stands for Drops-mechanism
// prefix-S stands for Sensor-holder
// prefix-W stands for Wave-Generator

#include "AccelStepper.h"

AccelStepper stepperCX(1, 2, 3);    // 1 = Easy Driver interface, 2 STEP, 3 DIR
AccelStepper stepperCY(1, 6, 7);    // 1 = Easy Driver interface, 6 STEP, 7 DIR
AccelStepper stepperCZ(1, 4, 5);    // 1 = Easy Driver interface, 4 STEP, 5 DIR

AccelStepper stepperDZ(1, 8, 9);    // 1 = Easy Driver interface, 8 STEP, 9 DIR

AccelStepper stepperSX(1, 14, 15);    // 1 = Easy Driver interface, 14 STEP, 15 DIR
AccelStepper stepperSY(1, 16, 17);    // 1 = Easy Driver interface, 16 STEP, 17 DIR
AccelStepper stepperSZ(1, 18, 19);    // 1 = Easy Driver interface, 18 STEP, 19 DIR

AccelStepper stepperWX(1, 24, 25);    // 1 = Easy Driver interface, 24 STEP, 25 DIR
AccelStepper stepperWY(1, 22, 23);    // 1 = Easy Driver interface, 22 STEP, 23 DIR
AccelStepper stepperWZ(1, 20, 21);    // 1 = Easy Driver interface, 20 STEP, 21 DIR


                                   
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
int move_finishedSX=1;
int move_finishedSY=1;
int move_finishedSZ=1;
int move_finishedWX=1;
int move_finishedWY=1;
int move_finishedWZ=1;

int DZAC=1;
int N_pic=1;

// steps(eingegeben)/micrometer(gemessen)
float cfcCX=1.28;
float cfcCY=1.28;
float cfcCZ=3.2;
float cfcDZ=6.4;
const float cfcSX=0.3759398;
const float cfcSY=0.3759398;
const float cfcSZ=0.7462686;
const float cfcWX=0.3759398;
const float cfcWY=0.3759398;
const float cfcWZ=0.7462686;

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
long TravelCX;                    // Used to store the CX value entered in the Serial Monitor
long TravelCY;                    // Used to store the CY value entered in the Serial Monitor
long TravelCZ;                    // Used to store the CZ value entered in the Serial Monitor
long TravelDZ;                    // Used to store the Z value entered in the Serial Monitor
long TravelSX;                    // Used to store the SX value entered in the Serial Monitor
long TravelSY;                    // Used to store the SY value entered in the Serial Monitor
long TravelSZ;                    // Used to store the SZ value entered in the Serial Monitor
long TravelWX;                    // Used to store the WX value entered in the Serial Monitor
long TravelWY;                    // Used to store the WY value entered in the Serial Monitor
long TravelWZ;                    // Used to store the WZ value entered in the Serial Monitor
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

  
  stepperCX.setMaxSpeed(30000.0);        // Set Max Speed of Stepper (Faster for regular movements)
  stepperCX.setAcceleration(2000.0);     // Set Acceleration of Stepper
  stepperCY.setMaxSpeed(30000.0);        // Set Max Speed of Stepper (Faster for regular movements)
  stepperCY.setAcceleration(2000.0);     // Set Acceleration of Stepper
  stepperCZ.setMaxSpeed(30000.0);        // Set Max Speed of Stepper (Faster for regular movements)
  stepperCZ.setAcceleration(2000.0);     // Set Acceleration of Stepper
  stepperDZ.setMaxSpeed(30000.0);        // Set Max Speed of Stepper (Faster for regular movements)
  stepperDZ.setAcceleration(1000.0);     // Set Acceleration of Stepper
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
}

void loop() {

  while (Serial.available()>0)  {   // Check if values are available in the Serial Buffer
  
    servo = Serial.readStringUntil(':');  // Slices the servo name out of the input
    pos = Serial.readStringUntil('&');    // gets the desired position
    int_posCX=cfcCX*pos.toFloat();
    int_posCY=cfcCY*pos.toFloat();
    int_posCZ=cfcCZ*pos.toFloat();
    int_posDZ=cfcDZ*pos.toFloat();
    int_posSX=cfcSX*pos.toFloat();
    int_posSY=cfcSY*pos.toFloat();
    int_posSZ=cfcSZ*pos.toFloat();
    int_posWX=cfcWX*pos.toFloat();
    int_posWY=cfcWY*pos.toFloat();
    int_posWZ=cfcWZ*pos.toFloat();
    
    Serial.print("Useful print?");

    //--- Absolute movement ---

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
    
    //--- Relative movement ---

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
    
    //--- Emergency stop ---

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
  
  //--- Movement Logic ---

  if(moveit==1) {
    if (stepperCX.distanceToGo() != 0) {    
      stepperCX.run();                // Move Stepper into position
     // Serial.println("RunCX");
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedCX == 0) && (stepperCX.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      move_finishedCX=1;              // Reset move variable
      moveit=0;
    }
  
    if (stepperCY.distanceToGo() != 0) {    
      stepperCY.run();
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedCY == 0) && (stepperCY.distanceToGo() == 0)) {
      Serial.println("COMPLETED!"); 
      move_finishedCY=1;
      moveit=0;
    }
    
    if (stepperCZ.distanceToGo() != 0) {    
      stepperCZ.run();
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedCZ == 0) && (stepperCZ.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      move_finishedCZ=1;
      moveit=0;
    }

   if (stepperDZ.distanceToGo() != 0) {    
      stepperDZ.run();
    }

    if ((move_finishedDZ == 0) && (stepperDZ.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      move_finishedDZ=1;
      moveit=0;
    }

  // New --------------------- Sensor movement
    if (stepperSX.distanceToGo() != 0) {    
      stepperSX.run();
    }

    if ((move_finishedSX == 0) && (stepperSX.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      move_finishedSX=1;
      moveit=0;
    }
  
    if (stepperSY.distanceToGo() != 0) {    
      stepperSY.run();
    }

    if ((move_finishedSY == 0) && (stepperSY.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      move_finishedSY=1;
      moveit=0;
    }
    
    if (stepperSZ.distanceToGo() != 0) {    
      stepperSZ.run();
    }

    if ((move_finishedSZ == 0) && (stepperSZ.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      move_finishedSZ=1;
      moveit=0;
    }

    if (stepperWX.distanceToGo() != 0) {
      stepperWX.run();
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedWX == 0) && (stepperWX.distanceToGo() == 0)) {
      move_finishedWX=1;
      moveit=0;
    }
  
    if (stepperWY.distanceToGo() != 0) {
      stepperWY.run();
    }

    if ((move_finishedWY == 0) && (stepperWY.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");    
      move_finishedWY=1;
      moveit=0;
    }
    
    if (stepperWZ.distanceToGo() != 0) {
      stepperWZ.run();
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedWZ == 0) && (stepperWZ.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      move_finishedWZ=1;
      moveit=0;
    }    
  }
}
