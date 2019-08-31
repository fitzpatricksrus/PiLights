//
// Created by Dad on 8/28/19.
//

#ifndef PILIGHTS_SIMPLEMONOLAMPSET_H
#define PILIGHTS_SIMPLEMONOLAMPSET_H

#include "monochrome/MonoLampSet.h"

#include <array>

template <int lampCount>
class SimpleMonoLampSet : public MonoLampSet {
public:
    SimpleMonoLampSet<lampCount>& operator=(const SimpleMonoLampSet<lampCount>& other);

    virtual int getLampCount() const override { return lampCount; }
    virtual const bool& operator[](int ndx) const override { return lampValues[ndx]; };
    virtual bool& operator[](int ndx)  override { return lampValues[ndx]; };
    virtual const bool* data() const override { return lampValues.data(); };
    virtual bool* data() override { return lampValues.data(); };

    virtual void setData(bool* newData);

    virtual void clear() { lampValues.fill(false); }
private:
    std::array<bool, lampCount> lampValues;
};

template <int lampCount>
SimpleMonoLampSet<lampCount>& SimpleMonoLampSet<lampCount>::operator=(const SimpleMonoLampSet<lampCount>& other) {
    lampValues = other.lampValues;
    return *this;
}

template <int lampCount>
void SimpleMonoLampSet<lampCount>::setData(bool* newData) {
    for (int i = 0; i < lampCount; i++) {
        lampValues[i] = newData[i];
    }
}

#endif //PILIGHTS_SIMPLEMONOLAMPSET_H
