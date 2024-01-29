//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;

int rec(vector<vector<pair<int, int>>>& v, int last, int left, int total, bool even) {
    
    if (left == 1) {
        return total;
    }
    int ans = INT_MAX;
    float c = even ? 0.5 : 2;
    for (unsigned int i = 0; i < v[last].size(); ++i) {
        ans = min(ans, rec(v, v[last][i].first, left - 1, total + v[last][i].second * c, !even));
    }
    return ans;
}
int main() {
// write your code here
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> v(n+1, vector<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
        int a;
        int b;
        int cost;
        cin >> a >> b >> cost;
        v[a].push_back({b,cost});
    }
    int ans = INT_MAX;
    for (unsigned int i = 0; i < v[1].size(); ++i) {
        ans = min(ans, rec(v, v[1][i].first, n - 1, v[1][i].second * 2, true));
    }
    cout << ans;
	return 0;
}
