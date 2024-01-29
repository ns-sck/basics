//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;


int main() {
// write your code here
    int li;
    cin >> li;
    string s;
    cin >> s;
    int i = 0;
    for (i = 0; i < s.length() - 1; i++) {
        
        if (s[i+1] != s[i]) {
            s.erase(i+1, 1);
        } else if (s[i-1] != s[i]) {
            s.erase(i-1, 1);
            i--;
        } else if (i != 0) {
            s.erase(i-1, 1);
            i--;
        } else {
            s.erase(1, 1);
        }
    }
    
    cout << (s[s.length() - 1] == 'A' ? "Extinction!" : "Victory!");
	return 0;
}
