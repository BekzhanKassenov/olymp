#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

int main() {
    #ifdef Local
        freopen("in", "r", stdin);
    #endif

    int a, b, d;

    while (cin >> a >> b >> d) {
        int num = a * b;
        int den = d - b;

        int g = gcd(num, den);
        num /= g;
        den /= g;

        cout << num << '/' << den << endl;
    }

    return 0;
}
