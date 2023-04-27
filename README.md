# Varal-Automático
## Garden

  Para implementar esse projeto, será necessário utilizar as seguintes bibliotecas:

LiquidCrystal.h: para o display LCD;
Servo.h: para o controle do micro servo;
Wire.h: para a comunicação com o módulo de sensor de umidade de solo.
Além disso, é necessário conectar os componentes ao Arduino da seguinte forma:

# Conexões

O display LCD deve ser conectado aos pinos 12, 11, 5, 4, 3, 2;
O módulo de sensor de umidade de solo deve ser conectado aos pinos A0 e GND;
O potenciômetro deve ser conectado aos pinos A1 e GND;
O micro servo deve ser conectado ao pino 9.

# Funcionalidade

O código lê a umidade do solo e a potência do potenciômetro, converte os valores para porcentagem e tempo de atraso, respectivamente, e exibe a umidade no display LCD. Se a umidade for menor do que o limiar definido, o servo gira para o ângulo de abertura e aguarda por um período de tempo antes de retornar ao ângulo de fechamento. Caso contrário, o servo permanece no ângulo de fechamento pelo tempo definido pelo potenciômetro. Ajuste o valor do 'threshold()' para definir o limiar de umidade adequado ao seu caso.
