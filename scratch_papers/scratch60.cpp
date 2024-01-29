//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>(0));
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<int> visited(n+1, 0);
    vector<int> current;
    current.push_back(1);
    visited[1]++;
    int x = n - 1;
    int ans = 0;
    while (x--) {
        int mw = INT_MAX;
        int nextNode = 0;
        for (unsigned int i = 0; i < current.size(); ++i) {
            for (unsigned int j = 0; j < adj[current[i]].size(); ++j) {
                auto p = adj[current[i]][j];
                if (p.second < mw && !visited[p.first]) {
                    mw = p.second;
                    nextNode = p.first;
                }
            }
            current.push_back(nextNode);
            ans += mw;
        }
    }
    cout << ans;
	return 0;
}
