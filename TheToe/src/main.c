#include <stdio.h>
#include "driver/gpio.h"
// #include "freeRTOS\freeRTOS.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

int counter = 0;

void app_main() {


    esp_rom_gpio_pad_select_gpio(8);
    gpio_set_direction(8, GPIO_MODE_OUTPUT);

    while (1) {
        // Blink the LED
        gpio_set_level(8, 0);
        vTaskDelay(pdMS_TO_TICKS(1000));
        printf("ON\n");
        gpio_set_level(8, 1);
        vTaskDelay(pdMS_TO_TICKS(1000));
        printf("OFF\n");
    }
}




/*
#include <stdio.h>

void app_main() {
    while (1) {
    printf("Ice cream\n");
    }
}
*/