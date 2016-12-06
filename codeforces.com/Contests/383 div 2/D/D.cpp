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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, maxW;
vector <int> g[MAXN];
vector <vector <int> > groups;

long long w[MAXN], b[MAXN];
bool used[MAXN];

void dfs(int v, vector <int>& group) {
    used[v] = true;
    group.push_back(v);

    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to, group);
        }   
    }
}

long long mem1[MAXN], mem2[MAXN];
long long *cur = mem1, *prev_ = mem2;

void clear(long long *ptr) {
    memset(ptr, 0, sizeof(long long) * MAXN);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &m, &maxW);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", w + i);
    }

    for (int i = 1; i <= n; i++) {
        scanf("%lld", b + i);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <int> group;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i, group);
            groups.emplace_back(group);
            group.clear();
        }
    }

    int iter = 0;
    clear(prev_);
    clear(cur);
    for (const vector <int>& group : groups) {
        long long sumB = 0;
        long long sumW = 0;
        for (int num : group) {
            sumB += b[num];
            sumW += w[num];
        }

        if (iter == 0) {
            if (sumW < MAXN) {
                cur[sumW] = sumB;
            }

            for (int num: group) {
                cur[w[num]] = max(cur[w[num]], b[num]);
            }
        } else {
            for (int curW = 0; curW < MAXN; curW++) {
                if (prev_[curW] != -1) {
                    cur[curW] = max(cur[curW], prev_[curW]);
                    if (curW + sumW < MAXN) {
                        cur[curW + sumW] = max(cur[curW + sumW], prev_[curW] + sumB);
                    }

                    for (int num : group) {
                        if (curW + w[num] < MAXN) {
                            cur[curW + w[num]] = max(cur[curW + w[num]], prev_[curW] + b[num]);
                        }
                    }
                }
            }
        }

        swap(prev_, cur);
        clear(cur);
        iter++;
    }

    long long ans = 0;
    for (int i = 0; i <= maxW; i++) {
        ans = max(ans, prev_[i]);
    }

    printf("%lld\n", ans);

    return 0;
}
