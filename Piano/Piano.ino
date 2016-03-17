int tonePin = 8;
int buttons[6];
int notes[] = {262,294,330,349};

void setup() {
  Serial.begin(9600);
}

void loop() {
 buttons[0] = 2;
 int keyVal = analogRead(A0);
 Serial.println(keyVal);

 if(keyVal == 1023)
    tone(8, notes[0]);
 else if(keyVal >= 990 && keyVal <= 1010)
    tone(tonePin, notes[1]);
 else if(keyVal >= 505 && keyVal <= 515)
    tone(tonePin, notes[2]);
 else if(keyVal >= 5 && keyVal <= 10)
    tone(tonePin, notes[3]);
 else
    noTone(8);

}
