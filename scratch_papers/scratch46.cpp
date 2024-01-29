//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;


int main() {
// write your code here
    
    int n;
    string s;
    cin >> n >> s;
    long long ans = 0;
    int count = 0;
    map<int, int> m;
    
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'p') {
            count++;
        } else if (s[i] == 'e') {
            count--;
        }
        m[count]++; 
    }
    m[0]++;
    for (auto& pair : m) {
        if (pair.second > 1)
            ans += (long long) pair.second * (pair.second - 1) / 2;
    }
    cout << ans;
	return 0;
}
