//kullanıcının secimine göre led yakma
String myName;
int colour;  // colour'ü int olarak tanımladık
String msg = "Please Enter Your Name";
String msg2 = "Hello, welcome to Arduino ";
String msg3 = "Hangi ledi yakmak istersiniz: Yeşil için:1, Kırmızı için:2, Mavi için:3 e basınız";
int redPin = 9;
int bluePin = 7;
int greenPin = 11;

void setup() {
  Serial.begin(9600);

  // LED pinlerini çıkış olarak ayarla
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  Serial.println(msg);
  
  // Kullanıcının ismini girene kadar bekle
  while (Serial.available() == 0) {
    // Bekleme döngüsü
  }
  myName = Serial.readString();  // Kullanıcıdan ismi al ve boşlukları temizle
  Serial.println(msg2 + myName);
  
  Serial.println(msg3);
  
  // LED seçimini yapana kadar bekle
  while (Serial.available() == 0) {
    // Bekleme döngüsü
  }

  // LED seçimini oku
  colour = Serial.parseInt();  // Kullanıcıdan LED seçimini oku
  
  // Seçilen LED'i kontrol et
  switch (colour) {
    case 1:
      digitalWrite(greenPin, HIGH);
      delay(1000);
      digitalWrite(greenPin, LOW);
      delay(1000);
      break;
    case 2:
      digitalWrite(redPin, HIGH);
      delay(1000);
      digitalWrite(redPin, LOW);
      delay(1000);
      break;
    case 3:
      digitalWrite(bluePin, HIGH);
      delay(1000);
      digitalWrite(bluePin, LOW);
      delay(1000);
      break;
    default:
      Serial.println("Geçersiz seçim, lütfen 1, 2 veya 3 girin.");
      break;
  }
}