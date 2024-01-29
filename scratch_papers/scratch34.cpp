#include <iostream>
#include <vector>
#include <map>
using namespace std;


int minCost(string colors, vector<int>& neededTime) {
        
    int ans = 0;

    for (unsigned int i = 0; i < colors.size() - 1; ++i) {

        if (colors[i] == colors[i+1]) {
            
            int index = i;
            while (i + 1 < colors.size() && colors[i] == colors[i+1]) {
                if (neededTime[i+1] < neededTime[index]) {
                    index = i + 1;
                    i++;
                }
            }
            ans += neededTime[index];
        }
    }
    
    return ans;
}

int main ()
{   
    vector<int> time = {1,2,3,4,1};
    cout << minCost("aabaa", time);
    return 0;
}