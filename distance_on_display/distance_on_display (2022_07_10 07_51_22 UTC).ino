#include <LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);

 int const ech=2;
  int const trig=4;

void setup() {
  // put your setup code here, to run once:
 
  
  pinMode(ech,INPUT);
  pinMode(trig,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  float duration,distance;

  digitalWrite(trig,HIGH);
  delay(1);
  digitalWrite(trig,LOW);

  duration=pulseIn(ech,HIGH);

  distance=(duration/2)/29.1;

  
lcd.setCursor(0,1);
  lcd.begin(16,2);
  lcd.print(distance);
  lcd.print("cm");

delay(1000);
}
