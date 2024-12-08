// INCLUDES & VARS ***************************************************
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h> 

// RFID = mouth
#define RST_PIN  9
#define SS_PIN  10 

// RFID READER = mouth
MFRC522 mfrc522(SS_PIN, RST_PIN);  // create MFRC522 instance

// PHOTORESISTOR = back
const int pResistor = A0;
int value; // store value from photoresistor (0-1023)

bool wasLastStateDark = false;
bool hasReportedCurrentState = false;

// change these values based on ypur enviroment
#define LIGHT_THRESHOLD 300
#define DARK_THRESHOLD 200
#define NUM_SAMPLES 20

// SETUP ***************************************************
void setup() {
	Serial.begin(9600); // init serial coms
	while (!Serial);
  // RFID
	SPI.begin(); // init SPI bus
	mfrc522.PCD_Init();	// init MFRC522
	mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
	Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

// LOOP ***************************************************
void loop() {
  readRFID();
  readPhoto();
}

// FUNCTIONS ***************************************************
void readRFID() {
if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
}

if (!mfrc522.PICC_ReadCardSerial()) {
    return;
}

    // check UID
    String uidString = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
        // convert each byte to a 2-character hex string
        if (mfrc522.uid.uidByte[i] < 0x10) {
            uidString += "0"; // add leading zero for single-digit hex values
        }
        uidString += String(mfrc522.uid.uidByte[i], HEX);
        if (i < mfrc522.uid.size - 1) {
            uidString += " "; // add space between bytes
        }
    }
    uidString.toUpperCase(); // convert to uppercase to match format

    // check if the UID matches EC D1 7C 32, print water
    if (uidString == "EC D1 7C 32") {
        Serial.println("water");
        Serial.flush();
        servoTrig();
    }
    
    if (uidString == "DC AD 84 33") {
        Serial.println("food");
        Serial.flush();
        servoTrig();
    }

    mfrc522.PICC_HaltA();
}

void readPhoto() {
  long totalValue = 0;
  for (int i = 0; i < NUM_SAMPLES; i++) {
    totalValue += analogRead(pResistor);
    delay(5); 
  }
  
  int averageValue = totalValue / NUM_SAMPLES;
  //Serial.println(averageValue);
  
  // dark state
  if (averageValue <= DARK_THRESHOLD) {
    if (!wasLastStateDark && !hasReportedCurrentState) {
      Serial.println("happiness");
      wasLastStateDark = true;
      hasReportedCurrentState = true;
    }
  } 
  // light state
  else if (averageValue >= LIGHT_THRESHOLD) {
    if (wasLastStateDark && !hasReportedCurrentState) {
      //Serial.println("light");
      wasLastStateDark = false;
      hasReportedCurrentState = true;
    }
  }

  else {
    hasReportedCurrentState = false;
  }
}
