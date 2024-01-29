#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_set>
#include <algorithm>
using namespace std;

string findDifferentBinaryString(vector<string>& nums) {
    
    int len = nums.size();
    unordered_set<int> binary_set;
    for (string num : nums) {
        int binary_int = stoi(num, nullptr, 2);
        binary_set.insert(binary_int);
    }
    vector<int> ordered(binary_set.begin(), binary_set.end());
    sort(ordered.begin(), ordered.end());
    int num = 0;
    if (ordered.size() == 1) {
        num = 1 - ordered[0];
    }
    for (int i = 0; i < len - 1; i++) {

        if (ordered.size() == 2 && ordered[i] == ordered[i+1] - 1) {
            if (ordered[0] == 0)
                num = 1;
            if (ordered[0] == 3)
                num = 0;
        }
        if (ordered[i+1] != ordered[i] + 1) {
            num = ordered[i] + 1;
            break;
        }
    }
    bitset<sizeof(int) * 8> bin(num);
    string result = bin.to_string().substr(bin.size() - len, len);
    return result;
}

int main ()
{

    vector<string> nums = {"00","01"};
    cout << findDifferentBinaryString(nums);

    return 0;
}

