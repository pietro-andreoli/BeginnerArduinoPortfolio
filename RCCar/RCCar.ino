int forward_pin = 4;
int back_pin = 7;
int left_pin = 8;
int right_pin = 12;

int enable_1 = 3;
int enable_2 = 9;
int m_1_in_1 = 5;
int m_1_in_2 = 2;
int m_2_in_1 = 11;
int m_2_in_2 = 10;

int currDir = 0;
void setup() {
  pinMode(forward_pin, INPUT);
  pinMode(back_pin, INPUT);
  pinMode(left_pin, INPUT);
  pinMode(right_pin, INPUT);

  pinMode(enable_1, OUTPUT);
  pinMode(enable_2, OUTPUT);
  pinMode(m_1_in_1, OUTPUT);
  pinMode(m_1_in_2, OUTPUT);
  pinMode(m_2_in_1, OUTPUT);
  pinMode(m_2_in_2, OUTPUT);
  digitalWrite(enable_1, HIGH);//HIGH was originally 255
  digitalWrite(enable_2, HIGH);
  Serial.begin(9600);
  
}

void loop() {
  delay(1);
  int l = digitalRead(left_pin);
  int r = digitalRead(right_pin);
  int f = digitalRead(forward_pin);
  int b = digitalRead(back_pin);
  if( l || r || f || b ){
    if( l && !r && !f && !b){  
      //Speed of motor 1 is set to 0
      analogWrite(enable_1, 0);
      //Speed of motor 2 is set to max
      analogWrite(enable_2, 255);
      //Sets motor 1's H-bridge inputs to turn the motor off
      digitalWrite(m_1_in_1, LOW);
      digitalWrite(m_1_in_2, LOW);
      //Sets motor 2's H-bridge inputs to turn the motor on
      digitalWrite(m_2_in_1, LOW);
      digitalWrite(m_2_in_2, HIGH);
    }
    else if( !l && r && !f && !b){
      Serial.print("\n Turning Right ");
      //Speed of motor 1 is set to 0
      analogWrite(enable_1, 255);
      //Speed of motor 2 is set to max
      analogWrite(enable_2, 0);
      //Sets motor 1's H-bridge inputs to turn the motor off
      digitalWrite(m_1_in_1, LOW);
      digitalWrite(m_1_in_2, HIGH);
      //Sets motor 2's H-bridge inputs to turn the motor on
      digitalWrite(m_2_in_1, LOW);
      digitalWrite(m_2_in_2, LOW);
    }
    else if( !l && !r && f && !b){
      Serial.print("\n Going Forwards ");
      //Speed of motor 1 is set to 0
      analogWrite(enable_1, 255);
      //Speed of motor 2 is set to max
      analogWrite(enable_2, 255);
      //Sets motor 1's H-bridge inputs to turn the motor off
      digitalWrite(m_1_in_1, LOW);
      digitalWrite(m_1_in_2, HIGH);
      //Sets motor 2's H-bridge inputs to turn the motor on
      digitalWrite(m_2_in_1, LOW);
      digitalWrite(m_2_in_2, HIGH);
    }
    else if( !l && !r && !f && b){
      Serial.print("\n Going Backwards ");
       //Speed of motor 1 is set to 0
      analogWrite(enable_1, 255);
      //Speed of motor 2 is set to max
      analogWrite(enable_2, 255);
      //Sets motor 1's H-bridge inputs to turn the motor off
      digitalWrite(m_1_in_1, HIGH);
      digitalWrite(m_1_in_2, LOW);
      //Sets motor 2's H-bridge inputs to turn the motor on
      digitalWrite(m_2_in_1, HIGH);
      digitalWrite(m_2_in_2, LOW);
    }
  }else{
    analogWrite(enable_1, LOW);
    analogWrite(enable_2, LOW);
  }
}

