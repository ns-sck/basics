#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int range_size = l.size();
        vector<bool> ans(range_size, false);
        for (int i = 0; i < range_size; i++) {

            bool b = true;
            int left = l[i];
            int right = r[i];
            int max_num = -100000;
            int min_num = 100000;
            int min_diff = 200000;

            for (int j = left; j < right; j++) {
                
                min_diff = min(min_diff, abs(nums[j] - nums[j+1]));
                max_num = max(max_num, nums[j]);
                min_num = min(min_num, nums[j]);
            }
            max_num = max(max_num, nums[right]);
            min_num = min(min_num, nums[right]);

            double diff = (double)(max_num - min_num) / (double)(right - left);
            int diff2 = diff;
            double int_p;
            double frac = modf(diff, &int_p);   
            if (frac || min_diff < diff2) {
                b = false;
            } else if (!diff2) {
                ans[i] = true;
                continue;
            }else {
// 2,4,4,4,6
                for (int j = left; j < right; j++) {
                    
                    if (abs(nums[j] - nums[j+1]) % diff2) {
                        b = false;
                        cout << abs(nums[j] - nums[j+1]) << ' ';
                    }
                }
            }

            ans[i] = b;
        }
        return ans;
    }
int main ()
{

    vector<int> nums = {4,6,5,9,3,7};
    vector<int> l = {0,0,2};
    vector<int> r = {2,3,5};
    cout << nums[171];
    cout << nums[240];
    for (bool x : checkArithmeticSubarrays(nums, l, r)) {
        cout << x << '\n';
    }
    return 0;
}