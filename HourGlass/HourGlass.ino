const int switchPin = 8;
unsigned long prevTime = 0;
int switchState = 8;
int prevSwitchState = 1;
int led = 2;
long interval = 2000;

void setup() {
  for(int i = 2; i<8; i++)
    pinMode(i, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currTime = millis();
  Serial.print(switchState);
  Serial.print("\n");
  Serial.print(prevSwitchState);
  Serial.print("\n");
  if(currTime - prevTime > interval){
    prevTime = currTime;
    digitalWrite(led,HIGH);
    led++;
    if(led == 7){
      tone(12, 4000, 1000);
    }
  }
  switchState = digitalRead(switchPin);
  if(switchState != prevSwitchState){
    for(int i = 2; i<8; i++){
      digitalWrite(i,LOW);
    }
    led = 2;
    prevTime = currTime;
    noTone(12);
    prevSwitchState = switchState;

  }
}
