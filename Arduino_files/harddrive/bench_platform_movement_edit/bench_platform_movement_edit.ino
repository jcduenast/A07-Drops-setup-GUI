// Version adjusted by: Juan Duenas - e-mail: jcduenast@unal.edu.co
// no-sufix means movement of camera setup
// sufix-S stands for Sensor
// sufix-W stands for Wave-Generator
// -> 6 additional motors added. No changes in the logic
// -> Adding end of line sensors

#include "AccelStepper.h" 

#define home_switch5 40 // Not in use
#define home_switch6 42 // Not in use

AccelStepper stepperX(1, 2, 3);    // 1 = Easy Driver interface, 2 STEP, 3 DIR
AccelStepper stepperY(1, 6, 7);    // 1 = Easy Driver interface, 6 STEP, 7 DIR
AccelStepper stepperZ(1, 4, 5);    // 1 = Easy Driver interface, 4 STEP, 5 DIR
AccelStepper stepperF(1, 8, 9);    // 1 = Easy Driver interface, 8 STEP, 9 DIR

// new
AccelStepper stepperXS(1, 14, 15);    // 1 = Easy Driver interface, 14 STEP, 15 DIR
AccelStepper stepperYS(1, 16, 17);    // 1 = Easy Driver interface, 16 STEP, 17 DIR
AccelStepper stepperZS(1, 18, 19);    // 1 = Easy Driver interface, 18 STEP, 19 DIR

AccelStepper stepperXW(1, 24, 25);    // 1 = Easy Driver interface, 24 STEP, 25 DIR
AccelStepper stepperYW(1, 22, 23);    // 1 = Easy Driver interface, 22 STEP, 23 DIR
AccelStepper stepperZW(1, 20, 21);    // 1 = Easy Driver interface, 20 STEP, 21 DIR
//

                                   
int ledPin = 13;                   // LED connected to digital pin 13
int inPin = 11;                    // pushbutton connected to digital pin 11. Is declared as an output why?
int val = 0;                       // variable to store the read value
int valsum =0;
int scanit=0;
int moveit=0;
int move_finishedX=1;
int move_finishedY=1;
int move_finishedZ=1;
int move_finishedF=1;
int move_finishedXS=1;  // new
int move_finishedYS=1;  // new
int move_finishedZS=1;  // new
int move_finishedXW=1;  // new
int move_finishedYW=1;  // new
int move_finishedZW=1;  // new
int FAC=1;
int N_pic=1;
// steps(eingegeben)/micrometer(gemessen)
float cfcX=1.28;
float cfcY=1.28;
//float cfcZ=1/0.78;
//float cfcZ=100000/78000;
//float cfcZ=1.28205;
//float cfcZ=0.645161;
float cfcZ=3.2;
//float cfcZ=1;
float cfcF=6.4;
const float cfcXS=0.3759398;  // new
const float cfcYS=0.3759398;  // new
const float cfcZS=0.7462686;  // new
const float cfcXW=0.3759398;  // new
const float cfcYW=0.3759398;  // new
const float cfcZW=0.7462686;  // new

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
float int_posXW=0;  // new
float int_posYW=0;  // new
float int_posZW=0;  // new
float scan_ende=0;
float scan_limit=0;
float scan_endeF=0; // why independent?
float scan_limitF=0;// why independent?
int help=0;

String servo;
String pos;


long TravelX;                     // Used to store the X value entered in the Serial Monitor
long TravelY;                     // Used to store the Y value entered in the Serial Monitor
long TravelZ;                     // Used to store the Z value entered in the Serial Monitor
long TravelF;                     // Used to store the Z value entered in the Serial Monitor
long TravelXS;                    // Used to store the XS value entered in the Serial Monitor (new)
long TravelYS;                    // Used to store the YS value entered in the Serial Monitor (new)
long TravelZS;                    // Used to store the ZS value entered in the Serial Monitor (new)
long TravelXW;                    // Used to store the XS value entered in the Serial Monitor (new)
long TravelYW;                    // Used to store the YS value entered in the Serial Monitor (new)
long TravelZW;                    // Used to store the ZS value entered in the Serial Monitor (new)
int move_finished1=1;             // Used to check if move is completed - What does 1 or 0 means?
long initial_homing1=-1;          // Used to Home Stepper at startup

