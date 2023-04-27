void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

int sum(int a, int b, int c){
  return a+b+c;
}

bool isTall(int height){
  if (height>100){
    return true;
  }
  else{
    return false;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  /*int d=sum(7,8,9);
  Serial.println(d);
  */
  Serial.println(isTall(123));
  Serial.println(isTall(90));

}
