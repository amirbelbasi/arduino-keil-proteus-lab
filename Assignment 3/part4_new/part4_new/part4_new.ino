#include <LiquidCrystal.h>

#define rs 13
#define en 12
#define d4 8
#define d5 9
#define d6 10
#define d7 11

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char password[7];
char cp[7] ={'9','8','3','1','7','0','1'};
int a=0;
char key;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16 , 2);
  lcd.clear();

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  if(Serial.available() > 0){
    key=Serial.read();
    }
  lcd.print(key);
  
  if(key == 'c'){lcd.clear();}
  
  int key_int = key - '0' ;
  
  if(key_int <= 9 && key_int >= 0){
    for(int i=0; i<=5 ; i++){
      password[i]=key;
      key = Serial.read();
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
        Serial.print("\n");
        a=1;
        break;
        }
      }
    if(a != 1){
      lcd.setCursor(0,1);
      lcd.print("correct password");
      Serial.print("\n");
      }
    }
}
