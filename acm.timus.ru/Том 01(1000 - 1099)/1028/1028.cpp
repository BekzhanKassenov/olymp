#include <iostream>
#include <cstdio>

using namespace std;

const int MAXC = 33000;

int t[MAXC];
int n, x, y;
int ans[MAXC];

void update(int pos) {
    for (int i = pos; i < MAXC; i |= i + 1) {
        t[i]++;
    }
}

int sum(int pos) {
    int result = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) {
        result += t[i];
    }

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        ans[sum(x)]++;
        update(x);
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}