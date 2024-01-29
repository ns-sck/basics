//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;


int rec(vector<vector<int>>& grid, string a, unsigned int r, unsigned int c, unsigned int step, vector<vector<vector<int>>>& dp) {
    if (r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0 || step > 4) {
        return 0;
    }
    if(dp[r][c][step] != -1) {
        return dp[r][c][step];
    }
    a += to_string(grid[r][c]);
    if (a == "2022") {
        dp[r][c][step] = 1;
        return 1;
    }
    int ans = 0;
    ans += rec(grid, a, r, c + 1, step + 1, dp);
    ans += rec(grid, a, r + 1, c, step + 1, dp);
    ans += rec(grid, a, r - 1, c, step + 1, dp);
    ans += rec(grid, a, r, c - 1, step + 1, dp);
    dp[r][c][step] = ans;
    return ans;
}
int main() {
// write your code here
    int counter = 0;
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c, 0));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<vector<vector<int>>> dp(r + 1, vector<vector<int>>(c + 1, vector<int>(5, -1)));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            counter += rec(grid, "", i, j, 1, dp);
        }
    }
    cout << counter;
	return 0;
}
