#include <iostream>
using std::cout;
using std::cin;
using std::endl;


class Box{
    
    private:
        int length;
        int width;
        
    public:
    //Constructor
    Box(int row, int col){
        length = row;
        width = col;
    }
    
    int boxVolumn(){
        return length*width;
    }
};

int main(){
    
    cout << "testing" << endl;
    Box *pBox;
    pBox = new Box(2,3);
    cout << pBox->boxVolumn() << endl;
    
    return 0;
}