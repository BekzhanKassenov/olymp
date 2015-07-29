/****************************************
**   Solution by Bekzhan Kassenov    **
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

int n, l[MAXN], d[MAXN];
int cnt_d[210], sumd;
int sum[MAXN];
int sum_r[MAXN], ans = INF;
vector <int> g[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }

    for (int i = 0; i < n; i++) {
        sum[l[i]] += d[i];
        g[l[i]].push_back(d[i]);
    }

    for (int i = MAXN - 2; i >= 0; i--) {
        sum_r[i] = sum[i + 1] + sum_r[i + 1];
    }

    int cnt_l = 0;
    for (int i = 0; i < MAXN - 1; i++) {
        if (g[i].empty()) {
            continue;
        }

        int curans = sum_r[i];

        int rest = max(cnt_l - ((int)g[i].size() - 1), 0);

        int z = 0;
        for (int j = 0; j < 210; j++) {
            if (cnt_d[j] <= rest) {
                z += cnt_d[j] * j;
                rest -= cnt_d[j];
            } else if (rest > 0) {
                z += rest * j;
                rest = 0;
            }
        }

        curans += z;

        ans = min(ans, curans);

        for (size_t j = 0; j < g[i].size(); j++) {
            cnt_d[g[i][j]]++;
        }

        cnt_l += g[i].size();
    }
    
    printf("%d\n", ans);

    return 0;
}
