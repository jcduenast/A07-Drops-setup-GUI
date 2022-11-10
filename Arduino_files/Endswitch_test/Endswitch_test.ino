void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
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
  if(digitalRead(2)){
    Serial.println("2 data received");
  }
  if(digitalRead(3)){
    Serial.println("3 data received");
  }
  if(digitalRead(4)){
    Serial.println("4 data received");
  }
  if(digitalRead(5)){
    Serial.println("5 data received");
  }
  if(digitalRead(6)){
    Serial.println("6 data received");
  }
  if(digitalRead(7)){
    Serial.println("7 data received");
  }
}
