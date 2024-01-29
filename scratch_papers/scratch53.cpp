//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
   
    string a;
    cin >> a;
    stack<char> st;
    bool flag = false;
    for (unsigned int i = 0; i < a.length(); ++i) {
        if (a[i] == '{' || a[i] == '(' || a[i] == '[')
            st.push(a[i]);
        else {
            if (st.empty()) {
                flag = true;
                break;
            }
            char x = st.top();
            if (a[i] == '}' && x == '{') {
                st.pop();
            }
            if (a[i] == ')' && x == '(') {
                st.pop();
            }
            if (a[i] == ']' && x == '[') {
                st.pop();
            } else {
                flag = true;
                break;
            }
        }
    }
    if (!st.empty())
        flag = true;
        
    if (!flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
