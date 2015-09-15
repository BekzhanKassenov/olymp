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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char colors[] = "ROYGBIV";
int color[MAXN];
bool avail[MAXN][7];
int n;

void paint(int pos, int col) {
    color[pos] = col;

    for (int i = 1; i <= 3; i++) {
        avail[(pos + i) % n][col] = false;
        avail[(pos - i + n) % n][col] = false;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            avail[i][j] = true;
        }
    }

    for (int i = 0; i < 7; i++) {
        paint(i, i);
    }

    for (int i = 7; i < n; i++) {
        int col = -1;

        for (int j = 0; j < 7; j++) {
            if (avail[i][j]) {
                col = j;
                break;
            }
        }

        paint(i, col);
    }

    for (int i = 0; i < n; i++) {
        putchar(colors[color[i]]);
    }

    putchar('\n');
    
    return 0;
}
