#include <iostream>
using namespace std;

void searchElement(int array[], int size, int n){
    
    for(int i=0; i<size;i++){
        if(array[i] == n){
            cout << n << " is found at index: " << i;
        }
    }
}

int main(){

    int myArray[] = {3,5,7,4,0,9,4,2,1};
    int size = sizeof(myArray)/sizeof(myArray[0]);    //it is not good to calculate size in function because it takes array's
                                                      //value but not itself
    searchElement(myArray, size, 3);


    return 0;
}