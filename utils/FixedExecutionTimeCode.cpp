//
// Created by Dad on 8/30/19.
//

#include "FixedExecutionTimeCode.h"

#include "pigpio.h"

static const int MICRO_CONVERSION = 1000000;

FixedExecutionTimeCode::FixedExecutionTimeCode(int seconds, int micros)
: delaySeconds(seconds), delayMicros(micros)
{
    gpioTime(PI_TIME_RELATIVE, &startSeconds, &startMicros);
}

FixedExecutionTimeCode::~FixedExecutionTimeCode() {
    delayNow();
}

int toMicros(int seconds, int micros) {
    return seconds * MICRO_CONVERSION + micros;
}

void FixedExecutionTimeCode::delayNow() {
    int s, m;
    gpioTime(PI_TIME_RELATIVE, &s, &m);

    int start = toMicros(startSeconds, startMicros);
    int now = toMicros(s, m);

    int waited = now - start;
    int desiredWait = toMicros(delaySeconds, delayMicros);

    int waitStillNeeded = desiredWait - waited;
    if (waitStillNeeded > 0) {
        stats.push(waitStillNeeded);
        s = waitStillNeeded / MICRO_CONVERSION;
        m = waitStillNeeded - (s * MICRO_CONVERSION);
        if (waitStillNeeded > 50) {
            gpioSleep(PI_TIME_RELATIVE, s, m);
        } else {
            gpioDelay(m);
        }
    }
    delaySeconds = 0;
    delayMicros = 0;
}

RunningStat FixedExecutionTimeCode::stats;

