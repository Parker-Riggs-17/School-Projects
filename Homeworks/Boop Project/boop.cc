#include <iostream>
#include "boop.h"

using namespace std;

Boop::Boop(){
    p1JuniorCounter = 8;
    p1SeniorCounter = 0;    
    p2JuniorCounter = 8;
    p2SeniorCounter = 0;

    for(int i = 0; i < 6; i++){ // Goes through the board and sets each space to type empty
        for(int j = 0; j < 6; j++){
            board[i][j].setPieceType(Space::EMPTY);
        }
    }
    restart();  // Does basically same thing as constructor but sets game move counter to 0
}

// make_move functions //
void Boop::make_move(const string& move){ // NEEDS UPDATED AFTER OTHER MAKE_MOVE FUNCTIONS ARE COMPLETE
    if(move == "FIN"){ // Check for game over string
        game::make_move(move);
        return;
    }else if(checkForThree()){ // If 3 in a row
        makeMoveThree(move); 
    }else if(getCPJuniorCount() < 1 || (getCPJuniorCount() + getCPSeniorCount()) == 0){ // Checking if there are any playable pieces left
        makeMoveOne(move);
    }else{ // if neither of those are true then its just a new piece
        makeMoveNew(move);
    }
}

void Boop::makeMoveNew(const string& move){
    // Move Format: A4F (Frog on A4)
    char playerChoice = toupper(move[2]);
    int row = int(move[1] - '1');
    int col = int(toupper(move[0]) - 'A');
    int currentPlayer;

    if(next_mover() == HUMAN){ // Setting currentPlayer variable so space knows what player occupies what space
        currentPlayer = 1;
    }else{
        currentPlayer = 2;
    }

    if(playerChoice == 'T'){
        board[row][col].setPieceType(Space::JUNIOR);
        board[row][col].setPlayer(currentPlayer);
        if(next_mover() == HUMAN){ // Adjust counters appropriately
            p1JuniorCounter -= 1;
        }else if(next_mover() == COMPUTER){
            p2JuniorCounter -= 1;
        }
    }else if(playerChoice == 'F'){
        board[row][col].setPieceType(Space::SENIOR);
        board[row][col].setPlayer(currentPlayer);
        if(next_mover() == HUMAN){ // Adjust counters appropriately
            p1SeniorCounter -= 1;
        }else if(next_mover() == COMPUTER){
            p2SeniorCounter -= 1;
        }
    }

    boopPieces(row, col);
    if(checkForThree()){
        makeMoveThree(move);
    }
    game::make_move(move); // Increment game counter
}

void Boop::makeMoveThree(const string& move){
    // Remove 3 pieces from the board and give current player 1 senior piece
    string choice;
    cout << "List 3 pieces in col to remove (e.g. a1a2a3): ";
    cin >> choice;

    // Assign Characters //
    int row1 = int(toupper(choice[0]) - 'A');
    int col1 = int(choice[1] - '1');
    int row2 = int(toupper(choice[3]) - 'A');
    int col2 = int(choice[4] - '1');
    int row3 = int(toupper(choice[5]) - 'A');
    int col3 = int(choice[6] - '1');

    // Empty Spaces //
    if(isLegalThree(move, row1, col1, row2, col2, row3, col3)){
        board[row1][col1].setPieceType(Space::EMPTY);
        board[row1][col1].setPlayer(0);
        board[row2][col2].setPieceType(Space::EMPTY);
        board[row2][col2].setPlayer(0);
        board[row3][col3].setPieceType(Space::EMPTY);
        board[row3][col3].setPlayer(0);
    }

    // Give Pieces Back //
    if(next_mover() == HUMAN){
        p1SeniorCounter += 3;
    }else{
        p2SeniorCounter += 3;
    }

    game::make_move(move); // Increment game counter
}

