#ifndef SPACE_H
#define SPACE_H
#include "game.h"
#include "colors.h"

using namespace main_savitch_14;

class Space{
    public:
        enum pieceType{EMPTY, JUNIOR, SENIOR}; // EMPTY(0), JUNIOR(1), SENIOR(2)

        Space(){
            player = 0;
            currentPieceType = EMPTY;
        }

        // Getters
        int getPlayer()const;
        pieceType getPieceType()const;

        // Setters
        void setPlayer(int newPlayer);
        void setPieceType(pieceType newPieceType);

        // Other Functions
        void printTop(int player)const;
        void printMiddle(int player)const;
        void printBottom(int player)const;
        void display()const;

    private:
        int player; // if == 1 then its player 1s space, if == 2 its player 2s space. if 0, empty space
        pieceType currentPieceType;
};

#endif