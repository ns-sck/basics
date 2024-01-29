#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main ()
{
    int a;
    int b;
    cin >> a >> b;
    int arr[b];
    
    for (int i = 0; i < b; ++i) {

        cin >> arr[i];
    }

    unordered_map<int, int> m;

    for (int i = 1;  i < a + 1; ++i) {

        m[i] = 0;
    }

    for (int i = 0; i < b; ++i) {

        m[arr[i]]++;

        bool ok = true;

        for (auto pair : m) {

            if (pair.second < 1) {

                ok = false;
                break;
            }
        }

        if (ok) {

            for (auto& pair : m) {

                pair.second--;
            }
        }
        cout << (ok ? "Y" : "N");
    }

    return 0;
}