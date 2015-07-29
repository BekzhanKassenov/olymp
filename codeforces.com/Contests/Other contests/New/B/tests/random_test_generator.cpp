#ifndef ONLINE_JUDGE
  #include "../testlib.h"
#else
  #include "testlib.h"
#endif

#include <iostream>

using namespace std;

const int MAXN = 100000;
const int MAXK = 100000;
const int MAXNUMBER = 1000 * 1000 * 1000;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(1, MAXN);

    cout << n << ' ' << rnd.next(1, MAXK) << endl;

    for (int i = 0; i < n; i++) {
        cout << rnd.next(1, MAXNUMBER);

        if (i == n - 1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }

    return 0;
}