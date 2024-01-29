//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int power(vector<vector<int>>& v, int n) {
    
    int p = 0;
    int i = n * 3;

    p += v[i+1][0] - v[i][0] + v[i+1][1] - v[i][1];
    p += v[i+2][0] - v[i][0] + v[i+2][1] - v[i][1];
    
    return p;
}

int main() {
// write your code here
    int num;
    cin >> num;
    
    vector<vector<int>> v(num * 3, vector<int>(2, 0));
    
    for (int i = 0; i < 4; i = i + 3) {
        cin >> v[i][0];
        cin >> v[i][1];
        cin >> v[i+1][0];
        cin >> v[i+1][1];
        cin >> v[i+2][0];
        cin >> v[i+2][1];
    }
    
    for (int i = 2 * 3; i < num * 3; i = i + 3) {
        v[i][0] = v[i - 6][0];
        v[i][1] = v[i - 6][1];
        v[i+1][0] = v[i - 5][0] + power(v, (i / 3) - 1);
        v[i+1][1] = v[i - 5][1] + power(v, (i / 3) - 1);
        v[i+2][0] = v[i - 4][0] + power(v, (i / 3) - 2);
        v[i+2][1] = v[i - 4][1] + power(v, (i / 3) - 2);
    }

    cout << power(v, num - 1) << '\n';
    // 1,2  10,11  10,
	return 0;
}
