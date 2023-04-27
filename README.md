# Varal-Automático
## Garden

  Para implementar esse projeto, será necessário utilizar as seguintes bibliotecas:

LiquidCrystal.h: para o display LCD;
Servo.h: para o controle do micro servo;
Wire.h: para a comunicação com o módulo de sensor de umidade de solo.
Além disso, é necessário conectar os componentes ao Arduino da seguinte forma:

# Conexões e montagem

O display LCD deve ser conectado aos pinos 12, 11, 5, 4, 3, 2;
O módulo de sensor de umidade de solo deve ser conectado aos pinos A0 e GND;
O potenciômetro deve ser conectado aos pinos A1 e GND;
O micro servo deve ser conectado ao pino 9.

Para montar esse projeto, siga os seguintes passos:

1. Conecte o display LCD aos pinos 12, 11, 5, 4, 3 e 2 do Arduino, sendo que o pino 1 do display é o pino ao lado do trimpot (potenciômetro ajustável) do display. O pino 1 do display deve ser conectado ao pino 12 do Arduino, o pino 2 do display deve ser conectado ao pino 11 do Arduino, e assim sucessivamente. Verifique o datasheet do seu display para garantir que está conectado corretamente.

2. Conecte o módulo de sensor de umidade de solo ao pino A0 e ao GND do Arduino. Certifique-se de que os pinos do módulo estejam bem conectados.

3. Conecte o potenciômetro aos pinos A1 e GND do Arduino. Ajuste o potenciômetro para que fique no meio de sua escala.

4. Conecte o micro servo ao pino 9 do Arduino e verifique se os fios estão bem conectados.

5. Carregue o código fornecido para o Arduino utilizando a IDE do Arduino. Certifique-se de que o tipo de placa selecionado na IDE é o "Arduino Uno" e que a porta serial correta está selecionada.

6. Depois de carregar o código para o Arduino, alimente o circuito com uma fonte de alimentação externa ou com a porta USB do computador. O display LCD deve exibir a umidade do solo medida pelo sensor. Se a umidade estiver abaixo do limiar definido, o micro servo girará para abrir o varal e permanecerá aberto por um período de tempo antes de retornar à posição original. Caso contrário, o servo permanecerá fechado.

7. Coloque o sensor de umidade de solo na terra ou no vaso de plantas e o varal na posição desejada.

# Datasheet

   O datasheet é um documento que contém informações técnicas sobre um componente eletrônico, como o display LCD, por exemplo. Você pode encontrá-lo facilmente pesquisando pelo modelo específico do componente na internet.

Normalmente, o datasheet está disponível no site do fabricante ou em sites de distribuidores autorizados. O documento contém especificações detalhadas, diagramas de pinos, características elétricas, informações de operação e outras informações relevantes.

Para verificar o datasheet do display LCD, procure pelo modelo específico na internet e baixe o arquivo PDF contendo as informações técnicas. No datasheet, você poderá encontrar o diagrama de pinos, especificações de tensão e corrente, instruções de operação e outras informações relevantes que podem ser úteis para montar e programar o projeto com sucesso.

# Funcionalidade

O código lê a umidade do solo e a potência do potenciômetro, converte os valores para porcentagem e tempo de atraso, respectivamente, e exibe a umidade no display LCD. Se a umidade for menor do que o limiar definido, o servo gira para o ângulo de abertura e aguarda por um período de tempo antes de retornar ao ângulo de fechamento. Caso contrário, o servo permanece no ângulo de fechamento pelo tempo definido pelo potenciômetro. Ajuste o valor do 'threshold()' para definir o limiar de umidade adequado ao seu caso.
