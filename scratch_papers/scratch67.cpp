#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    vector<vector<int>> dp(b.length() + 1, vector<int>(a.length() + 1, 0));

    for (int i = 1; i <= b.length(); ++i) {
        for (int j = 1; j <= a.length(); ++j) {
            if (a[j - 1] == b[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    cout << dp[b.length()][a.length()];
    return 0;
}
