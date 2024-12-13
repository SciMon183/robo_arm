#include <ESP32Servo.h>

// Ustawienia
const int servoPin = 19;  // Pin ESP32, do którego podłączono serwo
Servo myServo;           // Obiekt serwa
int currentAngle = 90;   // Aktualny kąt serwa (start od pozycji neutralnej)

// Zakresy serwa
const int minAngle = -180;  // Minimalny kąt użytkowy
const int maxAngle = 180;   // Maksymalny kąt użytkowy

void setup() {
  // Inicjalizacja Serial Monitor
  Serial.begin(115200);
  while (!Serial) {
    ; // Czekaj na otwarcie portu Serial
  }

  // Przygotowanie serwa
  myServo.attach(servoPin, 500, 2400); // Pin, minimalny, maksymalny impuls w mikrosekundach
  Serial.println("Sterowanie serwem: 0-180 (prawo), -180 do 0 (lewo).");

  // Ustaw serwo w pozycji neutralnej
  myServo.write(currentAngle);
  Serial.println("Serwo ustawione na pozycję początkową (90°).");
}

void loop() {
  // Sprawdź, czy użytkownik wprowadził dane
  if (Serial.available() > 0) {
    int newAngle = Serial.parseInt(); // Wczytaj kąt jako liczbę całkowitą

    // Sprawdzenie, czy kąt mieści się w zakresie
    if (newAngle >= minAngle && newAngle <= maxAngle) {
      // Przekształcenie kąta użytkownika (-180 do 180) na zakres 0-180 dla PWM
      currentAngle = map(newAngle, minAngle, maxAngle, 0, 180);
      myServo.write(currentAngle);  // Ustaw serwo w nowej pozycji
      Serial.print("Serwo przesunięte na pozycję: ");
      Serial.println(newAngle);
    } else {
      Serial.println("Błędna wartość! Podaj liczbę z zakresu -180 do 180.");
    }

    // Wyczyść bufor Serial, aby uniknąć ponownego odczytu tych samych danych
    while (Serial.available() > 0) {
      Serial.read();
    }
  }

  // Utrzymuj sygnał PWM przez ciągłe przesyłanie bieżącej pozycji
  myServo.write(currentAngle);
  delay(50); // Krótkie opóźnienie dla stabilnego sygnału PWM
}