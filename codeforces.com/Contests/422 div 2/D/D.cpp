/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXA = 5000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int t, l, r;
long long lp[MAXA];
long long f[MAXA];
vector <int> primes;
 
void sieve() {
    for (int i = 2; i < MAXA; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
        }
    	
        for (size_t j = 0; j < primes.size() && primes[j] <= lp[i] && i * primes[j] < MAXA; j++) {
    	    lp[i * primes[j]] = primes[j];
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    sieve();
    
    cin >> t >> l >> r;

    f[1] = 0;
    for (int i = 2; i < MAXA; i++) {
        f[i] = 1ll * i * (lp[i] - 1) / 2;
        f[i] += f[i / lp[i]];
        f[i] %= MOD;
    }

    long long p = 1;
    long long ans = 0;
    for (int i = l; i <= r; i++) {
        ans += f[i] * p;
        if (ans > MOD) {
            ans %= MOD;
        }

        p = (p * t) % MOD;
    }

    cout << ans << endl;

    return 0;
}
