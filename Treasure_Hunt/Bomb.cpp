/**********************************
** Program Name: Bomb.cpp
** Author: Miao Pan
** Date: 03/13/2019
** Description: This is the implementation file for the Bomb class.
**********************************/

#include "Bomb.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor
Bomb::Bomb(int rowInput, int colInput):Space(rowInput, colInput){
        
    typeName = "Bomb";
    damage = 25;
}

Bomb::Bomb(int rowInput, int colInput, Space* topPtr, Space* bottomPtr, Space* leftPtr, Space* rightPtr):Space(rowInput, colInput, topPtr, bottomPtr, leftPtr, rightPtr){
    
    typeName = "Bomb";
    damage = 25;
}

//Takes no argument and will return the HP damage it will cost the player.
int Bomb::getDamage(){
    return damage;
}

//Interact with bomb. It will return the HP damage to be done to the player. It will also set attribute "hidden" to false, which will reveal it when map is printed.
int Bomb::interact(){
    cout<< "Bombed! Loose 25 HP and a treasure!" << endl;
    hidden = false;
    return damage;
}

//Return a string indicate the type of space this is.
string Bomb::getType(){
    return "Bomb";
}
