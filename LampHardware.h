//
// Created by Dad on 2019-08-16.
//

#ifndef TESTPROJECT_LAMPHARDWARE_H
#define TESTPROJECT_LAMPHARDWARE_H

#include <memory>
#include "LampSet.h"

class LampHardware {
public:
    virtual ~LampHardware();

    virtual std::shared_ptr<LampSet> getLamps() const = 0;
    virtual void setLamps(std::shared_ptr<LampSet>& lamps) = 0;
};

#endif //TESTPROJECT_LAMPHARDWARE_H
