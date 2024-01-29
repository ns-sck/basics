//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
// write your code here
    
    int n;
    cin >> n;
    map<int, vector<pair<int, int>>> v1;
    for (int i = 1; i <= n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        v1[v].push_back({u, w});
    }
    map<int, int> v2;
    v2[0] = 0;
    for (auto& ways : v1) {
        v2[ways.first] = 0;
    }

    for (auto& x : v1) {
        sort(x.second.begin(), x.second.end());
        auto it = v2.lower_bound(x.first);
        if (it != v2.begin()) {
            --it;
            v2[x.first] = max(v2[x.first], it->second);
        }
        for (auto& ways : x.second) {
            auto it2 = v2.find(ways.first);
            if (it2 != v2.end()) {
                v2[x.first] = max(v2[x.first], it2->second + ways.second);
            } else {
                it2 = v2.lower_bound(ways.first);
                --it2;
                v2[x.first] = max(v2[x.first], it2->second + ways.second);
            }
        }
    }
    int ans = 0;
    for (auto& ways : v2) {
        ans = max(ans, ways.second);
    }
    cout << ans;
	return 0;
}
    