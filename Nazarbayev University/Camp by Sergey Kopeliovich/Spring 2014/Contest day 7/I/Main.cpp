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
#define File "cross"

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
const int maxn = 100010;
const int maxm = 300010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, m;
pair <int, int> edge[maxm];
int par[maxn];

int get_par(int n) {
    if (par[n] == n)
        return n;
        
    return par[n] = get_par(par[n]);
}

bool uni(int a, int b) {
    a = get_par(a);
    b = get_par(b);
    
    if (a != b) {
        par[a] = b;
        return true;
    } 
    
    return false;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &edge[i].F, &edge[i].S);
    }
    
    for (int i = 1; i <= n; i++)
        par[i] = i;
    
    vector <int> ans;
    
    for (int i = 0; i < m; i++) {
        if (uni(edge[i].F, edge[i].S)) {
            ans.push_back(i + 1);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (get_par(i) != get_par(1)) {
            puts("-1");
            return 0;
        }
    }
    
    printf("%u\n", ans.size());
    
    for (size_t i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    
    return 0;
}
