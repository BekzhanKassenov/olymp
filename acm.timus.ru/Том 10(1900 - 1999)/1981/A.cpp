#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    long long t, n;

    cin >> n;

    t = n * (n - 3) / 2;

    if (n == 4) cout << "0 2";
    else if (n == 5) cout << "0 0";
    else if (n == 6) cout << "6 9";
    else if (n & 1) {
        cout << t << " 0";
    }
    else 
        cout << t << " " << t;
}
