#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> St){
    while(!St.empty()){
        cout << St.top() << ' ';
        St.pop();
    }
}

int main(){

    stack<int> st;

    st.push(3);
    st.push(2);
    st.push(5);
    st.push(4);
    st.push(1);

    printStack(st);
    printStack(st);    //popping is removing element but function takes not stacks itself but its values;

    return 0;
}