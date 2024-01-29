#include <iostream>
#include <vector>
using namespace std;

int rec (vector<int>& nums, int index, vector<int>& dp) {

    bool found = false;
    int ans = 0;
    int size = nums.size();
    for (int i = index + 1; i < size; ++i) {

        if (nums[i] > nums[index]) {

            if (dp[i] != -1) {
                ans = max(ans, dp[i]);
            } else {
                ans = max(ans, rec(nums, i, dp));    
            }    
                found = true;
        }
    }

    if (!found) {
        dp[index] = 1;
        return 1;
    }
    
    dp[index] = ans + 1;
    return ans + 1;
}

int lengthOfLIS(vector<int>& nums) {

    vector<int> dp(nums.size(), -1);
    int size = nums.size();
    int ans = 0;

    for (int i = 0; i < size; ++i) {
        ans = max(ans, rec(nums, i, dp));
    }
    return ans;
}

int main ()
{

    vector<int> nums = {0,1,0,3,2,3};
    cout << lengthOfLIS(nums);
    return 0;
}