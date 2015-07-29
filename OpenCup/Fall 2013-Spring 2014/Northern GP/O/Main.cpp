/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "operationx"

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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

vector <int> g[200];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        int x, y;
        
        for (int i = 0; i <= n; i++)
            g[i].clear();
        
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        cin >> x;
        sort(all(g[x]));
        g[x].resize(unique(all(g[x])) - g[x].begin());
        
        for (size_t i = 0; i < g[x].size(); i++)
            cout << g[x][i] << ' ';
        
        cout << endl;
    }
    
    return 0;
}
