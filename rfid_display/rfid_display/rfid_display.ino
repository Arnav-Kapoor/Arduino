#include <LiquidCrystal.h>

#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

#include <SPI.h>


#define SS_PIN 10 //SDA pin
#define RST_PIN 13 //reset pin

byte readCard[4];

String MasterTag="E15D9602";
String MasterTag2="53085E04";
String tagID="";

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal lcd(4,3,5,6,7,8);

void setup() {
  // put your setup code here, to run once:
SPI.begin();
mfrc522.PCD_Init();
lcd.begin(16,2);

lcd.print("Access control");
lcd.setCursor(0,1);
lcd.print("Scan Card>>");
}

void loop() {
  // put your main code here, to run repeatedly:

  //wait until tag is scanned

   while(getId()){
    lcd.clear();
  

    if( MasterTag==tagID){
      lcd.print("Access granted");
    }
    else{
      lcd.print("Access denied");
    }
    lcd.setCursor(0,1);
   lcd.print(" ID: ");
   lcd.print(tagID);
  

   delay(2000);
   lcd.clear();
   lcd.print("Access control");
   lcd.setCursor(0,1);
   lcd.print("Scan card");
   }
}

boolean getId(){
  //getting ready to scan card
  if(!mfrc522.PICC_IsNewCardPresent()){
    return false;
  }
  if(!mfrc522.PICC_ReadCardSerial()){
    return false;
  }
tagID="";
  for(byte i=0;i<mfrc522.uid.size;i++){
    tagID.concat(String(mfrc522.uid.uidByte[i]<0x10 ? "0": ""));
    tagID.concat(String(mfrc522.uid.uidByte[i],HEX));
  }

  tagID.toUpperCase();
  mfrc522.PICC_HaltA();
  return true;
}
