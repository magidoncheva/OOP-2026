#include <iostream>
#include "patient.hpp"
#include "doctor.hpp"


int main() {
    Pair<int, int> p(4, 5);
    // std::cout << p << std::endl;

    Patient a(String("username"), String("password"), String("Ivancho"), 12345);
    Doctor d(String("doctor"), String("password"), String("Ivanov"));


    std::cout << a << std::endl;
    std::cout << d << std::endl;


    return 0;
}
