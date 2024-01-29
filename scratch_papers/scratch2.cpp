#include <iostream>
#include <string>
using namespace std;

struct node{

    node* next;
    int data;
};

void printarray(node* array)
{
    for (int i = 0; i < 10; i++) {
        cout << (array+i)->data << "\t" << (array+i)->next << '\n';
    }
}

void add2array(node* array, int val)
{
    array[val-1].data = val;
    array[val-1].next = &array[val];
}

void addtothebeginning(node* array, int val)
{
    for (int i = 9; i >= 1; i--) {

        array[i] = array[i-1];
    }
    array[0].data = val;
    array[9].next = NULL;
}

int main ()
{

    node array[10];
    for (int i = 1; i <= 9; i++) {
        add2array(array, i);
    }

    printarray(array);
    addtothebeginning(array,0);
    printarray(array);
    return 0;
}