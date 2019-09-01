//
// Created by Dad on 8/29/19.
//

#ifndef PILIGHTS_MONOLAMPMATRIXHARDWARE_H
#define PILIGHTS_MONOLAMPMATRIXHARDWARE_H

#include "monochrome/MonoLampHardware.h"
#include "utils/TThread.h"
#include <stdexcept>

template <int rows, int cols>
class MonoLampMatrixHardware : public MonoLampHardware {
public:
    MonoLampMatrixHardware();
    virtual ~MonoLampMatrixHardware() = default;

    virtual MonoLampSet* getLamps() const override { return lamps; };
    virtual void setLamps(MonoLampSet* lampsIn) override;
    virtual void startRefresh() override { refreshThread.start(); }
    virtual void stopRefresh() override { refreshThread.cancel(); }
    virtual bool refreshIsActive() override { return refreshThread.isRunning(); }

    virtual int getRowCount() const { return rows; };
    virtual int getColCount() const { return cols; };

protected:
    virtual void refreshColumn(int row, const bool* values) = 0;
    virtual void refreshLamps();

private:
    MonoLampSet* lamps;
    TThreadOf<MonoLampMatrixHardware> refreshThread;
};


template <int rows, int cols>
MonoLampMatrixHardware<rows, cols>::MonoLampMatrixHardware()
    : MonoLampHardware(), lamps(nullptr), refreshThread(this, &MonoLampMatrixHardware::refreshLamps)
{
}

template <int rows, int cols>
void MonoLampMatrixHardware<rows, cols>::setLamps(MonoLampSet* lampsIn) {
    if (lampsIn->getLampCount() != rows*cols) {
        throw std::invalid_argument("Lamps do not match matrix geometry");
    }
    lamps = lampsIn;
}

template <int rows, int cols>
void MonoLampMatrixHardware<rows, cols>::refreshLamps() {
    while (!refreshThread.isCanceled()) {
        const bool *values = lamps->data();
        for (int currentRow = 0; currentRow < rows; currentRow++) {
            refreshColumn(currentRow, values);
            values += cols;
        }
    }
}


#endif //PILIGHTS_MONOLAMPMATRIXHARDWARE_H
