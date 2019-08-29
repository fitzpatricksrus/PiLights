//
// Created by Dad on 8/28/19.
//

#ifndef PILIGHTS_SIMPLEMONOLAMPSET_H
#define PILIGHTS_SIMPLEMONOLAMPSET_H

#include "MonoLampSet.h"

class SimpleMonoLampSet : public MonoLampSet {
public:
    SimpleMonoLampSet(int lampCount);
    SimpleMonoLampSet(int lampCount, bool* lampsIn);
    SimpleMonoLampSet(bool* begin, bool* eng);
    SimpleMonoLampSet(std::vector<bool> lampsIn);
    SimpleMonoLampSet(const SimpleMonoLampSet& other);
    virtual ~SimpleMonoLampSet();

    virtual SimpleMonoLampSet& operator=(const SimpleMonoLampSet& other);

    virtual int getLampCount() const override;
    virtual bool getLampValue(int ndx) const override;
    virtual std::vector<bool> getLampValues() const override;
    virtual std::vector<bool>::const_iterator begin() const override;
    virtual std::vector<bool>::const_iterator end() const override;
    virtual bool operator[](int ndx) const override;

    virtual void setLampValue(int ndx, bool value);
    virtual void setLampValues(const std::vector<bool>& newValues);

    void adjustLampValues(int deltaValue) { adjustLampValues(deltaValue, 0, getLampCount()-1); }
    virtual void adjustLampValues(int deltaValue, int firstLampNdx, int lastLampNdx);

    class LampBlend;
    static const LampBlend& AND;
    static const LampBlend& OR;
    static const LampBlend& NOT;
    static const LampBlend& XOR;

    virtual void blendLamps(const MonoLampSet& other, const LampBlend& blend);

private:
    std::vector<bool> lampValues;
};

#endif //PILIGHTS_SIMPLEMONOLAMPSET_H
