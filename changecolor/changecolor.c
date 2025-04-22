#include <stdio.h>
#include "pico/stdlib.h"
#include <stdbool.h>

void put_led(uint red, uint green, uint blue, bool r, bool g, bool b) {

    gpio_put(red, r);
    gpio_put(green, g);
    gpio_put(blue, b);

}

void config_leds(uint red, uint green, uint blue) {

    gpio_init(red);
    gpio_init(green);
    gpio_init(blue);

    gpio_set_dir(red, GPIO_OUT);
    gpio_set_dir(green, GPIO_OUT);
    gpio_set_dir(blue, GPIO_OUT);

}


int main() {

    const uint led_vermelho = 13;
    const uint led_verde = 11;
    const uint led_azul = 12;

    bool r = 0;
    bool g = 0;
    bool b = 0;

    stdio_init_all();

    config_leds(led_vermelho, led_verde, led_azul);

    while (true) {

        put_led(led_vermelho, led_verde, led_azul, r, g, b);

        b = !b; // inverte o estado lógico do led azul a cada ciclo

        if (b == 0) { /* se o azul volta a zero, inverte o verde */
            g = !g;
        }

        if (b == 0 && g == 0) { /* se o azul e o verde volta a zero, inverte o vermelho */
            r = !r;
        }

        sleep_ms(200);

    }

    return 0;
}
