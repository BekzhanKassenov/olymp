#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = 100000;
    int m = 100000;

    cout << n << endl;

    for (int i = 1; i <= 300; i++) {
        cout << i << ' ' << 601 << endl;
    }

    for (int i = 301; i <= 600; i++) {
        cout << i << ' ' << 603 << endl;
    }

    cout << 603 << ' ' << 602 << endl;
    cout << 602 << ' ' << 601 << endl;

    for (int i = 604; i <= n; i++) {
        cout << i << ' ' << 602 << endl;
    }

    cout << m << endl;
    int lastQuery = 0;

    for (int i = 1; i <= 300; i++) {
        for (int j = 301; j <= 600; j++) {
            cout << i << ' ' << j << endl;
            lastQuery++;
        }
    }

    for (int i = lastQuery; i < m; i++) {
        cout << rnd.next(1, n) << ' ' << rnd.next(1, n) << endl;
    }

    return 0;
}