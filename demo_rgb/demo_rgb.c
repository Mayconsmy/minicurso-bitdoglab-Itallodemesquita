#include <stdio.h>
#include "pico/stdlib.h"


/* Acendendo o led */
// Definição dos pinos do LED RGB na BitDogLab
#define pino_vermelho 13  // Pino do LED Vermelho
#define pino_verde 11  // Pino do LED Verde

int main() {
    // Inicializa o padrão de entrada/saída
    stdio_init_all();
    
    // Configura os pinos do LED RGB como saída
    gpio_init(pino_vermelho);
    gpio_set_dir(pino_vermelho, GPIO_OUT);
    gpio_init(pino_verde);
    gpio_set_dir(pino_verde, GPIO_OUT);
    
    while (true) {
        // Acende o LED vermelho e apaga o verde
        gpio_put(pino_vermelho, 1);
        gpio_put(pino_verde, 0);
        sleep_ms(1000); // Aguarda 1 segundo

        // Acende o LED verde e apaga o vermelho
        gpio_put(pino_vermelho, 0);
        gpio_put(pino_verde, 0);
        sleep_ms(1000); // Aguarda 1 segundo
    }
}
