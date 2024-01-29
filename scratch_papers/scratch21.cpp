#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main ()
{
    vector<string> words = {"cat","bt","hat","tree"};
    string chars = "atach";

        int size = words.size();
        int ans = 0;

        for (int i = 0; i < size; i++) {
            
            bool check = true;
            unordered_map<char, int> m;

            for (char ch : chars) {
                m[ch]++;
            }

            for (auto a : words[i]) {

                auto it = m.find(a);

                if (it != m.end()) {
                    
                    if (it->second == 0) {
                        check = false;
                        break;
                    }
                    it->second--;
                } else {

                    check = false;
                    break;
                }
            }

            if (check)
                ans += words[i].length();
        }

    cout << ans;

    return 0;
}