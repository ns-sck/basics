//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;

int main() {
// write your code here
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<long long, long long>>> adj(n + m + 1, vector<pair<long long, long long>>(0));

    for (int i = 0; i < k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for (int i = 1; i <= n; ++i) {
        
        priority_queue<pair<long long ,long long>, vector<pair<long long,long long>>, greater<>> pq;
        vector<bool> visited(n + m + 1, false);
        vector<long long> dist(n + m + 1, 1e18);
        pq.push({0, i});
        long long ans = LLONG_MAX;
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            long long dis = p.first;
            long long node = p.second;
            visited[node] = true;
            if (dis > dist[node]) {
                continue;
            }
            dist[node] = dis;
            if (node > n) {
                ans = min(ans, dis);
            }
            for (auto neigh : adj[node]) {
                if (dis + neigh.second > dist[neigh.first]) {
                    pq.push({dis + neigh.second, neigh.first});
                }
            }
        }
        cout << ans << ' ';
    }
	return 0;
}
