/**********************************
** Program Name: Space.hpp
** Author: Miao Pan
** Date: 03/06/2019
** Description: This is the declaration file for the Space Class. This is an abstract class.
*               It has protected members of 4 space pointers (top/bottom/left/right), a type name, 2 integers to indicate it's row and col, and a bool indicating whether this space is hidden or not.
*               It will also execute multiple get functions, a function to set the space's surroundings and an interact function, which is a pure virtual function.
**********************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>

using std::string;

class Space{
    
    protected:
        string typeName;
        Space* top;
        Space* bottom;
        Space* left;
        Space* right;
        //char value;
        int row;
        int col;
        bool hidden;
        
    public:
        Space(int, int);
        Space(int, int, Space*, Space*, Space*, Space* );
        void setSurroundings(Space*, Space*, Space*, Space* );
        virtual string getType();
        virtual int interact() = 0;
        int getRow();
        int getCol();
        bool getHidden();
        
        Space* getRight();
        Space* getLeft();
        Space* getTop();
        Space* getBottom();
        
    
    
};


#endif

