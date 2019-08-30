//
// Created by Dad on 8/28/19.
//

#ifndef PILIGHTS_MONOLAMPSET_H
#define PILIGHTS_MONOLAMPSET_H

#include <array>

class MonoLampSet {
public:
    virtual ~MonoLampSet();

    virtual int getLampCount() const = 0;
    virtual const bool& operator[](int ndx) const = 0;
    virtual bool& operator[](int ndx) = 0;
    virtual const bool* data() const = 0;
    virtual bool* data() = 0;
};

#endif //PILIGHTS_MONOLAMPSET_H
