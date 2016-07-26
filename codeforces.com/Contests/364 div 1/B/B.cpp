/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, x, y;
bool row[MAXN], col[MAXN];
int rows, cols;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);
    rows = cols = n;
    long long cur = 1ll * n * n;
    
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        
        int hit = n + n - 1;
        if (!row[x] && !col[y]) {
            hit = rows + cols - 1;
            rows--, cols--;
        } else if (row[x] && !col[y]) {
            hit = rows;   
            cols--;     
        } else if (!row[x] && col[y]) {
            hit = cols;
            rows--;
        } else {
            hit = 0; 
        }
        
        cur -= hit;
        row[x] = true;
        col[y] = true;
        
        printf("%lld ", cur);
    }
    
    puts("");

    return 0;
}
