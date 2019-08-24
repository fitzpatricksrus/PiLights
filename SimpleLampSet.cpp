//
// Created by Dad on 2019-08-16.
//

#include "SimpleLampSet.h"
#include <stdexcept>

SimpleLampSet::SimpleLampSet(int lampCountIn)
: lampValues(lampCountIn)
{
    lampValues.assign(lampCountIn, 0);
}

SimpleLampSet::SimpleLampSet(int lampCountIn, int* lampsIn)
        : lampValues(lampsIn, lampsIn + lampCountIn)
{
}

SimpleLampSet::SimpleLampSet(int* firstLampPrt, int* lastLampPtr)
        : lampValues(firstLampPrt, lastLampPtr)
{
}

SimpleLampSet::SimpleLampSet(std::vector<int> lampsIn)
: lampValues(lampsIn)
{
}

SimpleLampSet::SimpleLampSet(const SimpleLampSet& other)
: lampValues(other.lampValues)
{
}

SimpleLampSet::~SimpleLampSet() {
}

SimpleLampSet& SimpleLampSet::operator=(const SimpleLampSet& other) {
    if (this != &other) {
        lampValues = other.lampValues;
    }
    return *this;
}

int SimpleLampSet::getLampCount() const {
    return lampValues.size();
}

int SimpleLampSet::getLampValue(int ndx) const {
    return lampValues[ndx];
}

void SimpleLampSet::setLampValue(int ndx, int value) {
    lampValues[ndx] = value;
}

std::vector<int> SimpleLampSet::getLampValues() const {
    return lampValues;
}

std::vector<int>::const_iterator SimpleLampSet::begin() const {
    return lampValues.begin();
}

std::vector<int>::const_iterator SimpleLampSet::end() const {
    return lampValues.end();
}

int SimpleLampSet::operator[](int ndx) const {
    return lampValues[ndx];
}

void SimpleLampSet::setLampValues(const std::vector<int>& newValues) {
    lampValues = newValues;
}

void SimpleLampSet::adjustLampValues(int deltaValue, int firstLampNdx, int lastLampNdx) {
    for (int i = firstLampNdx; i <= lastLampNdx; i++) {
        setLampValue(i, getLampValue(i) + deltaValue);
    }
}

class SimpleLampSet::LampBlend {
public:
    virtual int blendValues(int val1, int val2) const = 0;
};

class LampBlendAdd : public SimpleLampSet::LampBlend {
public:
    virtual int blendValues(int val1, int val2) const;
};
int LampBlendAdd::blendValues(int val1, int val2) const {
    return val1 + val2;
}

class LampBlendSub : public SimpleLampSet::LampBlend {
public:
    virtual int blendValues(int val1, int val2) const {
        return val1 - val2;
    }
};

class LampBlendMin : public SimpleLampSet::LampBlend {
public:
    virtual int blendValues(int val1, int val2) const {
        return val1 > val2 ? val2 : val1;
    }
};

class LampBlendMax : public SimpleLampSet::LampBlend {
public:
    virtual int blendValues(int val1, int val2) const {
        return val1 < val2 ? val2 : val1;
    }
};

class LampBlendAvg : public SimpleLampSet::LampBlend {
public:
    virtual int blendValues(int val1, int val2) const {
        return (val1 + val2) / 2;
    }
};

static const LampBlendAdd blendAdd;
static const LampBlendSub blendSub;
static const LampBlendMin blendMin;
static const LampBlendMax blendMax;
static const LampBlendAvg blendAvg;

const SimpleLampSet::LampBlend& ADD = blendAdd;
const SimpleLampSet::LampBlend& SUB = blendSub;
const SimpleLampSet::LampBlend& MIN = blendMin;
const SimpleLampSet::LampBlend& MAX = blendMax;
const SimpleLampSet::LampBlend& AVG = blendAvg;

void SimpleLampSet::blendLamps(const LampSet& other, const SimpleLampSet::LampBlend& blend) {
    if ((other.getLampCount() != getLampCount())) {
        throw std::invalid_argument("LampSet geometries don't match");
    } else {
        for (int i = 0; i < getLampCount(); i++) {
            setLampValue(i, blend.blendValues(getLampValue(i), other.getLampValue(i)));
        }
    }
}

