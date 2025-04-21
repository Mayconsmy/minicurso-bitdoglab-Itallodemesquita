#include <stdio.h>
#include "pico/stdlib.h"


int main() {

    /* Definindo os pinos RGB na BitDogLab*/
    const uint pino_vermelho = 13;
    const uint pino_verde = 11;
    const uint pino_azul = 12;

    stdio_init_all();
    
    // Configura os pinos do LED RGB como saída
    gpio_init(pino_verde);
    gpio_init(pino_vermelho);
    gpio_init(pino_azul);

    gpio_set_dir(pino_vermelho, GPIO_OUT);
    gpio_set_dir(pino_verde, GPIO_OUT);
    gpio_set_dir(pino_azul, GPIO_OUT);
    /* Por que o led é definido como saída? */
    
    /* while (true) {

        // Definindo cores do led
        gpio_put(pino_vermelho, 1);
        gpio_put(pino_verde, 1);
        gpio_put(pino_azul, 1);

    } */

    while (true) {

        gpio_put(pino_vermelho, 1);
        gpio_put(pino_verde, 0);
        sleep_ms(3000);

        gpio_put(pino_verde, 1);
        gpio_put(pino_vermelho, 1);
        sleep_ms(3000);

    }

    return 0;

}