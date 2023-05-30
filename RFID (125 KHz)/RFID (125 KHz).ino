#include <SoftwareSerial.h>

#define RX_PIN 2   // RX pin connected to RDM6300 module
#define TX_PIN 3   // TX pin connected to RDM6300 module
#define RFID_DATA_LENGTH 14   // Length of the RFID data

SoftwareSerial rdmSerial(RX_PIN, TX_PIN); // SoftwareSerial object for RDM6300

void setup() {
  Serial.begin(9600);    // Initialize Serial monitor
  rdmSerial.begin(9600); // Initialize SoftwareSerial for RDM6300
}

void loop() {
  if (rdmSerial.available() >= RFID_DATA_LENGTH) {
    // Read RFID data
    char rfidData[RFID_DATA_LENGTH];
    rdmSerial.readBytes(rfidData, RFID_DATA_LENGTH);
  
    // Print RFID data
    Serial.print("RFID card number: ");
    for (int i = 0; i < RFID_DATA_LENGTH; i++) {
      Serial.print(rfidData[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
}