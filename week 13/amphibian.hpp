#ifndef __AMPHIBIAN__
#define __AMPHIBIAN__

class Amphibian: public Terrestial, public Fish {
    public:
        Amphibian(): Terrestial(), Fish(), Animal() {}
        Animal* duplicate() const {
            return new Amphibian(*this);
        }
};

#endif // __AMPHIBIAN__