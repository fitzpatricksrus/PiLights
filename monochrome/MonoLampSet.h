//
// Created by Dad on 8/28/19.
//

#ifndef PILIGHTS_MONOLAMPSET_H
#define PILIGHTS_MONOLAMPSET_H

#include <vector>

class MonoLampSet {
public:
    virtual ~MonoLampSet();

    virtual int getLampCount() const = 0;
    virtual bool getLampValue(int ndx) const = 0;
    virtual std::vector<bool> getLampValues() const = 0;
    virtual std::vector<bool>::const_iterator begin() const = 0;
    virtual std::vector<bool>::const_iterator end() const = 0;
    virtual bool operator[](int ndx) const = 0;
};

#endif //PILIGHTS_MONOLAMPSET_H
