const int ledPin = 13;  // LED'in bağlı olduğu pin
const int ldrPin = A0;  // LDR'nin bağlı olduğu pin

void setup() {
  Serial.begin(9600);         // Seri iletişimi başlat
  pinMode(ledPin, OUTPUT);    // LED pinini çıkış olarak ayarla
  // pinMode(ledPin, INPUT);   // Bu satırı kaldırın; aynı pin hem çıkış hem giriş olamaz
}

void loop() {
  int ldrStatus = analogRead(ldrPin);  // LDR'den değer oku

  if (ldrStatus <= 300) {
    digitalWrite(ledPin, HIGH);        // LED'i aç
    Serial.println("LDR is DARK, LED is ON");
  } else {
    digitalWrite(ledPin, LOW);         // LED'i kapat
    Serial.println("----------------");
  }

}

