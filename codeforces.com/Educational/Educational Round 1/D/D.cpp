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
const int MAXN = 1010;
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, 1, -1, 0};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k;
char s[MAXN][MAXN];
int comp[MAXN][MAXN];

bool ok(int x, int y) {
    return 0 <= x && x < n &&
           0 <= y && y < m;    
}

int bfs(int si, int sj, int cnum) {
    queue <int> I, J;
    comp[si][sj] = cnum;

    I.push(si);
    J.push(sj);

    int ans = 0;
    while (!I.empty()) {
        assert(!J.empty());

        int ii = I.front();
        int jj = J.front();

        I.pop();
        J.pop();

        for (int k = 0; k < 4; k++) {
            int ti = ii + di[k];
            int tj = jj + dj[k];

            if (ok(ti, tj) && comp[ti][tj] == 0) {
                if (s[ti][tj] == '.') {
                    comp[ti][tj] = cnum;
                    I.push(ti);
                    J.push(tj);
                } else {
                    ans++;
                }
            }
        }
    }

    return ans;
}

int ans[MAXN * MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d\n", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    int cnum = 1;

    while (k--) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;

        if (comp[x][y] == 0) {
            ans[cnum] = bfs(x, y, cnum);
            cnum++;
        }

        printf("%d\n", ans[comp[x][y]]);
    }

    return 0;
}
