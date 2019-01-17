/**********************************
** Program Name: Board.cpp
** Author: Miao Pan
** Date: 01/10/2019
** Description: This is the implementation file for the Board Class.
**********************************/

#include "Board.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//Board class implementation

//Constructor, initiate a board with row and col input from user with spaces
Board::Board(int rowInput, int colInput){
    //Dynamically allocating a two dimensional array
    gameBoard = new char*[rowInput]; //allocate an array of int pointers - this will be row
    for(int i = 0; i<rowInput; i++){
        gameBoard[i] = new char[colInput]; // these are columns
    }
    //Fill in all board spots with space
    for (int i = 0; i < rowInput; i++){
        for(int j = 0; j < colInput; j++){
            gameBoard[i][j] = ' ';
        }
    }
    
    row = rowInput;
    col = colInput;
    cout << "Created board at address " << gameBoard << endl;
    
}

//Destructor
Board::~Board(){
    for(int i = 0; i < row; i++){
        delete[] gameBoard[i];
    }
    delete gameBoard;
    gameBoard = nullptr;
}

//Default constructor
/*Board::Board(){
    cout << "Hello" << endl;
    //Dynamically allocating a two dimensional array with 15 row and 15 col
    gameBoard = new char*[15];
    for(int i = 0; i < 15; i++){
        gameBoard[i] = new char[15];
    }
    cout << gameBoard << endl;
    //Fill in all board spots with space
    for (int i = 0; i < 15; i++){
        for(int j = 0; j< 15; j++){
            
            gameBoard[i][j] = ' ';
        }
    }
    
    row = 15;
    col = 15;

}
*/
//Get the cell value
char Board::getValue(int rowInput, int colInput){
    return gameBoard[rowInput-1][colInput-1];
}

//Set the cell value
void Board::setValue(int rowInput, int colInput, char valueInput){
    gameBoard[rowInput-1][colInput-1] = valueInput;
}

//Get the board
char** Board::getBoard(){
    return gameBoard;
}

//Print the board
void Board::printBoard(){
    cout << "Printing out the game board..." << endl;
    cout << row << "is row" << endl;
    cout << gameBoard << endl;
    //cout << "----------------------" << endl;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if(j ==0){
                cout << "|" << gameBoard[i][j] ;
            }else if(j == col -1){
                cout << gameBoard[i][j] << "|" ;
            }
            else{
                cout << gameBoard[i][j];
            }
        }
        cout << endl;
    }    
    //cout << "------------------------" << endl;
}