void Boop::makeMoveOne(const string& move){
    // When all pieces on board, they pick up a piece and it becomes a frog //
    string choice;

    cout << "Please select a piece to remove (e.g a4): ";
    cin >> choice;

    int col = int(toupper(choice[0]) - 'A');
    int row = int(choice[1] - '1');

    if(isLegalOne(choice)){
        if(next_mover() == HUMAN){
            board[row][col].setPieceType(Space::EMPTY);
            board[row][col].setPlayer(0);
            p1SeniorCounter += 1;
        }else if(next_mover() == COMPUTER){
            board[row][col].setPieceType(Space::EMPTY);
            board[row][col].setPlayer(0);
            p2SeniorCounter += 1;
        }
    }
    game::make_move(move); // Increment game counter
}

// is_legal functions //
bool Boop::is_legal(const string& move)const{
    // Check hiddenString
    if(move == "FIN"){
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(board[i][j].getPieceType() == Space::SENIOR){
                    // Check sides
                    if(j + 2 < 6 && board[i][j + 1].getPieceType() == Space::SENIOR && board[i][j + 2].getPieceType() == Space::SENIOR){
                        return true;
                    }
                    // Check up and down
                    if(i + 2 < 6 && board[i + 1][j].getPieceType() == Space::SENIOR && board[i + 2][j].getPieceType() == Space::SENIOR){
                        return true;
                    }
                    // Check down right
                    if(i + 2 < 6 && j + 2 < 6 && board[i + 1][j + 1].getPieceType() == Space::SENIOR && board[i + 2][j + 2].getPieceType() == Space::SENIOR){
                        return true;
                    }
                    // Check down left  
                    if(i + 2 < 6 && j - 2 >= 0 && board[i + 1][j - 1].getPieceType() == Space::SENIOR && board[i + 2][j - 2].getPieceType() == Space::SENIOR){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    char playerChoice = toupper(move[2]);
    int row = move[1] - '0';
    int col = toupper(move[0]) - 'A';

    if(playerChoice != 'T' && playerChoice != 'F'){ // for Tadpole and Frog
        return false;
    }else if(row < 0 || row >= 6){
        return false;
    }else if(col < 0 || col >= 6){
        return false;
    }else if(board[row][col].getPieceType() != Space::EMPTY){
        return false;
    }else if(next_mover() == 0 && playerChoice == 'T' && p1JuniorCounter < 1){ // Checking for player 1 has enough tadpole pieces
        return false;
    }else if(next_mover() == 0 && playerChoice == 'F' && p1SeniorCounter < 1){ // Checking for player 1 has enough frog pieces
        return false;
    }else if(next_mover() == 1 && playerChoice == 'T' && p2JuniorCounter < 1){ // Checking for player 2 has enough tadpole pieces
        return false;
    }else if(next_mover() == 1 && playerChoice == 'F' && p2SeniorCounter < 1){ // Checking for player 2 has enough frog pieces
        return false;
    }
    return true;
}

bool Boop::isLegalOne(const string& move)const{
    int col = int(toupper(move[0]) - 'A');
    int row = int(move[1] - '1');

    if(next_mover() == HUMAN){
        if(board[row][col].getPieceType() != Space::EMPTY){
        cout << "Invalid selection, space is not empty.";
        return 0;
        }else if(board[row][col].getPlayer() != 1){
            cout << "Invalid selection, piece does not belong to you.";
            return 0;
        }
    }else if(next_mover() == COMPUTER){
        if(board[row][col].getPieceType() != Space::EMPTY){
        cout << "Invalid selection, space is not empty.";
        return 0;
        }else if(board[row][col].getPlayer() != 2){
            cout << "Invalid selection, piece does not belong to you.";
            return 0;
        }
    }
    return true;
}

bool Boop::isLegalThree(const string& move, int col1, int row1, int col2, int row2, int col3, int row3)const{
    if(next_mover() == HUMAN){
        if(board[row1][col1].getPieceType() != Space::JUNIOR){
            cout << "CHOICE 1 INVALID: No valid tadpole.";
            return 0;
        }else if(board[row2][col2].getPieceType() != Space::JUNIOR){
            cout << "CHOICE 2 INVALID: No valid tadpole.";
            return 0;
        }else if(board[row3][col3].getPieceType() != Space::JUNIOR){
            cout << "CHOICE 3 INVALID: No valid tadpole.";
            return 0;
        }else if(board[row1][col1].getPlayer() != 1){
            cout << "CHOICE 1 INVALID: Space does not belong to you.";
            return 0;
        }else if(board[row2][col2].getPlayer() != 1){
            cout << "CHOICE 2 INVALID: Space does not belong to you.";
            return 0;
        }else if(board[row3][col3].getPlayer() != 1){
            cout << "CHOICE 2 INVALID: Space does not belong to you.";
            return 0;
        }
    }else if(next_mover() == COMPUTER){
        if(board[row1][col1].getPieceType() != Space::JUNIOR){
            cout << "CHOICE 1 INVALID: No valid tadpole.";
            return 0;
        }else if(board[row2][col2].getPieceType() != Space::JUNIOR){
            cout << "CHOICE 2 INVALID: No valid tadpole.";
            return 0;
        }else if(board[row3][col3].getPieceType() != Space::JUNIOR){
            cout << "CHOICE 3 INVALID: No valid tadpole.";
            return 0;
        }else if(board[row1][col1].getPlayer() != 2){
            cout << "CHOICE 1 INVALID: Space does not belong to you.";
            return 0;
        }else if(board[row2][col2].getPlayer() != 2){
            cout << "CHOICE 2 INVALID: Space does not belong to you.";
            return 0;
        }else if(board[row3][col3].getPlayer() != 2){
            cout << "CHOICE 2 INVALID: Space does not belong to you.";
            return 0;
        }
    }
    return true;
}

// Other Functions //
void Boop::restart(){
    p1JuniorCounter = 8;
    p1SeniorCounter = 0;    
    p2JuniorCounter = 8;
    p2SeniorCounter = 0;    

    for(int i = 0; i < 6; i++){ // Goes through the board and sets each space to type empty
        for(int j = 0; j < 6; j++){
            board[i][j].setPieceType(Space::EMPTY);  // Set to 1 because it will be player 1 turn
        }
    }
    game::restart();
}

void Boop::display_status()const{
    int player; // For display purposes
    if(next_mover() == HUMAN){
        player = 1;
    }else if(next_mover() == COMPUTER){
        player = 2;
    }

    cout << "      A      B      C      D      E      F" << endl;
    cout << "  +------+------+------+------+------+------+" << endl; // Top of board
    
    for(int i = 0; i < 6; i++){
        for(int line = 0; line < 3; line++){
            if(line == 0){
                cout << i + 1 << " ";   // Compensates for the space the number takes up
            }else{
                cout << "  ";
            }

            for(int j = 0; j < 6; j++){
                if(j == 0) cout << "|"; // Start of row
                if(line == 0) board[i][j].printTop(board[i][j].getPlayer());
                else if(line == 1) board[i][j].printMiddle(board[i][j].getPlayer());
                else if(line == 2) board[i][j].printBottom(board[i][j].getPlayer());

                if (j < 5) cout << " |"; // Space Separator
            }
            cout << " |" << endl; // End of row
        }
        cout << "  +------+------+------+------+------+------+" << endl; // Bottom of each row
    }
    cout << BLUE << "Player 1 Tadpole pieces: " << p1JuniorCounter << "\tPlayer 1 Frog pieces: " << p1SeniorCounter << RESET << endl;
    cout << RED << "Player 2 Tadpole pieces: " << p2JuniorCounter << "\tPlayer 2 Frog pieces: " << p2SeniorCounter << RESET << endl;
    cout << endl;
    cout << GREEN << "Player " << player << " turn" << RESET << endl;

}

void Boop::boopPieces(int x, int y){
    int originalPlayer;

    for(int i = -1; i <= 1; i++){ // Nested for loops to go in a circle around the piece
        for(int j = -1; j <= 1; j++){
            if(i == 0 && j == 0) continue; // Skips space where piece was just placed so that it doesnt get booped
            int nx = x + i, ny = y + j;
            int nx2 = x + (i * 2), ny2 = y + (j * 2);

            if (nx >= 0 && nx < 6 && ny >= 0 && ny < 6) {
                Space::pieceType adjacentPiece = board[nx][ny].getPieceType();
                if (adjacentPiece == Space::JUNIOR || (adjacentPiece == Space::SENIOR && board[x][y].getPieceType() == Space::SENIOR)) {
                    if (nx2 >= 0 && nx2 < 6 && ny2 >= 0 && ny2 < 6 && board[nx2][ny2].getPieceType() == Space::EMPTY) {
                        originalPlayer = board[nx][ny].getPlayer();
                        board[nx][ny].setPieceType(Space::EMPTY);
                        board[nx][ny].setPlayer(0);

                        board[nx2][ny2].setPieceType(adjacentPiece);
                        board[nx2][ny2].setPlayer(originalPlayer);
                    } else {
                        if (originalPlayer == 1) {
                            p1JuniorCounter += (adjacentPiece == Space::JUNIOR) ? 1 : 0;
                            p1SeniorCounter += (adjacentPiece == Space::SENIOR) ? 1 : 0;
                        } else if (originalPlayer == 2) {
                            p2JuniorCounter += (adjacentPiece == Space::JUNIOR) ? 1 : 0;
                            p2SeniorCounter += (adjacentPiece == Space::SENIOR) ? 1 : 0;
                        }
                    }
                }
            }
        }
    }
}   

bool Boop::checkForThree()const{
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(board[i][j].getPieceType() == Space::JUNIOR){
                // Check horizontal
                if(j + 2 < 6 && board[i][j + 1].getPieceType() == Space::JUNIOR && board[i][j + 2].getPieceType() == Space::JUNIOR){
                    return true;
                }
                // Check vertical
                if(i + 2 < 6 && board[i + 1][j].getPieceType() == Space::JUNIOR && board[i + 2][j].getPieceType() == Space::JUNIOR){
                    return true;
                }
                // Check diagonal to the right
                if(i + 2 < 6 && j + 2 < 6 && board[i + 1][j + 1].getPieceType() == Space::JUNIOR && board[i + 2][j + 2].getPieceType() == Space::JUNIOR){
                    return true;
                }
                // Check diagonal to the left
                if(i + 2 < 6 && j - 2 >= 0 && board[i + 1][j - 1].getPieceType() == Space::JUNIOR && board[i + 2][j - 2].getPieceType() == Space::JUNIOR){
                    return true;
                }
            }
        }
    }
    return 0;
}

int Boop::getCPJuniorCount(){
    int num;
    
    if(next_mover() == HUMAN){
        num = p1JuniorCounter;
    }else{
        num = p2JuniorCounter;
    }
    return num;
}

int Boop::getCPSeniorCount(){
    int num;

    if(next_mover() == COMPUTER){
        num = p1SeniorCounter;
    }else{
        num = p2SeniorCounter;
    }
    return num;
}

// Pure Virtual Functions //
game* Boop::clone()const{
    return new Boop(*this);
}

void Boop::compute_moves(queue<string>& moves) const{
    string hiddenString = "FIN";
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(board[i][j].getPieceType() == Space::SENIOR){
                // Checking side spaces
                if(j + 2 < 6 && board[i][j + 1].getPieceType() == Space::SENIOR && board[i][j + 2].getPieceType() == Space::SENIOR){
                    moves.push(hiddenString);
                }
                // Checking pieces above or below
                if(j + 2 < 6 && board[i + 1][j].getPieceType() == Space::SENIOR && board[i + 2][j].getPieceType() == Space::SENIOR){
                    moves.push(hiddenString);
                }
                // Checking down right
                if(i + 2 < 6 && j + 2 < 6 && board[i + 1][j + 1].getPieceType() == Space::SENIOR && board[i + 2][j + 2].getPieceType() == Space::SENIOR){
                    moves.push(hiddenString);
                }
                // Checking down left
                if(i + 2 < 6 && j - 2 >= 0 && board[i + 1][j + 1].getPieceType() == Space::SENIOR && board[i + 2][j + 2].getPieceType() == Space::SENIOR){
                    moves.push(hiddenString);
                }
            }
        }
    }
    
    string turnType; // Stores type of move
    if(checkForThree()){
        if(!moves.empty()){
            if(moves.front() == hiddenString){
                return;
            }
        }

        turnType = "3";
        string moveThree;
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(board[i][j].getPieceType() == Space::JUNIOR){
                    // Check sides
                    if(j + 2 < 6 && board[i][j + 1].getPieceType() == Space::JUNIOR && board[i][j + 2].getPieceType() == Space::JUNIOR){
                        moveThree = (to_string(j)) + to_string(i);  // For first coord
                        int row1 = int(toupper(moveThree[0]) + 'A');
                        int col1 = int(moveThree[1]);
                        moveThree = (to_string(j + 1)) + to_string(i); // For second coord
                        int row2 = int(toupper(moveThree[0]) + 'A');
                        int col2 = int(moveThree[1]);
                        moveThree = (to_string(j + 2)) + to_string(i); // For third coord
                        int row3 = int(toupper(moveThree[0]) + 'A');
                        int col3 = int(moveThree[1]);
                        if(isLegalThree(moveThree, row1, col1, row2, col2, row3, col3)){
                            moves.push(moveThree);
                        }
                    }
                    // Check top & bottom
                    if(i + 2 < 6 && board[i + 1][j].getPieceType() == Space::JUNIOR && board[i + 2][j].getPieceType() == Space::JUNIOR){
                        moveThree = (to_string(j)) + to_string(i);  // For first coord
                        int row1 = int(toupper(moveThree[0]) + 'A');
                        int col1 = int(moveThree[1]);
                        moveThree = (to_string(j + 1)) + to_string(i); // For second coord
                        int row2 = int(toupper(moveThree[0]) + 'A');
                        int col2 = int(moveThree[1]);
                        moveThree = (to_string(j + 2)) + to_string(i); // For third coord
                        int row3 = int(toupper(moveThree[0]) + 'A');
                        int col3 = int(moveThree[1]);
                        if(isLegalThree(moveThree, row1, col1, row2, col2, row3, col3)){
                            moves.push(moveThree);
                        }
                    }
                    // Check down to right
                    if(i + 2 < 6 && j + 2 < 6 && board[i + 1][j + 1].getPieceType() == Space::JUNIOR && board[i + 2][j + 2].getPieceType() == Space::JUNIOR){
                        moveThree = (to_string(j)) + to_string(i);  // For first coord
                        int row1 = int(toupper(moveThree[0]) + 'A');
                        int col1 = int(moveThree[1]);
                        moveThree = (to_string(j + 1)) + to_string(i); // For second coord
                        int row2 = int(toupper(moveThree[0]) + 'A');
                        int col2 = int(moveThree[1]);
                        moveThree = (to_string(j + 2)) + to_string(i); // For third coord
                        int row3 = int(toupper(moveThree[0]) + 'A');
                        int col3 = int(moveThree[1]);
                        if(isLegalThree(moveThree, row1, col1, row2, col2, row3, col3)){
                            moves.push(moveThree);
                        }
                    }
                    // Check down to left
                    if(i + 2 < 6 && j - 2 >= 0 && board[i + 1][j - 1].getPieceType() == Space::JUNIOR && board[i + 2][j - 2].getPieceType() == Space::JUNIOR){
                        moveThree = (to_string(j)) + to_string(i);  // For first coord
                        int row1 = int(toupper(moveThree[0]) + 'A');
                        int col1 = int(moveThree[1]);
                        moveThree = (to_string(j + 1)) + to_string(i); // For second coord
                        int row2 = int(toupper(moveThree[0]) + 'A');
                        int col2 = int(moveThree[1]);
                        moveThree = (to_string(j + 2)) + to_string(i); // For third coord
                        int row3 = int(toupper(moveThree[0]) + 'A');
                        int col3 = int(moveThree[1]);
                        if(isLegalThree(moveThree, row1, col1, row2, col2, row3, col3)){
                            moves.push(moveThree);
                        }
                    }
                }
            }
        }
    }
    else if(p2JuniorCounter < 1 || p2JuniorCounter + p2SeniorCounter == 0){ // Checking if piece count is valid
        turnType = "2";
        if(!moves.empty()){
            if(moves.front() == hiddenString){
                return;
            }
        }
        string userCoords;
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(board[i][j].getPieceType() == Space::JUNIOR){
                    if(board[i][j].getPlayer() == 2){
                        string moveOne = (to_string(j) + 'A') + to_string(i);
                        if(isLegalOne(moveOne)){
                            moves.push(moveOne);
                        }
                    }
                }
            }
        }
    }
    else{
        turnType = "1";
        if(!moves.empty()){
           if(moves.front() == hiddenString){
                return;
            }
        }

        string newMove = "";
        for(int i = 0; i < 6; i++){
            for(string j : {"A", "B", "C", "D", "E", "F"}){
                for(string k : {"T", "F"}){
                    newMove = j + to_string(i) + k;
                    if(is_legal(newMove)){
                        moves.push(newMove);
                    }
                }
            }
            /*for(int j = 0; j < 6; j++){
                for(char piece : {'t', 'f'}){
                    string newMove = string(1, 'A' + j) + to_string(i) + piece;
                    if(is_legal(newMove)){
                        moves.push(newMove);
                    }
                }
            }*/
        }
    }
}

