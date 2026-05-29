#include <iostream>
#include "bear.hpp"
#include "enclosure.hpp"
#include "water.hpp"
#include "amphibian.hpp"

int main() {
    Animal* bear = new Bear();
    Enclosure enclosure(100);

    Animal* salamander = new Amphibian();

    Water waterEnclosure(50, 10);
    std::cout << "Adding salamander to enclosure" << std::endl;
    waterEnclosure.addAnimal(salamander);

    std::cout << "Adding bear to enclosure" << std::endl;
    waterEnclosure.addAnimal(bear);

    return 0;
}
