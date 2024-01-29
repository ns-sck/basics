#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main ()
{
    string s = ")()())";
    map<int, int> m;
    int size = s.length();
    for (int i = 0; i < size - 1; i++) {

        if (s[i] == ')') {
            continue;
        }

        int op = 1;
        int cl = 0;
        int j = i + 1;
        int end = i;
        while (cl <= op && j < size) {

            if (s[j] == '(') {
                op++;
                j++;
            } else {
                cl++;
                j++;
            }
            if (cl == op) {
                end = j - 1;
            }
        }
        m[i] = end;
        cout << end;
    }
    int ans = 0;
    for (auto pair : m) {
        ans = max(ans, pair.second - pair.first - (pair.first != pair.second));
    }

    return 0;
}