#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    vector<int> v(n, 0);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v[i] = a;
    }

    // sort(v.begin(), v.end());

    vector<vector<long long>> dp(n + 1, vector<long long>(d + 1, 0));
    dp[0][0] = 1;

    for (int left = 0; left < n; ++left) {
        for (int total = 0; total <= d; ++total) {
            dp[left+1][total] += dp[left][total];
            dp[left+1][total] %= MOD;
            if (v[left] + total <= d) {
                dp[left+1][total + v[left]] = dp[left+1][total];
                dp[left+1][total + v[left]] %= MOD;
            }
        }
    }

    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < d + 1; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << dp[n][d];

    return 0;
}
