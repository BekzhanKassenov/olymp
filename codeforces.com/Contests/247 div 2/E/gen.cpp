#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int get_rand() {
    return (rand() << 16) ^ rand();
}

int main() {
    ios_base :: sync_with_stdio(false);
    srand(time(NULL));

    freopen("in", "w", stdout);

    int n = get_rand() % 100 + 1;
    int q = get_rand() % 100 + 1;

    
    cout << n << ' ' << q << endl;

    for (int i = 0; i < n; i++)
        cout << rand() << ' ';

    cout << endl;

    for (int i = 0; i < q; i++) {
        if (rand() & 1) {
            cout << 1 << ' ' << get_rand() % n + 1 << ' ' << get_rand() << endl;
        } else {
            cout << 2 << ' ' << get_rand() << endl;
        } 
    }
    
    return 0;
}
