//
// Created by Dad on 9/3/19.
//

#include <algorithm>
#include "PiLampHardware.h"

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
