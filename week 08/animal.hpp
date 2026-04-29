#ifndef __ANIMAL_H__
#define __ANIMAL_H__
#include <cstring>

class Animal{
    char* name;
    protected:
    Animal(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    ~Animal(){
        std::cout << "~Animal()";
        delete[] name;
    }


    void speak() const {
        std::cout << "Speak" << std::endl;
    }

    public:
    // const std::string& getName() const {
    //     return name;
    // }
};

class Cat: public Animal{
    unsigned age;
    public:
    Cat(const char* name, unsigned age): Animal(name) {
        this->age = age;
    }
    //copy
    // operator=
    // ~Cat

    void speak() const {
        std::cout << "Meow "<< age << std::endl;
    }
};

// class Dog: public Animal{
//     public:
//     Dog(const std::string& name): Animal(name) {}

//     void speak() const {
//         std::cout << "Wolf!" << std::endl;
//     }
// };



#endif 