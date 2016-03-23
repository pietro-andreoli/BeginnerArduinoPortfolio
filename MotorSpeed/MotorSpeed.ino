const int on_pin = 5;
const int direction_pin = 4;
const int enable_pin = 9;
const int dir_one = 3;
const int dir_two = 2;
const int speed_pin = A0;

int speed = 0;

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
  if(digitalRead(on_pin)){
    speed = analogRead(speed_pin)/4;
    if(digitalRead(direction_pin)){
      digitalWrite(dir_one, LOW);
      digitalWrite(dir_two, HIGH);
    }else{
      digitalWrite(dir_one, HIGH);
      digitalWrite(dir_two, LOW);     
    }
    
    analogWrite(enable_pin, speed);
  }else{
    digitalWrite(enable_pin, LOW);
  }
  
}
