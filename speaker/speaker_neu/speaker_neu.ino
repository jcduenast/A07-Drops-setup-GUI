int freq = 90;
int channel = 1;
int resolution = 8;
int duration = 20; //50;
int count = 1;
int wave_delay = 80;
int i;

void setup() {
  Serial.begin(115200);
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(17, channel);
  pinMode(15, INPUT);
}

void loop() {
  if (digitalRead(15)){
    run_sensor_function();
  }
  // Read and interpret serial input
  if (Serial.available() > 0) {
    // read serial input, if available
    String receivedString = "";
    
    while (Serial.available() > 0) {
      // read serial input
      int receivedByte = Serial.read();
      receivedString += (char)receivedByte;
    }
    if (receivedString.length() > 1) {
      int dlmIdx = receivedString.indexOf(" ");
      if (dlmIdx != -1) {
        // interpret string prior to delimiter as command and after delimiter as parameter
        String cmd = receivedString.substring(0, dlmIdx);
        String param = receivedString.substring(dlmIdx + 1, receivedString.length() - 1);
        
        if (cmd == "freq") {
          // Set set frequency of speaker
          freq = param.toFloat();
          Serial.print("frequency of speaker set to ");
          Serial.print(freq);
          Serial.println("Hz");
        } else if (cmd == "speaker" && param == "on") {
          //turn speaker on
          Serial.println("speaker is on");
          ledcWriteTone(channel, freq);
        } else if (cmd == "speaker" && param == "off") {
          //turn speaker off
          ledcWrite(channel, 0);
          Serial.println("speaker is off");
        } else if (cmd == "duration"){
          // Set tone duration
          duration = param.toFloat();
          Serial.print("duration set to ");
          Serial.print(duration);
          Serial.println("ms");
        } else if (cmd == "pulse" && param == "on") {
          //turn speaker on
          Serial.print("pulsing for ");
          Serial.println(duration);
          Serial.print(count);
          Serial.println(" times");
          for(i=0; i<count; i++) {
            ledcWriteTone(channel, freq);
            delay(duration);
            ledcWrite(channel,0);
            delay(1000);
          }
        } else if (cmd == "count"){
          // Set number of pulses
          count = param.toFloat();
          Serial.print("pulse count set to ");
          Serial.println(count);
        } else if (cmd == "wave_delay"){
          wave_delay = param.toFloat();
          Serial.print("wave delay set to ");
          Serial.println(wave_delay);
        }
      }
    }
//    delay(1000);
  }
}

void run_sensor_function(){
  //turn speaker on
  for(i=0; i<count; i++) {
    delay(wave_delay);
    ledcWriteTone(channel, freq);
    delay(duration);
    ledcWrite(channel,0);
    delay(20);
    Serial.print("pulsing for ");
    Serial.println(duration);
    Serial.print(count);
    Serial.println(" times");
    Serial.print("With a delay of ");
    Serial.print(wave_delay);
    Serial.println("ms");
  }
  
//  //turn speaker on
//  Serial.println("speaker is on");
//  ledcWriteTone(channel, freq);
//  delay(20);
//  ledcWrite(channel, 0);
}
