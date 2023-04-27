#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <deprecated.h>
#include <require_cpp11.h>
#include <SPI.h>

#include <Servo.h>

#define SS_PIN 10 //sda pin
#define RST_PIN 9 //reset pin

String MasterTag="E15D9602";
String MasterTag2="53085E04";
String tagID="";

MFRC522 mfrc522(SS_PIN,RST_PIN);
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  myservo.attach(7); //attatching servo to pin 7
  myservo.write(0);
  mfrc522.PCD_Init();
  Serial.println("ready");

}
int count=1;
void loop() {
  // put your main code here, to run repeatedly:

  while(getID()){
    if(MasterTag==tagID || MasterTag2==tagID){
      if(count==1){
        myservo.write(90); // places at 90 degrees
        delay(5);
        count++;
      }
      else if(count==2){
         myservo.write(0); // places at 0 degrees
        delay(5);
        count--;
      }
    }
  }

}

boolean getID(){
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




