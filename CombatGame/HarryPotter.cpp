/**********************************
** Program Name: HarryPotter.cpp
** Author: Miao Pan
** Date: 02/04/2019
** Description: This is the implementation file for the HarryPotter class.
**********************************/

#include "HarryPotter.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor
HarryPotter::HarryPotter():Character(){
        
    attack = "2d6";
    defense = "2d6";
    armour = 0; 
    strengthPoints = 10;
    deadTimes = 0;
}

//Attack function, it takes no argument and returns an integer as the attacked points.
int HarryPotter::attacking(){
    
    if(strengthPoints > 0){
        //cout << "============~~~Harry Potter attacking~~~~~~@@@@@@@------$$$$$^^^^^^^^^" <<endl;
        int attackOutput = 0;
        attackOutput = rollDice(2,6);
        //cout << "---Harry Potter attacked " << attackOutput << " HP!" << endl;
        return attackOutput;
    }else if(strengthPoints <= 0){
        cout << "Harry Potter is already dead. Cannot attack anymore." << endl;
        return 0;
    }   
    
}

//Defense function. It takes in an integer as argument (The point with which it will be attacked), updates it's strengthpoints according, and returns the updated strengthpoints.
int HarryPotter::defensing(int attackedHP){
    //If there were no attacks
    if(attackedHP <= 0){
        cout << "No attack detected, therefore no defense needed. "  << endl;
        return strengthPoints;
    }else if(attackedHP > 0){
        //If there are attacks and Harry Potter is still alive
        if(strengthPoints > 0){
            //cout << "==========Harry Potter defensing=========" <<endl;
            //cout << "HP: " << strengthPoints << ",  Armour: " << armour << endl;
            //If it's Medusa Glare, dies immediately
            if(attackedHP == 1000){
                cout << "OH NO! Turned into stone immediately!" <<endl;
                strengthPoints = 0;
                //If this is Harry Potter's first time being dead, comes back to life with doubled strength
                if(deadTimes == 0){
                    cout << "But it's Harry Potter! He came back to life with doubled strength!" << endl;
                    deadTimes = 1;
                    strengthPoints = 20;
                //If Harry Potter was dead once before, then he cannot come back to life again.
                }else if(deadTimes == 1){
                    cout << "Nothing can save Harry Potter this time. He is dead dead." << endl;
                    strengthPoints = 0;
                }
                return strengthPoints;
            //Else if it's a normal attack
            }else{
                int defenseOutput = 0;
                defenseOutput = rollDice(2,6);
                //Calculate attack impact
                int impact = attackedHP - defenseOutput - armour;
                //cout << "Impact = " << attackedHP << " - " << defenseOutput << " - " << armour << " = " << impact << endl;
                if(impact >=0){
                        
                    strengthPoints = strengthPoints -  impact;
                    cout << givenName << " Updated HP: " << strengthPoints << endl;
                    if(strengthPoints <= 0 and deadTimes == 0){
                        cout << "Harry Potter is dead but he has been brought back to life with doubled strength points!!" << endl;
                        deadTimes = 1;
                        strengthPoints = 20;
                    }
                    return strengthPoints;
                }else if(impact < 0){
                    //cout << "Attack is all defensed. Not losing HP this time!" << endl;
                    cout << givenName << " Updated HP (unharmed): " << strengthPoints << endl;
                }
                return strengthPoints;
            }
            
            
        }else if(strengthPoints <= 0){
            cout << "Harry Potter is already dead. Cannot defend anymore." << endl;
            return strengthPoints;
        }
    }
    
}

//Roll dice function. Takes in 2 int arguments as dice number and size, and returns an int which is the number rolled out.
int HarryPotter::rollDice(int number, int size){
    //cout << "HarryPotter rolling dice..." <<endl;
    Character::rollDice(number, size);
}

string HarryPotter::getName(){
    return "Harry Potter" ;
}

int HarryPotter::randomHeal(){
    cout << "               " << givenName << " current strengh points: " << strengthPoints << endl;
    if(deadTimes == 0 and strengthPoints == 10){
        cout << "               Didn't get hurt, no need to heal." << endl;
        return strengthPoints;
    }else if(deadTimes == 1 and strengthPoints == 20){
        cout << "               Didn't get hurt, no need to heal." << endl;
        return strengthPoints;
    }else{
        //cout << "Healing..." << endl;
        
        int newHP;
        if(deadTimes == 0){
            newHP = (rand()%(10 - strengthPoints-1 + 1)) + strengthPoints+1;
        }else if(deadTimes == 1){
            newHP = (rand()%(20 - strengthPoints-1 + 1)) + strengthPoints+1;
        }
        
        strengthPoints = newHP;
        cout << "               Healed strengthPoints: " << strengthPoints << endl;
        return strengthPoints;
    }
    
    
}
