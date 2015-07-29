#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
 
using namespace std;
 
const int inf = 1000000000;
 
struct vr
{
    int x, y;
};
 
vr vrm(int x, int y)
{
    vr ans;
    ans.x = x;
    ans.y = y;
    return ans;
}
 
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    vector <vector <int> > g(n, vector <int> (m,inf));
    int xs, ys;
    char c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            {
                cin >> c;
                if (c=='1')
                    g[i][j] = -1;
                if (c=='*')
                    {
                        xs = i;
                        ys = j;
                    }
            }
    int k;
    cin >> k;
    vector <vr> ins(k);
    for (int i = 0; i < k; i++)
        {
            cin >> ins[i].x >> ins[i].y;
            ins[i].x--;
            ins[i].y--;
        }
 
    g[xs][ys] = 0;
    queue <vr> q;
    q.push(vrm(xs,ys));
    vr z;
 
    vector <vector <vr> > pr(n, vector <vr> (m, vrm(-1, -1)));
 
    do
        {
            if (!q.empty())
                z = q.front();
            else
                break;
            q.pop();
            if (z.x > 0)
                if (g[z.x - 1][z.y] == inf)
                    q.push(vrm(z.x - 1, z.y));
                else   
                    if (g[z.x - 1][z.y] != -1 && g[z.x - 1][z.y] < g[z.x][z.y] + 1)
                        {
                            g[z.x][z.y] = g[z.x - 1][z.y] + 1;
                            pr[z.x][z.y] = vrm(z.x - 1,z.y);
                        }
           
            if (z.x < n - 1)
                if (g[z.x + 1][z.y] == inf)
                    q.push(vrm(z.x + 1, z.y));
                else   
                    if (g[z.x + 1][z.y] != -1 && g[z.x + 1][z.y] < g[z.x][z.y] + 1)
                        {
                            g[z.x][z.y] = g[z.x + 1][z.y] + 1;
                            pr[z.x][z.y] = vrm(z.x + 1, z.y);
                        }
           
            if (z.y > 0)
                if (g[z.x][z.y - 1] == inf)
                    q.push(vrm(z.x, z.y - 1));
                else   
                    if (g[z.x][z.y - 1] != -1 && g[z.x][z.y - 1] < g[z.x][z.y] + 1)
                        {
                            g[z.x][z.y] = g[z.x][z.y - 1] + 1;
                            pr[z.x][z.y] = vrm(z.x, z.y - 1);
                        }
 
            if (z.y < m - 1)
                if (g[z.x][z.y + 1] == inf)
                    q.push(vrm(z.x, z.y + 1));
                else
                    if (g[z.x][z.y + 1] != -1 && g[z.x][z.y + 1] < g[z.x][z.y] + 1)
                        {
                            g[z.x][z.y] = g[z.x][z.y + 1] + 1;
                            pr[z.x][z.y] = vrm(z.x,z.y + 1);
                        }
        }
    while (!q.empty());
 
    int ans = inf, p = inf;
    vr b;
    for (int i = 0; i < k; i++)
        {
            if (g[ins[i].x][ins[i].y] < p)
                {
                    p = g[ins[i].x][ins[i].y];
                    ans = i + 1;
                    b = ins[i];
                }
        }
    if (ans < inf)
        {
            vector <vr> w;
            cout << p << endl;
            for (int i = 0; i <= p; i++)
                {
                    cout << b.x + 1 << ' ' << b.y + 1 << endl;
                    b = pr[b.x][b.y];
                }
        }
    else
        {
            cout << -1;
            return 0;  
        }
        return 0;
}
