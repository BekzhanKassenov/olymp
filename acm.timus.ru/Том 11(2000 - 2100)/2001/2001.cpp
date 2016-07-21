#include <iostream>
#include <cstdio>

using namespace std;

int a1, a2, a3;
int b1, b2, b3;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &a1, &b1);
    scanf("%d%d", &a2, &b2);
    scanf("%d%d", &a3, &b3);

    printf("%d %d\n", a1 - a3, b1 - b2);

    return 0;
}