#ifndef __COORDINATES_H__
#define __COORDINATES_H__

class Coordinates {
    char x;
    size_t y;
public:
    Coordinates(): x('a'), y(0) {}
    Coordinates(const char x, const size_t y): x(x), y(y) {}
    
    int diffX(const Coordinates& other) const {
        return x - other.x;
    }

    int diffY(const Coordinates& other) const {
        return y - other.y;
    }

    char getX() const {
        return x;
    }

    size_t getY() const {
        return y;
    }

    bool operator==(const Coordinates& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Coordinates& other) const {
        return !operator==(other);
    }

    friend std::ostream& operator<<(std::ostream&, const Coordinates&);
    friend std::istream& operator>>(std::istream&, Coordinates&);

};

std::ostream& operator<<(std::ostream& os, const Coordinates& obj) {
    os << obj.x << obj.y;
    return os;
}

std::istream& operator>>(std::istream& is, Coordinates& obj) {
    is >> obj.x >> obj.y;
    return is;
}

#endif // __COORDINATES_H__