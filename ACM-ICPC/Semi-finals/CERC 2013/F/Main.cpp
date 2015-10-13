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
const int di[] = {-1, 1, 1, -1};
const int dj[] = {1, -1, 1, -1};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
char s[20][20];

int ok(int i, int j) {
    return 0 <= i && i < 10 &&
           0 <= j && j < 10;
}

int go(int i, int j) {
    int ans = 0;
    for (int k = 0; k < 4; k++) {
        int ti = i + di[k];
        int tj = j + dj[k];

        if (ok(ti, tj) && s[ti][tj] == 'B') {
            s[ti][tj] = '#';
            
            ti += di[k];
            tj += dj[k];

            if (ok(ti, tj) && s[ti][tj] == '#') {
                ans = max(ans, go(ti, tj) + 1);
            }

            ti -= di[k];
            tj -= dj[k];

            s[ti][tj] = 'B';
        }
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &T);

    while (T--) {
        scanf("\n");
        for (int i = 0; i < 10; i++) {
            gets(s[i]);
        }

        int ans = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (s[i][j] == 'W') {
                    s[i][j] = '#';
                    ans = max(ans, go(i, j));
                    s[i][j] = 'W';
                }
            }
        }

        printf("%d\n", ans);
    }
    
    return 0;
}
