//
// Created by Dad on 8/27/19.
//

#ifndef PILIGHTS_PIGPIOLAMPMATRIX_H
#define PILIGHTS_PIGPIOLAMPMATRIX_H

#include "LampMatrix.h"
#include "utils/TThread.h"

class PigpioLampMatrix;

class PigpioLampMatrix : public LampMatrix {
public:
    PigpioLampMatrix(int rows, int cols, int bits);
    virtual ~PigpioLampMatrix();

    virtual void setLamps(std::shared_ptr<LampSet>& lampsIn) override;
    virtual void startRefresh();
    virtual void stopRefresh();

protected:
    virtual void refreshLamps();

private:
    TThreadOf<PigpioLampMatrix> thread;
    int bits;
};


#endif //PILIGHTS_PIGPIOLAMPMATRIX_H
