#include <iostream>
#include <cstdio>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int f;
    scanf("%d", &f);

    int cnt = 240 / 45;
    if (cnt + f >= 12) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}