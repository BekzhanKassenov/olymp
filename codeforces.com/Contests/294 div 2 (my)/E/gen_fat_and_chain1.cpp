#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);

    int chain_size = n / 3 + 2;

    int star1_size = (n - chain_size) / 2;
    int star1_root = 1;

    int star2_root = chain_size;

    cout << n << endl;

    for (int i = 1; i < chain_size; i++) {
        cout << i << ' ' << i + 1 << endl;
    }

    for (int i = chain_size + 1; i <= chain_size + star1_size; i++) {
        cout << i << ' ' << star1_root << endl;
    }

    for (int i = chain_size + star1_size + 1; i <= n; i++) {
        cout << i << ' ' << star2_root << endl;
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