
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int pitch = map(analogRead(A0), 0, 1023, 50, 4000);
  tone(8, pitch, 20);
}
