/**********************************
** Program Name: Bomb.hpp
** Author: Miao Pan
** Date: 03/13/2019
** Description: This is the declaration file for the Bomb class. It inherits from the Space class. Bomb has special ability to damange palyer HP and mob them of one treasure.
**********************************/

#ifndef BOMB_HPP
#define BOMB_HPP
#include "Space.hpp"

class Bomb: public Space{
    
    private:
        int damage;
        
    public:
        Bomb(int, int);
        Bomb(int, int, Space*, Space*, Space*, Space* );
        virtual string getType();
        virtual int interact();
        
        int getDamage();
       
};




#endif