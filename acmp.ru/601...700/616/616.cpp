#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const int MAXN = 1010;
const int MAXV = 2010;
 
int n;
bool g[MAXN][MAXN];
int fL[MAXN], fR[MAXN];
int color[MAXV];
 
bool dfs(int v, bool isLeft) {
    int cur = isLeft ? v : v + n;
    color[cur] = 1;
 
    bool ans = false;
    for (int i = 1; i <= n && !ans; i++) {
        int other = isLeft ? i + n : i;
        bool edge = isLeft ? g[v][i] : !g[i][v];
 
        if (edge) {
            if (color[other] == 0) {
                ans |= dfs(i, !isLeft);
            } else if (color[other] == 1) {
                return true;
            }
        }
    }
 
    color[cur] = 2;
    return ans;
}
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    scanf("%d\n", &n);
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c = getchar();
            g[i][j] = c - '0';
        }
        getchar();
    }
 
    for (int i = 1; i <= n; i++) {
        bool hasCycle = false;
        if (color[i] == 0) {
            hasCycle |= dfs(i, true);
        }
 
        if (color[n + i] == 0) {
            hasCycle |= dfs(i, false);
        }
 
        if (hasCycle) {
            puts("NO");
            return 0;
        }
    }
 
    auto cmp = [](int a, int b) {
        bool isLeftA = a <= n;
        bool isLeftB = b <= n;
 
        if (isLeftA && isLeftB) {
            for (int i = 1; i <= n; i++) {
                if (g[a][i] && !g[b][i]) {
                    return true;
                }
            }
            return false;
        }
 
        if (!isLeftA && !isLeftB) {
            for (int i = 1; i <= n; i++) {
                if (!g[i][a - n] && g[i][b - n]) {
                    return true;
                }
            }
            return false;
        }
 
        if (isLeftA && !isLeftB) {
            return g[a][b - n];
        }
 
        return !g[b][a - n];
    };
 
    vector <int> a(2 * n);
 
    int it = 0;
    generate(a.begin(), a.end(), [&it] () mutable {return ++it;});
    sort(a.begin(), a.end(), cmp);
 
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] <= n) {
            fL[a[i]] = i + 1;
        } else {
            fR[a[i] - n] = i + 1;
        }
    }
 
    puts("YES");
    for (int i = 1; i <= n; i++) {
        printf("%d%c", fL[i], " \n"[i == n]);
    }
 
    for (int i = 1; i <= n; i++) {
        printf("%d%c", fR[i], " \n"[i == n]);
    }
    return 0;
}