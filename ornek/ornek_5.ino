//Binary 0000-1111 ledi yakan kod
// LED pinlerini global değişkenler olarak tanımla
const int leds[] = {10, 11, 12, 13}; // LED pinlerini bir dizi olarak tanımla

void setup() {
  // Tüm LED pinlerini çıkış olarak ayarla
  for (int i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // 1'den 15'e kadar rakamlarını göstermek için LED kombinasyonlarını tanımla
  byte patterns[] = {
    B0001, // 1: 0001 (sadece son LED yanar)
    B0010, // 2: 0010 (ikinci LED yanar)
    B0011, // 3: 0011 (ilk iki LED yanar)
    B0100, // 4: 0100 (üçüncü LED yanar)
    B0101, // 5: 0101 (birinci ve üçüncü LED yanar)
    B0110, // 6: 0110 (ilk iki ve üçüncü LED yanar)
    B0111, // 7: 0111 (ilk üç LED yanar)
    B1000, // 8: 1000 (sadece ilk LED yanar)
    B1001, // 9: 1001 (birinci ve son LED yanar)
    B1010, // 10: 1010 (birinci ve ikinci LED yanar)
    B1011, // 11: 1011 (birinci, ikinci ve son LED yanar)
    B1100, // 12: 1100 (ilk iki LED yanar)
    B1101, // 13: 1101 (ilk iki ve son LED yanar)
    B1110, // 14: 1110 (ilk üç LED yanar)
    B1111  // 15: 1111 (tüm LED'ler yanar)
  };

  for (int i = 0; i < 15; i++) {
    // LED'leri güncelle
    for (int j = 0; j < 4; j++) {
      digitalWrite(leds[j], (patterns[i] >> j) & 1); // LED'leri sırayla aç/kapat
    }
    delay(2000); // 1 saniye bekle
  }
}