// const float empty = 400.00;
// const float full = 600.00;

const float empty = 80.00;
const float full = 290.00;

float smoothADC = 0;

void reset(float value){
  smoothADC=value;
}

float readValue(){
  smoothADC = analogRead(0);

  /*smoothADC = (int) smoothADC * 10;
  smoothADC = (float) smoothADC / 10;
  smoothADC = (int) (smoothADC / 10) * 10;*/

  return smoothADC;
}

float readPercentage(){
  return calcPercentage(readValue());
}

float calcPercentage(float value) {
  float x = 100 * (value - empty) / (full - empty);

  if(x<0 && x > -25){return 0;}

  if(x>100){return 100;}

  return x;
}
