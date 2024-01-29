//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n;
    cin >> n;
    vector<long long> v1(n, -1);
    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
    }
    long long ans = INT_MAX;
    
    for (int i = 0; i < n; ++i) {
        long long total = 0;
        for (int j = i; j < n; ++j) {
            total += (long long) v1[j];
            ans = (long long) min(ans, abs(total));
        }
    }
    cout << ans;
	return 0;
}
