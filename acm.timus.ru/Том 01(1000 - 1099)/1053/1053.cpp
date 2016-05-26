#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1010;

int gcd(int a, int b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

int n;
int a[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int g = a[0];

    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
    }

    printf("%d\n", g);

    return 0;
}

