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
#define File "simple"

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
const int maxn = 110;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, p, a[maxn][maxn], b[maxn][maxn], cnt[maxn];
bool hard[maxn];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d%d", &n, &p);
    
    for (int i = 0; i < n; i++) {
        int mn = 0, mx = 0;
        
        for (int j = 0; j < p; j++) {
            scanf("%d", &a[i][j]);
            
            if (a[i][j] < a[i][mn])
                mn = i;
                
            if (a[i][j] > a[i][mx])
                mx = j;
        }
        
        for (int j = 0; j < p; j++) {
            if (a[i][j] == a[i][mn])
                cnt[j]++;
                
            if (a[i][j] == a[i][mx])
                hard[j] = true;
        }
    }
    
    bool output = false;
    
    for (int i = 0; i < p; i++) {
        if (cnt[i] * 2 > n && !hard[i]) {
            printf("%d ", i + 1);
            output = true;
        }
    }
    
    if (!output)
        puts("0");
    
    return 0;
}
