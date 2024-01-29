//Brace your keyboard
//inzva community built algoleague for every algorithm enthusiast hungry for self-improvement and friendly competition. Have fun and good luck!

#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n)
{   
    if (n == 1 || n == 0)
        return false;
        
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main() {
// write your code here
    
    int n, y;
    cin >> n;
    cin >> y;
    vector<long long> age(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> age[i];
    }
    
    int count = 0;
    for (int i = 0; i < n; ++i) {
        
        for (int j = 0; j < y; ++j) {
            
            if (isPrime(age[i] + j)) {
                count++;
                break;
            }
        }
    }
    
    if (count > n - count) {
        cout << "Berat\n" << count;
    } else if (count == n - count) {
        cout << "Sura\n" << count;
    } else {
        cout << "Sura\n" << n - count;
    }
	return 0;
}
