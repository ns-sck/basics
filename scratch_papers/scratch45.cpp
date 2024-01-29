#include <iostream>
#include <vector>

using namespace std;

bool rec(vector<int>& v, int index, int target, vector<vector<short>>& dp) {
    
    if (dp[index+1][target] != -1)
        return dp[index+1][target];
        
    int size = v.size();
    if (index == size) {
        dp[index+1][target] = 0;
        return false;
    }
    if (target == 0) {
        dp[index+1][target] = 1;
        return true;
    }
    for (int i = index + 1; i < size; ++i) {
        if (v[i] <= target) {
            if (rec(v, i, target - v[i], dp)) {
                dp[index+1][target] = 1;
                return true;
            }
        }
    }
    dp[index+1][target] = 0;
    return false;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num, st;
    cin >> num;
    cin >> st;
    vector<int> v(num, -1);
    vector<int> b(st, -1);
    for (int i = 0; i < num; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < st; ++i) {
        cin >> b[i];
    }
    vector<vector<short>> dp(num + 1, vector<short>(50000, -1));
    for (int i = 0; i < st; ++i) {
        if (rec(v, -1, b[i], dp)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    
    return 0;
}