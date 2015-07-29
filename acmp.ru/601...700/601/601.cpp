#include <iostream>
#include <cstdio>
 
using namespace std;
 
const int maxn = 100010;
 
int g[maxn][110], x, y, c, n, m, k, cur = 1;
 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    scanf("%d%d", &n, &m);
 
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &c);
        g[x][c] = y;
        g[y][c] = x;
    }
 
    scanf("%d", &k);
 
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        if (g[cur][x])
            cur = g[cur][x];
        else {
            puts("INCORRECT");
            return 0;
        }
    }
 
    printf("%d\n", cur);
 
    return 0;
}