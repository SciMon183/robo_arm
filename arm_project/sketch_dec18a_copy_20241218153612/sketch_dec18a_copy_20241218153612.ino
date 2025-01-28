#include <Servo.h>

Servo myServo; // Obiekt serwomechanizmu

int pos = 0; // Aktualna pozycja serwomechanizmu
bool direction = true; // Kierunek ruchu: true - w prawo, false - w lewo

void setup() {
  myServo.attach(9); // Podłącz serwomechanizm do pinu 9
}

void loop() {
  if (direction) {
    pos += 1; // Ruch w prawo
    if (pos >= 180) { // Osiągnięto maksymalny kąt
      direction = false; // Zmień kierunek
    }
  } else {
    pos -= 1; // Ruch w lewo
    if (pos <= 0) { // Osiągnięto minimalny kąt
      direction = true; // Zmień kierunek
    }
  }

  myServo.write(pos); // Ustaw nową pozycję serwomechanizmu
  delay(20); // Krótka przerwa dla płynnego ruchu
}
