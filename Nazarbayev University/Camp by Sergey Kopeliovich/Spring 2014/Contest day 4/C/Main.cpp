/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "binary"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD1 = 1000 * 1000 * 1000 + 7;
const ll MOD2 = MOD1 + 1;
const ll base1 = 39;
const ll base2 = 37;

const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);   
const int maxn = 2000010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

char s[maxn];
int respos, n, l;

ll power1[maxn], power2[maxn], revpower1[maxn], revpower2[maxn], hs1[maxn], hs2[maxn];

ll pow_mod(ll a, ll st, ll MOD) {
    ll res = 1;
    
    while (st) {
        if (st & 1) {
            res *= a;
            res %= MOD;
        }
            
        a *= a;
        a %= MOD;
        st >>= 1;
    }
    
    return res;
}

void build() {
    power1[0] = power2[0] = 1;
    revpower1[0] = revpower2[0] = 1;
    
    for (int i = 1; i < maxn; i++) {
        power1[i] = (power1[i - 1] * base1) % MOD1;
        power2[i] = (power2[i - 1] * base2) % MOD2;
    
        revpower1[i] = pow_mod(power1[i], MOD1 - 2, MOD1) % MOD1;
        revpower2[i] = pow_mod(power2[i], MOD2 - 2, MOD2) % MOD2;
    }
    
    hs1[0] = hs2[0] = s[0];
    
    for (int i = 1; i < n; i++) {
        hs1[i] = (s[i] + hs1[i - 1] * base1) % MOD1;
        hs2[i] = (s[i] + hs2[i - 1] * base2) % MOD2;
    }
}

pair <ll, ll> get(int l, int r) {
    ll h1 = hs1[r];
    
    if (l > 0) {
        h1 = (((h1 - hs1[l - 1] + MOD1) % MOD1) * revpower1[l]) % MOD1;
    }
    
    ll h2 = hs2[r];
    
    if (l > 0) {
        h2 = (((h2 - hs2[l - 1] + MOD2) % MOD2) * revpower2[l]) % MOD2;
    }
    
    return MP(h1, h2);
}

bool check(int len) {
    for (int i = n - len - 1; i >= 0; i--) {
        if (get(i, i + len - 1) == get(n - len, n - 1)) {
            respos = i;
            return true;
        } 
    }
    
    return false;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d\n", &n, &l);
    gets(s);
    
    build();
    
    int lt = 0, r = n;
    
    while (r - lt > 5) {
        int mid = (lt + r) >> 1;
        
        if (check(mid))
            lt = mid;
        else
            r = mid;
    }
    
    int res = lt;
    
    for (int i = lt; i <= r; i++)
        if (check(i))
            res = i;
    
    if (!check(res)) {
        putchar('0');
        s[n++] = '0';
        bool found = false;
        int pos = 0;
        
        for (int i = 0; i < n; i++) {
            found |= (s[i] == '0');
            pos = i;
        }
        
        if (found) {
            for (int i = pos + 1; l > 1; l--, i++) {
                putchar(s[i]);
                s[n++] = s[i];
            }
        } else {
            for (int i = 1; i < l; i++)
                putchar('0');
        }
        return 0;
    }
    
    respos += res;
    
    cout << res << ' ' << respos << endl;
    
    cerr << get(1, 2).F << ' ' << get(1, 2).S << endl;

    cerr << get(8, 9).F << ' ' << get(8, 9).S << endl; 
    
    for (int i = respos; l > 0; i++, l--) {
        putchar(s[i]);
        s[n++] = s[i];
    }
    
    return 0;
}
