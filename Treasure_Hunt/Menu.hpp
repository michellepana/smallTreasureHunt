/**********************************
** Program Name: Menu.hpp
** Author: Miao Pan
** Date: 03/04/2019
** Description: This is the declaration file for the menu function. 
*               It can print out different menus and get user's int/string input.
**********************************/

#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include <queue>
#include <stack>

using std::string;
using std::stack;
using std::queue;

//enum State {aQueue, aStack, other};

//Menu function prototype
class Menu{
    
    public:
        void printChoices();
        void printMoves();
        void printPlayAgain();
        int getInt(int, int);
        string getString();
        void printIntro();
    
};



#endif