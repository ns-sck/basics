#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    ios;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(0));
    vector<bool> visited(n + 1, false);
    visited[1] = true;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int a = 1;
    for (unsigned int i = 1; i < adj.size(); ++i) {
        sort(adj[i].begin(), adj[i].end());
    }
    int x = n;
    while(x--) {
        visited[a] = true;
        cout << a << ' ';
        bool b = false;
        for (unsigned int i = 0; i < adj[a].size(); ++i) {
            if (!visited[adj[a][i]]) {
                b = true;
                break;
            }
        }
        if (!b) {
            for (int i = 1; i < n + 1; ++i) {
                if (!visited[i]) {
                    a = i;
                    break;
                }
            }
        } 
        else {
            for (int i = adj[a].size() - 1; i >= 0; ++i) {
                if (!visited[adj[a][i]]) {
                    a = adj[a][i];
                    break;
                }
            }    
        }
    }
    
	return 0;
}
