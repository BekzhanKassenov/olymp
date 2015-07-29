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
#define File "borg"

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
const int maxn = 510;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, l, degree[maxn], path[maxn], tot_degree;
vector <int> g[maxn];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d", &n, &l);
    
    for (int i = 0; i < l; i++)
        scanf("%d", path + i);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", degree + i);
        
        tot_degree += degree[i];
        g[i].resize(degree[i]);
        
        for (int j = 0; j < degree[i]; j++)
            scanf("%d", &g[i][j]);
    }
    
    double res = 1;
    
    for (int i = 0; i < l; i++) {
        double sum = (degree[path[i]] + .0) / (tot_degree);
        
        if (i < l - 1) {
            double sum0 = (degree[path[i + 1]] + .0) / tot_degree;
            res += (sum0 + sum);
        } else
            res *= sum;
    }
    
    printf("%.10lf", 1 - res);
    
    return 0;
}
