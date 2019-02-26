/**********************************
** Program Name: Medusa.hpp
** Author: Miao Pan
** Date: 02/05/2019
** Description: This is the declaration file for the Medusa class. It inherits from the Character class. Medusa has a special ability called Glare, it activates when Medusa attacks with 12 points. Opponent will be stoned to death immediately.
**********************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Character.hpp"
#include <string>
using std::string;

class Medusa: public Character{
    
    public:
        Medusa();
        virtual int attacking();
        virtual int defensing(int);
        virtual int rollDice(int, int);
        virtual string getName();
        virtual int randomHeal();
};




#endif