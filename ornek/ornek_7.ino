//POTANSİYEMETRE UYGULAMASI
int myVoltPin=A3;
 int readVal;
 float V2;
void setup()
{
  Serial.begin(9600);

  
}
void loop()
{
  readVal=analogRead(myVoltPin);
V2=(5./1023.)*readVal;
Serial.println(V2);
delay(250);
 }