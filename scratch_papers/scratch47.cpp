#include <iostream>
#include <vector>
#include <map>
using namespace std;

int MOD = 1000000007;
int totalBetween(vector<int>& v, int left, int right) 
{
    int ans = 0;
    for (int i = left; i < right; ++i) {
        ans += v[i];
    }
    return ans % MOD;
}

int main () 
{
    int r1, r2;
    cin >> r1 >> r2;
    vector<int> v1(r1, 0);
    vector<int> v2(r2, 0);
    map<int, vector<int>> same;
    for (int i = 0; i < r1; ++i) {
        cin >> v1[i];
        same[v1[i]].push_back(i);
    }
    for (int i = 0; i < r2; ++i) {
        cin >> v2[i];
        same[v2[i]].push_back(i);
    }
    vector<int> fir;
    vector<int> sec;
    for (auto& pair : same) {
        if (pair.second.size() == 2) {
            fir.push_back(pair.second[0]);
            sec.push_back(pair.second[1]);
        }
    }
    int ans = 0;
    int left1 = 0;
    int left2 = 0;
    for (unsigned i = 0; i < fir.size(); ++i) {
        int a = totalBetween(v1, left1, fir[i]);
        int b = totalBetween(v2, left2, sec[i]);
        ans += max(a, b) % MOD;
        left1 = fir[i];
        left2 = sec[i];
    }
    ans += max(totalBetween(v1, left1, r1), totalBetween(v2, left2, r2)) % MOD;
    cout << ans;
    return 0;
}