int count = 0;
void setup(){
  Serial.begin(9600);              // Start the Serial monitor with speed of 9600 Bauds  
  pinMode(8, INPUT);
}

void loop(){
  if(digitalRead(8)){
    Serial.print("Detected: ");
    Serial.println(count);
    count++;
  }
}
