/**********************************
** Program Name: Character.cpp
** Author: Miao Pan
** Date: 02/04/2019
** Description: This is the implementation file for the Character class.
**********************************/

#include "Character.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor
Character::Character(){
    
    attack = " ";
    defense = " ";
    armour = 0;
    strengthPoints = 0;
    givenName = "no name given yet";
}


string Character::getAttack(){
    
    return attack;
}

string Character::getDefense(){
    return defense;
}

int Character::getArmour(){
    return armour;
}

int Character::getStrengthPoints(){
    return strengthPoints;
}

//This will let the characters roll dices. It takes in 2 int as argument (the number of dices, and how large the dice is), and will return the rolled number in the form of int.
int Character::rollDice(int numberOfDice, int diceSize){
    int diceTotal = 0;
    int diceRoll = 0;
    for(int i = 0; i < numberOfDice; i++){
        diceRoll = (rand()%(diceSize - 1 + 1)) + 1;
        //cout << "---Rolling dice, instance " << i+1 << " of total " << numberOfDice << ". Rolled dice to " << diceRoll << " out of " << diceSize << "." << endl;
        diceTotal += diceRoll;
    }
    cout << "points: " << diceTotal << endl;
    return diceTotal;
    
}

//This checks if the character is still alive or dead. It takes in no arguments, and will return true if dead, and false if alive.
bool Character::isDead(){
    if(strengthPoints<=0){
        //cout << "Strength points: " << strengthPoints << endl;
        //cout << "Dead" << endl;
        return true;
    }else{
        //cout << "Strength points: " << strengthPoints << endl;
        return false;
    }
}

//This will return a string which is the name of the character.
string Character::getName(){
    return "Character";
}

int Character::randomHeal(){
    cout << "To head" << endl;
    return 0;
    
}

string Character::getGivenName(){
    return givenName;
}

void Character::setGivenName(string userNameInput){
    givenName = userNameInput;
}
//int Character::attacking() = 0;
//int Character::defensing() = 0;
