/**********************************
** Program Name: Ant.cpp
** Author: Miao Pan
** Date: 01/11/2019
** Description: This is the implementation file for the Ant Class.
**********************************/
#include "Ant.hpp"
#include "Board.hpp"
#include <iostream>
#include <typeinfo> 

using std::cout;
using std::cin;
using std::endl;

//Constructor
Ant::Ant(int row, int col, int boardRowInput, int boardColInput, Orientation o = North){
   
    antOrient = o;
    antRow = row;
    antCol = col;
    boardRow = boardRowInput;
    boardCol = boardColInput;
    
}

//Default constructor (won't be used)
Ant::Ant(){
    
    antOrient = North;
    antRow = 0;
    antCol = 0;
    boardRow = 15;
    boardCol = 15;
}


//Get ant's orientation
Orientation Ant::getAntOrient(){
    
    return antOrient;
}

//Set ant's orientation
void Ant::setAntOrient(Orientation o){
    antOrient = o;
    
}
        
//Get ant's row
int Ant::getAntRow(){
    return antRow;
}
        
//Set ant's row        
void Ant::setAntRow(int row){
    antRow = row;
}
       
//Get ant's col       
int Ant::getAntCol(){
    return antCol;
}
        
//Set ant's col        
void Ant::setAntCol(int col){
    antCol = col;
}

//Get the board row number
int Ant::getBoardRow(){
    return boardRow;
}

//Get the board col number
int Ant::getBoardCol(){
    return boardCol;
}

//Turn the ant right 90 degrees
Orientation Ant::turnRight(){
    if(antOrient == North){
        setAntOrient(East);
    }else if(antOrient == East){
        setAntOrient(South);
    }else if(antOrient == South){
        setAntOrient(West);
    }else if(antOrient == West){
        setAntOrient(North);
    }
    
    return antOrient;
}

//Turn the ant left 90 degrees
Orientation Ant::turnLeft(){
    if(antOrient == North){
        setAntOrient(West);
    }else if(antOrient == West){
        setAntOrient(South);
    }else if(antOrient == South){
        setAntOrient(East);
    }else if(antOrient == East){
        setAntOrient(North);
    }
    
    return antOrient;
}
//Move the ant - forward the ant one cell in its orientation     
void Ant::moveAnt(){
    
    //cout << "trying to move ant, current ant row is " << antRow << endl;
    //cout << antOrient << " is antOrient" << endl;
    if(antOrient == North){
        if(antRow != 1){
            //cout << "ant row not equal to 1" << endl;
            setAntRow(antRow - 1);
        }else if(antRow == 1){
            antRow = boardRow;
        }
    }else if(antOrient == East){
        //cout << "trying to move ant, orientation is east." << endl;
        if(antCol != boardCol){
            //cout << "ant col not on right border" << endl;
            setAntCol(antCol + 1);
        }else if(antCol == boardCol){
            antCol = 1;
        }
    }else if(antOrient == South){
        //cout << "trying to move ant, orientation is south." << endl;
        if(antRow != boardRow){
            antRow = antRow + 1;
        }else if(antRow == boardRow){
            antRow = 1;
        }
    }else if(antOrient == West){
        //cout << "trying to move ant, orientation is west." << endl;
        if(antCol != 1){
            antCol = antCol -1;
        }else if(antCol == 1){
            antCol = boardCol;
        }
    }
}