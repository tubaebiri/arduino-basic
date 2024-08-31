//mors alfabesi ile sos
int redLed=8;
float  pi=3.14;
int dit=100;
int dah=500;
int uzun=1000;

void setup() {
 pinMode(redLed,OUTPUT);
}
void loop() {
digitalWrite(redLed,HIGH);
delay(dit);
digitalWrite(redLed,LOW);
delay(dit);

digitalWrite(redLed,HIGH);
delay(dit);
digitalWrite(redLed,LOW);
delay(dit);

digitalWrite(redLed,HIGH);
delay(dit);
digitalWrite(redLed,LOW);
delay(dit);
delay(uzun);

digitalWrite(redLed,HIGH);
delay(dah);
digitalWrite(redLed,LOW);
delay(dah);

digitalWrite(redLed,HIGH);
delay(dah);
digitalWrite(redLed,LOW);
delay(dah);

digitalWrite(redLed,HIGH);
delay(dah);
digitalWrite(redLed,LOW);
delay(dah);

digitalWrite(redLed,HIGH);
delay(dit);
digitalWrite(redLed,LOW);
delay(dit);

digitalWrite(redLed,HIGH);
delay(dit);
digitalWrite(redLed,LOW);
delay(dit);

digitalWrite(redLed,HIGH);
delay(dit);
digitalWrite(redLed,LOW);
delay(dit);

}