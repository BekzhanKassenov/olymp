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
const int maxn = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, l;
ll k, a[maxn];
int i = 1, j = 1;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &m);
    scanf("%I64d\n", &k);

    if (n > m)                  
        swap(n, m);

    for (int z = 0; z < n + m - 1; z++) {
        if (j == 1)
            l++;
        else if (j > m - n + 1)
            l--;

        //cout << i << ' ' << j << ' ' << l << endl;

        if (k <= l) {
            for (int q = 0; q < l; q++)
                a[q] = i-- * 1ll * j++;

            sort(a, a + l);
            printf("%I64d\n", a[k - 1]);
            
            return 0;
        }
        
        k -= l;

        j += (i == n);
        i += !(i == n);
    }

    assert(false);

    return 0;
}
