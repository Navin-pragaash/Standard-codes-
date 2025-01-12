#define level 11
#define sensorTA12 26
#define relay1 11
#define relay2 12

bool isMotorOn = true; 
void setup() {
Serial.begin(9600);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
}
void loop() {
  int IntreceivedValue = 50;
      Serial.print("Water Level");

      if (IntreceivedValue < 10) 
                {
                digitalWrite(relay2, HIGH);
                delay(30);  
                }


      else if (IntreceivedValue > 10 && IntreceivedValue < 90)
            {
                digitalWrite(relay2, HIGH);
              delay(30);
                }
    
      else {
        digitalWrite(relay1, LOW);
        delay(30);
      }
}
float final() {
  float result;
  int readValue;    // value read from the sensor
  int maxValue = 0; // store max value here
  uint32_t start_time = millis();
  while ((millis() - start_time) < 1000) // sample for 1 Sec
  {
    readValue = analogRead(sensorTA12);
    // see if you have a new maxValue
    if (readValue > maxValue) {
      //record the maximum sensor value/
      maxValue = readValue;
    }
  }
  // Convert the digital data to a voltage
  result = (maxValue * 5.0) / 1024.0;
  float nVPP = result;
  float CurrThruResistorPP = (nVPP / 200.0) * 1000.0;
  float CurrThruResistorRMS = CurrThruResistorPP * 0.707;
  float CurrentThruWire = CurrThruResistorRMS * 1000;
  Serial.print(CurrentThruWire);
    return CurrentThruWire;
}

