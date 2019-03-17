/**********************************
** Program Name: Board.hpp
** Author: Miao Pan
** Date: 03/13/2019
** Description: This is the declaration file for the Board class. It will initiate a 3*3 board of space pointers. 
*               You will be able to move up/down/left/right with the board cells, and also print board, and get current position.
**********************************/

#ifndef BOARD_HPP
#define BOARD_HPP
#include "Space.hpp"
#include "Bomb.hpp"
#include "Elixir.hpp"
#include "Treasure.hpp"
#include "Regular.hpp"

class Board{
    
    protected:
    
        Space* b31;
        Space* e32;
        Space* t33;
        Space* t21;
        Space* r22;
        Space* e23;
        Space* r11;
        Space* b12;
        Space* b13;
        
        Space* position;
        Space* boardArray[3][3];
   
    public:
        Board();
        ~Board();
        void printPosition();
        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();
        Space* getPosition();
        void printBoard();
        
  
};




#endif