//inspired from https://devcraze.com/tutorials/arduino/mfrc522-rfid-read-and-write-data-in-specific-rfid-block/
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
  byte pageNumber = 8;
  byte buffr[] = {
    0x6,0x6,0x6,0x6
  };

  mfrc522.MIFARE_Write(pageNumber, buffr, 16);

  Serial.println(" ");
  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}
