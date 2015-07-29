#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);

    cout << n << endl;

    for (int i = 2; i <= n; i++) {
        cout << 1 << ' ' << i << endl;
    }

    int m = n * n;
    cout << m << endl;

    for (int i = 0; i < m; i++) {
        cout << rnd.next(n) + 1 << ' ' << rnd.next(n) + 1 << endl;
    }

    return 0;
}