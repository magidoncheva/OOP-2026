#ifndef __CHESS_H__
#define __CHESS_H__
#include <iostream>
#include "piece.hpp"
#include "pawn.hpp"
#include "bishop.hpp"
#include "rook.hpp"
#include "knight.hpp"
#include "queen.hpp"
#include "king.hpp"
#include "vector.hpp"
#include "dict.hpp"

class Chess {
    Dict<Coordinates, Piece*> table;
    Vector<Piece*> pieces;

    bool gameOver;

    bool checkEmpty(const Coordinates& from, const Coordinates& to) const {
        int diffX = from.diffX(to);

        if (diffX < 0) {
            for (char i = diffX + 1; i < 0; ++i) {
                if (table[Coordinates(from.getX() + i, from.getY())]) {
                    return false;
                }
            }
        } else {
            for (char i = 1; i < diffX; ++i) {
                if (table[Coordinates(from.getX() + i, from.getY())]) {
                    return false;
                }
            }
        }

        int diffY = from.diffY(to);

        if (diffY < 0) {
            for (char i = diffY + 1; i < 0; ++i) {
                if (table[Coordinates(from.getX(), from.getY() + i)]) {
                    return false;
                }
            }
        } else {
            for (char i = 1; i < diffY; ++i) {
                if (table[Coordinates(from.getX(), from.getY() + i)]) {
                    return false;
                }
            }
        }

        return true;
    }

    void populateTable() {
        for (size_t j = 8; j >= 1; --j)
         {
            for (char i = 'a'; i <= 'h'; ++i) {
                Coordinates c(i, j);
                table.add(c, nullptr);
            }
        }
    }

    void populatePawns() {
        for (char col = 'a'; col <= 'h'; ++col) {
            Piece* whitePawn = new Pawn(true);
            pieces.append(whitePawn);

            Piece* blackPawn = new Pawn(false);
            pieces.append(blackPawn);

            Coordinates whiteCoordinates(col, 2);
            Coordinates blackCoordinates(col, 7);

            table[whiteCoordinates] = whitePawn;
            table[blackCoordinates] = blackPawn;
        }
    }

    void populateBishops() {
        Piece* whiteBishop1 = new Bishop(true);
        Piece* whiteBishop2 = new Bishop(true);
        Piece* blackBishop1 = new Bishop(false);
        Piece* blackBishop2 = new Bishop(false);

        Coordinates whiteBishop1Coordinates('c', 1);
        Coordinates whiteBishop2Coordinates('f', 1); 
        Coordinates blackBishop1Coordinates('c', 8);
        Coordinates blackBishop2Coordinates('f', 8);

        pieces.append(whiteBishop1);
        pieces.append(whiteBishop2);
        pieces.append(blackBishop1);
        pieces.append(blackBishop2);

        table[whiteBishop1Coordinates] = whiteBishop1;
        table[whiteBishop2Coordinates] = whiteBishop2;
        table[blackBishop1Coordinates] = blackBishop1;
        table[blackBishop2Coordinates] = blackBishop2;
    }

    void populateRooks() {
        Piece* whiteRook1 = new Rook(true);
        Piece* whiteRook2 = new Rook(true);
        Piece* blackRook1 = new Rook(false);
        Piece* blackRook2 = new Rook(false);

        Coordinates whiteRook1Coordinates('a', 1);
        Coordinates whiteRook2Coordinates('h', 1); 
        Coordinates blackRook1Coordinates('a', 8);
        Coordinates blackRook2Coordinates('h', 8);

        pieces.append(whiteRook1);
        pieces.append(whiteRook2);
        pieces.append(blackRook1);
        pieces.append(blackRook2);

        table[whiteRook1Coordinates] = whiteRook1;
        table[whiteRook2Coordinates] = whiteRook2;
        table[blackRook1Coordinates] = blackRook1;
        table[blackRook2Coordinates] = blackRook2;
    }

