//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> minv;
    vector<int> maxv;
    set<int> s1;
    for (int i = 0; i < n; ++i) {
        s1.insert(i+1);
    }
    set<int> s2 = s1;
    minv.push_back(v[0]);
    maxv.push_back(v[0]);
    auto it = s1.find(v[0]);
    s1.erase(it);
    auto it2 = s2.find(v[0]);
    s2.erase(it2);
    for (int i = 1; i < n; ++i) {
        if (v[i] > v[i-1]) {
            minv.push_back(v[i]);
            maxv.push_back(v[i]);
            auto it = s1.find(v[i]);
            s1.erase(it);
            auto it2 = s2.find(v[i]);
            s2.erase(it2);
        } else {
            auto it = s1.begin();  
            minv.push_back(*it);
            s1.erase(it);
            auto it2 = s2.lower_bound(v[i]);
            maxv.push_back(*--it2);
            s2.erase(it2);
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << minv[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; ++i) {
        cout << maxv[i] << ' ';
    }
	return 0;
}
