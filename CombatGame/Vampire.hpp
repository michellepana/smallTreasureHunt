/**********************************
** Program Name: Vampire.hpp
** Author: Miao Pan
** Date: 02/05/2019
** Description: This is the declaration file for the Vampire class. It inherits from the Character class.
*               Vampire has special defense ability of Charm. For a given attack there is a 50% chance that their opponent does not actually attack them.
**********************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Character.hpp"
#include <string>
using std::string;
class Vampire: public Character{
    
    
    public:
        Vampire();
        virtual int attacking();
        virtual int defensing(int);
        virtual int rollDice(int, int);
        virtual string getName();
        virtual int randomHeal();
};




#endif