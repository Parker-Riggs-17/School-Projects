#ifndef BOOP_H
#define BOOP_H
#include "game.h"
#include "space.h"

using namespace main_savitch_14;

class Boop:public game{
    public:
        // Constructors //
        Boop();

        // make_move functions //
        void make_move(const std::string& move); // Compute move 
        void makeMoveNew(const std::string& move);
        void makeMoveThree(const std::string& move);    // Removes pieces for 3 in a row and returns 3 frogs
        void makeMoveOne(const std::string& move);  // Remove piece and add one frog. 

        // is_legal functions //
        bool is_legal(const std::string& move)const;  // Checks if a move is legal
        bool isLegalOne(const std::string& move)const;
        bool isLegalThree(const std::string& move, int row1, int col1, int row2, int col2, int row3, int col3)const;

        // Other Functions //
        void restart(); // Reset initial piece count, set every space to empty
        void display_status()const; // Display the current state of the game
        void boopPieces(int x, int y); // x being row and y being column of piece being put down
        bool checkForThree()const; // Checks for 3 pieces in a row
        int getCPJuniorCount(); // gets the current players junior piece count
        int getCPSeniorCount(); // gets the current players senior piece count

        // Pure Virtual Functions //
        game* clone()const; // Return a pointer to a copy of myself
		void compute_moves(std::queue<std::string>& moves) const; // Compute all the moves that the next player can make
		// NOTE: positive values are good for the computer.
		int evaluate() const; // Evaluate a board status
		bool is_game_over() const; // Return true if the current game is finished

    private:
        int p1JuniorCounter;
        int p1SeniorCounter;
        int p2JuniorCounter;
        int p2SeniorCounter;
        Space board[6][6];
};

#endif