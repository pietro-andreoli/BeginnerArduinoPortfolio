const int redPin_led = 11;
const int bluePin_led = 10;
const int greenPin_led = 9;

const int redPin_sensor = A0;
const int bluePin_sensor = A1;
const int greenPin_sensor = A2;

int redVal = 0;
int blueVal = 0;
int greenVal = 0;

int redSensorVal = 0;
int blueSensorVal = 0;
int greenSensorVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for(int i = 9; i < 12; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorVal = analogRead(redPin_sensor);
  delay(5);
  blueSensorVal = analogRead(bluePin_sensor);
  delay(5);
  greenSensorVal = analogRead(greenPin_sensor);

  Serial.print("SENSOR VALUES \n");
  Serial.print("Red Sensor: ");
  Serial.print(redSensorVal);
  Serial.print("\t");
  Serial.print("Green Sensor: ");
  Serial.print(greenSensorVal);
  Serial.print("\t");
  Serial.print("Blue Sensor: ");
  Serial.print(blueSensorVal);
  Serial.print("\n");

  redVal = redSensorVal / 4;
  greenVal = greenSensorVal / 4;
  blueVal = blueSensorVal / 4;

  Serial.print("Red Value: ");
  Serial.print(redVal);
  Serial.print("\tGreen Value: ");
  Serial.print(greenVal);
  Serial.print("\tBlue Value: ");
  Serial.print(blueVal);

  analogWrite(redPin_led, redVal);
  analogWrite(bluePin_led, blueVal);
  analogWrite(greenPin_led, greenVal);
  Serial.print("\n");
  delay(500);
  
}
