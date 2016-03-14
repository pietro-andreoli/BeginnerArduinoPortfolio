#include <Servo.h>
Servo myServo;

const int servoPin = A0;
const int motorCtrl = 9;
int potVal;
int angle;
bool calibrate = false;
int base=0;
void setup() {
  myServo.attach(motorCtrl);
  Serial.begin(9600);
}

void loop() {
  if (!calibrate) {
    base = map(analogRead(servoPin), 0, 1023, 0, 179);
    calibrate = true;
  } else {
    potVal = analogRead(servoPin);
    Serial.print("potVal: ");
    Serial.print(potVal);
    //converts values between 0-1023 to 0-179
    angle = map(potVal, 0, 1023, 0, 179);
    Serial.print("\t Angle: ");
    Serial.print(angle);
    Serial.print("\n");
    myServo.write(angle);
    delay(100);
  }
}
