/**********************************
** Program Name: Elixir.hpp
** Author: Miao Pan
** Date: 03/13/2019
** Description: This is the declaration file for the Elixir class. It inherits from the Space class. Elixir has special ability to heal some HP of the playe.
**********************************/

#ifndef Elixir_HPP
#define Elixir_HPP
#include "Space.hpp"

class Elixir: public Space{
    
    private:
        int restoreAbility;
        
    public:
        Elixir(int, int);
        Elixir(int, int, Space*, Space*, Space*, Space* );
        virtual string getType();
        virtual int interact();
        
        int getRestoreAbility();
};




#endif