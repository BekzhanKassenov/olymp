#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct edge
{
    int from,to, cost;
    bool used;
};

int main()
{
    int n,m;
    cin >> n >> m;
    vector <edge> g(m);
    for (int i=0;i<m;i++)
        {
            int x,y;
            cin >> x >> y;
            g[i].from = x-1;
            g[i].to = y-1;
            cin >> g[i].cost;
            g[i].used=false;
        }
    vector <bool> u(n,false);
    u[0]=true;
    for (int z=0;z<n-1;z++)
        {
            edge k;
            k.cost=-1;
            int uk=0;
            for (int i=0;i<m;i++)
                {
                    if (u[g[i].to] ^ u[g[i].from]==true)
                        if (k.cost==-1 || g[i].cost<k.cost)
                            {
                                k = g[i];
                                uk = i;
                            }
                }
            if (k.cost==-1)
                {
                    for (int i=0;i<m;i++)
                        cout << "NO" << endl;
                    return 0;
                }
            g[uk].used=true;
            u[k.to]=true;
            u[k.from]=true;
        }
   for (int i=0;i<m;++i)
    if (!g[i].used)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
   return 0;
}
