#include <iostream>
#include <iostream>

#include "pigpio.h"

int value = 0;
int count = 0;

void bing() {
    value = ~value;
    gpioWrite(37, value);
    count++;
}

int main() {
    int err = gpioInitialise();
    if (err == 0) {
        try {
            gpioSetMode(37, PI_OUTPUT);
            err = gpioSetTimerFunc(0, 500, &bing);
            if (err) {
                gpioDelay(60*1000*1000);
                gpioSetTimerFunc(0, 500, 0);
                gpioWrite(37, 0);
                std::cout << "Done.";
            } else {
                std::cout << "Failed to set up timer: " << err << std::endl;
            }
        } catch (...) {
            gpioTerminate();
        }
    } else {
        std::cout << "Failed to initialize: " << err << std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}