//
// Created by Dad on 2019-08-16.
//

#ifndef TESTPROJECT_LAMPMATRIX_H
#define TESTPROJECT_LAMPMATRIX_H

#include "LampHardware.h"
#include <memory>

class LampMatrix : public LampHardware {
public:
    LampMatrix(int rows, int cols);
    virtual ~LampMatrix() override = default;

    virtual std::shared_ptr<LampSet> getLamps() const override { return lamps; };
    virtual void setLamps(std::shared_ptr<LampSet>& lampsIn) override;

    virtual int getRowCount() const { return rows; };
    virtual int getColCount() const { return cols; };

private:
    int rows;
    int cols;
    std::shared_ptr<LampSet> lamps;
};

#endif //TESTPROJECT_LAMPMATRIX_H
