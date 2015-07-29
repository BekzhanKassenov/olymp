/****************************************
**          Solution by NU #2          **
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
const int MAXN = 10010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int x[MAXN], y[MAXN], t[MAXN];
int inrow[MAXN], incol[MAXN];
int n, m;
int opx, opy;
bool turn[MAXN];

void get_opposite(int x, int y, int& xres, int& yres) {
    if (x == 0) {
        xres = incol[y];
        yres = n + 1;
    } else if (y == 0) {
        xres = n + 1;
        yres = inrow[x];
    } else if (x == n + 1) {
        xres = incol[y];
        yres = 0;
    } else if (y == n + 1) {
        xres = 0;
        yres = inrow[x];
    } else {
        assert(false);
    }
}

int get_mirror(int x, int y) {
    int result = -1;

    if (x == 0 || x == n + 1) {
        result = incol[y];
    } else if (y == 0 || y == n + 1) {
        result = inrow[x];
    } else {
        assert(false);
    }

    return result;
}

int get_len(int x, int y) {
    int mirrorx = get_mirror(x, y);
    int mirrory = inrow[mirrorx];

    int result = -1;
    if (x == 0) {
        xres = incol[y];
        yres = n + 1;
    } else if (y == 0) {
        xres = n + 1;
        yres = inrow[x];
    } else if (x == n + 1) {
        xres = incol[y];
        yres = 0;
    } else if (y == n + 1) {
        xres = 0;
        yres = inrow[x];
    } else {
        assert(false);
    }

    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &inrow[i]);
        incol[inrow[i]] = i;
    }

    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &x[i], &y[i], &t[i]);
        
        get_opposite(x[i], y[i], opx, opy);
        for (int j = 1; j <= m; j++) {
            if (opx == x[j] && opy == y[j] && t[j] + get_len(x[i], y[i]) > t[i]) {
                turn[get_mirror(x[i], y[i])] = true;
            }   
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d", (int)turn[i]);
    }
    puts("");

    return 0;
}
                                