/**
 * @file main.c
 * @brief Phase 01 — System Information & Silicon Revision Reporter
 * @details Inspects ESP32 dual-core Xtensa CPU, silicon revision, features,
 *          MAC address, and runtime heap memory maps.
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "esp_mac.h"
#include "esp_log.h"

static const char *TAG = "PHASE01_SYSINFO";

void app_main(void)
{
    ESP_LOGI(TAG, "==================================================");
    ESP_LOGI(TAG, "  ESP32 350-DAY MASTER PLAN — PHASE 01 STARTER    ");
    ESP_LOGI(TAG, "==================================================");

    /* 1. Query Chip Specifications */
    esp_chip_info_t chip_info;
    uint32_t flash_size;
    esp_chip_info(&chip_info);

    ESP_LOGI(TAG, "Chip Model:        %s", CONFIG_IDF_TARGET);
    ESP_LOGI(TAG, "CPU Cores:         %d", chip_info.cores);
    ESP_LOGI(TAG, "Silicon Revision:  v%d.%d", chip_info.revision / 100, chip_info.revision % 100);

    /* 2. Chip Features */
    ESP_LOGI(TAG, "Features:");
    ESP_LOGI(TAG, " - Wi-Fi 802.11b/g/n: %s", (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "YES" : "NO");
    ESP_LOGI(TAG, " - Bluetooth BLE:     %s", (chip_info.features & CHIP_FEATURE_BLE) ? "YES" : "NO");
    ESP_LOGI(TAG, " - Bluetooth Classic: %s", (chip_info.features & CHIP_FEATURE_BT) ? "YES" : "NO");
    ESP_LOGI(TAG, " - Embedded Flash:    %s", (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "YES" : "NO");

    /* 3. Flash Memory Size */
    if (esp_flash_get_size(NULL, &flash_size) == ESP_OK) {
        ESP_LOGI(TAG, "SPI Flash Size:    %" PRIu32 " MB (%s)", flash_size / (1024 * 1024),
                 (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
    }

    /* 4. Factory MAC Address */
    uint8_t mac[6];
    if (esp_read_mac(mac, ESP_MAC_WIFI_STA) == ESP_OK) {
        ESP_LOGI(TAG, "Wi-Fi Station MAC: %02X:%02X:%02X:%02X:%02X:%02X",
                 mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    }

    /* 5. Heap Memory Architecture */
    ESP_LOGI(TAG, "--------------------------------------------------");
    ESP_LOGI(TAG, "HEAP MEMORY PROFILE:");
    ESP_LOGI(TAG, " - Free Heap:      %" PRIu32 " bytes", esp_get_free_heap_size());
    ESP_LOGI(TAG, " - Min Free Heap:  %" PRIu32 " bytes", esp_get_minimum_free_heap_size());
    ESP_LOGI(TAG, "==================================================");

    ESP_LOGI(TAG, "Phase 01 setup verified successfully! Ready for Day 2.");

    /* Periodic heartbeat loop */
    int loop_counter = 0;
    while (1) {
        vTaskDelay(pdMS_TO_TICKS(5000));
        loop_counter++;
        ESP_LOGI(TAG, "Heartbeat #%d | Uptime: %" PRIu32 " s | Free Heap: %" PRIu32 " B",
                 loop_counter,
                 (uint32_t)(esp_log_timestamp() / 1000),
                 esp_get_free_heap_size());
    }
}

