#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9+7;
const int MAXN = 2e5 + 1;
vector<vector<int>> adj(MAXN, vector<int>(0));
vector<int> balloons(2e5 + 1, -1);
vector<vector<int>> dp(MAXN, vector<int>(5, -1));

long long rec(int node, int step, bool take)
{   
    if (step == 1 && take && balloons[node] == 0) {
        return 0;
    }
    if (step == 2 && take && balloons[node] == 2) {
        return 0;
    }
    if (step == 3 && take && balloons[node] == 0) {
        return 0;
    }
    if (step == 4) {
        return balloons[node] == 2;
    }
    
    long long ans = 0;
    for (unsigned int i = 0; i < adj[node].size(); ++i) {
        ans += rec(adj[node][i], step + 1, true) % MOD;
        ans += rec(adj[node][i], step, false) % MOD;
    }
    return ans % MOD;
}

int main() {
    ios;
    int n;
    cin >> n;
    
    for (int i = 2; i <= n; ++i) {
        int a;
        cin >> a;
        adj[a].push_back(i);
    }
    
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        balloons[i] = a;
    }
    
    cout << (rec(1, 0, false) + rec(1, 1, true)) % MOD;
    
    return 0;
}