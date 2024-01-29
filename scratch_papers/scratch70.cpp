//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
// write your code here
    
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if (n < 2) {
        return 0;
    }
    int ans = lcm(v[0], v[1]);
    for (int i = 1; i < n - 1; ++i) {
        int ekok = lcm(v[i], v[i+1]);
        ans = gcd(ans, ekok);
    }
    cout << ans;
}
