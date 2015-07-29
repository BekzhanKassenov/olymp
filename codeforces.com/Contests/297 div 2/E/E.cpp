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
const int MAXN = 26;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
long long S;
int a[MAXN];
int len_half;
long long f[MAXN];

long long fact(int n) {
    if (f[n] == 0) {
        if (n == 0) {
            f[n] = 1;
        } else {
            f[n] = 1ll * n * fact(n - 1);
        }
    }

    return f[n];
}

long long check(int mask, int submask, int l, int r) {
    long long res = 0;

    for (int i = l; i < r; i++) {
        int num = a[i];
        if (mask & (1 << (i - l))) {
            if (submask & (1 << (i - l))) {
                if (num <= 18) {
                    res += fact(num);
                } else {
                    res = -1;
                    break;
                }
            } else {
                res += num;
            }
        }
    }

    if (res > S) {
        res = -1;
    }

    return res;
}

map <long long, long long> Map[MAXN];
long long ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%I64d", &n, &k, &S);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    len_half = n / 2;
    for (int mask = 0; mask < (1 << len_half); mask++) {
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
            long long num = check(mask, submask, 0, len_half);
            
            if (num != -1 && __builtin_popcount(submask) <= k) {
                Map[__builtin_popcount(submask)][num]++;
            }
        }

        long long num = check(mask, 0, 0, len_half);
            
        if (num != -1) {
            Map[0][num]++;
        }
    }


    for (int mask = 0; mask < (1 << (n - len_half)); mask++) {
        for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
            long long num = check(mask, submask, len_half, n);
            int bitcount = __builtin_popcount(submask);

            //cout << mask << ' ' << submask << ' ' << S << ' ' << num << endl;

            if (num != -1 && bitcount <= k) {
                for (int cur = 0; cur <= k - bitcount; cur++) {
                    if (Map[cur].count(S - num)) {
                        ans += Map[cur][S - num];
                    }
                }
            }
        }

        long long num = check(mask, 0, len_half, n);

        if (num != -1) {
            for (int cur = 0; cur <= k; cur++) {
                if (Map[cur].count(S - num)) {
                    ans += Map[cur][S - num];
                }
            }
        }
    }

    printf("%I64d\n", ans);

    return 0;
}
