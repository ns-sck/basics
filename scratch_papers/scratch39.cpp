#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    vector<vector<string>> v(4, vector<string>(4, ""));
    bool q0, q1, x, y, q0p, q1p, z;

    for (int i = 0; i < 4; ++i) {

        q1 = (i >> 1) & 1;
        q0 = (i >> 0) & 1;

        for (int j = 0; j < 4; ++j) {

            x = (j >> 1) & 1;
            y = (j >> 0) & 1;
            q0p = !q0 + (q0 && !y);
            q1p = (!q0 && x) + (!q1 && !y);
            z = (q0 && !x) + (q1 && y);
            
            v[i][j] += to_string(q1p) + to_string(q0p) + to_string(z);
        }
    }
    
    for (int i = 0; i < 4; ++i) {

        for (int j = 0; j < 4; ++j) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 0; i < 4; ++i) {

        for (int j = 0; j < 4; ++j) {
            
            if (v[i][j].substr(0,2) == "00")
                cout << "A," << v[i][j][2] << ' ';
            if (v[i][j].substr(0,2) == "01")
                cout << "B," << v[i][j][2] << ' ';
            if (v[i][j].substr(0,2) == "10")
                cout << "C," << v[i][j][2] << ' ';
            if (v[i][j].substr(0,2) == "11")
                cout << "D," << v[i][j][2] << ' ';
        }
        cout << '\n';
    }

    return 0;
}