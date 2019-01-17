#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//prototypes
void display(int** array, int size);
void edit(int** array, int size);

int main(){
    
    char a = ' ';
    char b = '#';
    cout << "a is " << int(a) << " and " << a << endl;
    cout << "b is " << int(b) << " and " << b << endl;
    /*int size;
    //int array[size][size] =  {{1,2},{3,4}};
    
    int **array;
    array = new int *[size];
    for(int i = 0; i <size; i++)
        array[i] = new int[10];

    
    display(array, size);
    edit(array, size);
    display(array, size);
    */
    
    return 0;
}

void display(int** array, int size){
    
    for(int row=0; row<size; row++){
        for(int col = 0; col<size; col++){
            cout << array[row][col] ;
        }
        cout << endl;
    }
}

void edit(int** arrayPtr, int size){
    
    for (int row = 0; row < size; row++){
        for (int column = 0; column < size; column++){
            cout << "Please enter int for row " << row + 1 << " column " << column + 1 << endl;
            cin >> arrayPtr[row][column];
        }
    }
    
}