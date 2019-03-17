/**********************************
** Program Name: Board.cpp
** Author: Miao Pan
** Date: 03/13/2019
** Description: This is the implementation file for the Board class.
**********************************/

#include "Board.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor. It will initiate 9 pointers to space, link them together, and put them into a 2D array. It will also put the starting position at boardArray[0][0].
Board::Board(){
        
    //Initiate all the spaces. Upon initialization, all spaces are disconnected.
    b31 = new Bomb(3,1);
    e32 = new Elixir(3,2);
    t33 = new Treasure(3,3);
    t21 = new Treasure(2,1);
    r22 = new Regular(2,2);
    e23 = new Elixir(2,3);
    r11 = new Regular(1,1);
    b12 = new Bomb(1,2);
    b13 = new Bomb(1,3);
    
    //Connect all the spaces
    b31->setSurroundings(nullptr, t21, nullptr, e32);
    e32->setSurroundings(nullptr, r22, b31, t33);
    t33->setSurroundings(nullptr, e23, e32, nullptr);
    t21->setSurroundings(b31, r11, nullptr, r22);
    r22->setSurroundings(e32, b12, t21, e23);
    e23->setSurroundings(t33, b13, r22, nullptr);
    r11->setSurroundings(t21, nullptr, nullptr, b12);
    b12->setSurroundings(r22, nullptr, r11, b13);
    b13->setSurroundings(e23, nullptr, b12, nullptr);
    
    //Put the initiated Space* into a 2D array.
    boardArray[0][0] = r11;
    boardArray[0][1] = b12;
    boardArray[0][2] = b13;
    boardArray[1][0] = t21;
    boardArray[1][1] = r22;
    boardArray[1][2] = e23;
    boardArray[2][0] = b31;
    boardArray[2][1] = e32;
    boardArray[2][2] = t33;
    
    //Assign the starting position to r11, which is located at B[0][0]
    position = r11;
}

//Destructor
Board::~Board(){
    delete b31;
    b31 = nullptr;
    delete e32;
    e32 = nullptr;
    delete t33;
    t33 = nullptr;
    delete t21;
    t21 = nullptr;
    delete r22;
    r22 = nullptr;
    delete e23;
    e23 = nullptr;
    delete r11;
    r11 = nullptr;
    delete b12;
    b12 = nullptr;
    delete b13;
    b13 = nullptr;
}

Space* Board::getPosition(){
    return position;
}

//Move to the right
void Board::moveRight(){
    if(position->getRight() == nullptr){
        cout << "Already on edge. Cannot move to the right." <<endl;
    }else{
        position = position->getRight();
    }
}

//Move to the left
void Board::moveLeft(){
    if(position->getLeft() == nullptr){
        cout << "Already on left edge. Cannot move to the left." <<endl;
    }else{
        position = position->getLeft();
    }    
}

//Move up
void Board::moveUp(){
    if(position->getTop() == nullptr){
        cout << "Already on top edge. Cannot move up." <<endl;
    }else{
        position = position->getTop();
    }    
    
}

//Move down
void Board::moveDown(){
    if(position->getBottom() == nullptr){
        cout << "Already on bottom edge. Cannot move down." <<endl;
    }else{
        position = position->getBottom();
    }    
}

//Print out current position with words
void Board::printPosition(){
    cout << "---Currently at row " << position->getRow() << " col " << position -> getCol() << endl;
}

//Print out current position with a graph. Current position will be shown as "*".
void Board::printBoard(){
    //cout << "Printing board" <<endl;
    cout << "-----------" << endl;
    for(int i = 2; i >= 0; i--){
        cout << " | ";
        for (int j = 0; j < 3; j++){
            if(boardArray[i][j] == position){
                cout << "*" << " ";
            }else if(boardArray[i][j]->getHidden()){
                cout << "?" << " ";
            }
            else {
                cout << (boardArray[i][j]->getType())[0] << " ";
            }
          
        }
        cout << "|" << endl;  
    }
    cout << "-----------" << endl;
    cout << endl;
    
}

