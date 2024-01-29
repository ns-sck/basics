#include <iostream>
using namespace std;

void swap1(int& a, int&b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int l, int h){
    int x = arr[h];    //pivot
    int i = (l - 1);    //orange
 
 
    for (int j = l; j <= h- 1; j++)    //green
    {
        if (arr[j] <= x)
        {
            i++;
            swap1(arr[i], arr[j]);
        }
    }
    swap1(arr[i + 1], arr[h]);
    return (i + 1);
}

void quickSort(int A[], int l, int h){    //time complexity: O(NlogN)
    if (l < h)
    {        
        int p = partition(A, l, h);
        quickSort(A, l, p - 1);  
        quickSort(A, p + 1, h);
    }
}

int main(){

    int array[10] = {9,8,7,6,5,4,3,2,1,0};

    quickSort(array, 0, 9);

    for(auto number : array){
        cout << number << '\n';
    }

    return 0;
}