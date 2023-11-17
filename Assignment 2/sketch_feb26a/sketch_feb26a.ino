#include <Keypad.h>

#define LED1 30
#define LED2 29
#define LED3 28
#define LED4 27
#define LED5 26
#define LED6 25
#define LED7 24
#define LED8 23
#define LED9 22

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','-'},
  {'4','5','6','*'},
  {'7','8','9','/'},
  {'c','0','=','+'}
};
byte rowPins[ROWS] = {4,3,2,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8,9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int x =0;

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

  Serial.begin(9600); //for section 2  of lab
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
  
  Serial.print(key); //for section 2 of lab
  
  if(key == 'c'){Serial.println();}
  if(key == 'c'){
  for(int i =30;i>=22;i--){
    digitalWrite(i , LOW);
    }
  }
  else{
    int key_int = key - '0';
    for(int i=30; i > 30 - key_int; i--){
      digitalWrite(i , HIGH);
      delay(500);
    }
  }

}
