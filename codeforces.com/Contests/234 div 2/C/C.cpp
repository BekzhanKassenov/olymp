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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, m, dx, dy, dz, p, x, y;
int nn, mm;

void make_dx(int& x, int& y) {
    for (int i = 0; i < dx; i++) {
        int xx = y;
        int yy = nn - x + 1;
        swap(nn, mm);
        x = xx;
        y = yy;
    }
}

void make_dy(int& x, int& y) {
    if (dy)
        y = (mm - y + 1);
}

void make_dz(int& x, int& y) {
    for (int i = 0; i < dz; i++) {
        int yy = x;
        int xx = mm - y + 1;
        swap(nn, mm);
        x = xx;
        y = yy;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    scanf("%d%d%d%d%d%d", &n, &m, &dx, &dy, &dz, &p);
    
    dx %= 4;
    dy %= 2;
    dz %= 4;
    
    for (int i = 0; i < p; i++) {
        scanf("%d%d", &x, &y);
        
        nn = n, mm = m;
        make_dx(x, y);
        make_dy(x, y);
        make_dz(x, y);
        
        printf("%d %d\n", x, y);
        
    }
        
    return 0;
}
