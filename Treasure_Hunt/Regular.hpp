/**********************************
** Program Name: Regular.hpp
** Author: Miao Pan
** Date: 03/13/2019
** Description: This is the declaration file for the Regular class. It inherits from the Space class. 
**********************************/

#ifndef REGULAR_HPP
#define REGULAR_HPP
#include "Space.hpp"

class Regular: public Space{
    
   
    public:
        Regular(int, int);
        Regular(int, int, Space*, Space*, Space*, Space* );
        virtual string getType();
        virtual int interact();
        
};




#endif