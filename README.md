# Introdução ao desenvolvimento embarcado com BitDogLab

Repositório oficial do minicurso de "Introdução ao desenvolvimento embarcado com BitDogLab", ministrado por mim. Aqui, você encontrará aplicações e demonstrações básicas de código em linguagem C para manipulação de componentes da placa BitDogLab e do microcontrolador da Raspberry, feitas com base em Pico SDK.

### Introdução
A BitDogLab é um projeto de hardware aberto da Universidade de Campinas (UNICAMP), focado no ensino de eletrônica e de sistemas embarcados. Sua arquitetura é composta pelo microcontrolador Raspberry Pi Pico W, conectividade Bluetooth e Wi-Fi e compatibilidade com diversos protocolos de comunicação serial (UART, i2c, PWM, ADC) e sua organização é composta por diversos periféricos soldados em placa, como botões, joystick, buzzers, microfone, matriz de LEDs, sensor de temperatura, entre outros.

### Pico SDK
Para facilitar o processo de desenvolvimento de aplicações para seus microcontroladores, a Raspberry Foundation desenvolveu um kit de desenvolvimento de software (SDK) composto por diversas bibliotecas pré-definidas que possibilitam a manipulação de componentes de alto e baixo nível de seu microcontrolador.

### Roteiro do Minicurso
O minicurso terá duração de 4 horas, divididas em:

- Apresentação do professor e do conteúdo do minicurso
- Introdução aos sistemas embarcados
- Primeiro contato com a BitDogLab
- Manipulação de LEDs e cores
- Uso de botões e implementação de eventos
- Mensagens de saída em display
- Desafio final

## Cheat sheet (Raspberry Pi Pico W)
### Controle de pinos GPIO
| Função | Descrição |
| ----------------| ----- |
| `gpio_init(uint pino);`| Inicializa o pino |
| `gpio_set_dir(uint pin, GPIO_IN);`| Define como entrada |
| `gpio_set_dir(uint pin, GPIO_OUT);`| Define como saída |
| `gpio_put(uint pino, 0);`| Define o pino em estado LOW |
| `gpio_put(uint pino, 1);`| Define o pino em estado HIGH |
| `bool gpio_get(uint pino);`| Lê o estado do pino |
| `gpio_pull_up(uint pino);`| Ativa pull-up |
| `gpio_pull_down(uint pino);`| Ativa pull-down |

### Temporização
| Função | Descrição |
| ----------------| ----- |
| `sleep_ms(uint32_t ms);`| Delay em milissegundos |
| `sleep_us(uint32_t us);`| Delay em microssegundos |

### Comunicação I2C
| Função | Descrição |
| ----------------| ----- |
| `i2c_init(i2c_inst, freq_khz);`| Inicializa o barramento I2C com frequência especificada |
| `ssd1306_init();`| Inicializa o display OLED SSD1306 |
| `render_on_display(buffer, area);`| Renderiza o conteúdo do buffer na área de exibição definida |
| `ssd1306_draw_string(buffer, x, y, text);`| Escreve texto no buffer em coordenadas x, y |
| `calculate_render_area_buffer_length();`| Calcula o tamanho do buffer com base na área de renderização |