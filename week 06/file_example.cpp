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

    for (size_t i = 0; i <= 1; ++i) {
        t.read(fio);
    }

    t.write(std::cout);
    std::cout << std::endl << "binary: ";

    // t.write(fout);
    fio.close();

    fio.open("example_binary", std::ios::binary);
    fio.write((char*)&t, sizeof(t));

    fio.seekg(0, std::ios::beg);
    fio.read((char*)&t, sizeof(t));

    t.write(std::cout);
    std::cout << std::endl;

    fio.close();

    return 0;
}
