#ifndef __WATER_H__
#define __WATER_H__
#include "enclosure.hpp"
#include "fish.hpp"

class Water: public Enclosure {
    unsigned int depth;
    public:
        Water(const double& area, const unsigned int& depth): Enclosure(area), depth(depth) {}

        void addAnimal(Animal* animal) {
            if (dynamic_cast<Fish*>(animal) == nullptr) {
                throw std::invalid_argument("Only fish can be added to water enclosures");
            }
            Enclosure::addAnimal(animal);
        }
};

#endif // __WATER_H__