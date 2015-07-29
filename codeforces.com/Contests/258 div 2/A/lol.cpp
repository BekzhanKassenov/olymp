#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("in", "r", stdin);
    freopen("log", "w", stderr);

    int n, m;

    while (scanf("%d %d\n", &n, &m) == 2) {
        cerr << n << ' ' << m << endl;
        int inc = n * m;
        int c = 0;

        while (inc > 0) {
            inc = inc - (m - 1) - (n - 1) - 1;
            c++;
            m--, n--;
        }
        
        if (c & 1)
            puts("Akshat");
        else
            puts("Malvika");
    }

    return 0;
}
