#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    
    vector<int> ans;
    map<int, vector<int>> m;
    int diagonal = 0;

    for (int i = nums.size() - 1; i >= 0; i--) {

        for (int j = 0; j < nums[i].size(); j++) {

            diagonal = i + j;
            m[diagonal].push_back(nums[i][j]);
        }
    }

    for (auto pair : m) {
        
        for (int i = 0; i < pair.second.size(); i++) {
            ans.push_back(pair.second[i]);
        }
    }
    return ans;
}
int main ()
{

 vector<vector<int>> v(5, vector<int>(5, 0));

    int a = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            v[i][j] = a;
            a++;
        }
    }

    vector<int> result = findDiagonalOrder(v);

    for (int x : result) {
        cout << x << '\n';
    }

    return 0;
}