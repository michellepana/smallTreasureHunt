/**********************************
** Program Name: main.cpp
** Author: Miao Pan
** Date: 02/05/2019
** Description: This is the main function of the Fantasy Combat game. It will allow you to create 2 teams to play against each other and display the score.
*               For each team, you may select team member number, team member type and their names. At the end of the game, you may choose to play again or exit.
**********************************/
#include <iostream>
#include <string>
//#include <stdio.h>
//#include <ctype.h>

#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "menu.hpp"
#include "CharNode.hpp"
#include "CharQueue.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Prototypes
int getUserChoice(int, int);
string getString();

//Main function
int main(){
    
    //Seed the time for random number generating
    unsigned seed;
    seed = time(0);
    srand(seed);
    
    State gameState = newGame;
    Character* player1;
    Character* player2;
    bool status = true;
 
    while(status){
        //If the game state is new game, then display this menu
        if(gameState == newGame){
            cout << "\n\n          Welcome to the Fantasy Combat Game!\n\n" <<endl;
            cout << "------ Please choose an option ------" <<endl;
            cout << "1. Play" <<endl;
            cout << "2. Exit" <<endl;
        //If the game state is finished, then display this menu
        }else if(gameState == finished){
            cout << "------ Please choose an option ------" <<endl;
            cout << "1. Play AGAIN" <<endl;
            cout << "2. Exit" <<endl;
        }

        int rootMenuChoice = getUserChoice(1,2);
        
        //If user chooses to play the game
        if(rootMenuChoice == 1){
            cout << "Yes! Let's battle!" << endl;
            
            //Create 2 queue list to hold the 2 teams' players
            CharQueue* queue1 = new CharQueue;
            CharQueue* queue2 = new CharQueue;
            CharQueue* queueLosers = new CharQueue;
            
            //Set up for team 1
            cout << "How many team players for Team #1?" <<endl;
            int teamOneCount = getUserChoice(1,10);
            cout << "What characters will each player be?" << endl;
            int userChoice;
            for(int i = 0; i < teamOneCount; i++){
                userChoice = menu(newGame);
                //Inititate each plyer for team 1
                 if(userChoice == 1){
                    player1 = new Vampire;
                }else if(userChoice == 2){
                    player1 = new Barbarian;
                }else if(userChoice == 3){
                    player1 = new BlueMen;
                }else if(userChoice == 4){
                    player1 = new Medusa;
                }else if(userChoice = 5){
                    player1 = new HarryPotter;
                }
                cout << "Please enter a name for this fighter: " << endl;
              
                string fighterName = getString();
                player1->setGivenName(fighterName);
                //Create a node containing this fighter and assign it to pointer fighter.
                CharNode* fighter = new CharNode(player1);
                //Add this node to queue1
                queue1->addToBack(fighter);
            }
            queue1->printQueue();
            //queue1->printReverse();
            
            //Set up for team 2
            cout << "How many team players for Team #2?" <<endl;
            int teamTwoCount = getUserChoice(1,10);
            cout << "What characters will each player be?" << endl;
            //int userChoice;
            for(int i = 0; i < teamTwoCount; i++){
                userChoice = menu(newGame);
                //Inititate each plyer for team 1
                 if(userChoice == 1){
                    player2 = new Vampire;
                }else if(userChoice == 2){
                    player2 = new Barbarian;
                }else if(userChoice == 3){
                    player2 = new BlueMen;
                }else if(userChoice == 4){
                    player2 = new Medusa;
                }else if(userChoice = 5){
                    player2 = new HarryPotter;
                }
                cout << "Please enter a name for this fighter: " << endl;
                string fighterName = getString();
                player2->setGivenName(fighterName);
                //Create a node containing this fighter and assign it to pointer fighter.
                CharNode* fighter = new CharNode(player2);
                queue2->addToBack(fighter);
            }
            queue2->printQueue();
            //queue2->printReverse();
            
            //Fight begins
            cout << "\n********* Now the Fight Begins! *************\n" << endl;
            
            //Take a turn
            CharNode* TeamOneFighter = queue1->getHead();
            CharNode* TeamTwoFighter = queue2->getHead();
            
            //As long as no team has all its fighters dead, the game continues
            int fightNumber = 1;
            while(TeamOneFighter != nullptr and TeamTwoFighter != nullptr){
                cout << "#####################-------------------------------------------################" << endl;
                cout << "                            ******** New Fight! ********               " <<endl;
                cout << "                                      Fight #" << fightNumber <<"                 " <<endl;
                cout << "#####################-------------------------------------------################" << endl;
                int round = 1;
                
                //As long as no fighter has a HP <= 0, the fight between those two continues
                while(TeamOneFighter->charPtr->getStrengthPoints() > 0  and TeamTwoFighter->charPtr->getStrengthPoints() > 0){
                    cout << "---------------------------------------------------" <<endl;
                    cout << "                      *** Round " << round  << " ***" << endl;
                    cout << "---------------------------------------------------" <<endl;
                    cout << "Fighter1 " << queue1->getHeadVal() << " HP: " << TeamOneFighter->charPtr->getStrengthPoints() <<endl;
                    cout << "Fighter2 " << queue2->getHeadVal() << " HP: " << TeamTwoFighter->charPtr->getStrengthPoints() <<endl;
                    cout << "..........Player1 attack!..........: ";
                    int player1Attack = TeamOneFighter->charPtr->attacking();
                    
                    cout << "..........Player2 defense!........: ";
                    TeamTwoFighter->charPtr->defensing(player1Attack);
                    
                    cout << "..........Player2 attack!..........: ";
                    int player2Attack = TeamTwoFighter->charPtr->attacking();
                    
                    cout << "..........Player1 defense!.........: ";
                    TeamOneFighter->charPtr->defensing(player2Attack);
                    
                    //Display results of the fight between the 2 fighters
                    if(TeamOneFighter->charPtr->isDead() and TeamTwoFighter->charPtr->isDead()){
                        cout << "Both player 1 and player 2 are dead! No one wins!" << endl;
                    }else if(TeamOneFighter->charPtr->isDead()){
                        cout << "Team 1 fighter the " << queue1->getHeadVal() << " is dead! Team 2 fighter the "<< queue2->getHeadVal() << " wins!" <<endl;
                    }else if(TeamTwoFighter->charPtr -> isDead()){
                        cout << "Team 2 fighter the " << queue2->getHeadVal() << " is dead! Team 1 fighter the "<< queue1->getHeadVal() << " wins!" <<endl;
                    }
                    
                    round++;
                    
                }
                
                fightNumber++;
                //Move the winner to the end of their team's queue
                cout << "\n\n********xxxxxxxxxxxxxx Result Board XXXXXXXXXXXXXXXXX********\n" << endl;
                if(TeamOneFighter->charPtr->isDead() and TeamTwoFighter->charPtr->isDead()){
                    cout << "               how come both are dead! No team scores point!" << endl;
                }else if(TeamOneFighter->charPtr->isDead()){
                    //team 2 fighter won
                    cout << "               Team 2 wins! Scores 2 points!\n" << endl;
                    
                    //This fighter heals
                    TeamTwoFighter->charPtr->randomHeal();
                    //Move this fighter to the last in the team queue
                    queue2->moveFirstToLast();
                    //Set the score for both teams. Winner + 2, loser -1.
                    queue2->setScore(queue2->getScore() + 2);
                    cout << "               Team 2 score: " << queue2->getScore() << endl;
                    queue1->setScore(queue1->getScore() - 1);
                    cout << "               Team 1 score: " << queue1->getScore() << endl;
                    
                    //Distach this lost fighter from his team to be prepared to add to the loser pile
                    CharNode* theLoser = queue1->removeButNotDeleteFront();
                    queueLosers->addToFront(theLoser);
                    //cout << "Losers pile:" << endl;
                    //queueLosers->printQueue();
                   
                    //Print out team 1 and team 2 fighters in order
                    cout<< "               Team 1: " << endl;
                    cout << "               " ;
                    queue1->printQueue();
                    cout<< "               Team 2: " << endl;
                    cout << "               ";
                    queue2->printQueue();
                    
                }else if(TeamTwoFighter->charPtr -> isDead()){
                    //Team 1 fighter won
                    //cout << queue1->getHeadVal() << " wins! And is moved to the end of their team's queue." <<endl;
                    //This fighter heasl
                    TeamOneFighter->charPtr->randomHeal();
                    
                    queue1->moveFirstToLast();
                   
                    queue1->setScore(queue1->getScore() + 2);
                    queue2->setScore(queue2->getScore() - 1);
                    //cout << "Team 2 score: " << queue2->getScore() << endl;
                    CharNode* theLoser = queue2->removeButNotDeleteFront();
                    queueLosers->addToFront(theLoser);
                    //cout << "Losers pile:" << endl;
                    //queueLosers->printQueue();
                    cout << "               Team 1 wins! Scores 2 points!\n" << endl;
                    cout << "               Team 1 score: " << queue1->getScore() << endl;
                    cout << "               Team 2 score: " << queue2->getScore() << endl;
                    cout<< "               Team 1: " << endl;
                    cout << "               " ;
                    queue1->printQueue();
                    cout<< "               Team 2: " << endl;
                    cout << "               " ;
                    queue2->printQueue();
                   
                }
                cout << "\n********XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX********\n" << endl;
                
                //Get the next fighter in queue of their respective team, they are on for the next fight!
                TeamOneFighter = queue1->getHead();
                TeamTwoFighter = queue2->getHead();
            }
            
            //When a team has no memebers left, it's time to declare the final winning team
            cout << "\noooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo" << endl;
            cout << "oooooo                                                    oooooo" <<endl;
            cout << "oooooo                   FINAL SCORE BOARD                oooooo" <<endl;
            cout << "oooooo                                                    oooooo" <<endl;
            if(queue1->getHead() == nullptr){
                cout << "oooooo          All fighters from Team 1 is dead.         oooooo" <<endl;
            }else if(queue2->getHead() == nullptr){
                cout << "oooooo          All fighters from Team 2 is dead.         oooooo" <<endl;
            }else{
                cout << "oooooo                     No Team Won                    oooooo" <<endl;
            }
            cout << "                         Team 1 score: " << queue1->getScore() << endl;
            cout << "                         Team 2 score: " << queue2->getScore() << endl;
            cout << endl;
            if(queue1->getScore() > queue2->getScore() ){
                cout << "oooooo                    Team 1 WON !!!                  oooooo" <<endl;
            }else if(queue1->getScore() < queue2->getScore() ){
                cout << "oooooo                    Team 2 WON !!!                  oooooo" <<endl;
            }else if(queue1->getScore() == queue2->getScore() ){
                cout << "oooooo                    It's a TIE !!!                  oooooo" <<endl;
            }
            cout << "oooooo                                                    oooooo" <<endl;
            cout << "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo\n" << endl;
            
            //Ask if user wants to see the loser pile
            cout << "Would you like to print out the loser pile from top to bottom?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. Skip" << endl;
            
            int userLoserChoice = getUserChoice(1,2);
            if(userLoserChoice == 1){
                cout << "The loser pile is here: " << endl;
                queueLosers->printQueue();
            }else{
                cout << "Ok, this is skipped" << endl;
            }
            
            //Deallocate memories
            delete queue1;
            //cout << "deleted 1" << endl;
            delete queue2;
            //cout << "deleted 2" << endl;
            delete queueLosers;
            //cout << "deleted losers" << endl;
        
            queue1 = nullptr;
            queue2 = nullptr;
            queueLosers = nullptr;
           
            gameState = finished;
            
            
        }else{
            cout << "Exiting game. See you next time!" << endl;
            status = false;
        }

    }       
    cout << "Bye!" << endl;
    return 0;
}


//Helper function
//This function takes no argument and returns the user input as a string. It will not accept blank strings.
string getString(){
    //cout << "Please enter your choice, an integer between " << minInput << " and " << maxInput << ":"  << endl;
    string userString;
    bool status = true;
    while(status){
        getline(cin, userString); //Get the entire line, including spaces
        if(userString.empty()){
            cout << "The string you entered is empty. Please re-enter" << endl;
        }else if(userString.find_first_not_of(' ') == std::string::npos){
            cout << "The string you entered is all white spaces. Please re-enter" << endl;
        }
        else{
            status = false;
        }
    }
    
    return userString;
}
