/****************************************
**          Solution by NU #2          **
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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

vector <pair <int, int> > nxt[MAXN];
map <int, int> goDP[MAXN];

int n;
int par[MAXN], link[MAXN];
int pchar[MAXN];

int getLink(int v);
int go(int v, int c);

int getLink(int v) {
    if (link[v] == -1) {
        if (v == 0 || par[v] == 0) {
            link[v] = 0;
        } else {
            link[v] = go(getLink(par[v]), pchar[v]);
        }
    }

    return link[v];
}

int go(int v, int c) {
    if (!goDP[v].count(c)) {
        auto iter = lower_bound(all(nxt[v]), make_pair(c, 0), [](const pair <int, int>& a, const pair <int, int>& b) {
            return a.first < b.first;
        });

        if (iter != nxt[v].end() && iter->first == c) {
            goDP[v][c] = iter->second;
        } else {
            goDP[v][c] = (v == 0) ? 0 : go(getLink(v), c);
        }
    }

    return goDP[v][c];
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &par[i]);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &pchar[i]);
    }

    memset(link, 255, sizeof link);

    for (int i = 1; i <= n; i++) {
        nxt[par[i]].emplace_back(pchar[i], i);
    }

    for (int i = 0; i <= n; i++) {
        sort(all(nxt[i]));
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", getLink(i));
    }
    puts("");
    
    return 0;
}
