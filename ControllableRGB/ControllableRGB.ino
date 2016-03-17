
int red_input = A2;
int green_input = A1;
int blue_input = A0;

int red_output = 9;
int green_output = 10;
int blue_output = 11;

int red_value = 0;
int green_value = 0;
int blue_value = 0;

void setup() {
  Serial.begin(9600);

  for(int i = 9; i < 12; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  red_value = analogRead(red_input) / 4;
  delay(5);
  green_value = analogRead(green_input) / 4;
  delay(5);
  blue_value = analogRead(blue_input) / 4;

  Serial.print("Red Value:");
  Serial.print(red_value);
  Serial.print("\t Green Value:");
  Serial.print(green_value);
  Serial.print(" \t Blue Value:");
  Serial.print(blue_value);
  Serial.print("\n");

  analogWrite(red_output, red_value);
  analogWrite(green_output, green_value);
  analogWrite(blue_output, blue_value);
  
}
