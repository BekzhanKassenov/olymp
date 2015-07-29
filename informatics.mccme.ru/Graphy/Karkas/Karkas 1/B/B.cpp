#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > g;

vector <bool> used;

int n;

void dfs(int v, int p = -1)
{
    used[v] = true;

    if (p != -1)
        {
            cout << p + 1 << ' ' << v + 1 << endl;
        }

    for (int i = 0; i < n; i++)
        {
            if (g[v][i] && !used[i])
                dfs(i, v);
       }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;

    g.assign(n, vector <int> (n));

    used.assign(n, 0);

    int m;

    cin >> m;

    int x, y;

    for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            g[--x][--y] = 1;
            g[y][x] = 1;
        }

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs(i);

    return 0;
}
