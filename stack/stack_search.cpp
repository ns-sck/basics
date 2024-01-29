#include <bits/stdc++.h>
using namespace std;

void searchElement(stack<int> st, int n){
    int count = 0;
    while(!st.empty()){
        count += 1;
        if(st.top() == n){
            cout << "element found at place: " << count;
            return;
        }
        st.pop();
    }
    cout << "element not found";
}

int main(){

    stack<int> st;
    st.push(3);
    st.push(5);
    st.push(1);
    st.push(6);
    st.push(9);

    searchElement(st, 6);

    return 0;
}