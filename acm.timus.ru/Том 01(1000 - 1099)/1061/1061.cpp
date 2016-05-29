#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

const int MAXN = 100010;

int n, k;
char buf[81];
char s[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    scanf("%d%d\n", &n, &k);
    
    while (gets(buf) != NULL) {
        strcat(s, buf);
    }

    if (k > n) {
        puts("0");
        return 0;
    }

    int sum = 0, cnt = 0;

    for (int i = 0; i < k; i++) {
        if (s[i] == '*') {
            cnt++;
        } else {
            sum += s[i] - '0';
        }
    }

    int ans = -1;
    int anssum = n + 1;
    
    if (cnt == 0) {
        ans = 0;
        anssum = sum;
    }

    for (int i = 0; i + k < n; i++) {
        if (s[i] == '*') {
            cnt--;
        } else {
            sum -= s[i] - '0';
        }

        if (s[i + k] == '*') {
            cnt++;
        } else {
            sum += s[i + k] - '0';
        }

        if (cnt == 0 && sum < anssum) {
            ans = i + 1;
            anssum = sum;
        }
    }

    printf("%d\n", ans + 1);

    return 0;
}
