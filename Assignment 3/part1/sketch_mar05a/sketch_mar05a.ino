#include <TimeLib.h>
#include <LiquidCrystal.h>

#define rs 13
#define en 12
#define d4 8
#define d5 9
#define d6 10
#define d7 11

int count=0;
int row = 0;
//String myname;
int len;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16 , 2);
  lcd.clear();
  setTime(1646450384);
  //myname = String("emad");
  //len = myname.length();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  if(count == (7)){
    row=(row+1)%2;
    count=0;
    }
  lcd.setCursor(count,row);
  //lcd.print(myname);
  
  lcd.print(String(day(now())));
  lcd.print("-");
  lcd.print(String(month(now())));
  lcd.print("-");
  lcd.print(String(year(now())));
  delay(1000);
  count++;
}
