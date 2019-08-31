//
// Created by Dad on 8/28/19.
//

#ifndef PILIGHTS_MONOLAMPHARDWARE_H
#define PILIGHTS_MONOLAMPHARDWARE_H

#include <memory>
#include "monochrome/MonoLampSet.h"

class MonoLampHardware {
public:
    virtual ~MonoLampHardware() = default;
    virtual MonoLampSet* getLamps() const = 0;
    virtual void setLamps(MonoLampSet* lamps) = 0;

    virtual void startRefresh() = 0;
    virtual void stopRefresh() = 0;
    virtual bool refreshIsActive() = 0;
};

#endif //PILIGHTS_MONOLAMPHARDWARE_H
