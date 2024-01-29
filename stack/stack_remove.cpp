#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> st){

    while(!st.empty()){
        cout << st.top() << '\n';
        st.pop();
    }
}

int main(){

    //pop the elements up to the index to be removed and restore them into a temporary stack and get them back after removing.
    stack<int> st;
    stack<int> temp;
    st.push(3);
    st.push(2);
    st.push(5);
    st.push(6);
    st.push(7);

    int elementToRemove = 6;

    while(!st.empty()){
        if(st.top() == elementToRemove){
            st.pop();
        }
        else{
            temp.push(st.top());
            st.pop();
        }
    }

    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }

    printStack(st);

    return 0;
}