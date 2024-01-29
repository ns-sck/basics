#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxFrequency(vector<int>& nums, int k) {
    
    int len = nums.size();
    sort(nums.begin(), nums.end());
    int l = 0, r = 0;
    int res = 0;
    long total = 0;

    while (r < len) {
        total += nums[r];

        while (nums[r] * static_cast<long>(r - l + 1) > total + k) {
            total -= nums[l];
            l++;
        }
        res = std::max(res, r - l + 1);
        r++;
    }
    return res;
}


int main ()
{
    vector<int> nums = {1,2,4,1,2,4,1,2,4};

    cout << maxFrequency(nums, 5);
    return 0;
}