#include <iostream>
#include <vector>
using namespace std;

int peopleAwareOfSecret(int n, int delay, int forget) {
    
    vector<long long> people_aware(n, 0);
    vector<long long> people_learn(n, 0);

    int total = 0;
    for (int i = 0; i < delay && i < n; i++) {
        people_aware[i] = 1;
        people_learn[i] = 0;
    }
    people_learn[0] = 1;
    
    for (int i = delay; i < n; i++) {
        int j = delay;

        while (j < forget && i - j >= 0) {
            people_learn[i] += people_learn[i - j];
            people_aware[i] += people_learn[i - j];
            j++;
        }
        if (i - forget >= 0)
            people_aware[i] += people_aware[i - 1] - people_learn[i - forget];
        else
            people_aware[i] += people_aware[i - 1];
    }
    return (people_aware[n - 1] % static_cast<int>(1e9 + 7));   
}

int main ()
{
    int x = peopleAwareOfSecret(999, 2, 7);
    cout << x;
    return 0;
}