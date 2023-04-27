#include <Servo.h>
Servo myservo; //create a servo object

int pos=0;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(7); //attach the servo to pin 7

}

void loop() {
  // put your main code here, to run repeatedly:

  for(pos=0;pos<=180;pos++){
    myservo.write(pos); //tell servo to go to position according to variable pos
    delay(15); //wait 100ms to go to position
  }
  
  //same as above but in opposote direction
  for(pos=180;pos>=0;pos--){
    myservo.write(pos);
    delay(15);
  }

}
