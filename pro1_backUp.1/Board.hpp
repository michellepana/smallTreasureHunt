/**********************************
** Program Name: Board.hpp
** Author: Miao Pan
** Date: 01/10/2019
** Description: This is the declaration file for the Board Class.
**********************************/

#ifndef BOARD_HPP
#define BOARD_HPP
#include <string>

//Board class declaration
class Board{
    
    private:
        int row;
        int col;
        char** gameBoard;
    
    public:
        
        Board(int row, int col);
        Board();
        ~Board();
        char getValue(int row, int col);
        void setValue(int row, int col, char valueInput);
        char** getBoard();
        void printBoard();
        
};


#endif