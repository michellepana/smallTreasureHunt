/**********************************
** Program Name: Vampire.cpp
** Author: Miao Pan
** Date: 02/04/2019
** Description: This is the implementation file for the Vampire class.
**********************************/

#include "Vampire.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Constructor
Vampire::Vampire() : Character(){
    
        
    attack = "1d12";
    defense = "1d6";
    armour = 1; 
    strengthPoints = 18;

}

//Attack function. Takes no argument and returns an int as the attacked points.
int Vampire::attacking(){
    if(strengthPoints > 0){
        //cout << "============Vampire attacking~~~~~~@@@@@@@------$$$$$^^^^^^^^^" <<endl;
        int attackOutput = 0;
        attackOutput = rollDice(1,12);
        //cout << "---The vampire attacked " << attackOutput << " HP!" << endl;
        return attackOutput; 
    }else if(strengthPoints <= 0){
        cout << "The Vampire is already dead. Cannot attack anymore." << endl;
        return 0;
    }
    
}

//Defense function. It takes in an integer as argument (The point with which it will be attacked), updates it's strengthpoints according, and returns the updated strengthpoints.
//Special ability Charm included here
int Vampire::defensing(int attackedHP){
    //If there were no attacks
    if(attackedHP <= 0){
        cout << "No attack detected, therefore no defense needed. "  << endl;
        return strengthPoints;
    }else if(attackedHP > 0){
        if(strengthPoints > 0){
           // cout << "==========Vampire defensing=========" <<endl;
            //cout << "HP: " << strengthPoints << ",  Armour: " << armour << endl;
            
            int defenseOutput = rollDice(1,6);
            //int defenseOutput = 6;
            int impact = attackedHP - defenseOutput - armour;
            if(defenseOutput < 6){
                    //If Medusa Glare, turns into stone immediately
                    if(attackedHP == 1000){
                        
                        cout << "OH NO! Turned into stone immediately!" <<endl;
                        strengthPoints = 0;
                    }else if(impact > 0){
                        
                        //cout << "Impact = " << attackedHP << " - " << defenseOutput << " - " << armour << " = " << impact << endl;
                        strengthPoints = strengthPoints -  impact;
                        cout << givenName << " Updated HP: " << strengthPoints << endl;
                    }
                        
                    else if(impact < 0){
                        cout << "Attack is all defensed. Not losing HP this time!" << endl;
                    }
            //If Vampire defense with 6, may activate Charm ability
            }else if(defenseOutput == 6){
                    int randomInt = (rand()%( 2 - 1 + 1)) + 1;
                    //50% chance does not acitvate Charm. Game flows as normal
                    if(randomInt == 1){
                        //cout << "Rolled a 6 but did not activate Charm" <<endl;
                        impact = attackedHP - defenseOutput - armour;
                        if(attackedHP == 1000){
                        
                            cout << "OH NO! Turned into stone immediately!" <<endl;
                            strengthPoints = 0;
                        }else if(impact >= 0){
                            //int impact = attackedHP - defenseOutput - armour;
                            //cout << "Impact = " << attackedHP << " - " << defenseOutput << " - " << armour << " = " << impact << endl;
                            strengthPoints = strengthPoints -  impact;
                            cout << givenName << " Updated HP: " << strengthPoints << endl;
                        }
                            
                        else if(impact < 0){
                            cout << "Attack is all defensed. Not losing HP this time!" << endl;
                        }
                    //50% chance activating Charm. No attack damage will be taken!
                    }else if(randomInt == 2){
                        cout << "Vampire Charmed the opponent into NOT attacking! No damage taken!" << endl;
                    }
                }
            return strengthPoints;
            
           
        }else if(strengthPoints <=0){
            cout << "Vampire is already dead. Cannot defend anymore." << endl;
            return strengthPoints;
        }
    }
    
    
    
}

//Roll dice function. Takes in 2 int arguments as dice number and size, and returns an int which is the number rolled out.
int Vampire::rollDice(int number, int size){
    //cout << "Vampire rolling dice..." <<endl;
    Character::rollDice(number, size);
}

string Vampire::getName(){
    return "Vampire";
}

int Vampire::randomHeal(){
    cout << "               " << givenName << " current strengh points: " << strengthPoints << endl;
    if(strengthPoints == 18){
        cout << "               Vampire didn't get hurt, no need to heal" << endl;
        return strengthPoints;
    }else{
        //cout << "Healing..." << endl;
        int newHP = (rand()%(18 - strengthPoints-1 + 1)) + strengthPoints+1;
        strengthPoints = newHP;
        cout << "               Healed strengthPoints: " << strengthPoints << endl;
        return strengthPoints;
    }
    
    
}