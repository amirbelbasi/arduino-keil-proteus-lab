#include <LiquidCrystal.h>
#include <Keypad.h>

#define rs 35
#define en 36
#define d4 40
#define d5 41
#define d6 42
#define d7 43

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'c','0','=','+'}
};
byte rowPins[ROWS] = {13,12,11,10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {14,15,16,17}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String names[10];
String numbers[10];
int intNumbers[10];
int nContacts = 0;
String tmpName = "";
String numberHolder = "";
char tmpKey;

void setup() {
  lcd.begin(20 , 4);
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  int flag = 0;
  int cursorCounter = 0;
  Serial.println("What do you wish to do?");
  char operation = keypad.waitForKey();
  switch(operation)
  {
    case '+':
      lcd.clear();
      lcd.setCursor(0, 0);
      Serial.print("Contact name to add: ");
      while (!Serial.available()){}
      tmpName = Serial.readString();
      lcd.print(tmpName);
      tmpKey = keypad.waitForKey();
      lcd.setCursor(cursorCounter, 1);
      cursorCounter++;
      lcd.print(tmpKey);
      numberHolder = "";
      numberHolder += tmpKey;
      while (tmpKey != '='){
        tmpKey = keypad.waitForKey();
        lcd.setCursor(cursorCounter, 1);
        cursorCounter++;
        lcd.print(tmpKey);
        if (tmpKey != '=') numberHolder += tmpKey;
      }
      names[nContacts] = tmpName;
      numbers[nContacts] = numberHolder;
      nContacts++;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Contact added");
      break;

    case '/':
      Serial.println("Contacts:");
      for (int i = 0; i < nContacts; i++){
        Serial.print(names[i]);
        Serial.println(numbers[i]);
        Serial.println("---"); 
      }

    case '*':
      lcd.clear();
      lcd.setCursor(0, 0);
      Serial.print("Contact name to find: ");
      while (!Serial.available()){}
      tmpName = Serial.readString();
      for (int i = 0; i < nContacts; i++){
        if (names[i] == tmpName){
          lcd.print(numbers[i]);
        }
      }
      break;

    case '-':
      lcd.clear();
      lcd.setCursor(0, 0);
      Serial.print("Contact name to delete: ");
      while (!Serial.available()){}
      tmpName = Serial.readString();
      for (int i = 0; i < nContacts; i++){
        if (names[i] == tmpName){
          for (int j = i; j < nContacts-1; j++){
            names[j] = names[j+1];
            numbers[j] = numbers[j+1];
          }
          nContacts--;
          flag = 1;
          break;
        } 
      }
      if (flag == 1) lcd.print("Contact deleted");
      else lcd.print("Contact not found");
      break;

    default:
      break;
  }
}
