/*
 *  Single path
*/

#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);

    cout << n << endl;

    for (int i = 1; i < n; i++) {
        cout << (i - 1) / 3 + 1 << ' ' << i + 1 << endl;
    }

    int m = n * n;
    cout << m << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << i << ' ' << j << endl;
        }
    }

    return 0;
}