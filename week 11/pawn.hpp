#ifndef __PAWN_H__
#define __PAWN_H__
#include "piece.hpp"

class Pawn: public Piece {
    public:
    Pawn(const bool color): Piece(color, 'P') {}

    Piece* duplicate() const {
        return new Pawn(this->getColor());
    }

    bool canMove(const Coordinates& currentPosition, const Coordinates& position) {
        int diffX = currentPosition.diffX(position);
        int diffY = currentPosition.diffY(position);

        return diffY == (this->getColor() ? -1 : 1) && diffX == 0;
    }

    bool canAttack(const Coordinates& currentPosition, const Coordinates& position) {
        int diffX = currentPosition.diffX(position);
        int diffY = currentPosition.diffY(position);

        return diffY == (this->getColor() ? -1 : 1) && (diffX == 1 || diffX == -1);
    }
};

#endif