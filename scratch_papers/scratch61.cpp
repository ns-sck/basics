//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1, vector<int>(0));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    for (int i = 1; i < n+1; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }
    int counter = 0;
    map<pair<int,int>, int> answers;
    for (int i = 1; i < n + 1; ++i) {
        for (unsigned int j = 0; j < adj[i].size(); ++j) {
            int newNode = adj[i][j];
            if (answers[{newNode, i}] == 1) {
                continue;
            }
            auto it = find(adj[newNode].begin(), adj[newNode].end(), i);
            if (it != adj[newNode].end()) {
                counter++;
                answers[{i, newNode}] = 1;
            }
        }
    }
    cout << counter << '\n';
    for (auto p : answers) {
        if (p.second == 1)
            cout << p.first.first << ' ' << p.first.second << '\n';
    }
	return 0;
}
