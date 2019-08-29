//
// Created by Dad on 8/29/19.
//

#ifndef PILIGHTS_MONOLAMPMATRIXHARDWARE_H
#define PILIGHTS_MONOLAMPMATRIXHARDWARE_H

#include "MonoLampHardware.h"

class MonoLampMatrixHardware : public MonoLampMatrixHardware {
public:
    MonoLampMatrixHardware(int rows, int cols);
    virtual ~MonoLampMatrixHardware() = default;

    virtual std::shared_ptr<MonoLampSet> getLamps() const override { return lamps; };
    virtual void setLamps(std::shared_ptr<MonoLampSet>& lampsIn) override;

    virtual int getRowCount() const { return rows; };
    virtual int getColCount() const { return cols; };

private:
    int rows;
    int cols;
    std::shared_ptr<MonoLampSet> lamps;
};


#endif //PILIGHTS_MONOLAMPMATRIXHARDWARE_H
