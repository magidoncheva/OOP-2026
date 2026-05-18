#ifndef __KNIGHT_H__
#define __KNIGHT_H__

class Knight: public Piece {
    public:
    Knight(const bool color): Piece(color, 'N', true) {}

    Piece* duplicate() const {
        return new Knight(this->getColor());
    }

    bool canMove(const Coordinates& currentPosition, const Coordinates& position) {
        int diffX = currentPosition.diffX(position);
        int diffY = currentPosition.diffY(position);

        return (diffY == 2 || diffY == -2) && (diffX == 1 || diffX == -1) ||
               (diffY == 1 || diffY == -1) && (diffX == 2 || diffX == -2);
    }

    bool canAttack(const Coordinates& currentPosition, const Coordinates& position) {
        return canMove(currentPosition, position);
    }
};

#endif // __KNIGHT_H__