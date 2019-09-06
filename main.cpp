#include <iostream>
#include <iostream>

#include "pigpio.h"
#include "monochrome/DebugMonoLampMatrixHardware.h"
#include "monochrome/SimpleMonoLampSet.h"

int testRefresh() {
    static const int wait = 20;

    bool values[] = { 0, 1, 1, 1,   1, 0, 1, 1,   1, 1, 0, 1 };
    SimpleMonoLampSet<12> lampSet;
    lampSet.setData(values);
    DebugMonoLampMatrixHardware<3,4> matrix;
    matrix.setLamps(&lampSet);
    matrix.startRefresh();
    for (int i = 0; i < 15 * 1000 * 1000 / wait; i++) {
        gpioDelay(wait);
    }
//    gpioSleep(PI_TIME_RELATIVE, 15, 0);
    matrix.stopRefresh();
    FixedExecutionTimeCode::stats.dumpToCout();
    return 0;
}


#define TESTPIN 26
#define CYCLE_TIME 50

int DUTY_CYCLE = 100;
int value = 0;

void* bing(void* userData) {
    while (true) {
        value++;
        value = value % 100;
        gpioWrite(TESTPIN, (value <= DUTY_CYCLE));
        gpioSleep(PI_TIME_RELATIVE, 0, CYCLE_TIME);
    }
    return userData;
}

int testGpio() {
    int err = gpioInitialise();
    if (err != PI_INIT_FAILED) {
       try {
            gpioSetMode(TESTPIN, PI_OUTPUT);
            pthread_t* thread = gpioStartThread(&bing, nullptr);
            if (thread != nullptr) {
                for (int i = 100; i >= 0; i = i - 5) {
                    gpioSleep(PI_TIME_RELATIVE, 1, 0);
                    DUTY_CYCLE = i;
                    value = 0;
                }
                gpioStopThread(thread);
            } else {
                std::cout << "Failed to set up timer: " << err << std::endl;
            }
            gpioWrite(TESTPIN, 0);
            gpioTerminate();
        } catch (...) {
            gpioTerminate();
        }
    } else {
        std::cout << "Failed to initialize: " << err << std::endl;
    }

    std::cout << "Done." << std::endl;
    return 0;
}

int main() {
    int err = gpioInitialise();
    if (err != PI_INIT_FAILED) {
        try {
            testRefresh();
        } catch (...) {
            gpioTerminate();
        }
    } else {
        std::cout << "Failed to initialize: " << err << std::endl;
    }

    std::cout << "Done." << std::endl;
    return 0;
}
