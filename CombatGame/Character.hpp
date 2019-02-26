/**********************************
** Program Name: Character.hpp
** Author: Miao Pan
** Date: 02/04/2019
** Description: This is the declaration file for the Character Class. This is an abstract class.
*               It has protected members of attack, defense, armour and strength points. It will also execute the attack and defense methods, as well as assert strength points and if the character is still alive.
**********************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>

using std::string;

class Character{
    
    protected:
        string attack;
        string defense;
        int armour;
        int strengthPoints;
        string givenName;
        
    public:
        Character();
        string getAttack();
        string getDefense();
        int getArmour();
        int getStrengthPoints();
        int setStrengthPoints(int);
        virtual int attacking()=0;
        virtual int defensing(int)=0;
        virtual string getName();
        virtual bool isDead();
        virtual int rollDice(int, int);
        virtual int randomHeal();
        void setGivenName(string);
        string getGivenName();
    
    
};


#endif

