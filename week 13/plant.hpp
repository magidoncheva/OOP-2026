#ifndef __PLANT_H__
#define __PLANT_H__
#include "string"

class Plant {
    String spicies;
    int age;

    void copy(const Plan& other);
public:
    Plant();
    Plant(const String& spicies, int age);
};

Plant::Plant() : spicies(""), age(0) {}

Plant::Plant(const String& spicies, int age) : spicies(spicies), age(age) {}

#endif // __PLANT_H__