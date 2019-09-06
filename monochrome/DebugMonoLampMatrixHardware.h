//
// Created by Dad on 8/30/19.
//

#ifndef PILIGHTS_DEBUGMONOLAMPMATRIXHARDWARE_H
#define PILIGHTS_DEBUGMONOLAMPMATRIXHARDWARE_H

#include "monochrome/MonoLampMatrixHardware.h"
#include "utils/FixedExecutionTimeCode.h"
#include <iostream>

template <int rows, int cols>
class DebugMonoLampMatrixHardware : public MonoLampMatrixHardware<rows, cols> {
public:

protected:
    virtual void refreshColumn(int row, const bool* values);

private:
    static char valStr(bool b);
};

template <int rows, int cols>
void DebugMonoLampMatrixHardware<rows, cols>::refreshColumn(int row, const bool* values) {
    FixedExecutionTimeCode timer(0,1000*1000/250000);
}

template <int rows, int cols>
char DebugMonoLampMatrixHardware<rows, cols>::valStr(bool val) {
    return (val) ? '1' : '0';
}

#endif //PILIGHTS_DEBUGMONOLAMPMATRIXHARDWARE_H
