/**********************************
** Program Name: menu.cpp
** Author: Miao Pan
** Date: 01/10/2019
** Description: This is the implementation file for the menu function.
**********************************/

#include "menu.hpp"
#include <iostream>
#include <cmath>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

//Helper function prototype
int getUserChoice();
int getBoardInput();
int getStepInput();
int getUserAntRowInput(int);
int getUserAntColInput(int);
int* initSetUp();


//Menu function
int* menu(State gameStateInput){
    
    int userChoice, randomChoice;
    //int* userInitInput = new int[5];
    
    if(gameStateInput == newGame){
        
        cout << "\n  Welcome to Langton's Ant Simulation!  \n\n"; 
        cout << "1.Start Langton's Ant simulation" << endl;
        cout << "2.Quit" << endl;
        
        userChoice =  getUserChoice();
        if(userChoice == 1){
            return initSetUp();
           
        } else if(userChoice == 2){
            cout << "You decided to leave." << endl;
            int* exitArray = new int[5];
            exitArray[0] = 0;
            exitArray[1] = 0;
            exitArray[2] = 0;
            exitArray[3] = 0;
            exitArray[4] = 0;
            return exitArray;
        }
        
        
    } else if (gameStateInput == finished){
        
        cout << "1.Play again" << endl;
        cout << "2.Quit" << endl;
        
        userChoice = getUserChoice();
        if(userChoice == 1){
            return initSetUp();
        }else if(userChoice == 2){
            cout << "You decided to leave." << endl;
            int* exitArray = new int[5];
            exitArray[0] = 0;
            exitArray[1] = 0;
            exitArray[2] = 0;
            exitArray[3] = 0;
            exitArray[4] = 0;
            return exitArray;
        }
    }
}


//Helper functions

int* initSetUp(){
    
    int randomChoice;
    int* userInitInput = new int[5];
    //int userInitInput[5];
    int boardRow, boardCol, steps, antRow, antCol;
    cout << "We're now creating the game board." << endl;
    cout << "Please enter the number of rows for the board. Allowed rang is [3, 200]:  " << endl;
    boardRow = getBoardInput();
    cout << "Please enter the number of columns for the board. Allowed rang is [3, 200]:  " << endl;
    boardCol = getBoardInput();
    cout << "Please enter the number of steps you wish the ant to take after it's put on the board." << endl;
    steps = getStepInput();
    cout << "Would you like to get a random starting location of the ant?" << endl;
    cout << "1. Yes " << endl;
    cout << "2. No " << endl;
 
    randomChoice = getUserChoice();
    if(randomChoice == 1){
        srand(time(NULL)); // Seed the time
        antRow = static_cast<int>(rand()%(boardRow-3+1)+3-1);
        antCol = static_cast<int>(rand()%(boardCol-3+1)+3-1);
    }else if(randomChoice == 2){
        cout << "Please enter your desired starting row of the ant: " << endl;
        antRow = getUserAntRowInput(boardRow);
        cout << "Please enter your desired starting column of the ant: " << endl;
        antCol = getUserAntColInput(boardCol);
    }
    
    userInitInput[0] = boardRow;
    userInitInput[1] = boardCol;
    userInitInput[2] = steps;
    userInitInput[3] = antRow;
    userInitInput[4] = antCol;
        
    return userInitInput;
    
    
} 


int getUserChoice(){
    while(true){
        cout << "Please enter your choice, either 1 or 2:" << endl;
        int userChoice;
        cin >> userChoice;
        
        //Check for failed extractions
        if(cin.fail()){
            cin.clear();
            cin.ignore(32767,'\n');
            cout << "Oops, that entry was invalide. Please enter either 1 or 2:" << endl;
        } else {
            cin.ignore(32767, '\n');
            if(userChoice == 1 or userChoice == 2){
                return userChoice;
            }else {
                cout << "Oops, that input was not 1 or 2. Please enter either 1 or 2: " << endl;
            }
        }
    }
}

int getBoardInput(){
    while(true){
        int userBoardInput;
        cin >> userBoardInput;
        
        //check for failed extractions
        if(cin.fail()){
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Oops, that entry was invalid, please enter a number between 3 and 200, both inclusive." << endl;
        } else{
            cin.ignore(32767, '\n');
            if (userBoardInput >= 3 and userBoardInput <= 200){
                return userBoardInput;
            }else{
                cout << "Oops, that input was smaller than 3 or larger than 200. Please enter a number between 3 and 200, both inclusive." << endl;
            }
        }
    }
}

int getUserAntRowInput(int boardRowInput){
    while(true){
        int userAntRowInput;
        cin >> userAntRowInput;
        
        //check for failed extractions
        if(cin.fail()){
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Oops, that entry was invalid, please enter a number between 1 and " << boardRowInput << " , both inclusive." << endl;
        } else{
            cin.ignore(32767, '\n');
            if (userAntRowInput >= 1 and userAntRowInput <= boardRowInput){
                return userAntRowInput;
            }else{
                cout << "Oops, that input was smaller than 1 or larger than " << boardRowInput <<" ." << endl;
            }
        }
    }
}

int getUserAntColInput(int boardColInput){
    while(true){
        int userAntColInput;
        cin >> userAntColInput;
        
        //check for failed extractions
        if(cin.fail()){
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Oops, that entry was invalid, please enter a number between 1 and " << boardColInput << " , both inclusive." << endl;
        } else{
            cin.ignore(32767, '\n');
            if (userAntColInput >= 1 and userAntColInput <= boardColInput){
                return userAntColInput;
            }else{
                cout << "Oops, that input was smaller than 1 or larger than " << boardColInput <<" ." << endl;
            }
        }
    }
}

int getStepInput(){
    while(true){
        int userStepInput;
        cin >> userStepInput;
        
        //check for failed extractions
        if(cin.fail()){
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Oops, that entry was invalid. Please enter a number >= 0. " << endl;
        }else{
            cin.ignore(32767, '\n');
            if(userStepInput >= 0 and userStepInput < 32767){
                return userStepInput;
            }else{
                cout << "Oops, that input was smaller than 0 or just too large. Please re-enter a number." << endl;
            }
        }
    }
}