/**********************************
** Program Name: Barbarian.hpp
** Author: Miao Pan
** Date: 02/05/2019
** Description: This is the declaration file for the Babarian class. It inherits from the Character class.
**********************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include <iostream>
#include "Character.hpp"
using std::string;

class Barbarian: public Character{
    
    public:
        Barbarian();
        virtual int attacking();
        virtual int defensing(int);
        virtual int rollDice(int, int);
        virtual string getName();
        virtual int randomHeal();
 
    

    
    
};





#endif
