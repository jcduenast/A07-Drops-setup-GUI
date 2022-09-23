void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
}

void loop() {
//  if (Serial.available() > 0) {
//    String receivedString = "";
//    while (Serial.available() > 0) {
//      int receivedByte = Serial.read();
//      receivedString += (char)receivedByte;
//    }
//    if (receivedString.length() > 1) {
//      receivedString =
//    }
//  }
  if(digitalRead(7)){
    Serial.println("7 data received");
  }
  
  if(digitalRead(8)){
    Serial.println("8 data received");
  }
  if(digitalRead(9)){
    Serial.println("9 data received");
  }
  if(digitalRead(10)){
    Serial.println("10 data received");
  }
  if(digitalRead(11)){
    Serial.println("11 data received");
  }
  if(digitalRead(12)){
    Serial.println("12 data received");
  }
}
