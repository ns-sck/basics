#include <iostream>
#include <vector>
#include <map>
using namespace std;

    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < rows; i++) {
            map<int, int> freq;
            int total = 0;

            for (int j = 0; j < cols; j++) {
                freq[matrix[i][j]]++;
            }

            for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
                total += it->second;
                ans = max(ans, total * it->first);
            }
        }

        return ans;
    }

int main ()
{

    vector<vector<int>> arr = {{0,0,0,0,1}};

    largestSubmatrix(arr);


    return 0;
}