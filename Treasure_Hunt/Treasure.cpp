/**********************************
** Program Name: Treasure.cpp
** Author: Miao Pan
** Date: 03/13/2019
** Description: This is the implementation file for the Treasure class.
**********************************/

#include "Treasure.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor
Treasure::Treasure(int rowInput, int colInput):Space(rowInput, colInput){
        
    typeName = "Treasure";
    //count = 1;
}

Treasure::Treasure(int rowInput, int colInput, Space* topPtr, Space* bottomPtr, Space* leftPtr, Space* rightPtr):Space(rowInput, colInput, topPtr, bottomPtr, leftPtr, rightPtr){
    
    typeName = "Treasure";
    //count = 1;

}

/*
//Return how many treasure there are
int Treasure::getCount(){
    return count;
}
*/

/* 
void Treasure::setCount(int newCount){
    count = newCount;
}
*/

//Interact with Treasure. It will return the number of treasures to be added to the player. It will also set attribute "hidden" to false, which means it will reveal itself when map is printed.
int Treasure::interact(){
    cout<< "interacting with treasure" << endl;
    hidden = false;
    return (rand()%( 4 - 1 + 1) + 1);
}

//Return a string indicate the type of space this is.
string Treasure::getType(){
    return "Treasure";
}
