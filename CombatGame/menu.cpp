/**********************************
** Program Name: menu.cpp
** Author: Miao Pan
** Date: 02/05/2019
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
int getUserChoice(int min, int max);


//Menu function
int menu(State gameState){
    
 
    int userChoice;
    if(gameState == newGame){
        cout << "Please choose a character: " << endl;
        cout << "1. Vampire" << endl;
        cout << "2. Barbarian" << endl;
        cout << "3. Blue Men" << endl;
        cout << "4. Medusa" << endl;
        cout << "5. Harry Potter" << endl;
        
        userChoice =  getUserChoice(1,5);
    }else if(gameState == finished){
        cout << "-----------------------Please choose how to continue: ------------------------" << endl;
        cout << "1. That was awesome! Play again!" << endl;
        cout << "2. I'm tired now. Exit the game!" << endl;
        userChoice = getUserChoice(1,2);
        if(userChoice == 2){
            gameState = noMore;
            return 404;
        }
    }
    
   
        
    
    return userChoice;
    
    }
        
        
  
//Helper functions




//Get user's input. It takes 2 int as arguments, one as min limit, another as max limit, both inclusive.
int getUserChoice(int minInput, int maxInput){
    while(true){
        cout << "Please enter your choice, an integer between " << minInput << " and " << maxInput << ":"  << endl;
        int userChoice;
        cin >> userChoice;
        
        //Check for failed extractions
       
        if(cin.fail()){
            cin.clear();
            cin.ignore(32767,'\n');
            
        } else {
            cin.ignore(32767, '\n');
            if(cin.gcount() >1){
                cout << "This input is invalide. Please re-enter. " << endl;
            }
            else if(userChoice >= minInput and userChoice <= maxInput){
                return userChoice;
            }else {
                cout << "Oops, that input was not within the designated range. Please enter an integer between " << minInput << " and " << maxInput << ":"  << endl;
            }
        }
    }
}

