#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo myservo;

const int sensorPin = A0;
const int potPin = A1;
const int servoPin = 9;

int threshold = 500; // ajuste o limiar de umidade aqui
int servoClosedAngle = 0; // ângulo em que o servo fica com o varal fechado
int servoOpenAngle = 90; // ângulo em que o servo fica com o varal aberto
int servoDelay = 5000; // tempo que o servo fica aberto antes de fechar novamente (em milissegundos)

void setup() {
  lcd.begin(16, 2);
  myservo.attach(servoPin);
  pinMode(sensorPin, INPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  int potValue = analogRead(potPin);
  int umidade = map(sensorValue, 0, 1023, 0, 100);
  int delayTime = map(potValue, 0, 1023, 0, 10000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Umidade: ");
  lcd.print(umidade);
  lcd.print("%");

  if (umidade < threshold) {
    myservo.write(servoOpenAngle);
    delay(servoDelay);
    myservo.write(servoClosedAngle);
  } else {
    myservo.write(servoClosedAngle);
    delay(delayTime);
  }
}
