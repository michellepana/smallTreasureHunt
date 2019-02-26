/**********************************
** Program Name: Barbarian.cpp
** Author: Miao Pan
** Date: 02/04/2019
** Description: This is the implementation file for the Barbarian class.
**********************************/

#include "Barbarian.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor
Barbarian::Barbarian():Character(){
    
    attack = "2d6";
    defense = "2d6";
    armour = 0; 
    strengthPoints = 12;
    
}

//Attack function, it takes no argument and returns an integer as the attacked points.
int Barbarian::attacking(){
    //If it's still alive, then attack
    if(strengthPoints > 0){
        //cout << "============Barbarian attacking~~~~~~@@@@@@@------$$$$$^^^^^^^^^" <<endl;
        int attackOutput = 0;
        attackOutput = rollDice(2,6);
        //cout << "---The Barbarian attacked " << attackOutput << " HP!" << endl;
        return attackOutput;
    }else if(strengthPoints <= 0){
        cout << "The Barbarian is already dead. Cannot attack anymore." << endl;
        return 0;
    }
    
}

//Defense function. It takes in an integer as argument (The point with which it will be attacked), updates it's strengthpoints according, and returns the updated strengthpoints.
int Barbarian::defensing(int attackedHP){
    //If there were no attacks
    if(attackedHP <= 0){
        cout << "No attack detected, therefore no defense needed. "  << endl;
        return strengthPoints;
    }else if(attackedHP > 0){
        //If it's still alive
        if(strengthPoints > 0){
            //cout << "==========Barbarian defensing=========" <<endl;
            //cout << "HP: " << strengthPoints << ",  Armour: " << armour << endl;
            //If attacked by Medusa Glare, dies immediately
            if(attackedHP == 1000){
                cout << "OH NO! Turned into stone immediately!" <<endl;
                strengthPoints = 0;
                return 0;
            }else{
                int defenseOutput = rollDice(2,6);
            
                int impact = attackedHP - defenseOutput - armour;
                //cout << "Impact = " << attackedHP << " - " << defenseOutput << " - " << armour << " = " << impact << endl;
                if(impact >=0){
                        
                    strengthPoints = strengthPoints -  impact;
                    cout << givenName << " Updated HP: " << strengthPoints << endl;
                }else if(impact <= 0){
                    //cout << "Attack is all defensed. Not losing HP this time!" << endl;
                    cout << givenName << " Updated HP (unharmed): " << strengthPoints << endl;
                }
                return strengthPoints;
            }
            
        }else if(strengthPoints <= 0){
            cout << "The Barbarian is already dead. Cannot defend anymore." << endl;
            return strengthPoints;;
        }
    }
    
    
}

//Roll dice function. Takes in 2 int arguments as dice number and size, and returns an int which is the number rolled out.
int Barbarian::rollDice(int number, int size){
    //cout << "Barbarian rolling dice..." <<endl;
    Character::rollDice(number, size);
}

string Barbarian::getName(){
    return "Barbarian";
}

int Barbarian::randomHeal(){
    cout << "               " << givenName << " current strengh points: " << strengthPoints << endl;
    if(strengthPoints == 12){
        cout << "               Didn't get hurt, no need to heal" << endl;
        return strengthPoints;
    }else{
        //cout << "Healing..." << endl;
        int newHP = (rand()%(12 - strengthPoints -1 + 1)) + strengthPoints+1;
        strengthPoints = newHP;
        cout << "                Healed strengthPoints: " << strengthPoints << endl;
        return strengthPoints;
    
    }
    
}