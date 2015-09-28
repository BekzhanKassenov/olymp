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
const int MAXN = 500;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Logo {
    int x, y;
    char c;
};  

int area, n;
Logo l[3];
char s[MAXN][MAXN];

bool go(int i, int j, int h, int w, char c) {
    if (i + h - 1 >= n || j + w - 1 >= n) {
        return false;
    }

    for (int ii = i; ii <= i + h - 1; ii++) {
        for (int jj = j; jj <= j + w - 1; jj++) {
            s[ii][jj] = c;
        }
    }
    
    return true;
}

bool get_unused(int& i, int& j) {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (s[i][j] == '\0') {
                return true;
            }
        }
    }

    return false;
}

bool can_fill(const vector <int>& p) {
    int i, j;

    bool result = true;

    for (int k = 0; k < 3; k++) {
        get_unused(i, j);

        result &= go(i, j, l[p[k]].x, l[p[k]].y, l[p[k]].c);
    }

    result &= !get_unused(i, j);

    if (result) {
        return true;
    }

    memset(s, false, sizeof s);

    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 3; i++) {
        scanf("%d%d", &l[i].x, &l[i].y);
        l[i].c = 'A' + i;
        area += l[i].x * l[i].y;
    }

    n = sqrt(area + .0);

    if (n * n != area) {
        puts("-1");
        return 0;
    }

    for (int mask = 0; mask < (1 << 3); mask++) {
        for (int i = 0; i < 3; i++) {
            if (mask & (1 << i)) {
                swap(l[i].x, l[i].y);
            }
        }

        vector <int> p(3);
        
        for (int i = 0; i < 3; i++) {
            p[i] = i;
        }

        do {
            if (can_fill(p)) {
                printf("%d\n", n);

                for (int i = 0; i < n; i++) {
                    puts(s[i]);
                }

                return 0;
            }
        } while (next_permutation(all(p)));

        for (int i = 0; i < 3; i++) {
            if (mask & (1 << i)) {
                swap(l[i].x, l[i].y);
            }
        }
    }

    puts("-1");
    
    return 0;
}
