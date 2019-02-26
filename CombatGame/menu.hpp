/**********************************
** Program Name: menu.hpp
** Author: Miao Pan
** Date: 02/05/2019
** Description: This is the declaration file for the menu function. It will provide the user with choices and return an int representing the user's choice.
**********************************/

#ifndef MENU_HPP
#define MENU_HPP

enum State {newGame, finished, noMore};

//Menu function prototype
int menu(State gameState);



#endif