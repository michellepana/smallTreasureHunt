#include <iostream>
#include <string>
#include "menu.cpp"
#include "Board.cpp"
#include "Ant.cpp"


using std::cout;
using std::cin;
using std::endl;



//Function prototypes


//main function
int main(){
    
    State gameState = newGame;
    //gameState = finished;
    //Orientation antO = North;
    
  while (gameState == newGame or gameState == finished){  
    int* menuAnswer = menu(gameState);
    for (int i= 0; i<5; i++){
        cout << "menuAnswer: " << menuAnswer[i] << endl;
    }
    
    //Board newBoard(menuAnswer[0], menuAnswer[1]);
    //newBoard.printBoard();
   
     //Ant ant1(menuAnswer[3], menuAnswer[4] );
     ////cout << ant1.getAntCol() << endl;
     //ant1.moveAnt();
    
    int first = menuAnswer[0];
    first = static_cast<int>(first);
    cout << "first is " << first << endl;
    if (first != 0){
    cout << "Now making the game board" << endl;
    Board newBoard(menuAnswer[0], menuAnswer[1]);
    newBoard.printBoard();
    Ant ant1(menuAnswer[3], menuAnswer[4], menuAnswer[0], menuAnswer[1]);
    cout << " and row: " << ant1.getAntRow() << endl;
    cout << " ant col: " << ant1.getAntCol() << endl;
    //cout << " ant orient: " << ant1.getAntOrient() << endl;
    //cout << "ant turn right: " << ant1.turnRight() << endl;
    //cout << "ant turn right: " << ant1.turnRight() << endl;
    //cout << "ant turn right: " << ant1.turnRight() << endl;
    //cout << "ant turn right: " << ant1.turnRight() << endl;
    //cout << "ant turn right: " << ant1.turnRight() << endl;
    
    
        cout << "this should get the ant position value" << endl;
        cout << "menuAnswer3: " << menuAnswer[3] << endl;
         cout << "menuAnswer4: " << menuAnswer[4] << endl;
     
     cout << "board row from ant class" << ant1.getBoardRow() << endl;
     cout << "board col from ant class" << ant1.getBoardCol() << endl;
    
    char currentAntValue = newBoard.getValue(ant1.getAntRow(), ant1.getAntCol()); 
    int stepNumber = menuAnswer[2];
    for(int i = 0; i < stepNumber; i++){    
        cout << "Iterating instance " << i << endl;
        
        cout << currentAntValue << " is current ant value" << endl;
        if(currentAntValue == ' '){
            cout << ant1.getAntOrient() << endl;
            //Ant turn right
            cout << ant1.turnRight() << endl;
            //Ant change the space from white to black'#'
            newBoard.setValue(ant1.getAntRow(), ant1.getAntCol(), '#');
            //Ant moves forward
            ant1.moveAnt();
            //ant1.setAntRow(4);
            //ant1.setAntCol(5);
            cout << "new ant row: " << ant1.getAntRow() << endl;
            cout << "new ant col: " << ant1.getAntCol() << endl;
            //Update board with new ant position
            cout << "before changing to *, this space was " << newBoard.getValue(ant1.getAntRow(), ant1.getAntCol()) << endl;
            currentAntValue = newBoard.getValue(ant1.getAntRow(), ant1.getAntCol());
            newBoard.setValue(ant1.getAntRow(), ant1.getAntCol(), '*');
            cout << "the cell is now *, but before it was changed, it was " << currentAntValue << endl;
            //newBoard.printBoard();
        }else if(currentAntValue == '#'){
            //Turn ant left
            ant1.turnLeft();
            //Ant change the space from black'#' to white'-';
            newBoard.setValue(ant1.getAntRow(), ant1.getAntCol(), ' ');
            //Ant moves forward
            ant1.moveAnt();
            cout << "before changing to *, this space was " << newBoard.getValue(ant1.getAntRow(), ant1.getAntCol()) << endl;
            currentAntValue = newBoard.getValue(ant1.getAntRow(), ant1.getAntCol());
            //Change the cell the ant is on to *
            newBoard.setValue(ant1.getAntRow(), ant1.getAntCol(), '*');
           
            
        }else{
            cout << "something went rong!!!!" << endl;
            cout << "this is iteration instance " << i << endl;
        }
        newBoard.printBoard();
    }
    
     newBoard.printBoard();
     gameState = finished;
    
    /*
    menuChoice = menu(gameState);
    if(menuChoice == 1 and gameState == newGame){
        cout << "Welcome!" << endl;
        
        Board newBoard;
        //newBoard.printBoard();
        cout << "Getting the value" << endl;
        cout << newBoard.getValue(1,1) << endl;
        
    }else if(menuChoice == 1 and gameState == finished){
        cout << "Great! Let's play again!" << endl;
    } else if (menuChoice == 2){
        cout << "See you next time, Bye!" << endl;
        return 0;
    }
    */
    
    //deallocating menuAnswer array
    delete[] menuAnswer;
    menuAnswer = nullptr;
    
    }
    cout << gameState << " this is gameState. " << endl;
  }

   cout << gameState << " this is gameState. " << endl; 
    return 0;
}

