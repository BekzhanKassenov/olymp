/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

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

int T, n, m, p, q, t;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &T);

    while (T --> 0) {
        scanf("%d%d%d%d%d", &n, &m, &p, &q, &t);
        
        int ans;

        if (n * p + m * q <= t)
            ans = 1;
        else {
            int cnt_n = t / p;
            int cnt_m = t / q;

            int vas_n = n % cnt_n;
            if (vas_n == 0)
                vas_n = cnt_n;

            int vas_m = m % cnt_m;
            if (vas_m == 0)
                vas_m = cnt_m;

            ans = (n - vas_n) / cnt_n + (m - vas_m) / cnt_m + 1;

            if (vas_n * p + vas_m * q > t)
                ans++;
        }

        printf("%d\n", ans);
    }

    return 0;
}
