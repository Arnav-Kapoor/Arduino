#include <LiquidCrystal.h>
#include <SPI.h>
#include <Key.h>
#include <Keypad.h>

char keys[4][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[4]={6,7,8,9};
byte colPins[4]={10,11,12,13};

LiquidCrystal lcd(5,4,3,2,14,15); //rs e db4 db5 db6 db7
Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,4,4);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  // lcd.print("enter");
}

int count=0;
void loop() {
  // put your main code here, to run repeatedly:
  char keys=keypad.getKey();
  if(keys){
    if(keys=='#'){
      lcd.clear();
      count=0;
      Serial.println(keys);
    }
    else{
      lcd.setCursor(count, 0);
      lcd.print(keys);
      // Serial.println(keys);
      count++;
    }
  }
}
