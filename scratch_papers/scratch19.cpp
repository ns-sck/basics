#include <iostream>
#include <cmath>
using namespace std;

int change_leftmost(int arr[], int index) {

    for (int i = index; i < 32; i++) {

        if (arr[i] == 1) {
            index = i;
            break;
        }
    }

    int x = 0;

    if (index == 31) {
        
        return arr[31];
    }

    if (arr[index+1] == 0) {

        x += pow(2, (31 - index)) - change_leftmost(arr, index + 1);
        arr[index] = 0;
        x++;

    } else {

        arr[index] = 0;
        x++;
        x += change_leftmost(arr, index + 1);
    }

    return x;
}

int minimumOneBitOperations(int n) {
        
    int index = 0;
    int arr[32] = {0};

    while (n > 0) {

        arr[31 - (index++)] = n % 2;
        n /= 2;
    }

    return change_leftmost(arr, index);
}

int main ()
{

    cout << minimumOneBitOperations(63);


    return 0;
}