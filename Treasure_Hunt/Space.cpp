/**********************************
** Program Name: Space.cpp
** Author: Miao Pan
** Date: 03/06/2019
** Description: This is the implementation file for the Space class.
**********************************/

#include "Space.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor
Space::Space(int rowInput, int colInput){
    
    typeName = "Base Space";
    top = nullptr;
    bottom = nullptr;
    left = nullptr;
    right = nullptr;
    //value = 'x';
    row = rowInput;
    col = colInput;
    hidden = true;
}

//Constructor with overload
Space::Space(int rowInput, int colInput, Space* topPtr, Space* bottomPtr, Space* leftPtr, Space* rightPtr){
    
    typeName = "Base Space";
    top = topPtr;
    bottom = bottomPtr;
    left = leftPtr;
    right = rightPtr;
    row = rowInput;
    col = colInput;
}


string Space::getType(){
    return typeName;
}

//Set the surroundings of the space, namely, it's top/bottom/left/right spaces.
void Space::setSurroundings(Space* topPtr, Space* bottomPtr, Space* leftPtr, Space* rightPtr){
    
    top = topPtr;
    bottom = bottomPtr;
    left = leftPtr;
    right = rightPtr;
}

int Space::getRow(){
    return row;
}

int Space::getCol(){
    return col;
}

Space* Space::getRight(){
    return right;
}

Space* Space::getLeft(){
    return left;
}

Space* Space::getTop(){
    return top;
}

Space* Space::getBottom(){
    return bottom;
}

bool Space::getHidden(){
    return hidden;
}