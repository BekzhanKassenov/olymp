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
        if (g[v][i] && !used[i])
            dfs(i);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;

    g.assign(n, vector <int> (n));

    used.assign(n, 0);

    int cnt = 0;

    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                {
                    cin >> g[i][j];

                    cnt += g[i][j];
                }
        }

    cnt /= 2;

    if (cnt != n - 1)
        {
            cout << "NO" << endl;
        }

    
    cnt = 0;

    for (int i = 0; i < n; i++)
        {
            if (!used[i])
                {
                    dfs(i);
                    cnt++;
                }
        }   

    if (cnt == 1)
        {
            cout << "YES" << endl;
        }
    else
        {
            cout << "NO" << endl;
        }
}   
