#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

#include <SPI.h>

#define SS_PIN 10 //SDA pin
#define RST_PIN 13 //reset pin

MFRC522 mfrc522(SS_PIN, RST_PIN); //mfrc reader object
MFRC522::MIFARE_Key key; // MIFARE_Key struct called key to store card info

int block=2; //sector 0 block 2 where we will write into and read

byte blockContent[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //16 byte content to be written inside block

byte readBackBlock[18]; //reading content in block

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();// pcd- proxmity coupling device, init mfrc card
  Serial.println("Scan card");

  //preparing security key for read and write funtions

  for(byte i=0;i<6;i++){
    key.keyByte[i]=0xFF; //keyBye defined in .h file of library in the MIFARE_Key struct
  }


}

void loop() {
  // put your main code here, to run repeatedly:

  //scaning for card
  if(!mfrc522.PICC_IsNewCardPresent()){
    return;
  }

  //select one of the cards

  if(!mfrc522.PICC_ReadCardSerial()){
    return;
  }
  Serial.println("Card selected");

  writeBlock(block, blockContent);// inbuilt function to write 

  readBlock(block, readBackBlock); //to check if the writing is complete

  //uncomment below line if you want to see the entire 1k memory with the block written into it.
//mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

//printing block contents

Serial.println("read block: ");
for(int j=0;j<16;j++){
  Serial.write(readBackBlock[j]);
}
Serial.println(" ");

}

//Write specific block    
int writeBlock(int blockNumber, byte arrayAddress[]) 
{
  //this makes sure that we only write into data blocks. Every 4th block is a trailer block for the access/security info.
  int largestModulo4Number=blockNumber/4*4;
  int trailerBlock=largestModulo4Number+3;//determine trailer block for the sector
  if (blockNumber > 2 && (blockNumber+1)%4 == 0){Serial.print(blockNumber);Serial.println(" is a trailer block:");return 2;}
  Serial.print(blockNumber);
  Serial.println(" is a data block:");
  
  //authentication of the desired block for access
  byte status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));
  if (status != MFRC522::STATUS_OK) {
         Serial.print("PCD_Authenticate() failed: ");
         Serial.println(mfrc522.GetStatusCodeName(status));
         return 3;//return "3" as error message
  }
  
  //writing the block 
  status = mfrc522.MIFARE_Write(blockNumber, arrayAddress, 16);
  //status = mfrc522.MIFARE_Write(9, value1Block, 16);
  if (status != MFRC522::STATUS_OK) {
           Serial.print("MIFARE_Write() failed: ");
           Serial.println(mfrc522.GetStatusCodeName(status));
           return 4;//return "4" as error message
  }
  Serial.println("block was written");

  delay(1);
}



//Read specific block
int readBlock(int blockNumber, byte arrayAddress[]) 
{
  int largestModulo4Number=blockNumber/4*4;
  int trailerBlock=largestModulo4Number+3;//determine trailer block for the sector

  //authentication of the desired block for access
  byte status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, trailerBlock, &key, &(mfrc522.uid));

  if (status != MFRC522::STATUS_OK) {
         Serial.print("PCD_Authenticate() failed (read): ");
         Serial.println(mfrc522.GetStatusCodeName(status));
         return 3;//return "3" as error message
  }

//reading a block
byte buffersize = 18;//we need to define a variable with the read buffer size, since the MIFARE_Read method below needs a pointer to the variable that contains the size... 
status = mfrc522.MIFARE_Read(blockNumber, arrayAddress, &buffersize);//&buffersize is a pointer to the buffersize variable; MIFARE_Read requires a pointer instead of just a number
  if (status != MFRC522::STATUS_OK) {
          Serial.print("MIFARE_read() failed: ");
          Serial.println(mfrc522.GetStatusCodeName(status));
          return 4;//return "4" as error message
  }
  Serial.println("block was read");
}
