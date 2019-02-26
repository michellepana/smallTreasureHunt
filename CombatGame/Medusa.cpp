/**********************************
** Program Name: Medusa.cpp
** Author: Miao Pan
** Date: 02/04/2019
** Description: This is the implementation file for the Medusa class.
**********************************/

#include "Medusa.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor
Medusa::Medusa():Character(){
        
    attack = "2d6";
    defense = "1d6";
    armour = 3; 
    strengthPoints = 8;
}

//Attack function. Takes no argument and returns an int as the attacked points.
//Special ability included here. If Medusa attackes with 12 points, opponent is stoned to death.
int Medusa::attacking(){

    if(strengthPoints > 0){
        //cout << "============Medusa attacking~~~~~~@@@@@@@------$$$$$^^^^^^^^^" <<endl;
        int attackOutput = 0;
        attackOutput = rollDice(2,6);
        //cout << "---The Medusa attacked " << attackOutput << " HP!" << endl;
        if(attackOutput < 12){
            return attackOutput;
        }else if(attackOutput == 12){
            cout << "MEDUSA GLARE!!! The target instantly gets turned into STONE!" << endl;
            return 1000;
        }
        
    }else if(strengthPoints <= 0){
        cout << "The Medusa is already dead. Cannot attack anymore." << endl;
        return 0;
    }   
}

//Defense function. It takes in an integer as argument (The point with which it will be attacked), updates it's strengthpoints according, and returns the updated strengthpoints.
int Medusa::defensing(int attackedHP){
    //If there were no attacks
    if(attackedHP <= 0){
        cout << "No attack detected, therefore no defense needed. "  << endl;
        return strengthPoints;
    }else if(attackedHP > 0){
        if(strengthPoints > 0){
            //cout << "==========Medusa defensing=========" <<endl;
            //cout << "HP: " << strengthPoints << ",  Armour: " << armour << endl;
            if(attackedHP == 1000){
                cout << "OH NO! Turned into stone immediately!" <<endl;
                strengthPoints = 0;
                return 0;
            }else{
                int defenseOutput = rollDice(1,6);
            
                int impact = attackedHP - defenseOutput - armour;
                //cout << "Impact = " << attackedHP << " - " << defenseOutput << " - " << armour << " = " << impact << endl;
                if(impact >=0){
                        
                    strengthPoints = strengthPoints -  impact;
                    cout << givenName << " Updated HP: " << strengthPoints << endl;
                }else if(impact < 0){
                    //cout << "Attack is all defensed. Not losing HP this time!" << endl;
                    cout << givenName << " Updated HP (unharmed): " << strengthPoints << endl;
                }
                return strengthPoints;
            }
            
        }else if(strengthPoints <= 0){
            cout << "The Medusa is already dead. Cannot defend anymore." << endl;
            return strengthPoints;;
        }
    }
    
    
}

//Roll dice function. Takes in 2 int arguments as dice number and size, and returns an int which is the number rolled out.
int Medusa::rollDice(int number, int size){
    //cout << "Medusa rolling dice..." <<endl;
    Character::rollDice(number, size);
}


string Medusa::getName(){
    return "Medusa";
}

int Medusa::randomHeal(){
    cout << "               " << givenName << " current strengh points: " << strengthPoints << endl;
    if(strengthPoints == 8){
        cout << "               Medusa didn't get hurt, no need to heal" << endl;
        return strengthPoints;
    }else{
        //cout << "Healing..." << endl;
        int newHP = (rand()%(8 - strengthPoints-1 + 1)) + strengthPoints+1;
        strengthPoints = newHP;
        cout << "               Healed strengthPoints: " << strengthPoints << endl;
        return strengthPoints;
    }
    
    
}