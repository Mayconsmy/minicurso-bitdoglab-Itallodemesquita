#include <stdio.h>
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
    stdio_init_all();

    /* Inicialização do i2c */
    i2c_init(i2c1, ssd1306_i2c_clock * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    ssd1306_init();


    /* Declarando área de renderização */
    struct render_area frame_area = {
        start_column : 0,
        end_column : ssd1306_width - 1,
        start_page : 0,
        end_page : ssd1306_n_pages - 1
    };

    calculate_render_area_buffer_length(&frame_area);

    /* Zera o display */
    uint8_t ssd[ssd1306_buffer_length];
    memset(ssd, 0, ssd1306_buffer_length);
    render_on_display(ssd, &frame_area);

    restart:

    /* Exibindo mensagem no display */

    char *texto[] = {
        "  Hello World!  "};

    int y = 0;
    for (uint i = 0; i < count_of(texto); i++) {
        ssd1306_draw_string(ssd, 5, y, texto[i]);
        y += 8;
    }

    render_on_display(ssd, &frame_area);
    

}
