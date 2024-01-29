//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n;
    cin >> n;
    string a;
    cin >> a;
    stack<char> st;
    bool ok = false;
    int i = 0;
    for (i = 0; i < n; ++i) {
        if (a[i] == '{' || a[i] == '(' || a[i] == '[')
            st.push(a[i]);
        else {
            if (st.empty()) {
                break;
            }
            char x = st.top();
            if (a[i] == '}' && x == '{') {
                st.pop();
                if (st.empty()) {
                    ok = true;
                    break;
                }
            }
            else if (a[i] == ')' && x == '(') {
                st.pop();
                if (st.empty()) {
                    ok = true;
                    break;
                }
            }
            else if (a[i] == ']' && x == '[') {
                st.pop();
                if (st.empty()) {
                    ok = true;
                    break;
                }
            } else {
                break;
            }
        }
    }
    if (!ok) {
        cout << "NO";
    } else {

        bool flag = false;
        for (i = i + 1; i < n; ++i) {
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
                else if (a[i] == ')' && x == '(') {
                    st.pop();
                }
                else if (a[i] == ']' && x == '[') {
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
    }
    return 0;
}
