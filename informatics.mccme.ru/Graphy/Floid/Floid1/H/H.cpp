#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
 
const int inf = 1000000000;
 
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    vector <vector <int> > d(n, vector <int> (n, inf));
    for (int i = 0; i < n; i++)
        d[i][i] = 0;
    int x,y,val;
    for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> val;
            x--;
            y--;
            d[x][y] = val;
            d[y][x] = val;
        }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][k] < inf && d[k][j] < inf)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    int ans = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (d[i][j] != inf)
                ans = max(ans, d[i][j]);
    cout << ans;
    return 0;
}
