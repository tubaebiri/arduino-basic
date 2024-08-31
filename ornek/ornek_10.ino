//Serial monitorden girdi alıp ledi yakma
int myNumber;
int delayTime=500;
int redPin=9;
String msg="Please Enter Your Number";
String msg2="your number is:";
void setup() {
 Serial.begin(9600);

}
void loop(){
 Serial.println(msg);
 while(Serial.available()==0)
 {

 }
 myNumber=Serial.parseInt();
  Serial.println(msg2+myNumber);
for(int i=0;i<myNumber;i++){
  digitalWrite(redPin,HIGH);
  delay(1000);
  digitalWrite(redPin,LOW);
  delay(1000);

}

 }
