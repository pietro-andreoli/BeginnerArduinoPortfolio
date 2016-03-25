#include <Servo.h>
Servo myServo;
int const potentiometer = A0;
int angle;
int instructions[500];
boolean instructionPeriod = true;
int count = 0;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
  digitalWrite(13, HIGH);
  myServo.write(0);
}

void loop() {
  Serial.print(count);
  Serial.print("\n");
  if(instructionPeriod && count == 499){
    instructionPeriod = false;
    digitalWrite(13, LOW);
    count = 0;
  }
  if(instructionPeriod){
    instructions[count] = analogRead(potentiometer);
    count++;
  }else{
    if(count > 499)
      exit(0);
    angle = map(instructions[count], 0, 1023, 0, 179);
    Serial.print(count);
    Serial.print(" MOVING SERVO");
    Serial.print("\n");
    myServo.write(angle);
    count++;
  }
  delay(15);

}
