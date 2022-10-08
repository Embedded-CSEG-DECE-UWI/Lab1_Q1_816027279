/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include "hello_world_main.h"

static const uint32_t STUDENT_ID   = 816027279;
static const char    *STUDENT_NAME = "Aidan Pinard";
static const int      RESET_TIME   = ((STUDENT_ID) % 100) % 17;

void
app_main()
{
    printf("%s - %d\n", STUDENT_NAME, STUDENT_ID);

    /* Print chip information */
    esp_chip_info_t chip_info;
    esp_chip_info(&chip_info);

    printf("This is ESP8266 chip with %d CPU cores, WiFi, ", chip_info.cores);

    printf("silicon revision %d, ", chip_info.revision);

    printf("%dMB %s flash\n",
           spi_flash_get_chip_size() / (1024 * 1024),
           (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded"
                                                         : "external");

    for (int i = RESET_TIME; i >= 0; i--)
    {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}
