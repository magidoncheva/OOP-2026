#include <iostream>
#include <fstream>

class Time{
    unsigned hours, minutes;

    public:
    Time(const unsigned& hours = 0, const unsigned& minutes = 0): 
        hours(hours), minutes(minutes){}

    void write(std::ostream& os) const {
        os << hours << ":" << minutes;
    }

    void read(std::istream& is) {
        char dummy;
        is >> hours >> dummy >> minutes;
    }
};

int main() {
    Time t(12, 56);
    // t.read(std::cin);
    t.write(std::cout);
    std::cout << std::endl;

    std::fstream fio("example");
    // std::cout << sizeof(t) << std::endl;

    for (size_t i = 0; i <= 1; ++i) {
        t.read(fio);
    }

    t.write(std::cout);

    // t.write(fout);
    fio.close();

    return 0;
}
