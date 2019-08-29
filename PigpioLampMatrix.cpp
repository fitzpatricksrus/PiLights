//
// Created by Dad on 8/27/19.
//

#include "PigpioLampMatrix.h"

PigpioLampMatrix::PigpioLampMatrix(int rows, int cols, int bitsIn)
: LampMatrix(rows, cols), thread(this, &PigpioLampMatrix::refreshLamps), bits(bitsIn)
{
}

PigpioLampMatrix::~PigpioLampMatrix() {
}

void PigpioLampMatrix::setLamps(std::shared_ptr<LampSet>& lampsIn) {
    LampMatrix::setLamps(lampsIn);
}

void PigpioLampMatrix::startRefresh() {
    thread.stop();
    thread.start();
}

void PigpioLampMatrix::stopRefresh() {
    thread.stop();
}

void PigpioLampMatrix::refreshLamps() {

}

