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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, q;
int _time[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);

    while (q--) {
        int t, k, d;
        scanf("%d%d%d", &t, &k, &d);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (_time[i] <= t) {
                cnt++;
            }
        }
        
        if (cnt < k) {
            puts("-1");
        } else {
            int sum = 0;
            for (int i = 0; i < n && k > 0; i++) {
                if (_time[i] <= t) {
                    sum += i + 1;
                    _time[i] = t + d;
                    k--;
                }
            }

            printf("%d\n", sum);
        }
    }   

    return 0;
}
