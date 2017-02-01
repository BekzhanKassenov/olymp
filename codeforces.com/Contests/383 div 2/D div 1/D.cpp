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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <int> child[MAXN];
char c[MAXN];

int mask[MAXN], ans[MAXN];
int depth[MAXN], size[MAXN];

bool big[MAXN];
int sack[1 << 22];

int tin[MAXN], tout[MAXN], timer;
int atTin[MAXN];

void dfsPrepare(int v) {
    tin[v] = ++timer;
    atTin[tin[v]] = v;
    size[v] = 1;

    int biggest = -1;
    for (int to : child[v]) {
        mask[to] = mask[v] ^ (1 << (c[to] - 'a'));
        depth[to] = depth[v] + 1;
        
        dfsPrepare(to);
        
        size[v] += size[to];
        if (biggest == -1 || size[biggest] < size[to]) {
            biggest = to;
        }
    }

    if (biggest != -1) {
        big[biggest] = true;
    }

    tout[v] = timer;
}

void dfs(int v) {
    int biggest = -1;
    for (int to : child[v]) {
        if (!big[to]) {
            dfs(to);
            ans[v] = max(ans[v], ans[to]);
        } else {
            biggest = to;
        }
    }

    if (biggest != -1) {
        dfs(biggest);
        ans[v] = max(ans[v], ans[biggest]);
    }

    auto updateAns = [&](int ver, int mask) {
        if (sack[mask] != -1) {
            ans[v] = max(ans[v], depth[ver] + sack[mask] - 2 * depth[v]);
        }    
    };

    for (int to : child[v]) {
        if (!big[to]) {
            for (int _time = tin[to]; _time <= tout[to]; _time++) {
                int ver = atTin[_time];

                updateAns(ver, mask[ver]);
                for (int i = 0; i < 22; i++) {
                    updateAns(ver, mask[ver] ^ (1 << i));
                }
            }

            for (int _time = tin[to]; _time <= tout[to]; _time++) {
                int ver = atTin[_time];
                sack[mask[ver]] = max(sack[mask[ver]], depth[ver]);
            }
        }
    }

    updateAns(v, mask[v]);
    for (int i = 0; i < 22; i++) {
        updateAns(v, mask[v] ^ (1 << i));
    }
    sack[mask[v]] = max(sack[mask[v]], depth[v]);

    if (!big[v]) {
        for (int _time = tin[v]; _time <= tout[v]; _time++) {
            int ver = atTin[_time];
            sack[mask[ver]] = -1;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);

    for (int i = 2; i <= n; i++) {
        int par;
        scanf("%d %c\n", &par, c + i);
        child[par].push_back(i);
    }

    depth[1] = 1;
    dfsPrepare(1);

    memset(sack, 255, sizeof sack);
    dfs(1);

    for (int i = 1; i <= n; i++) {
        printf("%d%c", ans[i], " \n"[i == n]);
    }
    
    return 0;
}