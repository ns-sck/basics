#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string txt;
    string out;
    char prev = '\0';
    int count = 0;

    cout << "enter a text: ";
    getline(cin, txt);

    for (char ch : txt) {

        if (ch == prev) {
            count++;
        } else {
            char temp = prev + count;
            out += temp;
            count = 0;
        }
        prev = ch;

        if (ch == 'z' || ch == ' ')
            prev = ' ';
    }

    out += prev + count;

    cout << out;
    return 0;
}