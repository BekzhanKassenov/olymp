#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > g;

vector <bool> used;

int n;

void dfs(int v)
{
    used[v] = true;

    for (int i = 0; i < n; i++)
        if (!used[i] && g[v][i])
            dfs(i);
}
//Aika
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int s;

    cin >> n >> s;

    s--;

    g.assign(n, vector <int> (n));
    used.assign(n, false);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    dfs(s);

    int ans = 0;

    for (int i = 0; i < n; i++)
        ans += used[i];

    cout << ans;

    return 0;   
}
