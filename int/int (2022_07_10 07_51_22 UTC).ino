int myVar=5;

void setup() {
  Serial.begin(9600);
  Serial.println(myVar);
  myVar=myVar+2;
  Serial.println(myVar);

}

void loop() {
  // put your main code here, to run repeatedly:

}
