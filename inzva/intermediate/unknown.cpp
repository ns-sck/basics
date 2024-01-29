#include <iostream>

#define int long long
#define modulo 1000000007

using namespace std;

int fp(int a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 1) return (a * fp(a, b - 1)) % modulo;
    int half = fp(a, b / 2);
    return (half * half) % modulo;
}

int fct(int x) {
    int result = 1;
    for (int i = 1; i <= x; i++) {
        result *= i;
        result %= modulo;
    }
    return result;
}

int32_t main() {
    int a, b;
    cin >> a >> b;
    cout << (fct(a) * fp((fct(b) * fct(a-b)) % modulo, modulo - 2)) % modulo << endl;
}