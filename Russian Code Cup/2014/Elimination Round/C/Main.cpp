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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k;
bool ans[maxn];
map <int, vector <pair <ll, int> > > dens;
ll c[maxn], h[maxn], p, q, C, H;

ll gcd(ll a, ll b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    scanf("%d%d%I64d%I64d%d", &n, &m, &C, &H, &k);

    for (int i = 0; i < n; i++)
        scanf("%I64d", &c[i]);
    
    sort(c, c + n);
    n = unique(c, c + n) - c;
    
    for (int i = 0; i < m; i++) 
        scanf("%I64d", &h[i]);

    sort(h, h + m);
    m = unique(h, h + m) - h;

    for (int i = 0; i < k; i++) {
        scanf("%d%d", &p, &q);

        ll num = p - C * q;
        ll den = H * q - p;

        ll g = gcd(num, den);
        num /= g;
        den /= g;

        dens[num].push_back(MP(den, i));
    }

    return 0;
}
