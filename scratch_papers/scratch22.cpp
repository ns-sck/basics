#include <iostream>
#include <vector>

using namespace std;
 
// Main driver method
int main()
{
    // Creating and initializing an integer array
    // Custom input entries
    int a[]{ 1, 2, 3, 4 };
 
    // int (&b)[] = a;
    // Declaring this way wont work as an error will be
    // thrown invalid initialization of reference of type
    // ‘int (&)[]’ from expression of type ‘int [4]’ Here
    // you see compiler referred to "a" as int [4] not int*
 
    int(&b)[4] = a;
 
    // Iterating over elements using foreach loop
    for (int e : b) {
        // Print the elements of the array
        cout << e << " ";
    }

    vector<int> v = {0,1};
    int mid = v.size()/2;
    vector<int> left(v.begin(),v.begin()+mid);
    vector<int> right(v.begin()+mid+1, v.end()); 

    for (auto a : left) {
        cout << a << ' ';
    }
    for (auto a : right) {
        cout << a << ' ';
    }

    return 0;
}