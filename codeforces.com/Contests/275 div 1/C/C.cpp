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
const int MAXN = 60;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXN][MAXN];
double p_get[1 << 20];
double p_win[1 << 20];
long long found[1 << 20];
int n, len;
int cnt[52], timer, _time[52];

inline int index(char c) {
    if (islower(c))
        return c - 'a';

    return 26 + c - 'A';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
        gets(s[i]);

    len = strlen(s[0]);
    p_get[0] = 1.0;
    double E = 0;

    for (int mask = 1; mask < (1 << len); mask++) {
        for (int i = 0; i < len; i++) {
            if (!(mask & (1 << i)))
                continue;

            int prmask = mask ^ (1 << i);
            p_get[mask] += p_get[prmask];
            found[mask] = found[prmask];

            timer++;
            for (int j = 0; j < n; j++) {
                if (!(found[mask] & (1ll << j))) {
                    if (timer == _time[index(s[j][i])])
                        cnt[index(s[j][i])]++;
                    else {
                        _time[index(s[j][i])] = timer;
                        cnt[index(s[j][i])] = 1;
                    }
                }
            }

            int new_found = 0;
            for (int j = 0; j < n; j++) {
                if (!(found[mask] & (1ll << j)) && _time[index(s[j][i])] == timer && cnt[index(s[j][i])] == 1) {
                    found[mask] |= (1ll << j);
                    new_found++;
                }
            }

            p_win[mask] += new_found * p_get[prmask];
        }

        int bits = __builtin_popcount(mask);
        double den = (len - bits + 1.0);
        p_win[mask] /= den;
        p_get[mask] /= den;

        E += p_win[mask] * bits;
    }

    E /= (n + .0);

    printf("%.14lf", E);
    
    return 0;
}
