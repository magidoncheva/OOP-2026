#ifndef __TERRESTIAL_H__
#define __TERRESTIAL_H__
#include "animal.hpp"

class Terrestial: virtual public Animal {
    public:
        Animal* duplicate() const {
            return new Terrestial(*this);
        }
};

#endif // __TERRESTIAL_H__