float empty = 379.00;
float full = 606.00;

int setEmpty(float value) {
  empty = value;
}

int setFull(float value) {
  full = value;
}

int calcPercentage(float value) {
  float x = 100 * (value - empty) / (full - empty);

  if(x<0){return 0;}

  if(x>100){return 100;}

  return x;
}
