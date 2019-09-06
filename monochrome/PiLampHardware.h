//
// Created by Dad on 9/3/19.
//

#ifndef PILIGHTS_PILAMPHARDWARE_H
#define PILIGHTS_PILAMPHARDWARE_H

#include "MonoLampMatrixHardware.h"

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

#endif //PILIGHTS_PILAMPHARDWARE_H
