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
#define File "missions"

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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int a[maxn], b[maxn], maxa, maxb, n;

ll _try(int first, int second) {
    ll res = 0;
    
    res += a[first] + b[first];
    
    if (a[second] > a[first])
        res += a[second];
        
    if (b[second] > b[first])
        res += b[second];
        
    return res;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        
        if (a[i] > a[maxa])
            maxa = i;
            
        if (b[i] > b[maxb])
            maxb = i;
    }
    
    if (maxa == maxb) {
        printf("%d\n%d", a[maxa] + b[maxb], maxa + 1);
    } else {
        ll aa = _try(maxa, maxb);
        ll bb = _try(maxb, maxa);
        
        if (aa < bb) {
            printf("%I64d\n%d %d", aa, maxa + 1, maxb + 1);
        } else {
            printf("%I64d\n%d %d", bb, maxb + 1, maxa + 1);
        }
    }
    
    for (int i = 0; i < n; i++)
        if (i != maxa && i != maxb)
            printf(" %d", i + 1);
    
    return 0;
}
