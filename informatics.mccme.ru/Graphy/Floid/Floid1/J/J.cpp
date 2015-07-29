#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
 
const double inf = 10E+3;
const double eps = 10E-9;
 
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    if (n==1)
        {
            cout << 0;
            return 0;
        }
    int s,e;
    cin >> s >> e;
    s--;
    e--;
    vector <vector <double> > g(n, vector <double> (n, inf));
    for (int i = 0; i < n; i++)
        g[i][i] = 0;
    int x,y;
    double val;
    for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> val;
            x--;
            y--;
            val /= 100;
            g[x][y] = val ;
            g[y][x] = val ;
        }
    vector <bool> used(n, false);
    vector <double> d(n, inf);
    d[s] = 0;
    for (int i = 0; i < n; i++)
        {
            int v = -1;
            for (int j = 0; j < n; j++)
                if ((v == -1 || d[v] > d[j]) && !used[j])
                    v = j;
            used[v] = true;
            if (d[v] == inf)
                continue;
            for (int j = 0; j < n; j++)
                {
                    if (g[v][j] < inf)     
                        if (d[j] > (1 - (1 - d[v]) * (1 - g[v][j])))
                            d[j] = 1 - (1 - d[v]) * (1 - g[v][j]);
                }
        }
    printf("%.15lf", d[e]);
    return 0;
}
