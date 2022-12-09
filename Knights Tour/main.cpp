//
//  main.cpp
//  Knights Tour
//
//  Created by Lance Cole on 9/21/22.
//

#include <iostream>
#include <fstream>

#define MAXSIZE 64

using namespace std;

//On a chess board, a knight is a game piece that can move two spaces in the direction of any
//axis (i.e. up, down, left or right) and then turn at a right angle and move one space (this is sometimes alternately viewed as moving one space along an axis and then one space diagonally.) Unlike other chess pieces, it does not matter if other pieces “block” this move.

//prompts the user to enter the number of rows and columns on the board. Note that you are guaranteed that these values will be at least one and the number of resulting squares on the board (i.e. the product of the number of rows and the number of columns) will always be no more than 64.

//prompts the user to enter the row number and column number for the knight’s initial position. You may assume that the initial placement is on the board somewhere.


int board [MAXSIZE][MAXSIZE];
int r, c;

void initBoard()
{
    for(int row=0 ; row<r; row++)
    {
        for(int col=0; col<c; col++)
            board[row][col] = -1;
    }
}

void printHeader()
{
    // print first +
    cout << "+";
    
    //  -+-+-+-+-+-+-+-+
    for (int numCells=0; numCells<c; numCells++)
    {
        cout << "--+";
    }
    cout << endl;
}

void printBoard()
{
    for(int row=0 ; row<r; row++)
    {
        // print row header
        printHeader();
        
        // print actual board data
        cout << '|';
        for(int col=0; col<c; col++)
        {
            if (board[row][col] != -1) {
                if(board[row][col] < 9)
                    cout << ' ';
                cout << board[row][col] + 1 << "|";
            } else
                cout << "  |";
        }
            cout << endl;
    }
    printHeader();
}
bool path(int x, int y, int n){

    // If path is outside mboard, return false.
    if ( x < 0 || x > c - 1 || y < 0 || y > r -1)
            return false;
    if(board[y][x] != -1)
        return false;
    
    board[y][x] = n;
    //check if n = to the total # of squares on the board
    if (n == r * c -1) {
        return true;
    }
    
    // If path is true, return true.
    if ( path(x + 1, y - 2, n+1) == true )
        return true;
    if ( path(x - 1, y - 2, n+1) == true )
        return true;
    if ( path(x + 1, y + 2, n+1) == true )
        return true;
    if ( path(x - 1, y + 2, n+1) == true )
        return true;
    //Check for direction
    if ( path(x - 2, y + 1, n+1) == true )
        return true;
    if ( path(x + 2, y + 1, n+1) == true )
        return true;
    if ( path(x - 2, y - 1, n+1) == true )
        return true;
    if ( path(x + 2, y - 1, n+1) == true )
        return true;

    board[y][x] = -1;
    return false;
}

int main(int argc, const char * argv[]) {
    // code for user input and program output
    cout << "What size is the board, rows followed by columns? ";
    cin >> r >> c;
    
    int x, y;
    
    initBoard();
    
    cout << "Enter the initial Knight location: ";
    cin >> y >> x ;
    
    if (path(x, y, 0)) {
        cout << "Yes, there is a solution:" << endl;
        printBoard();
    }
    else
    cout << "No knights tour!!" << endl;
    
    return 0;
}
