/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-rfid-nfc
 */

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 5


int ledPinBot5 = 8;
int ledPinBot6 = 9;

MFRC522 rfid(SS_PIN, RST_PIN);

//Declare the NFCTAG that's correct
byte authorizedUID1[4] = {0xD0, 0x31, 0x62, 0x4D};


void setup() {
  //Setpup of LED's and innit of NFC Tag Reader.
  pinMode (ledPinBot5, OUTPUT);
  pinMode (ledPinBot6, OUTPUT);
  Serial.begin(115200);
  SPI.begin(); // init SPI bus
  rfid.PCD_Init(); // init MFRC522

  Serial.println("Tap RFID/NFC Tag on reader");

}

void loop() {
  if (rfid.PICC_IsNewCardPresent()) { // new tag is available
    if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

      // print NUID in Serial Monitor in the hex format
      Serial.print("UID:");
      for (int i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);}


        
      if (rfid.uid.uidByte[0] == authorizedUID1[0] &&
          rfid.uid.uidByte[1] == authorizedUID1[1] &&
          rfid.uid.uidByte[2] == authorizedUID1[2] &&
          rfid.uid.uidByte[3] == authorizedUID1[3] ) {
        Serial.println("Authorized Tag 1");
        digitalWrite(ledPinBot6, HIGH); 
        
      } else  {
        Serial.println("Authorized Tag 2");

        digitalWrite(ledPinBot5, HIGH);
      

      rfid.PICC_HaltA(); // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
    }
  }
}}
