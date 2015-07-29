#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 1010;

char s[maxn][maxn];
int n, m, a, b, tin[maxn], tout[maxn], timer;
bool start[maxn], used[maxn];

void dfs(int v) {
    used[v] = true;
    tin[v] = timer++;

    for (int i = 0; i < n; i++) {
        if (s[v][i] == '1')
            dfs(i);
    }

    tout[v] = timer++;
}

bool ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    memset(start, true, sizeof start);

    for (int i = 0; i < n; i++) {
        gets(s[i]);
        
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1')
                start[j] = false;
        }
    } 

    for (int i = 0; i < n; i++)
        if (start[i])
            dfs(i);

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);

        if (ancestor(--a, --b))
            puts("YES");
        else
            puts("No");
    }

    return 0; 
}
