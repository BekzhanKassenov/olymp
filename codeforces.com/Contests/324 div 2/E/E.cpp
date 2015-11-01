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
int p[MAXN], s[MAXN];
int pinv[MAXN], sinv[MAXN];
vector <pair <int, int> > swaps;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        pinv[p[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        sinv[s[i]] = i;
    }

    for (int i = n; i >= 1; i--) {
        int pos = pinv[s[i]];

        for (int j = pos + 1; j <= n; j++) {
            if (sinv[p[j]] <= pos) {
                ans += abs(j - pos);
                swaps.emplace_back(pos, j);
                swap(p[pos], p[j]);
                pos = j;
            }
        }
    }

    printf("%d\n%u\n", ans, swaps.size());
    for (auto p: swaps) {
        printf("%d %d\n", p.first, p.second);
    }

    return 0;
}
