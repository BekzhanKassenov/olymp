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
const char x = 'x';

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[5][5];

bool ok(int x, int y) {
    return 0 <= x && x < 4
        && 0 <= y && y < 4;
}

bool check_delta(int i, int j, int di, int dj) {
    for (int k = 0; k < 3; k++) {
        if (!ok(i, j) || s[i][j] != x) {
            return false;
        }

        i += di;
        j += dj;
    }

    return true;
}

bool check() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (check_delta(i, j, 1, 1)) {
                return true;
            }
            

            if (check_delta(i, j, 1, -1)) {
                return true;
            }

            if (check_delta(i, j, 0, 1)) {
                return true;
            }

            if (check_delta(i, j, 1, 0)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 4; i++) {
        gets(s[i]);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (s[i][j] == '.') {
                s[i][j] = x;
                if (check()) {
                    puts("YES");
                    return 0;
                }

                s[i][j] = '.';
            }
        }
    }

    puts("NO");

    return 0;
}
