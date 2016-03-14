int src1 = 13;
int src2=12;
int src3=8;

void blink(int src, int t){
  digitalWrite(src, HIGH);
  delay(t);
  digitalWrite(src,LOW);
  delay(t);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(src1, OUTPUT);
  pinMode(src2, OUTPUT);
  pinMode(src3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  blink(src1, 600);
  //blink(src2, 100);
  //blink(src3, 1000);
}
