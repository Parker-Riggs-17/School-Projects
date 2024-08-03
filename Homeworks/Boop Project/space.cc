#include <iostream>
#include "space.h"

using namespace std;

// Getters
int Space::getPlayer()const{
    return player;
}

Space::pieceType Space::getPieceType()const{
    return currentPieceType;
}

// Setters
void Space::setPlayer(int newPlayer){
    player = newPlayer;
}

void Space::setPieceType(Space::pieceType newPieceType){
    currentPieceType = newPieceType;
}

// Other Functions
void Space::printTop(int player)const{
    if(player == 1){    // Player 1 (so we can change the color)
        switch(currentPieceType){
            case EMPTY:
                cout << "     ";
                break;
            case JUNIOR:
                cout << "     ";
                break;
            case SENIOR:
                cout << BLUE << "(l.l)" << RESET;
                break;       
        }
    }else if(player == 2){  // Player 2
        switch(currentPieceType){
            case EMPTY:
                cout << "     ";
                break;
            case JUNIOR:
                cout << "     ";
                break;
            case SENIOR:
                cout << RED << "(l.l)" << RESET;
                break;       
        }
    }else{
        cout << "     ";
    }
}

void Space::printMiddle(int player)const{
    if(player == 1){    // Player 1
        switch(currentPieceType){
            case EMPTY:
                cout << "     ";
                break;
            case JUNIOR:
                cout << BLUE << " ~~o " << RESET;
                break;
            case SENIOR:
                cout << BLUE << "/___\\" << RESET;
                break;
        }
    }else if(player == 2){  // Player 2
        switch(currentPieceType){
            case EMPTY:
                cout << "     ";
                break;
            case JUNIOR:
                cout << RED << " ~~o " <<  RESET;
                break;
            case SENIOR:
                cout << RED << "/___\\" << RESET;
                break;
        }
    }else{
        cout << "     ";
    }
}

void Space::printBottom(int player)const{
    if(player == 1){    // Player 1
        switch(currentPieceType){
            case EMPTY:
                cout << "     ";
                break;
            case JUNIOR:
                cout << "     ";
                break;
            case SENIOR:
                cout << BLUE << "\\___/" << RESET;
                break;
        }
    }else if(player == 2){  // Player 2
        switch(currentPieceType){
            case EMPTY:
                cout << "     ";
                break;
            case JUNIOR:
                cout << "     ";
                break;
            case SENIOR:
                cout << RED << "\\___/" << RESET;
                break;
        }
    }else{
        cout << "     ";
    }
}

void Space::display()const{  // This function will be used to display just the board in the displayStatus function.
    printTop(player);
    printMiddle(player);
    printBottom(player);
}