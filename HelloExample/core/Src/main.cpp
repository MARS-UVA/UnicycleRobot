#include "main.h" // if this is squiggly red, it's a vscode issue, so not real

#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#include <vector>
#include <iostream>
#define LOOP "Counting"

extern "C" void app_main(void)
{ // extern allows the compiler to know this is cpp
    std::vector<int> vector = {1, 2, 4, 8, 16, 32};
    std::cout << "\n\nI'm using vectors!" << std::endl;
    std::cout << "C doesn't have any built in vectors, but cpp does! Ts is so crazy." << std::endl;
    std::cout << "I'll start listing the elements in my vector...\n"
              << std::endl;
    uint8_t idx = 0;

    while (true)
    {
        for (uint8_t num : vector)
        {
            ESP_LOGI(LOOP, "\tAt idx - %d,\t%d", idx, num);
            idx += 1;
            idx %= vector.size();
            vTaskDelay(200);
        }
        std::cout << "\n\n"
                  << std::endl;
    }
}