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

    int m = rnd.next(100000) + 1;
    
    cout << m << endl;

    for (int i = 0; i < m; i++) {
        cout << rnd.next(n) + 1 << ' ' << rnd.next(n) + 1 << endl;
    }

    return 0;
}