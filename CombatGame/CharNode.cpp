/**********************************
** Program Name: CharNode.cpp
** Author: Miao Pan
** Date: 02/21/2019
** Description: This is the implementation file for the CharNode structure.
**********************************/

#include "CharNode.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;



//Constructor, it only takes in one argument, a pointer to a Character. It will default the CharNode* prev and CharNode* next to nullptr.
CharNode::CharNode(Character* charInput){
    
    prev = nullptr;
    charPtr = charInput;
    next = nullptr;
}


// Another constructor with overload. It takes 3 arguments: a QueueNode pointer to previous QueueNode, a pointer to a Character, and another QueueNode pointer to the next Queuenode.
CharNode::CharNode(CharNode* prevPtr, Character* charInput, CharNode* nextPtr){
    
    prev = prevPtr;
    charPtr = charInput;
    next = nextPtr;
}

//Destructor
CharNode::~CharNode(){
    delete charPtr;
    charPtr = nullptr;
}
