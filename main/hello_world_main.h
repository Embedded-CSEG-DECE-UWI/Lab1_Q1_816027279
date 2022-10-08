/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#ifndef HELLO_WORLD_MAIN_H
#define HELLO_WORLD_MAIN_H
#include "esp_spi_flash.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>

/**
 * @brief Sends a message with the programmer's name and ID number, then resets
 * after the last two digits of the ID number mod 17 seconds.
 */
void appmain();

#endif
