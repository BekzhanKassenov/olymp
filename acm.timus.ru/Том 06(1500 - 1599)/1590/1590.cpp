#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 5010;

int n;
char s[MAXN];
int lcp[2][MAXN];

int f(int n) {
    return n * (n + 1) / 2;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    n = strlen(s);

    int ans = f(n);
    int idx = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
                lcp[idx][j] = lcp[idx ^ 1][j + 1] + 1;
            } else {
                lcp[idx][j] = 0;
            }
        }

        int maxlen = 0;
        for (int j = i + 1; j < n; j++) {
            maxlen = max(maxlen, lcp[idx][j]);
        }

        ans -= maxlen;
        idx ^= 1;
    }

    printf("%d\n", ans);

    return 0;
}
