const int on_pin = 5;
const int direction_pin = 4;
const int enable_pin = 9;
const int dir_one = 3;
const int dir_two = 2;
const int speed_pin = A0;

int speed = 0;
int prevMotorState=0;
int prevDir = 0;
int motorEnabled = 0;
int motorDir = 0;
void setup() {
  pinMode(on_pin, INPUT);
  pinMode(direction_pin, INPUT);
  pinMode(enable_pin, OUTPUT);
  pinMode(dir_one, OUTPUT);
  pinMode(dir_two, OUTPUT);
  digitalWrite(enable_pin, LOW);
}

void loop() {
  delay(1);
  if(digitalRead(on_pin) != prevMotorState){
    if(digitalRead(on_pin) == HIGH){
      motorEnabled = !motorEnabled;
    }
  }

  if(digitalRead(direction_pin) != prevDir){
    if(digitalRead(direction_pin) == HIGH){
      motorDir = !motorDir;
    }
  }

  if(motorDir == 1){
    digitalWrite(dir_one, HIGH);
    digitalWrite(dir_two, LOW);
  }else{
    digitalWrite(dir_one, LOW);
    digitalWrite(dir_one, HIGH);
  }

  if(motorEnabled == 1){
    analogWrite(enable_pin, speed_pin);
  }else{
    analogWrite(enable_pin, 0);
  }
  prevDir = digitalRead(direction_pin);
  prevMotorState = digitalRead(on_pin);
  
}
