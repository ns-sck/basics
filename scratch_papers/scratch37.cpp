#include <iostream>
using namespace std;

int maxLengthBetweenEqualCharacters(string s) {
    
    int alp[26] = {-1};
    int ans = -1;
    int size = s.length();
    for (int i = 0; i < size; ++i) {

        if (alp[s[i] - 'a'] == -1) {
            alp[s[i] - 'a'] = i;

        } else {

            ans = max(ans, i - alp[s[i] - 'a'] - 1);
            alp[s[i] - 'a'] = i;
        }
    }
    return ans;
}

int main ()
{

    cout << maxLengthBetweenEqualCharacters("cbzxy");

    return 0;
}