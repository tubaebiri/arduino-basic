//buzzer+potansiyometre uygulaması
int potVal;
int buzzPin = 8;
int potPin = A3;

void setup() {
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // Read the potentiometer value
  potVal = analogRead(potPin);

  // Print the potentiometer value to the Serial Monitor
  Serial.println(potVal);

  // Check if the potentiometer value is greater than a threshold
  if (potVal > 1000) {
    // Turn on the buzzer
    digitalWrite(buzzPin, HIGH);
    delay(100);  // Wait for 100 milliseconds

    // Turn off the buzzer
    digitalWrite(buzzPin, LOW);
    delay(100);  // Wait for 100 milliseconds
  }
  else {
    // Ensure buzzer is off if the value is below the threshold
    digitalWrite(buzzPin, LOW);
  }
