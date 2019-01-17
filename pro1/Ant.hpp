/**********************************
** Program Name: Ant.hpp
** Author: Miao Pan
** Date: 01/11/2019
** Description: This is the declaration file for the Ant Class.
**********************************/

#ifndef ANT_HPP
#define ANT_HPP
#include <string>

enum Orientation {North, East, South, West};

//Ant class declaration
class Ant{
    
    private:
        
        Orientation antOrient;
        int antRow;
        int antCol;
        int boardRow;
        int boardCol;
        //Board *pBoard;
        
    public:
        Ant();
        Ant(int row, int col, int boardRow, int boardCol, Orientation o );
        Orientation getAntOrient();
        void setAntOrient(Orientation);
        int getAntRow();
        void setAntRow(int row);
        int getAntCol();
        void setAntCol(int col);
        int getBoardRow();
        int getBoardCol();
        Orientation turnRight();
        Orientation turnLeft();
        void moveAnt();
    
    
};



#endif