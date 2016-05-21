// const float empty = 400.00;
// const float full = 600.00;

const float empty = 640.00;
const float full = 740.00;

float smoothADC = 0;

void reset(float value){
  smoothADC=value;
}

float readValue(){
  smoothADC = 0.9 * smoothADC + 0.1 * analogRead(0);

  return smoothADC;
}

float readPercentage(){
  return calcPercentage(readValue());
}

float calcPercentage(float value) {
  float x = 100 * (value - empty) / (full - empty);

  if(x<0 && x > -30){return 0;}

  if(x>100){return 100;}

  return x;
}
