//
// Created by Dad on 2019-08-16.
//

#include "LampMatrix.h"

#include <stdexcept>

using std::invalid_argument;

LampMatrix::LampMatrix(int rowsIn, int colsIn)
: rows(rowsIn), cols(colsIn)
{
}

void LampMatrix::setLamps(std::shared_ptr<LampSet>& lampsIn) {
    if (lampsIn->getLampCount() != rows*cols) {
        throw invalid_argument("Lamps do not match matrix geometry");
    }
    lamps = std::move(lampsIn);
}

