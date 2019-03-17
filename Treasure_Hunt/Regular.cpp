/**********************************
** Program Name: Regular.cpp
** Author: Miao Pan
** Date: 03/13/2019
** Description: This is the implementation file for the Regular class.
**********************************/

#include "Regular.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor
Regular::Regular(int rowInput, int colInput):Space(rowInput, colInput){
        
    typeName = "Regular";
    
}

Regular::Regular(int rowInput, int colInput, Space* topPtr, Space* bottomPtr, Space* leftPtr, Space* rightPtr):Space(rowInput, colInput, topPtr, bottomPtr, leftPtr, rightPtr){
    
    typeName = "Regular";
}

//Interact with Regular. It will set attribute "hidden" to false, which means it will reveal itself when map is printed.
int Regular::interact(){
    cout<< "interacting with Regular" << endl;
    hidden = false;
    return 0;
}

//Return a string indicate the type of space this is.
string Regular::getType(){
    return "Regular";
}
