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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[10][10];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    for (int i = 0; i < 8; i++) {
        gets(s[i]);
    }

    int ansA = INF, ansB = INF;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (s[i][j] == 'W') {
                bool ok = true;

                for (int k = i - 1; k >= 0; k--) {
                    if (s[k][j] != '.') {
                        ok = false;
                    }
                }

                if (ok) {
                    ansA = min(ansA, i);
                }
            } else if (s[i][j] == 'B') {
                bool ok = true;

                for (int k = i + 1; k < 8; k++) {
                    if (s[k][j] != '.') {
                        ok = false;
                    }
                }

                if (ok) {
                    ansB = min(ansB, 8 - i - 1);
                }
            }
        }
    }

    if (ansA <= ansB) {
        puts("A");
    } else {
        puts("B");
    }

    return 0;
}
