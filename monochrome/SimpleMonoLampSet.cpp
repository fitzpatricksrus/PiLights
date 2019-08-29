//
// Created by Dad on 8/28/19.
//

#include "SimpleMonoLampSet.h"

#include <stdexcept>

SimpleMonoLampSet::SimpleMonoLampSet(int lampCountIn)
        : lampValues(lampCountIn)
{
    lampValues.assign(lampCountIn, 0);
}

SimpleMonoLampSet::SimpleMonoLampSet(int lampCountIn, bool* lampsIn)
        : lampValues(lampsIn, lampsIn + lampCountIn)
{
}

SimpleMonoLampSet::SimpleMonoLampSet(bool* firstLampPrt, bool* lastLampPtr)
        : lampValues(firstLampPrt, lastLampPtr)
{
}

SimpleMonoLampSet::SimpleMonoLampSet(std::vector<bool> lampsIn)
        : lampValues(lampsIn)
{
}

SimpleMonoLampSet::SimpleMonoLampSet(const SimpleMonoLampSet& other)
        : lampValues(other.lampValues)
{
}

SimpleMonoLampSet::~SimpleMonoLampSet() {
}

SimpleMonoLampSet& SimpleMonoLampSet::operator=(const SimpleMonoLampSet& other) {
    if (this != &other) {
        lampValues = other.lampValues;
    }
    return *this;
}

int SimpleMonoLampSet::getLampCount() const {
    return lampValues.size();
}

bool SimpleMonoLampSet::getLampValue(int ndx) const {
    return lampValues[ndx];
}

void SimpleMonoLampSet::setLampValue(int ndx, bool value) {
    lampValues[ndx] = value;
}

std::vector<bool> SimpleMonoLampSet::getLampValues() const {
    return lampValues;
}

std::vector<bool>::const_iterator SimpleMonoLampSet::begin() const {
    return lampValues.begin();
}

std::vector<bool>::const_iterator SimpleMonoLampSet::end() const {
    return lampValues.end();
}

bool SimpleMonoLampSet::operator[](int ndx) const {
    return lampValues[ndx];
}

void SimpleMonoLampSet::setLampValues(const std::vector<bool>& newValues) {
    lampValues = newValues;
}

void SimpleMonoLampSet::adjustLampValues(int deltaValue, int firstLampNdx, int lastLampNdx) {
    for (int i = firstLampNdx; i <= lastLampNdx; i++) {
        setLampValue(i, getLampValue(i) + deltaValue);
    }
}

class SimpleMonoLampSet::LampBlend {
public:
    virtual bool blendValues(bool val1, bool val2) const = 0;
};

class LampBlendAnd : public SimpleMonoLampSet::LampBlend {
public:
    virtual bool blendValues(bool val1, bool val2) const override {
        return val1 && val2;
    }
};

class LampBlendOr : public SimpleMonoLampSet::LampBlend {
public:
    virtual bool blendValues(bool val1, bool val2) const override {
        return val1 || val2;
    }
};

class LampBlendNot : public SimpleMonoLampSet::LampBlend {
public:
    virtual bool blendValues(bool val1, bool val2) const override {
        return !val1;
    }
};

class LampBlendXor : public SimpleMonoLampSet::LampBlend {
public:
    virtual bool blendValues(bool val1, bool val2) const override {
        return val1 ^ val2;
    }
};

static const LampBlendAnd blendAnd;
static const LampBlendOr blendOr;
static const LampBlendNot blendNot;
static const LampBlendXor blendXor;

const SimpleMonoLampSet::LampBlend& AND = blendAnd;
const SimpleMonoLampSet::LampBlend& OR = blendOr;
const SimpleMonoLampSet::LampBlend& NOT = blendNot;
const SimpleMonoLampSet::LampBlend& XOR = blendXor;

void SimpleMonoLampSet::blendLamps(const MonoLampSet& other, const SimpleMonoLampSet::LampBlend& blend) {
    if ((other.getLampCount() != getLampCount())) {
        throw std::invalid_argument("LampSet geometries don't match");
    } else {
        for (int i = 0; i < getLampCount(); i++) {
            setLampValue(i, blend.blendValues(getLampValue(i), other.getLampValue(i)));
        }
    }
}

