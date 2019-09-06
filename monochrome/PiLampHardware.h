//
// Created by Dad on 9/3/19.
//

#ifndef PILIGHTS_PILAMPHARDWARE_H
#define PILIGHTS_PILAMPHARDWARE_H

#include "MonoLampMatrixHardware.h"
#include "pigpio.h"
#include <algorithm>

template <int rows, int cols>
class PiLampHardware : public MonoLampMatrixHardware<rows, cols> {
public:
    PiLampHardware(int *rowPins, int *colPins, bool activeHigh = true);
    PiLampHardware(bool activeHigh);
    virtual ~PiLampHardware() = default;

protected:
    virtual void refreshColumn(int row, const bool* values);

private:
    void setPin(int pin, bool value);

    bool activeHigh;
    std::array<int, rows> rowPins;
    std::array<int, cols> colPins;
};

template<int rows, int cols>
PiLampHardware<rows, cols>::PiLampHardware(int rowPinsIn[], int colPinsIn[], bool activeHighIn)
        :activeHigh(activeHigh), rowPins(), colPins()
{
    std::copy_n(&rowPinsIn[0], rows, rowPins.begin());
    std::copy_n(&colPinsIn[0], cols, colPins.begin());

/*    for (int i = 0; i < rows; i++) {
        rowPins[i] = rowPinsIn[i];
    }
    for (int i = 0; i < cols; i++) {
        colPins[i] = colPinsIn[i];
    } */
}

template<int rows, int cols>
void PiLampHardware<rows, cols>::refreshColumn(int row, const bool* values) {
    for (int i = 0; i < rows; i++) {
        setPin(rowPins[i], !activeHigh);
    }
    for (int i = 0; i < cols; i++) {
        setPin(colPins[i], activeHigh == values[i]);
    }
    setPin(rowPins[row], activeHigh);
}

template<int rows, int cols>
inline void PiLampHardware<rows, cols>::setPin(int pin, bool value) {
    gpioWrite(pin, value);
}


#endif //PILIGHTS_PILAMPHARDWARE_H
