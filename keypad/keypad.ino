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

Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,4,4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  char key=keypad.getKey();

  if(key){
    Serial.println(key);
  }

}
