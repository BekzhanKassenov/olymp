#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int fastAbs(int n) {
    return (n ^ (n >> 31)) - (n >> 31);
}

void show(int n) {
    if (n < 0)
        cout << 1;
    else
        cout << 0;

    for (int i = 31; i >= 0; i--)
        if (n & (1 << i))
            cout << 1;
        else
            cout << 0;
}

int main() {
    //int n = -5000;

    //show(n);

    for (int i = -5000; i <= 5000; i++)
        if (fastAbs(i) != abs(i)) {
            cout << "No";
            return 0;
        }

    cout << "Yes";  

    return 0;
}