// ------- Endswitch setup -----------
const int XSmin = 27;
const int XSmax = 29;
const int YSmin = 31;
const int YSmax = 33;
const int ZSmin = 35;
const int ZSmax = 37;

const int XWmin = 26;
const int XWmax = 28;
const int YWmin = 30;
const int YWmax = 32;
const int ZWmin = 34;
const int ZWmax = 36;
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
  pinMode(8, OUTPUT);     // F-Axis
  pinMode(9, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  pinMode(14, OUTPUT);   // new XS-Axis
  pinMode(15, OUTPUT);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
  pinMode(16, OUTPUT);   // new YS-Axis
  pinMode(17, OUTPUT);
  digitalWrite(16, LOW);
  digitalWrite(17, LOW);
  pinMode(18, OUTPUT);   // new ZS-Axis
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
  pinMode(XSmin, INPUT);
  pinMode(XSmax, INPUT);
  pinMode(YSmin, INPUT);
  pinMode(YSmax, INPUT);
  pinMode(ZSmin, INPUT);
  pinMode(ZSmax, INPUT);

  
  stepperX.setMaxSpeed(30000.0);        // Set Max Speed of Stepper (Faster for regular movements)
  stepperX.setAcceleration(2000.0);     // Set Acceleration of Stepper
  stepperY.setMaxSpeed(30000.0);        // Set Max Speed of Stepper (Faster for regular movements)
  stepperY.setAcceleration(2000.0);     // Set Acceleration of Stepper
  stepperZ.setMaxSpeed(30000.0);        // Set Max Speed of Stepper (Faster for regular movements)
  stepperZ.setAcceleration(2000.0);     // Set Acceleration of Stepper
  stepperF.setMaxSpeed(60000.0);        // Set Max Speed of Stepper (Faster for regular movements)
  stepperF.setAcceleration(5000.0);     // Set Acceleration of Stepper

  // new --------------------------
  stepperXS.setMaxSpeed(30000.0);       // Set Max Speed of Stepper (Faster for regular movements)
  stepperXS.setAcceleration(1000.0);    // Set Acceleration of Stepper
  stepperYS.setMaxSpeed(30000.0);       // Set Max Speed of Stepper (Faster for regular movements)
  stepperYS.setAcceleration(1000.0);    // Set Acceleration of Stepper
  stepperZS.setMaxSpeed(10000.0);       // Set Max Speed of Stepper (Faster for regular movements)
  stepperZS.setAcceleration(1000.0);    // Set Acceleration of Stepper
  stepperXW.setMaxSpeed(30000.0);       // Set Max Speed of Stepper (Faster for regular movements)
  stepperXW.setAcceleration(1000.0);    // Set Acceleration of Stepper
  stepperYW.setMaxSpeed(30000.0);       // Set Max Speed of Stepper (Faster for regular movements)
  stepperYW.setAcceleration(1000.0);    // Set Acceleration of Stepper
  stepperZW.setMaxSpeed(10000.0);       // Set Max Speed of Stepper (Faster for regular movements)
  stepperZW.setAcceleration(1000.0);    // Set Acceleration of Stepper
  //

  
}

