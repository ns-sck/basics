#include <iostream>
using namespace std;

int main ()
{

    bool q1;
    bool q0;
    bool x;
    bool y;

    cin >> q1;
    cin >> q0;
    cin >> x;
    cin >> y;

    bool q0p;
    bool q1p;
    bool z;

    q0p = !q0 + (q0 && !y);
    q1p = (!q0 && x) + (!q1 && !y);
    z = (q0 && !x) + (q1 && y);

    cout << q1p << q0p << ',' << z;
    return 0;
}