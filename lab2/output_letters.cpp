/**********************************
** Program Name: output_letters.cpp
** Author: Miao Pan
** Date: 01/16/2019
** Description: This is the implementation file for the output_letters function.
**********************************/

#include "output_letters.hpp"
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

//funtion prototypes;
string getOutputFileName();

//Output_letters function
void output_letters(ofstream &outputF, int* outputArr){
    
    char displayLetter;
    string outputFileName;
    outputFileName = getOutputFileName();
    
    outputF.open(outputFileName);
    
    for (int i = 0; i<26; i++){
        //cout << "this is main: " << endl;
        displayLetter = i + 97;
        outputF << displayLetter << " : "<< outputArr[i] << endl;
    }
    
    //Close the file
    outputF.close();
    
    
    cout << "done" <<endl;
    
}


//Helper functions
string getOutputFileName(){
    
    string userFileNameInput;
    cout << "Please enter the name of the file you want to output to: " << endl;
    cin >> userFileNameInput;
    
    return userFileNameInput;

}