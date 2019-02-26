/**********************************
** Program Name: CharQueue.hpp
** Author: Miao Pan
** Date: 02/21/2019
** Description: This is the declaration file for the CharQueue class. This is a double linked list. It will initiate QueueNode structures within. 
*               Class memeber functions include to check if list is empty, add value to the back of the list, get front node value, remove front node, traverse the list, etc.
**********************************/

#ifndef CHARQUEUE_HPP
#define CHARQUEUE_HPP
#include "CharNode.hpp"

using std::string;

class CharQueue{
    
    private:
        
        CharNode* head;
        CharNode* tail;
        int score;
        
    public:
        CharQueue();
        CharQueue(CharNode*);
        ~CharQueue();
        bool isEmpty();
        void addToBack(CharNode*);
        void addToFront(CharNode*);
        string getNodeName(CharNode*);
        void moveFirstToLast();
        CharNode* removeButNotDeleteFront();
        void printQueue();
        void printReverse();
        string getHeadVal();
        string getTailVal();
        CharNode* getHead();
        void setScore(int);
        int getScore();
        
    
};

#endif