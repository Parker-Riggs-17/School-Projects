/*************************************************************************
   This is a sample of what the main should like for the final phase of 
   the Boop game.

   Patricia Lindner	Ohio University		Fall 2023
*************************************************************************/
#include <iostream>
#include "boop.h"
#include "colors.h"

using namespace std;
using namespace main_savitch_14;


int main(){
   cout << endl;
   cout << BOLD << "Welcome to Boop!" << RESET << endl;
   cout << "There are two piece types, frog and a tadpole, your tadpole is your junior piece and your frog is your senior piece." << endl;
   cout << "To make a move, follow the format: column, row, piece (e.g. a4f for frog on a4).\n" << endl;

   Boop mygame;
   game::who winner = mygame.play();

   if(winner == game::HUMAN) cout << "Player 1 Wins!\n\n";
   else cout << "Player 2 Wins!\n\n";

   return 0;
}