#include <iostream>
#include "pawn.hpp"
#include "bishop.hpp"
#include "chess.hpp"

int main() {
    // Coordinates c1('c', 2);

    // Coordinates c2('b', 1);


    // std::cout << c1 << " - " << c2 << " (" << c1.diffX(c2) << ", " << c1.diffY(c2) << ")" << std::endl;

    // Pawn p(true);
    // Bishop b(false);
    // // Piece k(true, 'a');
    // Piece* ptr = &p;

    // // std::cout << *ptr << std::endl;

    // ptr = &b;
    // // std::cout << *ptr << std::endl;

    // std::cout << ptr->canMove(c1, c2) << std::endl;

    Chess chess;

    // std::cout << chess << std::endl;

    // chess.move(Coordinates('c', 2), Coordinates('c', 3), true);

    // std::cout << chess << std::endl;

    chess.play();


    return 0;
}
