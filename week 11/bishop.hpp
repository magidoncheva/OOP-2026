#ifndef __BISHOP_H__
#define __BISHOP_H__
#include "piece.hpp"

class Bishop: public Piece {
    public:
    Bishop(const bool color): Piece(color, 'B') {}

    Piece* duplicate() const {
        return new Bishop(this->getColor());
    }

    bool canMove(const Coordinates& currentPosition, const Coordinates& position) {
        int diffX = currentPosition.diffX(position);
        int diffY = currentPosition.diffY(position);

        return diffY == diffX || diffY == diffX * -1;
    }

    bool canAttack(const Coordinates& currentPosition, const Coordinates& position) {
        return canMove(currentPosition, position);
    }
};

#endif // __BISHOP_H__