#include <bits/stdc++.h>
using namespace std;

bool rec(vector<int>& buckets, int left, int target, vector<bool>& used)
{   
    if ((unsigned) left == buckets.size()) {
        return (target == 0);
    }
    if (target < 0) {
        return false;
    }

    bool b = false;
    bool a = rec(buckets, left + 1, target - buckets[left], used);
    if (!a)
        b = rec(buckets, left + 1, target, used);
    
    if (a && !b) {
        used[left] = true;
    }

    return a || b;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int sn, bn;
        cin >> sn >> bn;
        vector<int> salaries(sn, 0);
        vector<int> buckets(bn, 0);
        vector<bool> used(bn, false);

        for (int j = 0; j < sn; ++j) {
            cin >> salaries[j];
        }

        for (int j = 0; j < bn; ++j) {
            cin >> buckets[j];
        }

        bool b = true;
        for (int j = sn - 1; j >= 0; --j) {
            if (!rec(buckets, 0, salaries[j], used)) {
                b = false;
                break;
            }
        }

        if (b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}