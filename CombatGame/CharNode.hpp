/**********************************
** Program Name: CharNode.hpp
** Author: Miao Pan
** Date: 02/19/2019
** Description: This is the declaration file for the CharNode structure. A CharNode has a value, and two QueueNode pointers: a prev and a next.
                It also has a Character pointer.
                All memebers default to public.
**********************************/

#ifndef CHARNODE_HPP
#define CHARNODE_HPP
#include <string>
#include "Character.hpp"
using std::string;

struct CharNode{
    
        CharNode* next;
        CharNode* prev;
        Character* charPtr;
        CharNode(Character*); //Constructor
        CharNode(CharNode*, Character*, CharNode*); //Constructor with overload
        ~CharNode(); //destructor
  
};

#endif