/**********************************
** Program Name: main.cpp
** Author: Miao Pan
** Date: 03/12/2019
** Description: This is the main function of the Treasure Hunt game. 
**********************************/

#include <iostream>
#include <string>

/*
#include "Space.cpp"
#include "Bomb.cpp"
#include "Elixir.cpp"
#include "Treasure.cpp"
#include "Regular.cpp"
#include "Board.cpp"
#include "Player.cpp"
#include "Menu.cpp"
*/

#include "Space.hpp"
#include "Bomb.hpp"
#include "Elixir.hpp"
#include "Treasure.hpp"
#include "Regular.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Menu.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

//Prototypes
int getUserChoice(int, int);
string getString();

//Main function
int main(){
    
    //Seed the rand
    unsigned seed;
    seed = time(0);
    srand(seed);
    
    //Game start
    cout << "\n\n Welcome to the Treasure Hunt! \n" << endl;
    //Initiate a menu
    Menu aMenu;
    
    //Print out introduction menu options
    bool intro = true;
    while(intro){
        aMenu.printIntro();
        int introChoice = aMenu.getInt(1,3);
    
        if(introChoice == 1){
        cout << "\nWelcome! To WIN, you need: " << endl;
        cout << "1. to have a positive HP" <<endl;
        cout << "2. picked up 5 treasures." << endl;
        cout << "You can specify how many turns you can have. The less the turns, the harder it is to win.\n" << endl;
        cout << "The game board consists of 3*3 blocks. There are 4 kinds of blocks: " << endl;
        cout << "1. A Regular: indicated as 'R'. Regular blocks does nothing." << endl;
        cout << "2. A Bomb: indicated as 'B'. Bombs will cost you 25 HP and a treasure." << endl;
        cout << "3. An Elixir: indicated as 'E'. Elixir blocks will give you 20 HP." << endl;
        cout << "4. A Treasure: indicated as 'T'. Treasure blocks will have 1 - 4 treasures randomly." << endl;
        cout << "\nOther notes on blocks: " <<endl;
        cout << "1. You can choose to interact with the blocks or simply move to another block. " <<endl;
        cout << "2. Once you interact with the block, it will also reveal itself on the map, instead of showing '?' " << endl;
        cout << "3. You can interact with a block multiple times" << endl;
        cout << "4. The block in which you are in will be indicated with '*'" << endl;
        
        cout << "\nGame flow: " << endl;
        cout << "1. Enter how many turns you want to take. (You can enter up to 100, and you can abort any time in the middle.)" << endl;
        cout << "2. Move around the board and/or interact with the blocks. (Menu #3 - display items - will not count as a turn taken.)" <<endl;
        cout << "3. Game will not exit unless all turns are taken (or you chose to abort). Your HP may go below 0, but as long as you have enough turns left, you can make it positive again by getting Elixir." << endl;
        cout << "4. After all turns are taken, you will be evaluated if you won or lost." << endl;
        cout << "Note: Each move on the board will cost 10 HP. If you try to move out of boarder, you will not move but still cost 10 HP." << endl;
        cout << "Another Note: Player can hold up to 6 treasures." << endl;
        
        
        }else if(introChoice == 2){
            cout << "\nRevealing the secret map: " << endl;
            cout << " B E T" << endl;
            cout << " T R E" << endl;
            cout << " R B B\n" << endl;
            
        }else if(introChoice == 3){
            cout << "\n Great! GAME START! " << endl;
            cout << "You're starting at row 1, col 1\n" << endl;
            intro = false;
        }
    }

    //Actual game starts
    bool playAgain = true;
    while(playAgain){
        
        //Initiate a board
        Board* boardPtr = new Board();
        //Initiata a player
        Player* thePlayer = new Player("You", boardPtr);
        
        cout << "\nPlease let us know how many moves you want to make?" << endl;
        int stepsLeft = aMenu.getInt(1,100);
        int stepCount = 0;
        while(stepsLeft > 0){
            aMenu.printChoices();
            int uChoice = aMenu.getInt(1, 4);
            
            cout << " ---------- An Action ----------" << endl;
            //If user choose to interact
            if(uChoice == 1){
                stepsLeft -= 1;
                stepCount += 1;
                
                if(boardPtr->getPosition()->getType() == "Elixir"){
                    cout << "It's Elixir! " << endl;
                    //Gain HP
                    int points = boardPtr->getPosition()->interact();
                    cout << "---Current HP: " << thePlayer->getStrength() << endl;
                    thePlayer->addStrength(points);
                    cout << "---Updated HP: " <<thePlayer->getStrength() << endl;
                }else if(boardPtr->getPosition()->getType() == "Regular"){
                    cout << "This is a regular block. Nothing happens!" << endl;
                    boardPtr->getPosition()->interact();
                }else if(boardPtr->getPosition()->getType() == "Bomb"){
                    cout << "It's a bomb!" << endl;
                    //Loose HP
                    int bPoints = boardPtr->getPosition()->interact();
                    cout << "---Current HP: " << thePlayer->getStrength() << endl;
                    thePlayer->minusStrength(bPoints);
                    cout << "---Updated HP: " <<thePlayer->getStrength() << endl;
                    //Loose a treasure
                    cout << "Currently carrying " << thePlayer->getItemsCount() << " items." << endl;
                    thePlayer->minusItem();
                    cout << "After the bomb carrying " << thePlayer->getItemsCount() << " items." << endl;
                }else if(boardPtr->getPosition()->getType() == "Treasure"){
                    cout << "It's treasures!" << endl;
                    int tPoints = boardPtr->getPosition()->interact();
                    cout << "Yay! Found " << tPoints << " treasures!" << endl;
                    for (int i = 0; i< tPoints; i++){
                        thePlayer->addItem("Treasure-" + to_string(thePlayer->getItemsTotal()));
                    }
                    cout << "Now carrying " << thePlayer->getItemsCount() << " items." << endl;
                    thePlayer->displayItems(thePlayer->getItems());
                    //thePlayer->displayItems(thePlayer->getItems());
                    //cout << "Now carrying " << thePlayer->getItemsCount() << " items." << endl;
                }
            }
            //If user choose to move around
            else if(uChoice == 2){
                stepsLeft -= 1;
                stepCount += 1;
                aMenu.printMoves();
                int moveChoice = aMenu.getInt(1,4);
                if(moveChoice == 1){
                    cout << "Moving up" << endl;
                    boardPtr->moveUp();
                    boardPtr->printPosition();
                }else if(moveChoice == 2){
                    cout << "Moving down" << endl;
                    boardPtr->moveDown();
                    boardPtr->printPosition();
                }else if(moveChoice == 3){
                    cout << "Moving left" << endl;
                    boardPtr->moveLeft();
                    boardPtr->printPosition();
                }else if(moveChoice == 4){
                    cout << "Moving right" << endl;
                    boardPtr->moveRight();
                    boardPtr->printPosition();
                }
                cout << "---Moved! HP minus 10.";
                cout << " Current strength: " << thePlayer->minusStrength(10) << endl;
                
            }else if(uChoice == 3){
                //stepCount = stepCount;
                thePlayer->displayItems(thePlayer->getItems());
            }else if(uChoice ==4){
                stepsLeft = 0;
                stepCount += 1;
                cout << "Fast forwarding to result evaluation ---\n" << endl;
            }
            
            //Print the board
            boardPtr->printBoard();
            cout << " ----- That was Step #" << stepCount << " -- Steps left: " <<  stepsLeft << " -----\n" << endl;
        }
        
        cout << "\n ************** Result Board! ************** \n" << endl;
        cout << "              Health Points: " << thePlayer->getStrength() << endl;
        cout << "              Treasures in hand: " << thePlayer->getItemsCount() << endl;
        cout << endl;
        if(thePlayer->getStrength() >0 and thePlayer->getItemsCount() >=5 ){
            cout << "              Good Job! You WON!!!" << endl;
        }else if(thePlayer->getStrength() <= 0){
            cout << "Too bad, HP below 0. Mission unsuccessful." << endl;
        }else if(thePlayer->getItemsCount() < 5){
            cout << "Too bad, didn't collect enough treasure. Mission unsuccessful. " << endl;
        }
        cout << endl;
     
        //De-allocate memories
        delete boardPtr;
        boardPtr = nullptr;
        delete thePlayer;
        thePlayer = nullptr;
     
        aMenu.printPlayAgain();
        int userPAChoice = aMenu.getInt(1,2);
        if(userPAChoice == 1){
            cout << "YES! Let the adventure re-begin!" << endl;
        }else if(userPAChoice == 2){
            playAgain = false;
            cout << "Thanks for playing! See you next time!" << endl;
        }
    }
    
    
    cout << "Bye!" << endl;
    return 0;
}

