#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MOD = 1000000007;
int g[100000][3], n, m, a, b, res, gl;
long long ans = 1;
const long long lim = 8e15;
bool used[100000];
char c;

inline int read_int() {
    res = 0;

    do {
        c = getc(stdin);
    } while (c < '0' || c > '9');

    do {
        res = res * 10 + c - '0';
        c = getc(stdin);
    } while (c >= '0' && c <= '9');

    return res;
}

void dfs(int v) {
    used[v] = true;
    char cnt = 0;
    gl++;

    for (int i = 1; i <= g[v][0]; i++) {
        if (used[g[v][i]])
        	cnt++;    
        else
            dfs(g[v][i]);  
    }

    if (cnt == 2) {
        ans *= gl;

        if (ans > lim)
            ans %= MOD;
    }
    gl--;
}

int main() {
    freopen("fortification.in", "r", stdin);
    freopen("fortification.out", "w", stdout);

    n = read_int(), m = read_int();

    for (int i = 0; i < m; i++) {
        a = read_int(), b = read_int();
        a--, b--;

        g[a][++g[a][0]] = b;
        g[b][++g[b][0]] = a;
    }

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs(i);

    printf("%I64d", ans % MOD);

    return 0;
}
