//for uygulaması
int i;
int redPin=9;
int yellowPin=6;

void setup()
{
  pinMode(redPin,OUTPUT);
  pinMode(yellowPin,OUTPUT);
  Serial.begin(9600);

}
void loop()
{
  for(int i=0;i<3;i++)
  {
    digitalWrite(redPin,HIGH);
    delay(1000);
    digitalWrite(redPin,LOW);
    delay(1000);

  }
  for(int i=0;i<5;i++)
  {
    digitalWrite(yellowPin,HIGH);
    delay(1000);
    digitalWrite(yellowPin,LOW);
    delay(1000);

  }

}