#include <stdio.h>
#include "pico/stdlib.h"

void ligaLed(uint vermelho, uint verde, uint azul, bool r, bool g, bool b) {
  gpio_put(vermelho, r);
  gpio_put(verde, g);
  gpio_put(azul, b);
  sleep_ms(1000);
}

const uint pino_vermelho = 13;
const uint pino_verde = 11;
const uint pino_azul = 12;

int main() {

    gpio_init(pino_vermelho);
    gpio_init(pino_verde);
    gpio_init(pino_azul);
    gpio_set_dir(pino_vermelho, GPIO_OUT);
    gpio_set_dir(pino_verde, GPIO_OUT);
    gpio_set_dir(pino_azul, GPIO_OUT);

    while (true) {

      ligaLed(pino_vermelho, pino_verde, pino_azul, 1, 0, 0);
      ligaLed(pino_vermelho, pino_verde, pino_azul, 0, 1, 0);
      ligaLed(pino_vermelho, pino_verde, pino_azul, 0, 0, 1);
      ligaLed(pino_vermelho, pino_verde, pino_azul, 1, 1, 0);
      ligaLed(pino_vermelho, pino_verde, pino_azul, 1, 0, 1);
      ligaLed(pino_vermelho, pino_verde, pino_azul, 0, 1, 1);
      ligaLed(pino_vermelho, pino_verde, pino_azul, 1, 1, 1);
      ligaLed(pino_vermelho, pino_verde, pino_azul, 0, 0, 0); /* Desliga todos os leds */

    }

    /* Por conseguinte, essa parte do programa nunca
    é executada pelo microcontrolador. */
    return 0;

}