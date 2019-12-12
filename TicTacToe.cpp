#include <vector>
#include <iostream>

using namespace std;

/// @brief Draws the provided tic-tac-toe board to the screen
//  @param board is the tic-tac-toe board that should be drawn
void drawBoard(const vector<char> &gameBoard)
{
    for (int i = 0; i < 9; i += 3)
    {
        cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
             << gameBoard.at(i + 2) << "  " << endl;
        if (i < 6)
        {
            cout << "-----|-----|-----" << endl;
        }
    }
    cout << endl;
    return;
}

void initVector(vector<char> &v)
{
    if (v.size() == 3)
    {
        v = {'a', 'b', 'c'};
    }
    else if (v.size() == 5)
    {
        v = {'a', 'b', 'c', 'd', 'e'};
    }
    else
    {
        v = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    }
}

/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int convertPosition(char boardPosition)
{
    if (boardPosition == 'a')
    {
        return 0;
    }
    if (boardPosition == 'b')
    {
        return 1;
    }
    if (boardPosition == 'c')
    {
        return 2;
    }
    if (boardPosition == 'd')
    {
        return 3;
    }
    if (boardPosition == 'e')
    {
        return 4;
    }
    if (boardPosition == 'f')
    {
        return 5;
    }
    if (boardPosition == 'g')
    {
        return 6;
    }
    if (boardPosition == 'h')
    {
        return 7;
    }
    if (boardPosition == 'i')
    {
        return 8;
    }
    return -1;
}

/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool validPlacement(const vector<char> &gameBoard, int positionIndex)
{
    if (positionIndex == 0 and (gameBoard.at(0) == 'X' or gameBoard.at(0) == 'O'))
    {
        return false;
    }
    if (positionIndex == 1 and (gameBoard.at(1) == 'X' or gameBoard.at(1) == 'O'))
    {
        return false;
    }
    if (positionIndex == 2 and (gameBoard.at(2) == 'X' or gameBoard.at(2) == 'O'))
    {
        return false;
    }
    if (positionIndex == 3 and (gameBoard.at(3) == 'X' or gameBoard.at(3) == 'O'))
    {
        return false;
    }
    if (positionIndex == 4 and (gameBoard.at(4) == 'X' or gameBoard.at(4) == 'O'))
    {
        return false;
    }
    if (positionIndex == 5 and (gameBoard.at(5) == 'X' or gameBoard.at(5) == 'O'))
    {
        return false;
    }
    if (positionIndex == 6 and (gameBoard.at(6) == 'X' or gameBoard.at(6) == 'O'))
    {
        return false;
    }
    if (positionIndex == 7 and (gameBoard.at(7) == 'X' or gameBoard.at(7) == 'O'))
    {
        return false;
    }
    if (positionIndex == 8 and (gameBoard.at(8) == 'X' or gameBoard.at(8) == 'O'))
    {
        return false;
    }

    // TODO: implement function
    return true;
}

/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///     Continues asking for a position until a valid position has been entered.
///
/// @param board the current tic-tac-toe board
/// @return an integer index in board vector of a chosen available board spot
int getPlay(const vector<char> &gameBoard)
{

    // TODO: implement function
    char boardPosition = ' ';
    int position;
    bool isValid;

    cout << "Please choose a position: " << endl;
    cin >> boardPosition;
    position = convertPosition(boardPosition);
    while (position == -1)
    {
        cout << "Please choose a position: " << endl;
        cin >> boardPosition;
        position = convertPosition(boardPosition);
    }
    isValid = validPlacement(gameBoard, position);
    while (isValid == false)
    {
        cout << "Please choose a position: " << endl;
        cin >> boardPosition;
        position = convertPosition(boardPosition);
        isValid = validPlacement(gameBoard, position);
        if (isValid)
        {
            isValid = true;
        }
    }
    return position;
}

/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board
/// @return true if the game has been won, false otherwise
bool gameWon(const vector<char> &gameBoard)
{
    for (int i = 0; i < 3; i++)
    {
        if (gameBoard.at(3 * i) == gameBoard.at(3 * i + 1) && gameBoard.at(3 * i + 1) == gameBoard.at(3 * i + 2))
            return true;
        else if (gameBoard.at(i) == gameBoard.at(i + 3) && gameBoard.at(i + 3) == gameBoard.at(i + 6))
            return true;
    }

    //code to determine if we have 3 in a row diagonally.
    if (gameBoard.at(0) == gameBoard.at(4) && gameBoard.at(4) == gameBoard.at(8))
        return true;
    else if (gameBoard.at(2) == gameBoard.at(4) && gameBoard.at(4) == gameBoard.at(6))
        return true;

    return false;

    // TODO: implement function
    return false;
}

/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board
/// @return true iff the board is full (no cell is available)
bool boardFull(const vector<char> &gameBoard)
{
    int j = 0;
    for (int i = 0; i < gameBoard.size(); i++)
    {
        if (gameBoard.at(i) == 'X' || gameBoard.at(i) == 'O')
            j++;
    }

    if (j == 9)
        return true;
    else
        return false;
}

// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main()
{
    /* gameWon: Define, test, and submit this function. (Should now have 16 points.)  */

    // Variables that you may find useful to utilize
    vector<char> gameBoard(9);
    initVector(gameBoard);
    drawBoard(gameBoard);
    int curPlay;
    int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'
    while (!boardFull(gameBoard) && !gameWon(gameBoard))
    {
        curPlay = getPlay(gameBoard);

        gameBoard.at(curPlay) = (whosTurn == PLAYER1) ? 'X' : 'O';

        // Turn switches only when board is not full or game is not won
        if (!boardFull(gameBoard) && !gameWon(gameBoard))
        {
            if (whosTurn == PLAYER1)
                whosTurn = PLAYER2;
            else if (whosTurn == PLAYER2)
                whosTurn = PLAYER1;
        }

        drawBoard(gameBoard);
    }

    if (whosTurn == PLAYER1 && gameWon(gameBoard))
        cout << "Player 1 Wins!!" << endl
             << endl;
    else if (whosTurn == PLAYER2 && gameWon(gameBoard))
        cout << "Player 2 Wins!!" << endl
             << endl;
    else
        cout << "No one wins" << endl
             << endl;
    /// TODO: Determine winner

    return 0;
}