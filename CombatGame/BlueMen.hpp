/**********************************
** Program Name: BlueMen.hpp
** Author: Miao Pan
** Date: 02/05/2019
** Description: This is the declaration file for the BlueMen class. It inherits from the Character class. Blue Men has special defense ability of Mob.
**********************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Character.hpp"

class BlueMen: public Character{
    
    public:
        BlueMen();
        virtual int attacking();
        virtual int defensing(int);
        virtual int rollDice(int, int);
        virtual string getName();
        virtual int randomHeal();
};




#endif