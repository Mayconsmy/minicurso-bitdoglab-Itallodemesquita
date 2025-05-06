# 🎛️ Demonstração: Uso de LED, Botões e Display com Raspberry Pi Pico

Este projeto demonstra como utilizar três periféricos essenciais com o **Raspberry Pi Pico W**: **LEDs**, **botões** e **display OLED** (SSD1306 via I2C). É um exemplo didático ideal para iniciantes no desenvolvimento embarcado com C e o SDK oficial do Pico.

### 🎯 Objetivo

Demonstrar como:
- Inicializar e controlar **LEDs RGB**
- Ler o estado de **botões físicos**
- Escrever e exibir mensagens em um **display OLED SSD1306**
- Integrar esses três periféricos em um único programa funcional usando C e o SDK oficial do Pico.


## 📂 Estrutura Geral do Código

### 1. Inclusão de bibliotecas

```c
#include <string.h>

#include "pico/stdlib.h"
#include "hardware/i2c.h"

#include "ssd1306.h"
````

Essas bibliotecas oferecem:

* Controle de GPIO e temporização (`pico/stdlib.h`)
* Manipulação de arrays de strings (`string.h`)
* Comunicação I2C (`hardware/i2c.h`)
* Manipulação do display OLED SSD1306 (`ssd1306.h`)

---

### 2. Inicialização de Periféricos

#### `initLed(pin)`

Configura o pino como saída para controlar um LED (ex: pino 13).

```c
gpio_init(pin);
gpio_set_dir(pin, GPIO_OUT);
```

#### `putLed(r, g, b, R_val, G_val, B_val)`

Controla o estado dos três eletrodos do LED RGB, ligando ou desligando conforme os valores lógicos fornecidos.

#### `initButton(pin)`

Inicializa o botão com resistor de pull-up interno ativado.

```c
gpio_init(pin);
gpio_set_dir(pin, GPIO_IN);
gpio_pull_up(pin);
```

#### `initDisplay(buffer, area)`

Inicializa o barramento I2C (padrão pinos GP14 e GP15) e configura a área de renderização do display.

```c
i2c_init(i2c1, ssd1306_i2c_clock * 1000);
gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
gpio_pull_up(I2C_SDA);
gpio_pull_up(I2C_SCL);
```

---

### 3. Escrita no Display

#### `typeText(buffer, area, text[], count)`

A função screve múltiplas strings no buffer e as renderiza no display.

```c
for (int i = 0; i < count; i++) {
    ssd1306_draw_string(buffer, 0, i, text[i]);
}
render_on_display(buffer, *area);
```


## 🧠 Função `main()`

```c
initLed(led_vermelho);
initLed(led_verde);
initLed(led_azul);

initButton(botao_A);
initButton(botao_B);
```

* Inicializa LEDs nos pinos 13 (vermelho), 11 (verde), 12 (azul) e botões A e B nos pinos 4 e 5 (respectivamente).

```c
initDisplay(ssd, &frame_area);
```

* Inicializa o display OLED.

```c
char *message[] = {"", "   Hello World"};
typeText(ssd, frame_area, message, count_of(message));
```

* Define uma mensagem e exibe no display.

```c
putLed(led_vermelho, led_verde, led_azul, 0, 1, 0);
```

* Acende o LED verde (pino 11).

```c
while (1) {
    sleep_ms(500);
}
```

* Loop principal vazio — apenas mantém o sistema ativo.


## 📌 Pinos Utilizados

| Pino   | Função                        |
| ----   | ----------------------------- |
| 13     | LED vermelho                  |
| 11     | LED verde                     |
| 12     | LED azul                      |
| 4      | Botão A                       |
| 5      | Botão B                       |
| 14/15  | I2C SDA/SCL para display OLED |

---

## 🔗 Links Úteis

* [SDK do Raspberry Pi Pico (C/C++)](https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html)
* [BitDogLab — Banco de Informações de Hardware (BIH)](google.com)

---

## 📥 Simulação e compilação

1. Antes de rodá-lo na placa, simule o programa via Wokwi ou outra ferramenta de simulação de hardware.
2. Ao executar diretamente no hardware, compile antes com `cmake` e `make`.
3. Execute o programa via extensão do Raspberry.

---
