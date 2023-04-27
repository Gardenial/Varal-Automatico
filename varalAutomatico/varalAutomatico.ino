#include <LiquidCrystal.h> // Biblioteca para o display LCD
#include <Servo.h> // Biblioteca para o micro servo

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Pinos utilizados para o display LCD
Servo motor; // Objeto do micro servo
int sensorPin = A0; // Pino utilizado para o sensor de umidade de solo
int potPin = A1; // Pino utilizado para o potenciômetro
int motorPin = 9; // Pino utilizado para o micro servo
int motorPos = 0; // Posição inicial do motor
int threshold = 500; // Limiar de umidade
int timeOut = 5000; // Tempo em milissegundos que o motor permanece aberto
unsigned long startTime = 0; // Tempo em que o motor foi acionado
int umid = 0; // Variável para armazenar a umidade medida
int potValue = 0; // Variável para armazenar o valor do potenciômetro

void setup() {
  lcd.begin(16, 2); // Inicializa o display LCD com 16 colunas e 2 linhas
  motor.attach(motorPin); // Conecta o micro servo ao pino 9
}

void loop() {
  umid = analogRead(sensorPin); // Lê a umidade medida pelo sensor
  potValue = analogRead(potPin); // Lê o valor do potenciômetro

  // Converte o valor lido do potenciômetro em um intervalo de 0 a 180 graus
  motorPos = map(potValue, 0, 1023, 0, 180);

  lcd.clear(); // Limpa o display LCD
  lcd.setCursor(0, 0); // Define o cursor para a primeira coluna da primeira linha
  lcd.print("Umidade: "); // Escreve "Umidade: " no display LCD
  lcd.print(umid); // Escreve a umidade medida no display LCD
  lcd.setCursor(0, 1); // Define o cursor para a primeira coluna da segunda linha

  // Verifica se a umidade é menor que o limiar definido
  if (umid < threshold) {
    motor.write(motorPos); // Gira o motor na direção horária
    startTime = millis(); // Armazena o tempo atual
    lcd.print("Motor Aberto"); // Escreve "Motor Aberto" no display LCD
  } else {
    motor.write(0); // Mantém o motor parado
    lcd.print("Motor Fechado"); // Escreve "Motor Fechado" no display LCD
  }

  // Verifica se o tempo em que o motor está aberto excedeu o tempo limite
  if ((millis() - startTime) > timeOut) {
    motor.write(0); // Gira o motor na direção anti-horária
  }

  delay(500); // Espera 500 milissegundos antes de executar novamente o loop
}
