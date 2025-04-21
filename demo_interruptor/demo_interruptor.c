#include <stdio.h>
#include "pico/stdlib.h"


int main() {
    // Inicializa o padrão de entrada/saída

    // Definição dos pinos do LED e Botão na BitDogLab
    const uint pino_vermelho = 13;
    const uint botao_A = 5;

    stdio_init_all();
    
    // Configura o pino do LED como saída
    gpio_init(pino_vermelho);
    gpio_set_dir(pino_vermelho, GPIO_OUT);

    // O led inicia desligado
    gpio_put(pino_vermelho, 0);
    
    // Configura o pino do botão como entrada com pull-up interno
    gpio_init(botao_A);
    gpio_set_dir(botao_A, GPIO_IN);
    gpio_pull_up(botao_A);
    
    while (true) {
        // Lê o estado do botão (ativo em nível baixo)

        if (gpio_get(botao_A) == 0) {
            gpio_put(pino_vermelho, 1);
        }

        else {
            gpio_put(pino_vermelho, 0);
        }
        
        // Liga ou desliga o LED conforme o estado do botão
        
        sleep_ms(10); // Pequeno atraso para debounce
    }
}
