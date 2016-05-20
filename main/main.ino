float smoothADC;
float value;
int pin = A0;
int x = 0;

void setup() {
  Serial.begin(9600);

  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {
  value = smoothADC = 0.9 * smoothADC + 0.1 * analogRead(0);
  //value = runningAverage(smoothADC);
  
  if(digitalRead(2) == HIGH){
    Serial.print("empty: ");
    Serial.println(value);
    setEmpty(value);
    delay(500);
  }
  
  if(digitalRead(3) == HIGH){
    Serial.print("full: ");
    Serial.println(value);
    setFull(value);
    delay(500);
  }

    x++;
  if(x == 10){
    Serial.println(calcPercentage(value));
    x=0;
  }
  
  delay(20);
}
