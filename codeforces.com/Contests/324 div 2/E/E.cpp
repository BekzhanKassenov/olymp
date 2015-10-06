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
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, ans;
int p[MAXN], s[MAXN], pos_s[MAXN];
vector <pair <int, int> > res;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        pos_s[s[i]] = i;
    }

    for (int i = n; i > 1; i--) {
        int v = 1;
        for (int j = 1; j <= i; j++) {
            if (pos_s[p[j]] > pos_s[p[v]]) {
                v = j;
            }
        }

        if (i != v) {
            ans += abs(i - v);
            res.push_back(make_pair(i, v));
            swap(p[i], p[v]);
        }
    }

    printf("%d\n", ans);
    printf("%u\n", res.size());

    for (auto x: res) {
        printf("%d %d\n", x.first, x.second);
    }

    return 0;
}
