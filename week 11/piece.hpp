#ifndef __PIECE_H__
#define __PIECE_H__
#include "coordinates.hpp"

class Piece {
    bool color;
    char symbol;
    bool canSkip;
    bool endGame;

public:
    Piece(const char& color, const char& symbol, const bool& canSkip = false, const bool& endGame = false): 
        color(color), symbol(symbol), canSkip(canSkip), endGame(endGame) {}
    virtual ~Piece() {}
    virtual Piece* duplicate() const = 0;

    bool getColor() const {
        return color;
    }

    bool skip() const {
        return canSkip;
    }

    bool isEndGame() const {
        return endGame;
    }

    virtual bool canMove(const Coordinates& currentPosition, const Coordinates& position) = 0;
    virtual bool canAttack(const Coordinates& currentPosition, const Coordinates& position) = 0;

    friend std::ostream& operator<<(std::ostream&, const Piece&);
};

std::ostream& operator<<(std::ostream& os, const Piece& obj) {
    os << (obj.color ? 'w' : 'b') << obj.symbol;

    return os;
}

#endif // __PIECE_H__