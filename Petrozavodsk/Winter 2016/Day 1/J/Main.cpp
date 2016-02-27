/****************************************
**          Solution by NU #2          **
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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int p[2020], d[2020][2020], f[2020], t[4 * 2020], c[2020][2020];
int n;
    
int sum(int v, int l, int r, int A, int B) {
    if(r < A || l > B) return 0;

    if(A <= l && r <= B) return t[v];
    int mid = (l + r) / 2;
    return (sum(v * 2, l, mid, A, B) + sum(v * 2 + 1, mid + 1, r, A, B)) % MOD;
}

void update(int v, int l, int r, int index, int val) {
    if(l == r) {
        t[v] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(index <= mid) update(v * 2, l, mid, index, val); else update(v * 2 + 1, mid + 1, r, index, val);
    t[v] = (t[v * 2] + t[v * 2 + 1]) % MOD;
}

ll binpow(ll k, int n) {
    ll res = 1;
    while(n) {
        if(n & 1) {
            res = res * 1LL * k;
            res %= MOD;
        }
        k *= k;
        k %= MOD;
        n = n >> 1;
    }
    return res;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    scanf("%i", &n);

    for (int i = 1; i <= n; i++){
        scanf("%i", &p[i]);
        d[i][1] = 1;
    }    

    for(int len = 2; len <= n; len++) {
        update(1, 1, n, p[len - 1], d[len - 1][len - 1]);

        for(int i = len; i <= n; i++) {
            d[i][len] = sum(1, 1, n, 1, p[i] - 1);
            update(1, 1, n, p[i], d[i][len - 1]);
        }
        for(int i = 1; i <= n; i++)
            update(1, 1, n, i, 0);
    }
    
    for(int len = 1; len <= n; len++) {
        for(int i = 1; i <= n; i++) {
            //cout << d[i][len] << " ";
            f[len] += d[i][len];
            f[len] %= MOD;
        }
        //cout << endl;
    }

    c[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            c[i][j] %= MOD;
        }
    }

    ll res = 0;
    ll fact = 1;

    for(int i = 1; i <= n; i++) {
        fact *= i;
        fact %= MOD;
        res += ((f[i] * 1LL * c[n][i - 1]) % MOD * 1LL * fact) % MOD;
        res %= MOD;

    }
    cout << res << endl;

        
    return 0;
}
