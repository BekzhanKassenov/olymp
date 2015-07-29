/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

const int size = 100010;

ll fact[size], revfact[size];

ll pow_mod(ll a, int st) {
    if (st == 0)
        return 1;
    
    if (st & 1) {
        return (pow_mod(a, st - 1) * a) % MOD;
    }

    ll b = pow_mod(a, st >> 1);

    return (b * b) % MOD; 
}

void build() {
    fact[0] = 1;
    revfact[0] = 1;
    
    for (int i = 1; i < size; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        revfact[i] = pow_mod(fact[i], MOD - 2);
    }
}

ll C(ll k, ll n) {
    return (fact[n] * revfact[k] % MOD) * revfact[n - k] % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    
    int n;
    
    cin >> n;
    
    int a;
    
    map <int, int> Map;
    
    build();
    
    for (int i = 0; i < n; i++) {
        cin >> a;
        
        int k = sqrt(a);
        
        for (int j = 2; j <= k; j++) {
            while (a % j == 0) {
                a /= j;
                Map[j]++;
            }
        }
        
        if (a > 1)
            Map[a]++;
    }
    
    ll res = 1;
    
    for (map <int, int> :: iterator it = Map.begin(); it != Map.end(); it++) {
        res *= C(n - 1, it -> S + n - 1);
        res %= MOD;
    }
    
    cout << res;
    
    return 0;
}
