#ifndef __KING_H__
#define __KING_H__

class King: public Piece {
    public:
    King(const bool color): Piece(color, 'K', false, true) {}

    Piece* duplicate() const {
        return new King(this->getColor());
    }

    bool canMove(const Coordinates& currentPosition, const Coordinates& position) {
        int diffX = currentPosition.diffX(position);
        int diffY = currentPosition.diffY(position);

        return (diffY == 1 || diffY == -1 || diffY == 0) && (diffX == 1 || diffX == -1 || diffX == 0);
    }

    bool canAttack(const Coordinates& currentPosition, const Coordinates& position) {
        return canMove(currentPosition, position);
    }
};

#endif // __KING_H__