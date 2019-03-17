/**********************************
** Program Name: Player.hpp
** Author: Miao Pan
** Date: 03/07/2019
** Description: This is the declaration file for the Character Class. This is an abstract class.
*               It has protected members of attack, defense, armour and strength points. It will also execute the attack and defense methods, as well as assert strength points and if the character is still alive.
**********************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include <queue>

#include "Space.hpp"
#include "Board.hpp"

using std::string;
using std::queue;

class Player{
    
    protected:
        string name;
        queue<string>* items;
        int steps;
        int itemsTotal;
        int itemsLimit;
        int strength;
        Space* where;
        
    public:
        Player(string, Board*);
        ~Player();
        int getSteps();
        int getStrength();
        Space* getWhere();
        int addStrength(int);
        int minusStrength(int);
        void addItem(string);
        void minusItem();
        int getItemsCount();
        void displayItems(queue<string>* q);
        queue<string>* getItems();
        int getItemsTotal();
    
    
};


#endif

