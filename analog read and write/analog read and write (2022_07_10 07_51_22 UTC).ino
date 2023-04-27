int led1=9;
int led2=7;
int led3=2;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int fadeValue=0;fadeValue<=255;fadeValue+=5){
    analogWrite(led1,fadeValue);
    delay(40);
    analogWrite(led2,fadeValue);
    delay(40);
    analogWrite(led3,fadeValue);
    delay(40);
  }

  for(int fadeValue=255;fadeValue<=0;fadeValue-=5){
    analogWrite(led1,fadeValue);
    delay(40);
    analogWrite(led2,fadeValue);
    delay(40);
    analogWrite(led3,fadeValue);
    delay(40);
  }
  

}
