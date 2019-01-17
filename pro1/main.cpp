/**********************************
** Program Name: main.cpp
** Author: Miao Pan
** Date: 01/13/2019
** Description: This is the main function of the Langton's Ant game. 
**********************************/

#include <iostream>
#include <string>
#include "menu.cpp"
#include "Board.cpp"
#include "Ant.cpp"


using std::cout;
using std::cin;
using std::endl;



//main function
int main(){
    
    State gameState = newGame;
    
    while (gameState == newGame or gameState == finished){  
        int* menuAnswer = menu(gameState);
        int first = menuAnswer[0];
        
        if (first != 0){
            //Print out the user input from menu
            for (int i= 0; i<5; i++){
                cout << "menuAnswer: " << menuAnswer[i] << endl;
            }
            cout << "Now making the game board" << endl;
            //Create the board
            Board newBoard(menuAnswer[0], menuAnswer[1]);
            newBoard.printBoard();
            //Create the ant
            Ant ant1(menuAnswer[3], menuAnswer[4], menuAnswer[0], menuAnswer[1]);
            
            //Get the cell value of where the ant is sitting on
            char currentAntValue = newBoard.getValue(ant1.getAntRow(), ant1.getAntCol()); 
            int stepNumber = menuAnswer[2];
            if(stepNumber == 0){
                newBoard.setValue(ant1.getAntRow(), ant1.getAntCol(), '*');
                newBoard.printBoard();
            }
            for(int i = 0; i < stepNumber; i++){    
                cout << "Iterating instance " << i << endl;
        
                if(currentAntValue == ' '){
                    //cout << ant1.getAntOrient() << endl;
                    //Ant turn right
                    cout << ant1.turnRight() << endl;
                    //Ant change the space from white to black'#'
                    newBoard.setValue(ant1.getAntRow(), ant1.getAntCol(), '#');
                    //Ant moves forward
                    ant1.moveAnt();
                    //Update board cell value to * with new ant position, but before updating, get the original cell value
                    currentAntValue = newBoard.getValue(ant1.getAntRow(), ant1.getAntCol());
                    newBoard.setValue(ant1.getAntRow(), ant1.getAntCol(), '*');
                    cout << "the cell is now *, but before it was changed, it was " << currentAntValue << endl;
                    
                }else if(currentAntValue == '#'){
                    //Turn ant left
                    ant1.turnLeft();
                    //Ant change the space from black'#' to white' ';
                    newBoard.setValue(ant1.getAntRow(), ant1.getAntCol(), ' ');
                    //Ant moves forward
                    ant1.moveAnt();
                    //Update board cell value to * with new ant position, but before updating, get the original cell value
                    cout << "before changing to *, this space was " << newBoard.getValue(ant1.getAntRow(), ant1.getAntCol()) << endl;
                    currentAntValue = newBoard.getValue(ant1.getAntRow(), ant1.getAntCol());
                    newBoard.setValue(ant1.getAntRow(), ant1.getAntCol(), '*');
           
                }else{
                    cout << "something went rong!!!!" << endl;
                    cout << "this is iteration instance " << i << endl;
                }
                //Print the board after each step
                newBoard.printBoard();
            }
    
            gameState = finished;
    

        }
        else if(first == 0){
            gameState = noMore;
        
        }
        
       //deallocating menuAnswer array
       delete[] menuAnswer;
        menuAnswer = nullptr;
    }

    cout << "Thanks for your time! See you next time!" << endl; 
   
    return 0;
}

