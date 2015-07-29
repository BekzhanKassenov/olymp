/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 1010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, m;
char a[maxn][maxn]; 
int dist[maxn], pos_gn[maxn], pos_candy[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    
    gets(a[0]);
    
    for (int i = 0; i < n; i++) {
        gets(a[i]);
        
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'G')
                pos_gn[i] = j;
            else if (a[i][j] == 'S')    
                pos_candy[i] = j;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (pos_candy[i] < pos_gn[i]) {
            cout << -1;
            return 0;
        }
        
        dist[i] = pos_candy[i] - pos_gn[i] + 1;
    }
    
    sort(dist, dist + n);
    
    cout << unique(dist, dist + n) - dist;
    
    return 0;
}
