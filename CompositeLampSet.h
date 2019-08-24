//
// Created by Dad on 2019-08-17.
//

#ifndef TESTPROJECT_COMPOSITELAMPSET_H
#define TESTPROJECT_COMPOSITELAMPSET_H

#include "LampSet.h"

class CompositeLampSet : public LampSet {
public:

    class LampComposition;
    static const LampComposition& ADD;
    static const LampComposition& SUB;
    static const LampComposition& AVG;
    static const LampComposition& MIN;
    static const LampComposition& MAX;


    virtual int getLampCount() const;
    virtual int getLampValue(int ndx) const;
    virtual void getLampValues(int valuesOut[]) const;

};


#endif //TESTPROJECT_COMPOSITELAMPSET_H
