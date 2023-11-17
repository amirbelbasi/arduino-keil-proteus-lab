#define LED1 0
#define LED2 1
#define LED3 9
#define LED4 3
#define LED5 4
#define LED6 5
#define LED7 6
#define LED8 7
#define LED9 8
String myname;
unsigned long lasttime;
volatile byte state = LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  pinMode(20, INPUT);
  pinMode(21, INPUT);
  pinMode(2, INPUT);
  myname=String("emad");
  lasttime = millis();
  attachInterrupt(digitalPinToInterrupt(18), s1, FALLING);
  attachInterrupt(digitalPinToInterrupt(19), s2, FALLING);
  attachInterrupt(digitalPinToInterrupt(20), s3, FALLING);
  attachInterrupt(digitalPinToInterrupt(2), s, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(21)==0){
    if(millis() - lasttime >=5000){
      lasttime = millis();
      if(digitalRead(LED9)==HIGH){
      digitalWrite(LED9, LOW);        
      }
      else{
      digitalWrite(LED9, HIGH);
      }
    }
  }
}
void s1(){
  digitalWrite(LED1, HIGH);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  digitalWrite(LED2, HIGH);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  digitalWrite(LED3, HIGH);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  digitalWrite(LED4, HIGH);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  digitalWrite(LED5, HIGH);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  digitalWrite(LED6, HIGH);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  digitalWrite(LED7, HIGH);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  digitalWrite(LED8, HIGH);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
  delayMicroseconds(16383);
}
void s2(){
  int x = myname.length();
  for(int i=0;i < x;i++){
    if(i==2){
      i=9;
    }
    for(int j=0 ; j<6 ;j++){
      digitalWrite(i, HIGH);
      delayMicroseconds(16383);
      delayMicroseconds(16383);
      delayMicroseconds(16383);
      delayMicroseconds(16383);
      digitalWrite(i, LOW);
      delayMicroseconds(16383);
      delayMicroseconds(16383);
      delayMicroseconds(16383);
    }
    digitalWrite(i, HIGH);
    delayMicroseconds(16383);
    delayMicroseconds(16383);
    delayMicroseconds(16383);
    if(i==9){
      i=2;
    }
    }

}
void s3(){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED8, LOW);  
}
void s(){
  for(int i=0;i<=10;i++){
    digitalWrite(LED1, state);
    digitalWrite(LED2, !state);
    digitalWrite(LED3, state);
    digitalWrite(LED4, !state);
    digitalWrite(LED5, state);
    digitalWrite(LED6, !state);
    digitalWrite(LED7, state);
    digitalWrite(LED8, !state);
    state=!state;
  }
}
