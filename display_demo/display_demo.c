#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "pico/binary_info.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#include "display/ssd1306.h"


const uint I2C_SDA = 14;
const uint I2C_SCL = 15;


int main() {
    
    /* Inicializa a comunicação i2c */
    i2c_init(i2c1, ssd1306_i2c_clock * 1000);

    /* Tranforma os pinos em barramentos i2c*/
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);

    /* Mantém o estado lógico HIGH */
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    /* Função de inicialização do Display SSD1306 */
    ssd1306_init();


    /* Declarando área de renderização */
    struct render_area frame_area = {
        start_column : 0,
        end_column : ssd1306_width - 1, /* 128 de largura */
        start_page : 0,
        end_page : ssd1306_n_pages - 1 /* 64 / 8 = 8 */
    };

    /* Calcula tamanho do buffer a partir da área de renderização */
    calculate_render_area_buffer_length(&frame_area);

    /* Declaração do buffer */
    uint8_t ssd[ssd1306_buffer_length];

    /* Limpa o buffer */
    memset(ssd, 0, ssd1306_buffer_length);

    /* Renderiza a informação do buffer no display */
    render_on_display(ssd, &frame_area);

    char *string[] = {
        " ",
        "  Hello World  "};
    
    /* Declarando linha */
    int y = 0;

    /* Percorre cada linha do vetor */
    for (uint i = 0; i < count_of(string); i++) {

        /* Desenha a string, letra por letra */
        ssd1306_draw_string(ssd, 5, y, string[i]);

        /* Pula uma linha */
        y += 8;
    }

    /* Renderiza o texto no display */
    render_on_display(ssd, &frame_area);
    

}