void loop() {

  while (Serial.available()>0)  {   // Check if values are available in the Serial Buffer
  
    servo = Serial.readStringUntil(':');  // Slices the servo name out of the input
    pos = Serial.readStringUntil('&');    // gets the desired position
    int_posX=cfcX*pos.toFloat();
    int_posY=cfcY*pos.toFloat();
    int_posZ=cfcZ*pos.toFloat();
    int_posF=cfcF*pos.toFloat();
    int_posXS=cfcXS*pos.toFloat();       // new
    int_posYS=cfcYS*pos.toFloat();       // new
    int_posZS=cfcZS*pos.toFloat();       // new
    int_posXW=cfcXW*pos.toFloat();       // new
    int_posYW=cfcYW*pos.toFloat();       // new
    int_posZW=cfcZW*pos.toFloat();       // new
    
    Serial.print("help=");
    Serial.println(help);

//  scan_limit=int_posZ+stepperZ.currentPosition ();  // stores the new final position ?
//  scan_limitF=int_posF+stepperF.currentPosition (); // stores the new final position ?

    if(servo =="XZ") {
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

    if(servo =="YZ") {
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
    
    if(servo =="ZZ") {
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

    if(servo =="FZ") {
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
    if(servo =="XSZ") {
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

    if(servo =="YSZ") {
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
    
    if(servo =="ZSZ") {
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
    
    
    if(servo =="MX") {
      scanit=0;
      moveit=1;
      stepperX.moveTo(int_posX);
      move_finishedX=0;
      Serial.println("MOVE"); 
    }
    
    if(servo =="MY") {
      scanit=0;
      moveit=1;
      stepperY.moveTo(int_posY);
      move_finishedY=0;
      Serial.println("MOVE"); 
    }
    
    if(servo =="MZ") {
      scanit=0;
      moveit=1;
      stepperZ.moveTo(int_posZ);
      move_finishedZ=0;
      Serial.println("MOVE"); 
    }

    if(servo =="MF") {
      scanit=0;
      moveit=1;
      stepperF.moveTo(int_posF);
      move_finishedF=0;
      Serial.println("MOVE"); 
    }

    // new -----------------
    if(servo =="MXS") {
      scanit=0;
      moveit=1;
      stepperXS.moveTo(int_posXS);
      move_finishedXS=0;
      Serial.println("MOVE"); 
    }
    
    if(servo =="MYS") {
      scanit=0;
      moveit=1;
      stepperYS.moveTo(int_posYS);
      move_finishedYS=0;
      Serial.println("MOVE"); 
    }
    
    if(servo =="MZS") {
      scanit=0;
      moveit=1;
      stepperZS.moveTo(int_posZS);
      move_finishedZS=0;
      Serial.println("MOVE"); 
    }

    if(servo =="MXW") {
      scanit=0;
      moveit=1;
      stepperXW.moveTo(int_posXW);
      move_finishedXW=0;
      Serial.println("MOVE"); 
    }
    
    if(servo =="MYW") {
      scanit=0;
      moveit=1;
      stepperYW.moveTo(int_posYW);
      move_finishedYW=0;
      Serial.println("MOVE"); 
    }
    
    if(servo =="MZW") {
      scanit=0;
      moveit=1;
      stepperZW.moveTo(int_posZW);
      move_finishedZW=0;
      Serial.println("MOVE"); 
    }
    // ---

    if(servo =="RX") {
      scanit=0;
      moveit=1;
      stepperX.moveTo(int_posX+stepperX.currentPosition ());
      move_finishedX=0;
      Serial.println("MOVE");
    }
    
    if(servo =="RY") {
      scanit=0;
      moveit=1;
      stepperY.moveTo(int_posY+stepperY.currentPosition ());
      move_finishedY=0;
      Serial.println("MOVE");
    }
    
    if(servo =="RZ") {
      scanit=0;
      moveit=1;
      stepperZ.moveTo(int_posZ+stepperZ.currentPosition ());
      move_finishedZ=0;
      Serial.println("MOVE");
    }

      if(servo =="RF") {
      scanit=0;
      moveit=1;
      stepperF.moveTo(int_posF+stepperF.currentPosition ());
      move_finishedF=0;
      Serial.println("MOVE");
    }

    // NEW ----------------------------
    if(servo =="RXS") {
      scanit=0;
      moveit=1;
      stepperXS.moveTo(int_posXS+stepperXS.currentPosition ());
      move_finishedXS=0;
      Serial.println("MOVE");
    }
    
    if(servo =="RYS") {
      scanit=0;
      moveit=1;
      stepperYS.moveTo(int_posYS+stepperYS.currentPosition ());
      move_finishedYS=0;
      Serial.println("MOVE");
    }
    
    if(servo =="RZS") {
      scanit=0;
      moveit=1;
      stepperZS.moveTo(int_posZS+stepperZS.currentPosition ());
      move_finishedZS=0;
      Serial.println("MOVE");
    }

    if(servo =="RXW") {
      scanit=0;
      moveit=1;
      stepperXW.moveTo(int_posXW+stepperXW.currentPosition ());
      move_finishedXW=0;
      Serial.println("MOVE");
    }
    
    if(servo =="RYW") {
      scanit=0;
      moveit=1;
      stepperYW.moveTo(int_posYW+stepperYW.currentPosition ());
      move_finishedYW=0;
      Serial.println("MOVE");
    }
    
    if(servo =="RZW") {
      scanit=0;
      moveit=1;
      stepperZW.moveTo(int_posZW+stepperZW.currentPosition ());
      move_finishedZW=0;
      Serial.println("MOVE");
    }
    // ---

    if(servo =="SP") {
      scan_limit=int_posZ+stepperZ.currentPosition ();
      scanit=1;
      moveit=0;
      Serial.println("SCAN Mode-positive started");
            FAC=1;
    }
    
    if(servo =="SN") {
      scan_limit=-int_posZ+stepperZ.currentPosition ();
      scanit=1;
      moveit=0;
      Serial.println("SCAN Mode-negative started");
      FAC=-1;
    }

    if(servo =="SPF") {
      scan_limitF=int_posF+stepperF.currentPosition ();
      scanit=1;
      moveit=0;
      Serial.println("SCAN Mode F-positive started");
            FAC=1;
         
    }
    
    if(servo =="SNF") {
      scan_limitF=-int_posF+stepperF.currentPosition ();
      scanit=1;
      moveit=0;
      Serial.println("SCAN Mode F-negative started");
      FAC=-1;
    }

    if(servo =="S") {
      scanit=0;
      moveit=1;
//      stepperX.stop(); // smoother stop
      stepperX.moveTo(stepperX.currentPosition ());   // Full inmediate stop
      stepperY.moveTo(stepperY.currentPosition ());
      stepperZ.moveTo(stepperZ.currentPosition ());
      stepperF.moveTo(stepperF.currentPosition ());
      stepperXS.moveTo(stepperXS.currentPosition ());
      stepperYS.moveTo(stepperYS.currentPosition ());
      stepperZS.moveTo(stepperZS.currentPosition ());
      stepperXW.moveTo(stepperXW.currentPosition ());
      stepperYW.moveTo(stepperYW.currentPosition ());
      stepperZW.moveTo(stepperZW.currentPosition ());
      move_finishedX=0;
      move_finishedY=0;
      move_finishedZ=0;
      move_finishedF=0;
      move_finishedXS=0;
      move_finishedYS=0;
      move_finishedZS=0;
      move_finishedXW=0;
      move_finishedYW=0;
      move_finishedZW=0;
      Serial.println("STOP");
      scan_limit=0;
    }
  }
  // --------------------- End of while(Serial) -----------------------------

  if(digitalRead(XSmin)){
    Serial.println("XSmin");
    stepperXS.moveTo(stepperXS.currentPosition ());
    move_finishedXS=0;
  }
  if(digitalRead(XSmax)){
    Serial.println("XSmax");
    stepperXS.moveTo(stepperXS.currentPosition ());
    move_finishedXS=0;
  }
  if(digitalRead(YSmin)){
    Serial.println("YSmin");
    stepperYS.moveTo(stepperYS.currentPosition ());
    move_finishedYS=0;
  }
  if(digitalRead(YSmax)){
    Serial.println("YSmax");
    stepperYS.moveTo(stepperYS.currentPosition ());
    move_finishedYS=0;
  }
  if(digitalRead(XWmin)){
    Serial.println("XWmin");
    stepperXW.moveTo(stepperXW.currentPosition ());
    move_finishedXW=0;
  }
  if(digitalRead(XWmax)){
    Serial.println("XWmax");
    stepperXW.moveTo(stepperXW.currentPosition ());
    move_finishedXW=0;
  }
  if(digitalRead(YWmin)){
    Serial.println("YWmin");
    //stepperYW.moveTo(stepperYW.currentPosition ());
    //stepperYW.moveTo(stepperYW.currentPosition ());
    //stepperYW.setSpeed(0.0);
    // Serial.print(stepperYW.distanceToGo());
    //move_finishedYW=0;
  }
  if(digitalRead(YWmax)){
    Serial.println("YWmax");
    stepperYW.moveTo(stepperYW.currentPosition ());
    move_finishedYW=0;
  }

  if(scanit==1 && Serial.available()==0) {  
    digitalWrite(inPin,HIGH) ;     // read the input pin
    delay(10); 
    digitalWrite(inPin,LOW);
//      delay(1500); 
    delay(125);

    if(Serial.available()==0 && servo =="SP" || Serial.available()==0 && servo =="SN") {   
      stepperZ.runToNewPosition(stepperZ.currentPosition ()+(FAC)*micron_per_scan);
      val =0;         
      Serial.print("Pos: ");
      Serial.print(stepperZ.currentPosition ()/cfcZ);
      Serial.println(" micron");    
    }

    if(Serial.available()==0 && servo =="SPF" || Serial.available()==0 && servo =="SNF") {   
      stepperF.runToNewPosition(stepperF.currentPosition ()+(FAC)*micron_per_scanF);
      val =0;         
      Serial.print("Pos: ");
      Serial.print(stepperF.currentPosition ()/cfcF);
      Serial.println(" micron");    
    }
    
//Serial.print("scan_limit: ");
//Serial.print(scan_limit);
//Serial.print("stepperZ.currentPosition ()");
//Serial.print(stepperZ.currentPosition ());
    
  }

  if(servo =="SP") {
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

  if(servo =="SN") {
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

  if(servo =="SPF") {
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

  if(servo =="SNF") {
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

  if(moveit==1) {
    if (stepperX.distanceToGo() != 0) {    
      stepperX.run();                            // Move Stepper into position    
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
      stepperY.run();                            // Move Stepper into position    
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
      stepperZ.run();                            // Move Stepper into position    
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
      stepperF.run();                            // Move Stepper into position    
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
      stepperXS.run();                            // Move Stepper into position
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
      stepperYS.run();                            // Move Stepper into position    
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
      stepperZS.run();                            // Move Stepper into position    
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

    // New --------------------- Wave generator movement
    if (stepperXW.distanceToGo() != 0) {    
      stepperXW.run();                            // Move Stepper into position
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedXW == 0) && (stepperXW.distanceToGo() == 0)) {
      Serial.print("PosX: ");
      Serial.print(stepperXW.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperYW.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZW.currentPosition ()/cfcZ);
      Serial.println("| micron");
      move_finishedXW=1;                           // Reset move variable
      moveit=0;
    }
  
    if (stepperYW.distanceToGo() != 0) {    
      stepperYW.run();                            // Move Stepper into position
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedYW == 0) && (stepperYW.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");    
      Serial.print("PosX: ");
      Serial.print(stepperXW.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperYW.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZW.currentPosition ()/cfcZ);
      Serial.println("| micron");
      move_finishedYW=1;                           // Reset move variable
      moveit=0;
    }
    
    if (stepperZW.distanceToGo() != 0) {    
      stepperZW.run();                            // Move Stepper into position    
    }

    // If move is completed display message on Serial Monitor
    if ((move_finishedZW == 0) && (stepperZW.distanceToGo() == 0)) {
      Serial.println("COMPLETED!");
      Serial.print("PosX: ");
      Serial.print(stepperXW.currentPosition ()/cfcX);   
      Serial.print("| PosY: ");
      Serial.print(stepperYW.currentPosition ()/cfcY);    
      Serial.print("| PosZ: ");
      Serial.print(stepperZW.currentPosition ()/cfcZ);
      Serial.println("| micron");
      move_finishedZW=1;                           // Reset move variable
      moveit=0;
    }    
  }
}
