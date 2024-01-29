#include <bits/stdc++.h>
using namespace std;

int INF = INT_MAX / 2;
int rec(vector<int>& m1, int left, int total, int target, vector<int>& dp) {

    if (dp[left] != INT_MAX) {
        return dp[left] + total;
    }
    if (left == target) {
        dp[left] = 0;
        return total;
    }
    if (m1[left] == left) {
        dp[left] = INF;
        return INT_MAX;
    }
    if (m1[left] >= target) {
        dp[left] = 0;
        return total;
    }
    int ans = INT_MAX;
    for (int i = left; i < m1[left]; ++i) {
        ans = min(ans, rec(m1, i + 1, total + 1, target, dp));
        if (ans != INT_MAX) {
            dp[left] = min(dp[left], ans - total);
        }
    }

    if (ans != INT_MAX) {
        dp[left] = min(dp[left], ans - total);
    } else {
        dp[left] = INF;
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> m1(n + 1);
    iota(m1.begin(), m1.end(), 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        m1[a] = max(m1[a], b);
    }
    vector<int> dp(n + 1, INT_MAX);

    int ans = rec(m1, 1, 1, n, dp);
    if (ans > INF - 100000) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}