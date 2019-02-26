/**********************************
** Program Name: BlueMen.cpp
** Author: Miao Pan
** Date: 02/04/2019
** Description: This is the implementation file for the BlueMen class.
**********************************/

#include "BlueMen.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor
BlueMen::BlueMen():Character(){
        
    attack = "2d10";
    defense = "3d6";
    armour = 3; 
    strengthPoints = 12;
}

//Attack function. Takes no argument and returns an int as the attacked points.
int BlueMen::attacking(){
    //If it's alive, attack
    if(strengthPoints > 0){
        //cout << "============Blue Men attacking~~~~~~@@@@@@@------$$$$$^^^^^^^^^" <<endl;
        int attackOutput = 0;
        attackOutput = rollDice(2,10);
        //cout << "---The Blue Men attacked " << attackOutput << " HP!" << endl;
        return attackOutput;
    //If it's already dead
    }else if(strengthPoints <= 0){
        cout << "The Blue Men is already dead. Cannot attack anymore." << endl;
        return 0;
    }   
    
}

//Defense function. It takes in an integer as argument (The point with which it will be attacked), updates it's strengthpoints according, and returns the updated strengthpoints.
//Special ability Mob included here
int BlueMen::defensing(int attackedHP){
    //If there were no attacks
    if(attackedHP <= 0){
        cout << "No attack detected, therefore no defense needed. "  << endl;
        return strengthPoints;
    }else if(attackedHP > 0){
        //If there are attacks and blue men is still alive
        if(strengthPoints > 0){
            //cout << "==========Blue Men defensing=========" <<endl;
            //cout << "HP: " << strengthPoints << ",  Armour: " << armour << endl;
            //If it's Medusa Glare
            if(attackedHP == 1000){
                cout << "OH NO! Turned into stone immediately!" <<endl;
                strengthPoints = 0;
                return 0;
            //Else, defense strength level goes down with strength points
            }else{
                int defenseOutput = 0;
          
                if(strengthPoints > 8){
                    defenseOutput = rollDice(3,6);
                }else if(strengthPoints > 4 and strengthPoints <=8){
                    defenseOutput = rollDice(2,6);
                }else if(strengthPoints >0 and strengthPoints <= 4){
                    defenseOutput = rollDice(1,6);
                }
                
                //Calculate attack impact
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
            cout << "The Blue Men is already dead. Cannot defend anymore." << endl;
            return strengthPoints;
        }
    }
    
    
}

//Roll dice function. Takes in 2 int arguments as dice number and size, and returns an int which is the number rolled out.
int BlueMen::rollDice(int number, int size){
    //cout << "BlueMen rolling dice..." <<endl;
    Character::rollDice(number, size);
}


string BlueMen::getName(){
    return "Blue Men";
}

int BlueMen::randomHeal(){
    cout << "               " << givenName << " current strengh points: " << strengthPoints << endl;
    if(strengthPoints == 12){
        cout << "               Didn't get hurt, no need to heal" << endl;
        return strengthPoints;
    }else{
        //cout << "Healing..." << endl;
        int newHP = (rand()%(12 - strengthPoints-1 + 1)) + strengthPoints+1;
        strengthPoints = newHP;
        cout << "               Healed strengthPoints: " << strengthPoints << endl;
        return strengthPoints;
    }
    
    
}