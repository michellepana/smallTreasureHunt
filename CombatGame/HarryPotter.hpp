/**********************************
** Program Name: HarryPotter.hpp
** Author: Miao Pan
** Date: 02/05/2019
** Description: This is the declaration file for the HarryPotter class. It inherits from the Character class. Harry Potter has a special ability called Hogwarts, which let him come back to life after being dead once.
**********************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Character.hpp"
#include <string>
using std::string;

class HarryPotter: public Character{
    
    private:
        int deadTimes;
        
    public:
        HarryPotter();
        virtual int attacking();
        virtual int defensing(int);
        virtual int rollDice(int, int);
        virtual string getName();
        virtual int randomHeal();
};




#endif