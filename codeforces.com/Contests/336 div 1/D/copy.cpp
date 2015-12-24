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
const int BSIZE = 450;
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Query {
    int type;
    int x, y, z;
};


int n;
Query q[MAXN];
vector <int> child[MAXN];

int parent[MAXN];
int tin[MAXN], tout[MAXN], timer;
int highest[MAXN];

int size[MAXN], val[MAXN];
long long sumval[MAXN];

void dfs(int v) {
    tin[v] = timer++;

    highest[v] = v;
    sumval[v] = val[v];
    size[v] = 1;

    for (int to: child[v]) {
        dfs(to);
        
        sumval[v] += sumval[to];
        size[v] += size[to];
    }

    tout[v] = timer++;
}

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

void add(int v, int par) {
    highest[v] = highest[par];
    parent[v] = par;
    child[par].push_back(v);

    for (int ver = parent[v]; highest[ver] != ver; ver = parent[ver]) {
        sumval[ver] += val[v];
        size[ver]++;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &val[1]);

    scanf("%d", &n);

    int last = 2;
    for (int i = 0; i < n; i++) {
        if (i % BSIZE == 0) {
            timer = 0;
            dfs(1);
        }

        scanf("%d", &q[i].type);

        if (q[i].type == 1) {
            scanf("%d%d", &q[i].x, &q[i].y);
            val[last] = q[i].y;
            add(last, q[i].x);

            q[i].z = last;
            last++;
        } else {
            scanf("%d", &q[i].x);

            long long ans = 0;
            if (highest[q[i].x] != q[i].x) {
                ans = sumval[q[i].x] * size[q[i].x];
            } else {
                long long sval = sumval[q[i].x];
                long long sz = size[q[i].x];

                for (int j = i; j % BSIZE != 0; j--) {
                    if (q[j].type == 1) {
                        int ver = highest[q[j].z];
                        if (ancestor(q[i].x, ver)) {
                            sval += val[q[j].z];
                            sz++;
                        }
                    }
                }
                ans = sval * sz;
            }

            printf("%I64d\n", ans);
        }
    }

    return 0;
}
