//3 led ve potansiyometre uygulaması
const int potPin = A3;  // Potansiyometrenin bağlı olduğu analog pin
const int bluePin = 9;  // Mavi LED'in bağlı olduğu pin
const int greenPin = 8; // Yeşil LED'in bağlı olduğu pin
const int redPin = 7;   // Kırmızı LED'in bağlı olduğu pin

void setup() {
  Serial.begin(9600);       // Seri haberleşmeyi başlat
  pinMode(potPin, INPUT);   // Potansiyometre pinini giriş olarak ayarla
  pinMode(bluePin, OUTPUT); // Mavi LED pinini çıkış olarak ayarla
  pinMode(greenPin, OUTPUT);// Yeşil LED pinini çıkış olarak ayarla
  pinMode(redPin, OUTPUT);  // Kırmızı LED pinini çıkış olarak ayarla
}

void loop() {
  int readVal = analogRead(potPin);   // Potansiyometreden değeri oku
  float V2 = (5.0 / 1023.0) * readVal; // Voltajı hesapla
  
  Serial.print("Potansiyometre voltajı: ");
  Serial.println(V2);
  
  // LED'leri kontrol et
  if (V2 >= 3.0 && V2 < 5.0) {       // 5-3 arası voltaj
    digitalWrite(bluePin, HIGH);     // Mavi LED yanar
    digitalWrite(greenPin, LOW);     // Yeşil LED sönük
    digitalWrite(redPin, LOW);       // Kırmızı LED sönük
  } 
  else if (V2 >= 2.0 && V2 < 3.0) {  // 3-2 arası voltaj
    digitalWrite(bluePin, LOW);      // Mavi LED sönük
    digitalWrite(greenPin, HIGH);    // Yeşil LED yanar
    digitalWrite(redPin, LOW);       // Kırmızı LED sönük
  } 
  else if (V2 >= 0.0 && V2 < 2.0) {  // 2-0 arası voltaj
    digitalWrite(bluePin, LOW);      // Mavi LED sönük
    digitalWrite(greenPin, LOW);     // Yeşil LED sönük
    digitalWrite(redPin, HIGH);      // Kırmızı LED yanar
  } 
  else { 
    // Voltajın belirlenen aralıklarda olmadığı durum
    digitalWrite(bluePin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);
  }
  
  delay(250);  // 250 ms bekle
}