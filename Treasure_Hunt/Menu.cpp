/**********************************
** Program Name: Menu.cpp
** Author: Miao Pan
** Date: 03/04/2019
** Description: This is the implementation file for the Menu class member functions.
**********************************/

#include "Menu.hpp"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::count_if;


void Menu::printIntro(){
    cout << "\nPlease enter how you want to proceed: " << endl;
    cout << "1. Read game rules" << endl;
    cout << "2. Reveal hidden map (Not recommended!)" << endl;
    cout << "3. Continue to game play" << endl;
}

void Menu::printChoices(){
    cout << "Please enter how you want to proceed: " << endl;
    cout << "1. Interact with current space" << endl;
    cout << "2. Move" << endl;
    cout << "3. Display found treasures" << endl;
    cout << "4. I still have moves left, but I want to exit early. \n" << endl;
}

void Menu::printMoves(){
    cout << "1. Move up" << endl;
    cout << "2. Move down" << endl;
    cout << "3. Move left" << endl;
    cout << "4. Move right \n" << endl;
}

void Menu::printPlayAgain(){
    cout << "Would you like to play again?" <<endl;
    cout << "1. Yes, play AGAIN!" << endl;
    cout << "2. No, maybe next time." << endl;
}

//Get user's input. It takes 2 int as arguments, one as min limit, another as max limit, both inclusive.
//It will return the user's input as an int.
int Menu::getInt(int minInput, int maxInput){
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

//This function takes no argument and returns the user input as a string. It will not accept blank strings or anything with space within
string Menu::getString(){
    
    string userString;
    bool status = true;
    while(status){
        getline(cin, userString); //Get the entire line, including spaces
        if(userString.empty()){
            cout << "The string you entered is empty. Please re-enter" << endl;
        //If it's only white spaces, re-enter
        }else if(userString.find_first_not_of(' ') == std::string::npos){
            cout << "The string you entered is all white spaces. Please re-enter" << endl;
        //If it's only tabs, re-enter
        }else if(userString.find_first_not_of('\t') == std::string::npos){
            cout << "The string you entered is all tab and white spaces. Please re-enter" << endl;
        //If it conains white-space, re-enter
        //}else if(count_if(userString.begin(), userString.end(), isspace)){
            //cout << "The string you entered is not a word but multiple. Please re-enter" << endl;
        }else{
            status = false;
        }
    }
    
    return userString;
}

    
