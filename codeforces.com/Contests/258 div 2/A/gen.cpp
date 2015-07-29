#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    freopen("in", "w", stdout);

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++)
            printf("%d %d\n", i, j);
    }

    return 0;
}
