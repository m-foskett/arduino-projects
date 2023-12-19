// RFID Reader Module

//  Example to show how to set the UID on a UID changeable MIFARE card

// Typical pin layout used:
/* -------------------------------------
 *             MFRC522      Arduino     
 *             Reader/PCD   Uno         
 * Signal      Pin          Pin         
 * -------------------------------------
 * RST/Reset   RST          9           
 * SPI SS      SDA(SS)      10          
 * SPI MOSI    MOSI         11 / ICSP-4 
 * SPI MISO    MISO         12 / ICSP-1 
 * SPI SCK     SCK          13 / ICSP-3 
*/

#include <SPI.h>
#include <MFRC522.h>

// Pinout Definitions
#define RST_PIN   9 
#define SS_PIN    10
// Instantiate an RFID Reader module object of class MFRC522
MFRC522 mfrc522(SS_PIN, RST_PIN);

// Define a new UID
#define NEW_UID {0xDE, 0xAD, 0xBE, 0xEF}
// Define a new MIFARE key
MFRC522::MIFARE_Key key;

void setup() {
  // Initialise a serial connection with Baud rate of 9600
  Serial.begin(9600);
  // Wait until serial port is opened before proceeding
  while (!Serial);
  // Initialise the SPI bus
  SPI.begin();
  // Initialise the MFRC522 card
  mfrc522.PCD_Init();
  // Write user warning to the serial monitor
  Serial.println(F("Warning: this example overwrites the UID of your changeable UID card, proceed with caution!"));
  // Prepare the key (Factory default: FFFFFFFFFFFFh)
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
}

void loop() {
  
  // Check if a new MFRC522 card is present and read the selected card
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  // The UID and SAK of the selected card is now stored
  // Print the read UID to the serial monitor
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial.println();
  
  // Set the new UID
  byte newUid[] = NEW_UID;
  if ( mfrc522.MIFARE_SetUid(newUid, (byte)4, true) ) {
    Serial.println(F("Wrote the new UID to the card"));
  }
  
  // Halt PICC and re-select it so that DumpToSerial works
  mfrc522.PICC_HaltA();
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    return;
  }
  
  // Dump the new memory contents to the serial monitor
  Serial.println(F("New UID and contents:"));
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  
  delay(2000);
}
