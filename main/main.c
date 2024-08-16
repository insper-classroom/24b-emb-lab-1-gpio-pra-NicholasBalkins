#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 9;
const int LED_PIN = 10;
const int ROT_PIN_1 = 21;
const int ROT_PIN_2 = 20;
const int ROT_PIN_3 = 19;
const int ROT_PIN_4 = 18;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  gpio_init(ROT_PIN_1);
  gpio_set_dir(ROT_PIN_1, GPIO_OUT);

  gpio_init(ROT_PIN_2);
  gpio_set_dir(ROT_PIN_2, GPIO_OUT);

  gpio_init(ROT_PIN_3);
  gpio_set_dir(ROT_PIN_3, GPIO_OUT);

  gpio_init(ROT_PIN_4);
  gpio_set_dir(ROT_PIN_4, GPIO_OUT);

  while (true) {
    if (!gpio_get(BTN_PIN)) {
    gpio_put(LED_PIN, 1);

    
    for(int i = 0; i < 512; i++) {
        gpio_put(ROT_PIN_1, 1);
      sleep_ms(10);
      gpio_put(ROT_PIN_1, 0);
      gpio_put(ROT_PIN_2, 1);
      sleep_ms(10);
      gpio_put(ROT_PIN_2, 0);
      gpio_put(ROT_PIN_3, 1);
      sleep_ms(10);
      gpio_put(ROT_PIN_3, 0);
      gpio_put(ROT_PIN_4, 1);
      sleep_ms(10);
      gpio_put(ROT_PIN_4, 0);

    }


    gpio_put(LED_PIN, 0);

      while (!gpio_get(BTN_PIN)) {
        

      };
    }
  }



}
