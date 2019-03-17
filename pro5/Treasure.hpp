/**********************************
** Program Name: Treasure.hpp
** Author: Miao Pan
** Date: 03/13/2019
** Description: This is the declaration file for the Treasure class. It inherits from the Space class. Treasure has special ability give player 1 - 4 treasure during interaction.
**********************************/

#ifndef TREASURE_HPP
#define TREASURE_HPP
#include "Space.hpp"

class Treasure: public Space{
    
    private:
        //int count;
        
    public:
        Treasure(int, int);
        Treasure(int, int, Space*, Space*, Space*, Space* );
        virtual string getType();
        virtual int interact();
        
        //int getCount();
        //void setCount(int);
};




#endif