#include "determinant.hpp"
#include <iostream>

int determinant(int** a, int size){
    
    if(size == 2){
        return a[0][0]*a[1][1] - a[0][1]*a[1][0];
    } else if(size == 3){
        return a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1]) - a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0]) + a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
    }
}