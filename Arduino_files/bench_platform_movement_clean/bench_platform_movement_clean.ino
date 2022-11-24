// Written by Juan Duenas: jcduenast@unal.edu.co
// for SLA Project A07
// A change of variable names and Serial coding is applied
// for compatibility issues with the GUI, try the _edit version

#include "AccelStepper.h"

// Cameras motors
AccelStepper stepperCX(1, 2, 3);    // 1 = Easy Driver interface, 2 STEP, 3 DIR
AccelStepper stepperCY(1, 6, 7);    // 1 = Easy Driver interface, 6 STEP, 7 DIR
AccelStepper stepperCZ(1, 4, 5);    // 1 = Easy Driver interface, 4 STEP, 5 DIR

// Sensor motors
AccelStepper stepperSX(1, 14, 15);  // 1 = Easy Driver interface, 14 STEP, 15 DIR
AccelStepper stepperSY(1, 16, 17);  // 1 = Easy Driver interface, 16 STEP, 17 DIR
AccelStepper stepperSZ(1, 18, 19);  // 1 = Easy Driver interface, 18 STEP, 19 DIR

// Wave generator motors
AccelStepper stepperWX(1, 24, 25);  // 1 = Easy Driver interface, 24 STEP, 25 DIR
AccelStepper stepperWY(1, 22, 23);  // 1 = Easy Driver interface, 22 STEP, 23 DIR
AccelStepper stepperWZ(1, 20, 21);  // 1 = Easy Driver interface, 20 STEP, 21 DIR

// Drops motor
AccelStepper stepperDZ(1, 8, 9);    // 1 = Easy Driver interface, 8 STEP, 9 DIR

// Inicializar variables
bool move_finished = true;
// steps to um calibration values : steps(eingegeben)/micrometer(gemessen)
const float um2sCX = 1.28;
const float um2sCY = 1.28;
const float um2sCZ = 3.2;
const float um2sSX = 0.3759398;
const float um2sSY = 0.3759398;
const float um2sSZ = 0.7462686;
const float um2sWX = 0.3759398;
const float um2sWY = 0.3759398;
const float um2sWZ = 0.7462686;
const float um2sDZ = 6.4;

String cmd;
String val;

// End-switch variables
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


void setup(){
  Serial.begin(9600);                 // Start the Serial monitor with speed of 9600 Bauds    
  delay(5);                           // Wait for EasyDriver wake up

  // initialization of pinMode(PinNumber, OUTPUT) is not necesary
  
  // Sensor input pins
  pinMode(SXmin, INPUT);
  pinMode(SXmax, INPUT);
  pinMode(SYmin, INPUT);
  pinMode(SYmax, INPUT);
  pinMode(SZmin, INPUT);
  pinMode(SZmax, INPUT);
  pinMode(WXmin, INPUT);
  pinMode(WXmax, INPUT);
  pinMode(WYmin, INPUT);
  pinMode(WYmax, INPUT);
  pinMode(WZmin, INPUT);
  pinMode(WZmax, INPUT);
  
  // Motor movement variable initialization
  stepperCX.setMaxSpeed(30000.0);     // Set Max Speed of Stepper (Faster for regular movements)
  stepperCX.setAcceleration(2000.0);  // Set Acceleration of Stepper
  stepperCY.setMaxSpeed(30000.0);
  stepperCY.setAcceleration(2000.0);
  stepperCZ.setMaxSpeed(30000.0);
  stepperCZ.setAcceleration(2000.0);
  stepperSX.setMaxSpeed(30000.0);
  stepperSX.setAcceleration(1000.0);
  stepperSY.setMaxSpeed(30000.0);
  stepperSY.setAcceleration(1000.0);
  stepperSZ.setMaxSpeed(10000.0);
  stepperSZ.setAcceleration(1000.0);
  stepperWX.setMaxSpeed(30000.0);
  stepperWX.setAcceleration(1000.0);
  stepperWY.setMaxSpeed(30000.0);
  stepperWY.setAcceleration(1000.0);
  stepperWZ.setMaxSpeed(10000.0);
  stepperWZ.setAcceleration(1000.0);
  stepperDZ.setMaxSpeed(60000.0);
  stepperDZ.setAcceleration(5000.0);
}

void loop(){
  // While Serial available
  while (Serial.available()>0){
    // procesar la entrada y asignar valores
    cmd = Serial.readStringUntil(':');  // Slices the servo name out of the input
    val = Serial.readStringUntil('&');    // gets the desired position
    // try: if (cmd!=0) {data = Serial.read...}
    Serial.println("1");

    // Comando de asignar posición como cero iZ

    // Comandos de movimiento absoluto Mi
    if (cmd[0] == "M"){
      if (cmd == "MCX"){  stepperCX.moveTo(um2sCX*val.toFloat()); }
      if (cmd == "MCY"){  stepperCY.moveTo(um2sCY*val.toFloat()); }
      else {              Serial.println("Command not supported");}
      move_finished = false;
    }
    
    // Comandos de movimiento relativo Ri
    if (cmd[0] == "R"){
      if (cmd == "RCX"){  stepperCX.moveTo(um2sCX*val.toFloat()+stepperCX.currentPosition ());  }
      if (cmd == "RCY"){  stepperCY.moveTo(um2sCY*val.toFloat()+stepperCY.currentPosition ());  }
      else {              Serial.println("Command not supported");                              }
      move_finished = false;
    }
    
    // Comandos de SCAN | not included

    // Comando de parada S | in the future, wire directly to the power supply
    if (cmd == "S"){
      stepperSX.setSpeed(0.0);    // stops the motor
      stepperSX.moveTo(stepperSX.currentPosition());
      stepperSY.setSpeed(0.0);    // stops the motor
      stepperSY.moveTo(stepperSX.currentPosition());
    }
  }

  // End-switch Logic
  if(digitalRead(SXmin)){
    if(!endswitch_state[0]){      // checks if is the first time entering the loop
      stepperSX.setSpeed(0.0);    // stops the motor
      stepperSX.moveTo(stepperSX.currentPosition());
      endswitch_state[0] = true;  // states that the motor has been stopped
      Serial.println("XSmin reached");
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
      Serial.println("XSmax reached");
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

  
  // if con scanit==1 - función indeterminada
  // procesado de comando SN SPF usw. | to be removed

  // if moveit=1 | stops stepperi.run() from excecuting (apparently)
  //    what is move_finishedi used for?
    // motor movement logic
      // try excecuting allways a stepper.run() instructions
      // send info once the movement is completed
  stepperCX.run();
  if (!move_finished && stepperCX.distanceToGo() == 0){
    Serial.print("CX at");
    Serial.println(stepperCX.currentPosition ()/um2sCX);
    move_finished = true;
  }
}
