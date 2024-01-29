#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> st, int n){
    while(!st.empty()){
        cout << st.top() << '\n';
        st.pop();
    }
}

int main(){

    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(6);
    st.push(8);
    st.push(1);

    printStack(st, 44);

    return 0;
}