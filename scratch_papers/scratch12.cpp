#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int reductionOperations(vector<int>& nums) {
        
    sort(nums.begin(), nums.end());
    bool first = true;
    vector<int> occurence(1, 0);
    int i = 0;
    int prev = 0;
    for (int num : nums) {
        
        if (first) {
            occurence[i]++;
            first = false;
            prev = num;
            continue;
        }
        if (num != prev) {
            occurence.push_back(1);
            i++;
        } else {
            occurence[i]++;
        }
        prev = num;
    }
    int sum = 0;
    for (int j = 0; j < occurence.size(); j++) {

        sum += j * occurence[j];
    }
    return sum;
}

int main ()
{

    vector<int> nums = {1,3,5};

    cout << reductionOperations(nums);
    return 0;
}