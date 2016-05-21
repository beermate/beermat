float waitForYes(float last) {
  while(readPercentage() < 0) {
    delay(20);
  }

  delay(3000);

  reset(last);

  int x = 0;
  while(x < 300){
    readPercentage();
    x++;
  }

  return readPercentage();
}

int waitForNo() {
  while(readPercentage() >= 0) {
    delay(20);
  }
}
