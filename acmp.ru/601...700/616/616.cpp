#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1010;
const int INF = 1000 * 1000 * 1000;

int n;
char a[MAXN][MAXN];
bool g[MAXN][MAXN];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
        gets(a[i]);

    return 0;
}
