#include <iostream>
#include "string.hpp"

int main() {
    String str1, str = "testStr";

    str = "other value";

    std::cout << str1.length() << std::endl;
    std::cout << str1.isEmpty() << std::endl;
    
    str.print();

    std::cout << str.length() << std::endl;
    std::cout << str.isEmpty() << std::endl;

    str1 = str;
    if (str1 == str) {
        std::cout << "equal!" << std::endl;
    }

    if (str1 != str) {
        std::cout << "not equal!" << std::endl;
    }

    str1 += " asdf";
    str1.print();

    return 0;
}
