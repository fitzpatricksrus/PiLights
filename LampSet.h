//
// Created by Dad on 2019-08-16.
//

#ifndef TESTPROJECT_LAMPSET_H
#define TESTPROJECT_LAMPSET_H

#include <vector>

class LampSet {
public:
    virtual ~LampSet();

    virtual int getLampCount() const = 0;
    virtual int getLampValue(int ndx) const = 0;
    virtual std::vector<int> getLampValues() const = 0;
    virtual std::vector<int>::const_iterator begin() const = 0;
    virtual std::vector<int>::const_iterator end() const = 0;
    virtual int operator[](int ndx) const = 0;
};


#endif //TESTPROJECT_LAMPSET_H
