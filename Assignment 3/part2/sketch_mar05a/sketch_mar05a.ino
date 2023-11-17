#include <LiquidCrystal.h>
#include <Keypad.h>

#define rs 13
#define en 12
#define d4 8
#define d5 9
#define d6 10
#define d7 11

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','-'},
  {'4','5','6','*'},
  {'7','8','9','/'},
  {'c','0','=','+'}
};
byte rowPins[ROWS] = {5,6,7,4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {3,2,1,0}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char password[7];
char cp[7] ={'9','8','3','1','7','0','1'};
int a=0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16 , 2);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  char key = keypad.waitForKey();
  lcd.print(key);
  
  if(key == 'c'){lcd.clear();}
  
  int key_int = key - '0' ;
  
  if(key_int <= 9 && key_int >= 0){
    for(int i=0; i<=5 ; i++){
      password[i]=key;
      key = keypad.waitForKey();
      lcd.print(key);
      }
    password[6]=key;
    }
  if(key == '*'){
    for(int i=0; i<7 ;++i){
      if(password[i] == cp[i]){continue;}
      else{
        lcd.setCursor(0,1);
        lcd.print("wrong password");
        a=1;
        break;
        }
      }
    if(a != 1){
      lcd.setCursor(0,1);
      lcd.print("correct password");
      }
    }
}
