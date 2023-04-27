void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  char str[5]={'a','b','c','d'};
  Serial.println(str);
  char str2[5]={'a','b','c','d','\0' };
  Serial.println(str2);
  char str3='abcd';
  Serial.println(str3);

  String str4 ="jkbk";
  Serial.println(str4);
  Serial.println(str4.charAt(0));

}

void loop() {
  // put your main code here, to run repeatedly:

}
