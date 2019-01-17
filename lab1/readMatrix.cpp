#include "readMatrix.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//Helper function prototype
int getMatrixItem(); 

//Get user input for matrix item value and populate value to the matrix.
void readMatrix(int **arrayPtr, int size){
    
    cout << "Please enter all the numbers within the matrix." << endl;
    cout << "The matrix has " << size << " rows and " << size << " columns." << endl;
    
    //check if arrayPtr points to null.
    if (!arrayPtr){
        cout << "passed in array pointer is null." << endl;
    }
    
    //prompt the user to enter 4 or 9 int to fill the matrix
    for (int row = 0; row < size; row++){
        for (int column = 0; column < size; column++){
            cout << "Please enter int for row " << row + 1 << " column " << column + 1 << endl;
            arrayPtr[row][column] = getMatrixItem();
        }
        
    }
    
    
}

//Helper function

//Get user input for matrix item value with input validation
int getMatrixItem(){
    while(true){
        cout << "Please enter an integer" << endl;
        int matrixInput;
        cin >> matrixInput;
        
        //Check for failed extractions
        if(cin.fail()){
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Oops, that matrix input was invalid, please try again!" << endl;
        } else {
            cin.ignore(32767, '\n');
            return matrixInput;
        }
    }
}