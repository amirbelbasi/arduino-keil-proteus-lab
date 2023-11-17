#define LED1 0
#define LED2 1
#define LED3 2
#define LED4 3
#define LED5 4
#define LED6 5
#define LED7 6
#define LED8 7
String myname;
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
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  myname=String("emad");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(10)==0){
    digitalWrite(LED1, HIGH);
    delay(1000);
    digitalWrite(LED2, HIGH);
    delay(1000);
    digitalWrite(LED3, HIGH);
    delay(1000);
    digitalWrite(LED4, HIGH);
    delay(1000);
    digitalWrite(LED5, HIGH);
    delay(1000);
    digitalWrite(LED6, HIGH);
    delay(1000);
    digitalWrite(LED7, HIGH);
    delay(1000);
    digitalWrite(LED8, HIGH);
    delay(1000);
  }
  if(digitalRead(11)==0){
    int x = myname.length();
    for(int i=0;i < x;i++){
      for(int j=0 ; j<10 ;j++){
        digitalWrite(i, HIGH);
        delay(100);
        digitalWrite(i, LOW);
        delay(100);
      }
      digitalWrite(i, HIGH);
      delay(100);
    }
  }
  if(digitalRead(12)==0){
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED8, LOW);
  }
}
