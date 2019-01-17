/**********************************
** Program Name: count_letters.cpp
** Author: Miao Pan
** Date: 01/15/2019
** Description: This is the implementation file for the count_letters function.
**********************************/

#include "count_letters.hpp"
#include "output_letters.cpp"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;

//Function prototype
string getInputFileName();
void output_letters(ofstream&, int*);

//count_letters function
void count_letters(ifstream &inputF, int* letterA){
    
    char aLetter;
    string aSentence;
    bool initStatus = true;
    bool status = true;
    ofstream outputFile;
   
    string inputFileName;
    
    while(initStatus){
        inputFileName = getInputFileName();
        cout << "Trying to open file " << inputFileName << endl;
        inputF.open(inputFileName);
        if(inputF.fail()){
            cout << "Cannot open file. Please enter an existing file." << endl;
        }else{
            initStatus = false;
        }
    }
    
    
    
    if(inputF){
        cout << "success!" << endl;
        getline(inputF, aSentence);
        while(inputF){
            cout << aSentence << endl;
            for(int i = 0; i < aSentence.length(); i++){
                aLetter = aSentence[i];
                if(aLetter != ' '){
                    aLetter = tolower(aLetter);
                    cout << "index is " << aLetter - 97 <<endl;
                    cout << aLetter << " : " << ++letterA[aLetter - 97] << endl;
                }
            }
            char displayLetter;
            cout << "that was a line" << endl;
        
            for (int i = 0; i<26; i++){
                //cout << "this is main: " << endl;
                displayLetter = i + 97;
                cout << displayLetter << " : "<< letterA[i] << endl;
            }
        
            output_letters(outputFile, letterA);
        
            //Re-initialize all array values to 0
            for (int i =0; i< 26; i++){
                letterA[i] = 0;
            }
        
            //Get next line
            getline(inputF, aSentence);
        }
    }
    
    
    
   /* 
    while(aLetter != '\n'){
        aLetter = tolower(aLetter);
        cout << "to lower case: " << aLetter << endl;
        cout << "index is " << aLetter - 97 <<endl;
        cout << aLetter << " : " << letterA[aLetter - 97]++ << endl;
        aLetter = inputF.get();
    }
    */
   
    
    /*
    aLetter = inputF.get();
    cout << aLetter << endl;
    while(aLetter != EOF and status == true){
        aLetter = tolower(aLetter);
        cout << aLetter <<endl;
        if(aLetter != '\n'){
            
            //cout << "iteration letter is " << letter << " and aLetter is " << aLetter << endl;
            cout << "index is " << aLetter - 97 <<endl;
            cout << aLetter << " : " << letterA[aLetter - 97]++ << endl;
            
        }else if(aLetter == '\n'){
            status = false;
        }
        aLetter = inputF.get();
    }
    */
  
    
}


//Helper functions
string getInputFileName(){
    
    string userFileNameInput;
    cout << "Please enter the name of the file you want to read: " << endl;
    cin >> userFileNameInput;
    
    return userFileNameInput;

}
