#include <SPI.h>
#include <MFRC522.h>

/* preassure */
float last = 0;
float x = 0;
float calibValue = 0;
float calibRound = 0;

/* nfc */
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.
MFRC522::StatusCode status;

void setup() {
  Serial.begin(9600); 

  /* nfc */
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card
  Serial.println("Scan PICC to see UID and type...");
}

void loop() {
  //nfc();
  run();
}

void run() {
  waitForNo();

  last = waitForYes(last);
  Serial.println(last);
}

void calib() {
  if (x == 100) {
      calibRound = (int) calibValue * 10;
      calibRound = (float) calibRound / 10;
      Serial.println((int) (calibRound / 10) * 10);
      x = 0;
  }
  calibValue = readValue();
  delay(5);

  x++;
}
