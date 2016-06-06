#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long uint;

const int MAXN = 35;

char digit[2] = {'4', '7'};

bool calced[MAXN][2];
uint dp[MAXN][2];
char n[MAXN];
int len;

uint f(int pos, bool smaller) {
    if (calced[pos][smaller]) {
        return dp[pos][smaller];
    }

    calced[pos][smaller] = true;
    uint& ans = dp[pos][smaller];

    if (pos == len) {
        return ans = 1;
    }

    if (smaller) {
        return ans = 1LL << (len - pos);
    }

    int upper = -1;
    if (n[pos] >= '7') {
        upper = 1;
    } else if (n[pos] >= '4') {
        upper = 0;
    }

    for (int d = 0; d <= upper; d++) {
        if (digit[d] < n[pos]) {
            ans += f(pos + 1, true);
        } else {
            ans += f(pos + 1, false);
        }
    }

    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    gets(n);
    len = strlen(n);

    uint ans = f(0, false);
    
    for (int i = 1; i < len; i++) {
        ans += 1ll << i;
    }

    printf("%lld\n", ans);

    return 0;
}
