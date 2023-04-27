void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("this line should print irrespective of anything");
  if(5>3){
    Serial.println("this line should print only if the condition is true");
  }

  if( 5<3){
    Serial.println("this line will not print as the condition is false");
  }
  Serial.println("this line should print irrespective of anything");

  if(true){
    Serial.println("my first statement");
  }
  else{
    Serial.println("my else statement");
  }

  

}

void loop() {
  // put your main code here, to run repeatedly:

}
