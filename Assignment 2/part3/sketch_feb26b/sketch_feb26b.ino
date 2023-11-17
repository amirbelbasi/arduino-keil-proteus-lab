#define LED1 30
#define LED2 29
#define LED3 28
#define LED4 27
#define LED5 26
#define LED6 25
#define LED7 24
#define LED8 23
#define LED9 22
int x = 0;

int num = 0;
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

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //if(x ==0){
  //  Serial.print("enter num between 1-9: ");
  //  x++;
 // }

  if (Serial.available() > 0) {
    // read the incoming byte:
    num = Serial.parseInt();
    Serial.print(num);
  }
  if(num > 9){
    Serial.print("Invalid number");
    Serial.print("\n");
    }
  else{
    for(int i=30; i > 30 - num; i--){
      digitalWrite(i , HIGH);
      delay(500);
    }
    }

}
