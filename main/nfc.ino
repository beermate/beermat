void nfc() {
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Dump debug info about the card. PICC_HaltA() is automatically called.
  //mfrc522.PCD_WriteRegister(0x26 , 0x7E); 
  //mfrc522.PCD_WriteRegister(0x25 , 0x7F); 
  //Serial.println(mfrc522.PCD_ReadRegister(0x25));
  //Serial.println(mfrc522.PCD_ReadRegister(0x26));
}

