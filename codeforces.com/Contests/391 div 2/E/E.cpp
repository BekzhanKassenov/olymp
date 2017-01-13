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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int q;
vector <int> divs[MAXN];
bool prime[MAXN];
int mu[MAXN];
int primecnt[MAXN];

void prepare() {
    prime[1] = false;
    mu[1] = 1;

    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            divs[j].push_back(i);
        }

        if (divs[i].size() == 2u) {
            prime[i] = true;
        }
    }

    for (int i = 2; i < MAXN; i++) {
        for (int d : divs[i]) {
            if (prime[i]) {
                primecnt[i]++;
            }
        }

        int cnt = 0;
        for (int d : divs[i]) {
            if (i % sqr(d) == 0) {
                cnt = -1;
                break;
            }
        }
        if (cnt != -1) {
            if (cnt & 1) {
                mu[i] = -1;
            } else {
                mu[i] = 1;
            }
        }
    }

    for (int i = 2; i < MAXN; i++) {
        vector <int> temp;
        for (int d : divs[i]) {
            if (mu[d] != 0) {
                temp.push_back(d);
            }
        }

        divs[d].swap(temp);
    }
}

int binpow(int b, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = (1ll * res * b) % MOD;
        }

        b = (1ll * b * b) % MOD;
        n >>= 1;
    }

    return res;
}

int f(int r, int n) {
    if (mu[n] != 0) {
        return binpow(r + 2, primecnt[n]);
    }

    int ans = 0;
    for (int d : divs[n]) {
        ans += mu[d] * f(r + 1, n / d);
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    prepare();

    return 0;
}
