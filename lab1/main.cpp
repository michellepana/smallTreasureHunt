#include <iostream>

#include "readMatrix.hpp"
#include "determinant.hpp"

using std::cout;
using std::cin;
using std::endl;

//Helper function prototypes
void displayMatrix(int** array, int size);
int getMatrixSize();

//Main 
int main(){
    
    int matrixSize;
    int determinantValue;
    
    //Get the size of the matrix
    matrixSize = getMatrixSize();
    
    //Dynamically allocating the two dimensional array
    int** array = new int*[matrixSize];//allocate an array of matrixSize int pointers - these are rows
    for (int i = 0; i < matrixSize; i++){
        array[i] = new int[matrixSize]; //these are columns;
    }
    
    //Initiate the matrix with user input
    readMatrix(array, matrixSize);
    
    //Get the determinant
    determinantValue = determinant(array, matrixSize);
    
    //Display the matrix
    displayMatrix(array, matrixSize);
    
    //Display the determinant
    cout << "The determinant is " << determinantValue << "." << endl;
    
    //Deallocating the dynamically allocated two-dimensional array
    for (int i = 0; i < matrixSize; i++){
        delete[] array[i];
    }
    delete[] array;
    array = nullptr;
    
    
    return 0;
}

//Helper functions 

//Display the matrix
void displayMatrix(int** array, int size){
    
    for(int row = 0; row < size; row++){
        for (int col = 0; col < size; col++){
            cout << " | " << array[row][col] << " | ";
        }
        cout << endl;
    }
}

//Get matrix size input with input validation
int getMatrixSize(){
    while(true){
        cout << "Please choose the number of rows and columns of the matrix, either 2 or 3." << endl;
        int sizeInput;
        cin >> sizeInput;
        
        //Check for failed extraction
        if(cin.fail()){
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Oops, that input was invalid, please try again!" << endl;
        } else{
            cin.ignore(32767, '\n'); //remove any extraneous input
            if(sizeInput == 2 or sizeInput ==3){
                return sizeInput;
            }else{
                cout << "Oops, that input was not 2 nor 3, please try again!" << endl;
            }
        
        }
    }
}