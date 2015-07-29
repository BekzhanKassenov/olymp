
#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
 
const int inf = 10000000;
 
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   
    int n, m;
    
    cin >> n >> m;
    
    vector <vector <int> > d(n, vector <int> (n, inf));
 
    for (int i = 0; i < n; i++)
        d[i][i] = 0;
   
    int x, y, val;
   
    for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> val;
            
            x--, y--, val++;
            
            d[x][y] = val;
            d[y][x] = val;
        }
   
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
               d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
 
    vector <int> b(n, 0);

    for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
    		if (i != j && d[i][j] < inf)
    			b[i] = max(b[i], d[i][j]);
    
    int ans = 0;
    
    for (int i = 1; i < n; i++)
    	if (b[ans] > b[i])
    		ans = i;

    cout << ans + 1;

    return 0;
}
