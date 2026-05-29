#ifndef __ENCLOSURE_H__
#define __ENCLOSURE_H__
#include "vector.hpp"
#include "animal.hpp"

class Enclosure {
    double area;
    Vector<Animal*> animals;

    void copy(const Enclosure& other);
    void clear();
public:
    Enclosure(const double& area);
    Enclosure(const Enclosure& other);
    Enclosure& operator=(const Enclosure& other);
    virtual ~Enclosure();

    virtual void addAnimal(Animal* animal) {
        this->animals.append(animal);
    }
};

void Enclosure::copy(const Enclosure& other) {
    this->area = other.area;

    for (size_t i = 0; i < other.animals.length(); ++i) {
        this->animals.append(other.animals[i]->duplicate());
    }
}

void Enclosure::clear() {
    for (size_t i = 0; i < this->animals.length(); ++i) {
        delete this->animals[i];
    }

    this->animals.clear();
}

Enclosure::Enclosure(const double& area): area(area){   }

Enclosure::Enclosure(const Enclosure& other){
    copy(other);
}

Enclosure& Enclosure::operator=(const Enclosure& other) {
    if (this != &other) {
        clear();
        copy(other);
    }

    return *this;
}

Enclosure::~Enclosure(){
    clear();
}


#endif // __ENCLOSURE_H__