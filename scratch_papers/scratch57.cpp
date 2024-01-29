//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;

int main() {
// write your code here

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(0));
    vector<vector<int>> m1(n + 1, vector<int>(n + 1 , 0));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        m1[a][b] = 1;
        m1[b][a] = 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool b = true;
    for (auto v : adj) {
        if (b) {
            b = false;
            continue;
        }
        sort(v.begin(), v.end());
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            cout << m1[i][j] << ' ';
        }
        cout << '\n';
    }
    
	return 0;
}
