//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long, long>>> adj(2e5 + 1, vector<pair<long, long>>(0));
vector<long long> dist(2e5 + 1, 1e12);
map<pair<long, long>, long> m1;
vector<int> ans;
int main() {
// write your code here
    long n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        long a, b, c;
        cin >> a >> b >> c;
        auto it = m1.find({a,b});
        if (it == m1.end()) {
            m1[{a,b}] = c;
            m1[{b,a}] = c;
        } else {
            m1[{a,b}] = min(c, m1[{a,b}]);
            m1[{b,a}] = min(c, m1[{b,a}]);
        }
    }
    for (auto p : m1) {
        adj[p.first.first].push_back({p.first.second, p.second});
    }
    vector<vector<long>> parents(n + 1, vector<long>(0));
    priority_queue<pair<long, long>, vector<pair<long, long>>, function<bool(pair<long, long>, pair<long, long>)>> pq([](pair<long, long> a, pair<long, long> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first > b.first;
});
    pq.push({n, 1});
    
    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        long dis = current.first;
        long node = current.second;
        if (dis > dist[node]) {
            continue;
        }
        for(auto neigh: adj[node]){
            if(dis+neigh.second< dist[neigh.first]){
                pq.push(make_pair(dis+neigh.second, neigh.first));
                parents[neigh.first].push_back(node);
            }
        }

        ans.push_back(node);
        dist[node] = dis;
        for (unsigned int i = 0; i < adj[node].size(); ++i) {
            auto p = adj[node][i];
            if (p.second + dis < dist[p.first]) {
                dist[p.first] = p.second + dis;
                parents[p.first].push_back(node);
                pq.push({p.second + dis, p.first});
            }
        }
    }
    if (dist[1] == 1e12) {
        cout << -1;
    } else {
        int a = 1;
        while (true) {
            cout << a << ' ';
            if (a == n) {
                break;
            }
            sort(parents[a].begin(), parents[a].end());
            a = parents[a][0];
        }
    
    }
	return 0;
}
