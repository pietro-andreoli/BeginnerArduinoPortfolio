const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;
void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  //Get whether the pushbutton is currently being pressed or not (0=no 1=yes)
  switchState = digitalRead(switchPin);
  //if it is being pushed, then supply power to the gate pin on the transistor, closing the circuit
  if(switchState == HIGH)
    digitalWrite(motorPin, HIGH);
  //else close the gate and open the circuit 
  else 
    digitalWrite(motorPin, LOW);
}
