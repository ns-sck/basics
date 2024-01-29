#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> find_sequence(string s)
{   
    int startIndex = 0;
    int endIndex = 0;
    for (int i = 0; i < s.length() - 1; ++i) {

        if (s[i+1] - s[i] == 1) {

            startIndex = i;
            endIndex = i + 1;

            while (i < s.length() - 1 && s[i+1] - s[i] == 1) {
                endIndex = i + 1;
                i++;
            }
        }
    }
    vector<int> ans;
    ans.push_back(startIndex);
    ans.push_back(endIndex - startIndex + (endIndex != 0));
    return ans;
}

string compress_string(string s)
{
    string ans;

    for (int i = 0; i < s.length(); ++i) {

        ans += s[i];
        int count = 0;

        while (i + 1 < s.length() && s[i+1] - s[i] == 1) {
            count++;
            i++;
        }
        if (count != 0) {
            ans += to_string(count);
        }
    }

    return ans;
}

int main()
{

    for (auto& a : find_sequence("hellopqrst")) {
        cout << a << ' ';
    }
    cout << '\n';
    cout << compress_string("abcdefghellopqrst");

    return 0;
}