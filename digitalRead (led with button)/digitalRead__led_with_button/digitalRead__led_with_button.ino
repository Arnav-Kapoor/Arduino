int button=5;
int led1=9;
int led2=7;
int led3=2;

void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

}


void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(button));

if (digitalRead(button)==HIGH){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
}
else{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
}

}
