//
// Created by Dad on 2019-08-16.
//

#ifndef TESTPROJECT_SIMPLELAMPSET_H
#define TESTPROJECT_SIMPLELAMPSET_H

#include "LampSet.h"

#include <vector>

class SimpleLampSet : public LampSet {
public:
    SimpleLampSet(int lampCount);
    SimpleLampSet(int lampCount, int* lampsIn);
    SimpleLampSet(int* begin, int* eng);
    SimpleLampSet(std::vector<int> lampsIn);
    SimpleLampSet(const SimpleLampSet& other);
    virtual ~SimpleLampSet();

    virtual SimpleLampSet& operator=(const SimpleLampSet& other);

    virtual int getLampCount() const override;
    virtual int getLampValue(int ndx) const override;
    virtual std::vector<int> getLampValues() const override;
    virtual std::vector<int>::const_iterator begin() const override;
    virtual std::vector<int>::const_iterator end() const override;
    virtual int operator[](int ndx) const override;

    virtual void setLampValue(int ndx, int value);
    virtual void setLampValues(const std::vector<int>& newValues);



    void adjustLampValues(int deltaValue) { adjustLampValues(deltaValue, 0, getLampCount()-1); }
    virtual void adjustLampValues(int deltaValue, int firstLampNdx, int lastLampNdx);

    class LampBlend;
    static const LampBlend& ADD;
    static const LampBlend& SUB;
    static const LampBlend& MIN;
    static const LampBlend& MAX;
    static const LampBlend& AVG;

    virtual void blendLamps(const LampSet& other, const LampBlend& blend);

private:
    std::vector<int> lampValues;
};


#endif //TESTPROJECT_SIMPLELAMPSET_H
