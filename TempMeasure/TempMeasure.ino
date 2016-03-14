const float baselineTemp = 20.0;
void setup() {
  //open a serial port. 9600 = how many bits per second will be transferred from the arduino to the Serial.
  Serial.begin(9600); 
  //Initializing all the pins
  for (int i=2; i<6; i++){
    //Sets the pin to output
    pinMode(i,OUTPUT);
    //Sets the beginning status to LOW
    digitalWrite(i,LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(A0);
  float voltageRead = (sensorVal / 1024.0) * 5.0;
  float temperature = (voltageRead - 0.5) * 100;
  Serial.print("Sensor: ");
  Serial.print(sensorVal);
  Serial.print(", Volts: ");
  Serial.print(voltageRead);
  Serial.print(", Degrees: ");
  Serial.print(temperature);
  Serial.print("\n");

  if(temperature <= baselineTemp){
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
  }else if(temperature >= baselineTemp && temperature < 22){
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
  }else if(temperature >= 22 && temperature < 24){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
  }else if(temperature >= 24 && temperature <27){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
  }else if(temperature >= 27){
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      if(digitalRead(5) == LOW)
        digitalWrite(5, HIGH);
      else
        digitalWrite(5, LOW);
  }
  delay(100);
}
