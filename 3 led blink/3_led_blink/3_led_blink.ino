int led1=9;
int led2=7;
int led3=2;


void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);

}
void myCustomLED(int pin){
  digitalWrite(pin,HIGH);
  delay(1000);
  digitalWrite(pin,LOW);
  delay(100);
  

}

void loop(){
  myCustomLED(led1);
  myCustomLED(led2);
  myCustomLED(led3);
  
}

