/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXN];
int n;

int cnt[64];

int convert(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (isupper(c)) {
        return 10 + c - 'A';
    } else if (islower(c)) {
        return 36 + c - 'a';
    } else if (c == '-') {
        return 62;
    } else {
        return 63;
    }
}

void mul(int& a, int b) {
    a = (1ll * a * b) % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    n = strlen(s);

    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) {
            cnt[i & j]++;
        }
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        mul(ans, cnt[convert(s[i])]);
    }

    printf("%d\n", ans);

    return 0;
}
