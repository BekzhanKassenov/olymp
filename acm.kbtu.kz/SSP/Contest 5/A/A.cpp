#include <cstdio>
#include <vector>

using namespace std;

vector <vector <int> > g;

vector <int> a;

vector <int> tin, tout;

int timer = 0;

void dfs(int v)
{
    tin[v] = timer++;
    for (size_t i = 0; i < g[v].size(); i++)
        dfs(g[v][i]);
    tout[v] = timer++;
}

void init(int n)
{
    g.resize(n + 1);
    a.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
}

int main()
{
    int n;
    scanf("%d",&n);
    init(n);
    int predok = -1;
    for (int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
            if (a[i] != 0)
                g[a[i]].push_back(i);
            else
                predok = i;
        }
    dfs(predok);
    int m;
    scanf("%d",&m);
    int a,b;
    for (int i = 0; i < m; i++)
        {
            scanf("%d%d",&a,&b);
            if (tin[a] < tin[b] && tout[a] > tout[b])
                printf("%d\n",1);
            else
                printf("%d\n",0);
        }
    return 0;
}
