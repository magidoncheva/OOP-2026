#ifndef __ANIMAL_H__
#define __ANIMAL_H__

class Animal {
    public:
    virtual Animal* duplicate() const = 0;
    virtual ~Animal() {}
};

#endif // __ANIMAL_H__