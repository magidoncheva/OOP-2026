#ifndef __QUEEN_H__
#define __QUEEN_H__

class Queen: public Piece {
    public:
    Queen(const bool color): Piece(color, 'Q') {}

    Piece* duplicate() const {
        return new Queen(this->getColor());
    }

    bool canMove(const Coordinates& currentPosition, const Coordinates& position) {
        int diffX = currentPosition.diffX(position);
        int diffY = currentPosition.diffY(position);

        return diffX == 0 || diffY == 0 || diffY == diffX || diffY == diffX * -1;
    }

    bool canAttack(const Coordinates& currentPosition, const Coordinates& position) {
        return canMove(currentPosition, position);
    }
};

#endif // __QUEEN_H__