int Boop::evaluate()const{
    // Point System to evaluate who is winning //
    int p2Points = p2JuniorCounter * 2 + p2SeniorCounter * 3;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(board[i][j].getPlayer() == 2){ // For player two
                if(board[i][j].getPieceType() == Space::JUNIOR && board[i][j].getPlayer() == 2){ // Gives point for tadpole on the board
                    p2Points++;
                }
                else if(board[i][j].getPieceType() == Space::SENIOR && board[i][j].getPlayer() == 2){ // Check for frogs on the board
                    p2Points += 2;
                }
                else if(j + 1 < 6 && board[i][j + 1].getPieceType() == Space::JUNIOR && board[i][j + 1].getPlayer() == 2){ // Check 2 adjacent tadpoles
                    p2Points += 3;
                }
                else if(j + 2 < 6 && board[i][j + 2].getPieceType() == Space::JUNIOR && board[i][j + 2].getPlayer() == 2){ // Cehck 3 adjecent tadpoles
                    p2Points += 5;
                }
            }
        }
    }

    return p2Points;
}

bool Boop::is_game_over()const{
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(board[i][j].getPieceType() != Space::EMPTY && board[i][j].getPieceType() == Space::SENIOR){
                for(int k = -1; k < 1; k++){ // Checks 3x3 space for other frogs
                    for(int l = -1; l < 1; l++){
                        if((i + k >= 0 && i + k < 6) || ((i + (k * 2) >= 0) && i + (l * 2) < 6)){ // Checking if were in bounds
                            if((j + l >= 0 && j + l < 6) || ((j + (k * 2) >= 0) && (j + (l * 2) < 6))){ // Checking if were in bounds
                                if(board[k][l].getPieceType() == Space::SENIOR){ // Checking if the piece occupying space is frog
                                    if(board[k * 2][l * 2].getPieceType() == Space::SENIOR){ // Checking if frog
                                        return 1; // If all is true, must be 3 in a row so return 1 for true
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
