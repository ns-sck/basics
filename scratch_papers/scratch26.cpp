#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main ()
{
    vector<string> words = {"word","good","best","good"};
    string s = "wordgoodgoodgoodbestword";
    int size = s.length();
    int size2 = words.size();
    int len = words[0].length();
    vector<int> ans;
    unordered_map<string, int> m1;
    for (int i = 0; i < size2; i++) {
        m1[words[i]]++;
    }
    for (int i = 0; i <= size - (size2 * len); i++) {
        
        bool ok = true;
        unordered_map<string, int> m2 = m1;
        int j = i;
        int count = size2;
        while (j + len <= size && m2.find(s.substr(j, len)) != m2.end() && count > 0) {

            m2[s.substr(j, len)]--;
            j += len;
            count--;
        }

        for (int k = 0; k < size2; k++) {

            if (m2[words[k]] != 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans.push_back(i);
        }

    }

    return 0;
}