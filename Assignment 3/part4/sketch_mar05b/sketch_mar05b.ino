#include <LiquidCrystal.h>

#define rs 13
#define en 12
#define d4 8
#define d5 9
#define d6 10
#define d7 11

int col=0;
int row = 0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16 , 2);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  if(col == (16)){
    col=0;
    }
  lcd.setCursor(col,row);
  lcd.print("+");
  delay(500);
  col++;
  row=(row+1)%2;
}
