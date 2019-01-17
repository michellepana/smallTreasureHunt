/**********************************
** Program Name: main.cpp
** Author: Miao Pan
** Date: 01/15/2019
** Description: This is the main function of the Count Letter program.
**********************************/

#include <iostream>
#include <fstream>
#include <string>
#include "count_letters.cpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;


//Function prototype
//string getInputFileName();
//void count_letters(ifstream &, int*);

//Main function
int main(){
    
    ifstream inputFile;
    ofstream outputFile;
    char letter;
    string aSentence;
    
    int letterArr[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    
    string inputFileName;
    
    //inputFileName = getInputFileName();
    //cout << "Trying to open file " << inputFileName << endl;
    //inputFile.open(inputFileName);
    
    //cout << "Trying to open file " << inputFileName << endl;
    
 
    
  
    /*
    if(inputFile){
        while(inputFile >> indi){
            if(indi == 'a'){
                count_letters(inputFileName, letterArr)
            }
        }
        
    }
    
    
    getline(inputFile, aSentence);
    while(inputFile){
        cout << aSentence << endl;
        count_letters(inputFile, letterArr);
        for (int i = 0; i<26; i++){
            cout << "this is main: " << endl;
            letter = i + 97;
            cout << letter << " : "<< letterArr[i] << endl;
        }
        
        
        getline(inputFile, aSentence);
        
    }
    */
    
    count_letters(inputFile, letterArr);
    
    //for (int i = 0; i<26; i++){
    cout << "Exiting program now. " << endl;
            //letter = i + 97;
            //cout << letter << " : "<< letterArr[i] << endl;
        //}
    /*
    for (int i = 0; i<26; i++){
        cout << "this is main: " << endl;
        letter = i + 97;
        cout << letter << " : "<< letterArr[i] << endl;
    }
 
    */
    return 0;
}

/*
//Helper functions
string getInputFileName(){
    
    string userFileNameInput;
    cout << "Please enter the name of the file you want to read: " << endl;
    cin >> userFileNameInput;
    
    return userFileNameInput;

}
*/