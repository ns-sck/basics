//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>

using namespace std;

int main() {
// write your code here
    int row;
    int col;
    cin >> row;
    cin >> col;
    vector<vector<int>> v = {{23,0,0},{0,0,0},{0,0,35}};
    
    int rel[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    
    for (int i = 0; i < row; ++i) {
        
        for (int j = 0; j < col; ++j) {
            bool found = false;
            for (auto& coor : rel) {
                
                int r = i + coor[0];
                int c = j + coor[1];
                if (c < col && c >= 0 && r < row && r >= 0) {
                    if (v[i][j] == v[r][c]) {
                        found = true;
                        break;
                    }
                }
            }
            if (!found && v[i][j] == 23)
                v[i][j] = 35;
            if (!found && v[i][j] == 35)
                v[i][j] = 23;
        }
    }
    
    for (int i = 0; i < row; ++i) {
        
        for (int j = 0; j < col; ++j) {
            
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
	return 0;
}
