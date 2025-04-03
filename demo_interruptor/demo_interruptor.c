#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos do LED e Botão na BitDogLab
#define pino_vermelho 11  // Pino do LED Vermelho
#define botao_A 5  // Pino do Botão A

int main() {
    // Inicializa o padrão de entrada/saída
    stdio_init_all();
    
    // Configura o pino do LED como saída
    gpio_init(pino_vermelho);
    gpio_set_dir(pino_vermelho, GPIO_OUT);
    
    // Configura o pino do botão como entrada com pull-up interno
    gpio_init(botao_A);
    gpio_set_dir(botao_A, GPIO_IN);
    gpio_pull_up(botao_A);
    
    while (true) {
        // Lê o estado do botão (ativo em nível baixo)
        bool button_pressed = !gpio_get(botao_A); /* Guarda o estado do botão */
        
        // Liga ou desliga o LED conforme o estado do botão
        gpio_put(pino_vermelho, button_pressed);
        
        sleep_ms(10); // Pequeno atraso para debounce
    }
}
