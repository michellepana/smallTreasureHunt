/**********************************
** Program Name: Player.cpp
** Author: Miao Pan
** Date: 02/04/2019
** Description: This is the implementation file for the BlueMen class.
**********************************/

#include "Player.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor
Player::Player(string nameInput, Board* bPtr){
    
    name = nameInput;
    items = new queue<string>;
    itemsLimit = 6;
    itemsTotal = 0;
    steps = 0;
    strength = 100;
    where = bPtr->getPosition();
    
}

Player::~Player(){
    delete items;
    items = nullptr;
}

int Player::getSteps(){
    return steps;
}

int Player::getStrength(){
    return strength;
}

Space* Player::getWhere(){
    return where;
}

int Player::addStrength(int input){
    strength += input;
    return strength;
}

int Player::minusStrength(int input){
    strength -= input;
    return strength;
}

void Player::addItem(string treasure){
    if(items->size() < itemsLimit){
        itemsTotal += 1;
        items->push(treasure);
    }else if(items->size() >= itemsLimit){
        cout << "Already reached items capacity limit. Don't have room to hold more items." << endl;
    }
    
}

void Player::minusItem(){
    if(!items->empty()){
        items->pop();
    }else{
        cout << "Not carrying anything! Nothing to loose." << endl;
    }
}

int Player::getItemsCount(){
    return items->size();
}

void Player::displayItems(queue<string>* q){
    if(q->empty()){
        cout << "Bag is empty! Haven't found any treasures yet!" << endl;
    }
    queue<string>* temp = new queue<string>;
    *temp = *q;
    while (!temp->empty()){
        cout << temp->front() << " ";
        temp->pop();
    }
    cout << endl;
    //De-allocate the temp queue
    delete temp;
    temp = nullptr;
}

queue<string>* Player:: getItems(){
    return items;
}

int Player::getItemsTotal(){
    return itemsTotal;
}