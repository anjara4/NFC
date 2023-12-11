/*Writing data from an NFC Reader RC522 to an NHS3152 nxp chip
This code is inspired by https://devcraze.com/tutorials/arduino/mfrc522-rfid-read-and-write-data-in-specific-rfid-block/
The original code can be used to write data into an Mifair card but cannot work whith the NHS3152 chip
The problem is that the authenfication for the Mifair card does not work with the NHS3152 chip
Mifair need to be authentified in order to work
My initial solution is to remove the authentication phase, which is not mandatory with the NHS3152 (obviously)
The next step will be to add the authentification for the NHS3152*/
/*Integration of the DumpInfo.ino program into this code. 
  In this way, writing and reading the information inside the shared memory is possible with the same program*/ 
/*The original code does not allow read and write mutliple time.
By removing the PICC_HaltA() inside the code for writing 
and also inside the ...\Arduino\libraries\MFRC522\src\MFRC522.c for the reading*/

#include <SPI.h>
#include <MFRC522.h>
#define RST_PIN         9           // Configurable, see typical pin layout above
#define SS_PIN          10          // Configurable, see typical pin layout above
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

void setup() {
  Serial.begin(9600);        // Initialize serial communications with the PC
  SPI.begin();               // Init SPI bus
  mfrc522.PCD_Init();        // Init MFRC522 card
  Serial.println(F("Write personal data NHS3152"));
}

void loop() {
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
  if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
  Serial.setTimeout(20000L);
  
  byte dataValue = 1;
  if (Serial.available() > 0) {
    dataValue = Serial.parseInt();

    if(dataValue > 0){
      if(dataValue == 9) //Print data from the shared memory
        mfrc522.PICC_DumpToSerial(&(mfrc522.uid)); //comment the PICC_HaltA() from ...\Arduino\libraries\MFRC522\src\MFRC522.c
      
      writingNFC(4, dataValue);//write datavalue into the page 4 of the shared memory
    }
  }
}

void writingNFC(byte pageNumber, byte dataValue){
  Serial.print("I received: ");
  Serial.println(dataValue);
  byte buffr[] = {dataValue,0x0,0x0,0x0};
  mfrc522.MIFARE_Write(pageNumber, buffr, 16); 
}

