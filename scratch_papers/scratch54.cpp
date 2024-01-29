//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;

void rec(string a, unsigned int left, bool b, string a2) {
    if (b) {
        char c = a[left];
        a2 += " ";
        a2 += c;
        if (left + 1 == a.length()) {
            cout << a2 << '\n';
            return;
        }
        rec(a, left + 1, true, a2);
        rec(a, left + 1, false, a2);
    } else {
        char c = a[left];
        a2 += c;
        if (left + 1 == a.length()) {
            cout << a2 << '\n';
            return;
        }
        rec(a, left + 1, true, a2);
        rec(a, left + 1, false, a2);
    }
}
int main() {
// write your code here
   
    int n;
    string a;
    cin >> n >> a;
    string x = "";
    char c = a[0];
    x += c;
    rec(a, 1, true, x);
    rec(a, 1, false, x);
    return 0;
}
