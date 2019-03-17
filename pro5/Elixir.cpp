/**********************************
** Program Name: Elixir.cpp
** Author: Miao Pan
** Date: 03/15/2019
** Description: This is the implementation file for the Elixir class.
**********************************/

#include "Elixir.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor
Elixir::Elixir(int rowInput, int colInput ):Space(rowInput, colInput){
        
    typeName = "Elixir";
    restoreAbility = 20;
}

Elixir::Elixir(int rowInput, int colInput, Space* topPtr, Space* bottomPtr, Space* leftPtr, Space* rightPtr):Space(rowInput, colInput, topPtr, bottomPtr, leftPtr, rightPtr){
    
    typeName = "Elixir";
    restoreAbility = 20;
}

//Takes no argument and will return the HP points it will give to the player.
int Elixir::getRestoreAbility(){
    return restoreAbility;
}

//Interact with Elixir. It will return the HP points to be added to the player. It will also set attribute "hidden" to false, which means it will reveal itself when map is printed.
int Elixir::interact(){
    cout<< "interacting with Elixir" << endl;
    hidden = false;
    return restoreAbility;
}

//Return a string indicate the type of space this is.
string Elixir::getType(){
    return "Elixir";
}
