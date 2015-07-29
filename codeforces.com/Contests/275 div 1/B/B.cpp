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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int delta[32][MAXN];
int num[32][MAXN], sum[32][MAXN];
int a[MAXN];                    
int l[MAXN], r[MAXN], q[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {    
        scanf("%d%d%d", l + i, r + i, q + i);

        for (int j = 0; j < 30; j++) {
            if (q[i] & (1 << j)) {
                delta[j][l[i]] += 1;
                delta[j][r[i] + 1] += -1;
            }
        }
    }

    int s;
    for (int bit = 0; bit < 30; bit++) {
        s = 0;
        for (int i = 1; i <= n; i++) {
            s += delta[bit][i];

            if (s > 0)
                num[bit][i] = 1;

            sum[bit][i] = sum[bit][i - 1] + num[bit][i];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 30; j++) {
            s = sum[j][r[i]] - sum[j][l[i] - 1];

            if (q[i] & (1 << j)) {
                if (s < r[i] - l[i] + 1) {
                    puts("NO");
                    return 0;
                }
            } else {
                if (s == r[i] - l[i] + 1) {
                    puts("NO");
                    return 0;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            if (num[j][i])
                a[i] += (1 << j);
        }
    }

    puts("YES");

    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    puts("");

    return 0;
}
