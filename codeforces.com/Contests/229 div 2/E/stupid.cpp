#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    freopen("in", "r", stdin);
    
    int n, m, w;
    
    cin >> n >> m >> w;
    
    vector <vector <ll> > a(n, vector <ll> (m));
    
    int t, x, y, _x, _y, val;
    
    while (w--) {
        cin >> t >> x >> y >> _x >> _y;
        
        if (t == 0) {
            cin >> val;
            
            for (int i = x - 1; i < _x; i++) {
                for (int j = y - 1; j < _y; j++) {
                    a[i][j] += val;
                }
            }
            
        } else {
            x--, y--, _x--, _y--;
            
            ll D = 0, I = 0;
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (x <= i && i <= _x && y <= j && j <= _y)
                        D += a[i][j];
                        
                    if ((i < x || i > _x) && (j < y || j > _y))
                        I += a[i][j]; 
                }
            }
            
            cout << D - I << endl;
        }   
    }
    
    return 0;
}