    void populateKnights() {
        Piece* whiteKnight1 = new Knight(true);
        Piece* whiteKnight2 = new Knight(true);
        Piece* blackKnight1 = new Knight(false);
        Piece* blackKnight2 = new Knight(false);

        Coordinates whiteKnight1Coordinates('b', 1);
        Coordinates whiteKnight2Coordinates('g', 1); 
        Coordinates blackKnight1Coordinates('b', 8);
        Coordinates blackKnight2Coordinates('g', 8);

        pieces.append(whiteKnight1);
        pieces.append(whiteKnight2);
        pieces.append(blackKnight1);
        pieces.append(blackKnight2);

        table[whiteKnight1Coordinates] = whiteKnight1;
        table[whiteKnight2Coordinates] = whiteKnight2;
        table[blackKnight1Coordinates] = blackKnight1;
        table[blackKnight2Coordinates] = blackKnight2;
    }

    void populateQueens() {
        Piece* whiteQueen = new Queen(true);
        Piece* blackQueen = new Queen(false);

        Coordinates whiteQueenCoordinates('d', 1);
        Coordinates blackQueenCoordinates('d', 8);

        pieces.append(whiteQueen);
        pieces.append(blackQueen);

        table[whiteQueenCoordinates] = whiteQueen;
        table[blackQueenCoordinates] = blackQueen;
    }

    void populateKings() {
        Piece* whiteKing = new King(true);
        Piece* blackKing = new King(false);

        Coordinates whiteKingCoordinates('d', 1);
        Coordinates blackKingCoordinates('d', 8);

        pieces.append(whiteKing);
        pieces.append(blackKing);

        table[whiteKingCoordinates] = whiteKing;
        table[blackKingCoordinates] = blackKing;
    }

    void populatePieces() {
        populatePawns();
        populateBishops();
        populateRooks();
        populateKnights();
        populateQueens();
        populateKings();
    }

    // не се очаква копиране на обекта Chess, затова изтриваме copy constructor и assignment operator
    Chess(const Chess& other) = delete;
    Chess& operator=(const Chess& other) = delete;

public:
    Chess(): gameOver(false) {
        populateTable();
        populatePieces();
    }

    ~Chess() {
        for (size_t i = 0; i < pieces.length(); ++i) {
            delete pieces[i];
        }
    }

    void move(const Coordinates& from, const Coordinates& to, bool color) {
        if (gameOver) {
            std::cout << "Game over!" << std::endl;
            return;
        }

        if (from != to && table[from] && table[from]->getColor() == color) {
            if (table[from]->skip() || checkEmpty(from, to)) {
                if (!table[to] && table[from]->canMove(from, to)) {
                    table[to] = table[from];
                    table[from] = nullptr;
                    return;
                }
                if (table[to] && table[to]->getColor() != color && table[from]->canAttack(from, to)) {
                    if (table[to]->isEndGame()) {
                        gameOver = true;
                    }

                    table[to] = table[from];
                    table[from] = nullptr;
                    return;
                }
            }
        }

        std::cout << "Invalid move!" << std::endl;
    }

    void play() {
        bool player = true; // true - white, false - black
        while (!gameOver) {
            std::cout << (*this) << std::endl;
            std::cout << (player ? "White" : "Black") << "'s turn." << std::endl;

            Coordinates from, to;
            do {
                std::cout << "Enter move (e.g. c2 c3): ";
                std::cin >> from >> to;
            } while(!move(from, to, player));
            player = !player;
        }

        std::cout << (player ? "Black" : "White") << " wins!" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Chess& obj);
};

std::ostream& operator<<(std::ostream& os, const Chess& obj) {
    os << "  ";
    for (char i = 'a'; i <= 'h'; ++i) {
        os << "|" << i << " "; 
    }
    os << std::endl << "---------------------------"<< std::endl;

    for (size_t j = 8; j >= 1; --j) {
        os << j << " |";
        for (char i = 'a'; i <= 'h'; ++i) {
            Coordinates c(i, j);
            if (obj.table[c]) {
                os << *(obj.table[c]);
            } else {
                os << "  ";
            }
            os << "|";

        }
        os <<std::endl << "---------------------------"<< std::endl;
    }

    return os;
}


#endif // __CHESS_H__