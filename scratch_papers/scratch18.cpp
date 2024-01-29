#include <iostream>
#include <vector>
using namespace std;

int numberOfWays(string corridor) {
        
    int len = corridor.length();
    vector<int> start;
    vector<int> end;
    int count1 = 0;

    for (int i = 0; i < len; i++) {

        if (corridor[i] == 'S') {

            count1++;
        }

        if (count1 == 2) {

            start.push_back(i);
            count1 = 0;
        }

        if (i != 0 && count1 == 0 && i < len - 1 && corridor[i+1] == 'S') {

            end.push_back(i);
        }
    }

    int ans = 0;
    int size = start.size();

    for (int i = 0; i < size - 1; i++) {

        ans += end[i] - start[i] + 1;
    }

    return ans;
}

int main ()
{

    string a = "PPSPSPSSPSPSPSPPPPPSPSPSPPPSSPPPSPSSPSPSPSSPS";

    cout << numberOfWays(a);

    return 0;
}