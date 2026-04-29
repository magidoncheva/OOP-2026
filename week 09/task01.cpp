#include <iostream>
#include "vector.hpp"
#include "matrix.hpp"

int main() {
    Matrix<int> m;
    Vector<int> a(4), b;
    a.append(34);
    m.append(a);

    std::cout << m.lenght() << " " << m[0][4] << std::endl;

    // Vector<int> c(a);
    // b = a;

    // std::cout << a.lenght() << std::endl;

    // // std::cout << a[1] << std::endl;
    // std::cout << a[4] << std::endl;


    return 0;
}
