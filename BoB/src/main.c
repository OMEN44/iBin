#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "esp_log.h"

#define TAG "EPAPER"

#define SDA 8
#define SCL  9
#define CS   10
#define DC   11
#define RST  12
#define BUSY 13

void app_main()
{
    // setup GPIO pins for e-paper display
    esp_rom_gpio_pad_select_gpio(SDA);
    esp_rom_gpio_pad_select_gpio(SCL);
    esp_rom_gpio_pad_select_gpio(CS);
    esp_rom_gpio_pad_select_gpio(DC);
    esp_rom_gpio_pad_select_gpio(RST);
    esp_rom_gpio_pad_select_gpio(BUSY);
    gpio_set_direction(SDA, GPIO_MODE_OUTPUT);
    gpio_set_direction(SCL, GPIO_MODE_OUTPUT);
    gpio_set_direction(CS, GPIO_MODE_OUTPUT);
    gpio_set_direction(DC, GPIO_MODE_OUTPUT);
    gpio_set_direction(RST, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUSY, GPIO_MODE_INPUT);

    // setup epd
    gpio_set_level(RST, 1);
    gpio_set_level(DC, 1);
    gpio_set_level(SCL, 1);
    gpio_set_level(SDA, 1);
    gpio_set_level(CS, 1);

    // reset the display
    gpio_set_level(RST, 0);
    vTaskDelay(pdMS_TO_TICKS(10));
    gpio_set_level(RST, 1);
    vTaskDelay(pdMS_TO_TICKS(10));

    while (1);    
}

// spi_device_handle_t spi;

// void epd_send_cmd(uint8_t cmd) {
//     gpio_set_level(PIN_NUM_DC, 0); // Command mode
//     spi_transaction_t t = {
//         .length = 8,
//         .tx_buffer = &cmd
//     };
//     spi_device_transmit(spi, &t);
// }

// void epd_send_data(uint8_t data) {
//     gpio_set_level(PIN_NUM_DC, 1); // Data mode
//     spi_transaction_t t = {
//         .length = 8,
//         .tx_buffer = &data
//     };
//     spi_device_transmit(spi, &t);
// }

// void epd_wait_until_idle() {
//     while (gpio_get_level(PIN_NUM_BUSY) == 1) {
//         vTaskDelay(pdMS_TO_TICKS(100));
//     }
// }

// void epd_reset() {
//     gpio_set_level(PIN_NUM_RST, 0);
//     vTaskDelay(pdMS_TO_TICKS(200));
//     gpio_set_level(PIN_NUM_RST, 1);
//     vTaskDelay(pdMS_TO_TICKS(200));
// }

// void epd_init() {
//     epd_reset();
//     epd_send_cmd(0x01); // POWER_SETTING
//     epd_send_data(0x03);
//     epd_send_data(0x00);
//     epd_send_data(0x2B);
//     epd_send_data(0x2B);

//     epd_send_cmd(0x04); // POWER_ON
//     epd_wait_until_idle();

//     epd_send_cmd(0x00); // PANEL_SETTING
//     epd_send_data(0xCF);

//     epd_send_cmd(0x50); // VCOM AND DATA INTERVAL SETTING
//     epd_send_data(0x37);
// }

// void epd_clear() {
//     epd_send_cmd(0x10); // DATA_START_TRANSMISSION_1
//     for (int i = 0; i < 128 * 296 / 8; i++) {
//         epd_send_data(0xFF); // White
//     }

//     epd_send_cmd(0x13); // DATA_START_TRANSMISSION_2
//     for (int i = 0; i < 128 * 296 / 8; i++) {
//         epd_send_data(0xFF);
//     }

//     epd_send_cmd(0x12); // DISPLAY_REFRESH
//     epd_wait_until_idle();
// }

// void spi_epaper_init() {
//     spi_bus_config_t buscfg = {
//         .mosi_io_num = PIN_NUM_MOSI,
//         .miso_io_num = -1,
//         .sclk_io_num = PIN_NUM_CLK,
//         .quadwp_io_num = -1,
//         .quadhd_io_num = -1
//     };
//     spi_bus_initialize(SPI2_HOST, &buscfg, SPI_DMA_CH_AUTO);

//     spi_device_interface_config_t devcfg = {
//         .clock_speed_hz = 2 * 1000 * 1000,
//         .mode = 0,
//         .spics_io_num = PIN_NUM_CS,
//         .queue_size = 7,
//     };
//     spi_bus_add_device(SPI2_HOST, &devcfg, &spi);
// }

// void gpio_epaper_init() {
//     gpio_config_t io_conf = {
//         .pin_bit_mask = (1ULL << PIN_NUM_DC) | (1ULL << PIN_NUM_RST),
//         .mode = GPIO_MODE_OUTPUT
//     };
//     gpio_config(&io_conf);

//     gpio_set_direction(PIN_NUM_BUSY, GPIO_MODE_INPUT);
// }

// void app_main() {
//     gpio_epaper_init();
//     spi_epaper_init();
//     epd_init();
//     epd_clear();
//     ESP_LOGI(TAG, "E-paper cleared!");
// }


