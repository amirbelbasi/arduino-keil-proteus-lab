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

int num1=0;
char operand;
int i=0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16 , 2);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(i==0){lcd.setCursor(0,0);i++;}
  int a = 1;
  char key = keypad.waitForKey();
  lcd.print(key);
  if(key == 'c'){lcd.clear();}
  int key_int0 = key - '0';
  if(key_int0 <= 9 && key_int0 >= 0 ){
    while(a == 1){
      key = keypad.waitForKey();
      int key_int1 = key - '0';
      if(key_int1 <=9 && key_int1 >=0 ){
        key_int0 = (key_int0 * 10) + key_int1;
        }
      else{a=0;lcd.print(" ");}
      lcd.print(key);
    }
  }
  if(key == '='){
    lcd.setCursor(0,1);
    if(operand == '/'){lcd.print(String(num1 / key_int0));}
    if(operand == '*'){lcd.print(String(key_int0 * num1));}
    if(operand == '+'){lcd.print(String(key_int0 + num1));}
    if(operand == '-'){lcd.print(String(num1 - key_int0));}
    }
  operand = key;
  num1 = key_int0;
}
