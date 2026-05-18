#ifndef __ROOK_H__
#define __ROOK_H__

class Rook: public Piece {
    public:
    Rook(const bool color): Piece(color, 'R') {}

    Piece* duplicate() const {
        return new Rook(this->getColor());
    }

    bool canMove(const Coordinates& currentPosition, const Coordinates& position) {
        int diffX = currentPosition.diffX(position);
        int diffY = currentPosition.diffY(position);

        return diffX == 0 || diffY == 0;
    }

    bool canAttack(const Coordinates& currentPosition, const Coordinates& position) {
        return canMove(currentPosition, position);
    }
};

#endif // __ROOK_H__