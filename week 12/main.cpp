#include <iostream>
#include "role.hpp"

int main() {
    Werewolf a(String("asdf"));
    Werewolf b(String("dhdhd"));

    std::cout << a.isAlive() << " " << b.isAlive() << std::endl;

    a.attack(&b);
    a.attack(&a);
    b.attack(&a);

    std::cout << a.isAlive() << " " << b.isAlive() << std::endl;


    return 0;
}
