/**********************************
** Program Name: CharQueue.cpp
** Author: Miao Pan
** Date: 02/21/2019
** Description: This is the implementation file for the CharQueue class.
**********************************/

#include "CharQueue.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Default constructor. It will initiate head and tail to nullptr. This takes into account of cases when a linked list is empty.
CharQueue::CharQueue(){
    
    head = nullptr;
    tail = nullptr;
    score = 0;
}

//Constructor overload. This constructor takes in a QueueNode pointer as argument and initialize both head and tail to point to it.
//This takes into account of cases when there is only one Queuenode in the Queue.
CharQueue::CharQueue(CharNode* charPtr){
    
    head = charPtr;
    tail = charPtr;
    score = 0;
    
}

//Destructor
CharQueue::~CharQueue(){
    if(isEmpty()){
        //cout << "Empty list, destructor no need to do anthing" << endl;
    }else if(head == tail){
        //cout << "One node in list, destructor to delete the one node" << endl;
        delete head;
        head = nullptr;
        tail = nullptr;
    }else{
        //cout << "Many nodes in list, destructor to delete the nodes" << endl;
        CharNode* temp = head;
        //cout << "temp: " << temp->name << endl;
        while(temp != nullptr){
            CharNode* garbage = temp;
            temp = temp->next;
            delete garbage;
            garbage = nullptr;
            
            }
        temp = nullptr;
    }
}

//Checks if the Queue list is empty. It takes no argument and returns true if the list is empty, and false if not.
bool CharQueue::isEmpty(){
    if(head == nullptr){
        //cout << "The queue is empty" << endl;
        return true;
    }else{
        //cout << "The queue is NOT empty" << endl;
        return false;
    }
}

//Adds a CharNode to the back of the linked list. It takes a pointer to CharNode as argument, and returns nothing.
void CharQueue::addToBack(CharNode* charPtrInput){
    if(isEmpty()){
        cout << "-----The queue is currently empty. Adding its first Character！" << endl;
        head = charPtrInput;
        tail = charPtrInput;
        //head->next = nullptr;
        //tail->next = nullptr;
        //head->prev = nullptr;
        //tail->prev = nullptr;
    }
    //If the queue is not empty
    else{
        cout << "-----Adding the new character to the back of the queue." << endl;
        CharNode* temp = tail;
        tail = charPtrInput;
        tail->prev = temp;
        temp->next = charPtrInput;
        tail->next = nullptr;
        temp = nullptr;
    }
}

//Adds a CharNode to the front of the linked list. It takes a pointer to CharNode as argument, and returns nothing.
void CharQueue::addToFront(CharNode* charPtrInput){
    if(isEmpty()){
        head = charPtrInput;
        tail = charPtrInput;
        //head->next = nullptr;
        //tail->next = nullptr;
        //head->prev = nullptr;
        //tail->prev = nullptr;
    }else{
        CharNode* temp = head;
        head = charPtrInput;
        head->next = temp;
        head->prev = nullptr;
        temp->prev = charPtrInput;
        //tail->next = nullptr;
        temp = nullptr;
    }
}

//Moves the first node of the linked list to the very back. It takes no argument, and returns nothing.
void CharQueue::moveFirstToLast(){
    if(isEmpty()){
        cout << "Queue is empty." << endl;
    }else if(head == tail){
        //cout << "There is only one fighter in the team. No need moving" << endl;
    }else{
        CharNode* first = head;
        head = head->next;
        head->prev = nullptr;
        first->next = nullptr;
        first->prev = tail;
        tail->next = first;
        tail = first;
        first = nullptr;
    }
}

//Removes the first node of linked list (but that node is not deleted), so that the second node of the list now becomes its first node. It takes no argument, and returns a CharNode pointer to the removed first node.
CharNode* CharQueue::removeButNotDeleteFront(){
    if(isEmpty()){
        cout << "List is empty" << endl;
        //cout << "Queue is already empty. Nothing to remove." << endl;
    }else if(head == tail){
        //cout << "There is only one fighter in the team. Removing,,," << endl;
        CharNode* oldHead = head;
        head = nullptr;
        tail = nullptr;
        return oldHead;
    }else{
        CharNode* oldHead = head;
        head = head->next;
        head->prev = nullptr;
        oldHead->next = nullptr;
        
        return oldHead;
    }
}

//Gets the name of the character given by user that the CharNode pointer is pointed to. It takes a CharNode* as argument, and returns the name of the character as a string.
string CharQueue::getNodeName(CharNode* charPtrInput){
    return charPtrInput->charPtr->getGivenName();
}

//Prints out the queue in order. It takes no argument and returns nothing.
void CharQueue::printQueue(){
    if(isEmpty()){
        cout << "The queue is empty. Nothing to print out." << endl;
    }
    //If only has one node
    else if(head == tail){
        cout << "The team has only 1 fighter: " << head->charPtr->getGivenName() <<endl;
    }
    else{
        cout << "This team has the following fighters ------ ";
        CharNode* temp = head;
        while(temp != nullptr){
            cout << "  '" << temp->charPtr->getGivenName() << "'" ;
            temp = temp->next;
        }
        cout << endl;
    }
}

//Prints out the queue in reverse order. It takes no argument and returns nothing.
void CharQueue::printReverse(){
    if(isEmpty()){
       cout << "The queue is empty. Nothing to print out." << endl; 
    }
    //If only has one node
    else if(head == tail){
        cout << "The team has only 1 fighter: " << head->charPtr->getGivenName() <<endl;
    }
    else{
       cout << "This team has the following fighters in REVERSE order ------" << endl; 
       CharNode* temp = tail;
       while(temp != head){
            cout << "  '" << temp->charPtr->getGivenName() << "'" ;
            temp = temp->prev;
       }
       cout << "  '" << temp->charPtr->getGivenName() << "'" << endl;
    }
}

//Gets the name of the character given my user in the head node. It takes no argument and returns the name as a string.
string CharQueue::getHeadVal(){
    if(isEmpty()){
        return "Head does not exist.";
    }else{
        //cout << "Head: " << head->charPtr->getGivenName() << endl;
        return head->charPtr->getGivenName();
    }
}

//Gets the name of the character given my user in the tail node. It takes no argument and returns the name as a string.
string CharQueue::getTailVal(){
    if(isEmpty()){
        return "Tail does not exist.";
    }else{
        //cout << "Tail: " << tail->charPtr->getGivenName() << endl;
        return tail->charPtr->getGivenName();
    }
}

//Gets the head node. It takes no argument and returns the node that head is pointed to.
CharNode* CharQueue::getHead(){
    if(isEmpty()){
        return nullptr;
    }else{
        return head;
    }
    
}

//Sets the score for the queue. It takes an int as score to be set, and returns nothing.
void CharQueue::setScore(int scoreInput){
    score = scoreInput;
}

//Gets the score of the queue. It takes no argument and returns the score as an int.
int CharQueue::getScore(){
    return score;
}