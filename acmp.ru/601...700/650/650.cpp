#pragma comment(linker, "/STACK:32000000")
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 100010;

int n, m, x, y;
vector <int> g[maxn];
long long ans, chain_ans[maxn];
bool used[maxn];

inline long long coeff(long long cnt) {
    long long res = 0;

    if (cnt > 3) {
        long long val = (cnt - 1) >> 1;

        if (!(cnt & 1))
            res += val * cnt;

        res += cnt * val * (val - 1);
    }

    return res;
}

inline bool dfs(int v, int& gl, int pr = -1) {
    used[v] = true;
    gl++;
    bool res = false;

    for (size_t i = 0; i < g[v].size(); i++) {
        int to = g[v][i];

        if (pr == to)
            continue;

        if (!used[to])
            res |= dfs(to, gl, v);
        else
            return true;
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);

        g[--x].push_back(--y);
        g[y].push_back(x);
    }

    for (int i = 3; i < maxn; i++)
        chain_ans[i] = chain_ans[i - 1] + (i - 1) * 1ll * (i - 2);

    //for (int i = 0; i < 10; i++)
    //    cout << i << ' ' << coeff(i) << endl;
    
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            int cnt = 0;
            
            if (dfs(i, cnt))
                ans += coeff(cnt);
            else
                ans += chain_ans[cnt];
        }
    }

    printf("%I64d\n", ans);

    return 0;
}
