#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "pico/binary_info.h"
#include "pico/stdlib.h"

#include "hardware/i2c.h"
#include "display/ssd1306.h"

const uint I2C_SDA = 14; /* Declarando barramento SDA */
const uint I2C_SCL = 15; /* Declarando barramento SCL */

void initLed(uint pin) {
  gpio_init(pin);
  gpio_set_dir(pin, GPIO_OUT);
}

void putLed(uint red, uint green, uint blue, bool r, bool g, bool b) {
  gpio_put(red, r);
  gpio_put(green, g);
  gpio_put(blue, b);
}

void initButton(uint pin) {
  gpio_init(pin);
  gpio_set_dir(pin, GPIO_IN);
  gpio_pull_up(pin);
}

/* Função de inicialização do display */
void initDisplay(uint8_t *ssd, struct render_area *frame_area) {
  i2c_init(i2c1, ssd1306_i2c_clock * 1000);
  gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
  gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
  gpio_pull_up(I2C_SDA);
  gpio_pull_up(I2C_SCL);

  ssd1306_init();

  /* Define área do display que será desenhada */
  *frame_area = (struct render_area) {
    .start_column = 0,
    .end_column = ssd1306_width - 1, // 128 de largura
    .start_page = 0,
    .end_page = ssd1306_n_pages - 1 // 64 / 8
  }; 

  /* Calcula tamanho do buffer a partir da área de renderização */
  calculate_render_area_buffer_length(frame_area);

  /* Limpa o buffer */
  memset(ssd, 0, ssd1306_buffer_length);

  /* Renderiza a informação presente no buffer */
  render_on_display(ssd, frame_area);
}

/* Função que escreve texto no display */
void typeText(uint8_t *ssd, struct render_area frame_area, char *text[], int count_of) { 
  memset(ssd, 0, ssd1306_buffer_length); /* Zera o conteúdo do buffer */
  
  /* Declarando linha */
  int y = 0;

  /* Percorre cada linha do vetor */
  for (uint i = 0; i < count_of; i++) { 

    /* Desenha a string, letra por letra */
    ssd1306_draw_string(ssd, 0, y, text[i]); 
    y += 8; /* Pula uma linha */
  }

  /* Renderiza o texto no display */
  render_on_display(ssd, &frame_area); 
}

int main() {

  const uint botao_A = 5;
  const uint botao_B = 6;
  const uint led_vermelho = 13;
  const uint led_verde = 11;
  const uint led_azul = 12;

  initLed(led_vermelho);
  initLed(led_verde);
  initLed(led_azul);

  initButton(botao_A);
  initButton(botao_B);

  uint8_t ssd[ssd1306_buffer_length];  /* Define o tamanho do buffer */
  struct render_area frame_area; /* Define a área de renderização do display */
  initDisplay(ssd, &frame_area);

  while (true) {

    char *message[] = {"", "   Hello World", "   ECOP"};
    typeText(ssd, frame_area, message, count_of(message));
    putLed(led_vermelho, led_verde, led_azul, 0, 1, 0);
    sleep_ms(10000);
  }

    return 0;
}