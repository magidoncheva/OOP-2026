#include <iostream>
#include "animal.hpp"

int main() {
    // Animal a("mimi");
    Cat a("didi", 6);
    Cat b("fhfh", 7);
    b.speak();
    b = a;
    b.speak();
    // Dog a;

    // Animal* a = new Cat("Didi");
    // Animal* animals[8];
    // size_t size;

    // Cat cats[5];
    // Dog dogs[3];
    // size_t catsSize, dogsSize;


    // a->speak();
    // std::cout << a.getName() << std::endl;

    return 0;
}
