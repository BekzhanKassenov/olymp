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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, k;

void fact(int n, vector <pair <int, int> >& d) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }

            d.emplace_back(i, cnt);
        }
    }

    if (n > 1) {
        d.emplace_back(n, 1);
    }
}

int power(int fact, int d) {
    int cur = d;
    int ans = 0;
    while (fact / cur > 0) {
        ans += fact / cur;
        cur *= d;
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    for (int _case = 1; _case <= T; _case++) {
        scanf("%d%d", &n, &k);

        vector <pair <int, int> > divs;
        fact(k, divs);

        int x = INF;
        for (const auto d : divs) {
            int p = power(n, d.first);
            x = min(x, p / d.second);
        }

        printf("Case %d: %d\n", _case, x);
    }

    return 0;
}
