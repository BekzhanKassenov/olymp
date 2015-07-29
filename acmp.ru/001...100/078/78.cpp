#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int f, p;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &f, &p);

    int cur = f;

    for (int i = 0; i < 4; i++) {
        int x = (f - cur % p) / p;

        int b = cur % p + x * p;

        if (b >= f) {
            b -= p;
        }

        int a = (cur - b) / p;
        cur = a * f + b;
    }

    printf("%d\n", cur);

    return 0;   
}
