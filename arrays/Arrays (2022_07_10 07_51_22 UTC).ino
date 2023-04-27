void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  int array[5]={1,2,3,4,5};
  Serial.println(array[2]);

  array[2]=67;
  Serial.println(array[2]);

  int sum=0;
  for(int i=0; i<5;i++){
    sum+=array[i];
  }
  Serial.println(sum);
}

void loop() {
  // put your main code here, to run repeatedly:

}
