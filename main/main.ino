float last = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  run();
}

void run() {
  waitForNo();

  last = waitForYes(last);
  Serial.println(last);
}

void calib() {
  Serial.println(readValue());
  delay(10);
}
