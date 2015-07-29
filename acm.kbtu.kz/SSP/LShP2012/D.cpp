#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> tin,fup;
vector <vector <int> > g;
vector <bool> used;
int n,m,timer = 0, ans = 0;

void dfs(int v,int p=-1)
{
    used[v] = true;
    timer++;
    tin[v] = fup[v] = timer;
    for (int i = 0; i < g[v].size(); i++)
        {
            int to = g[v][i];
            if (to==p)
                continue;
            if (used[to])
                fup[v] = min(fup[v],fup[to]);
            else
                {   
                    dfs(to,v);
                    fup[v] = min(fup[to], fup[v]);
                    if (fup[to]>tin[v])
                        ans++;
                }
        }
}

void init(int n)
{
    g.resize(n);
    fup.resize(n);
    tin.resize(n);
    used.resize(n);
    for (int i = 0; i < n; i++)
        {   
            used[i] = false;
            tin[i] = 0;
            fup[i] = 0;
        }
}

int main()
{
    cin >> n >> m;
    init(n);
    int x,y;
    for (int i = 0; i < m; i++)
        {   
            cin >> x >> y;
            x--;
            y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }
    dfs(0);
    cout << m - ans;
    return 0;
}
