#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
 
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    vector <vector <bool> > g(n, vector <bool> (n,false));
    int q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            {
                cin >> q;
                g[i][j] = q;
           }
   
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = g[i][j] | (g[i][k] & g[k][j]);
 
    for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << g[i][j] << ' ';
            cout << endl;
        }
    return 0;
}
 