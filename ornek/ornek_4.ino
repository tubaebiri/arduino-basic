//Latin alfabesini mors alfabesine çevirip ona göre ışık veren arduino kodu

const int ledPin =13; // LED'in bağlı olduğu pin
const int dotDuration = 100; // Nokta süresi (ms)
const int dashDuration = 3 * dotDuration; // Çizgi süresi (ms)
const int letterSpace = 3 * dotDuration; // Harfler arası boşluk (ms)
const int wordSpace = 7 * dotDuration; // Kelimeler arası boşluk (ms)

// Morse kodları için eşleme tablosu
const char* morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", // A-Z
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." // 0-9
};

const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

// Verilen karakteri Morse koduna çeviren fonksiyon
String charToMorse(char c) {
    c = toupper(c); // Büyük harfe çevir
    if (c >= 'A' && c <= 'Z') {
        return morseCode[c - 'A'];
    } else if (c >= '0' && c <= '9') {
        return morseCode[26 + (c - '0')];
    } else if (c == ' ') {
        return " "; // Boşluk karakterini ayırt etmek için
    } else {
        return ""; // Desteklenmeyen karakterler için boş
    }
}

void dot() {
    digitalWrite(ledPin, HIGH);
    delay(dotDuration);
    digitalWrite(ledPin, LOW);
    delay(dotDuration);
}

void dash() {
    digitalWrite(ledPin, HIGH);
    delay(dashDuration);
    digitalWrite(ledPin, LOW);
    delay(dotDuration);
}

void playMorse(String morse) {
    for (int i = 0; i < morse.length(); i++) {
        char symbol = morse[i];
        if (symbol == '.') {
            dot();
        } else if (symbol == '-') {
            dash();
        } else if (symbol == ' ') {
            delay(letterSpace); // Harfler arası boşluk
        }
    }
    delay(wordSpace); // Kelimeler arası boşluk
}

void loop() {
    String message = "BOZOK"; // Morse koduna çevrilecek mesaj

    for (int i = 0; i < message.length(); i++) {
        char character = message[i];
        String morse = charToMorse(character); // Karakteri Morse koduna çevir
        playMorse(morse); // Morse kodunu LED ile göster
        delay(wordSpace); // Kelime arası boşluk
    }

    delay(5000); // Mesajın tekrar edilmeden önce bekleme süresi
}