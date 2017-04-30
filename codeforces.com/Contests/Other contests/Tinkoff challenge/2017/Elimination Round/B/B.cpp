/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
char s[MAXN][MAXN];
int sum_col[MAXN][MAXN];
int sum_row[MAXN][MAXN];

bool is_clear(int si, int sj, int fi, int fj) {
    if (si == fi) {
        int rnum = si;
        int lcol = min(sj, fj);
        int rcol = max(sj, fj);
        return sum_row[rnum][rcol] - sum_row[rnum][lcol - 1] == 0;
    } else if (sj == fj) {
        int cnum = sj;
        int brow = min(si, fi);
        int trow = max(si, fi);
        return sum_col[cnum][trow] - sum_col[cnum][brow - 1] == 0;
    }

    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &m);
    for (int i = 1; i <= n; i++) {
        gets(s[i] + 1);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum_row[i][j] = sum_row[i][j - 1] + (s[i][j] == '*');
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            sum_col[j][i] = sum_col[j][i - 1] + (s[i][j] == '*');
        }
    }

    int si = -1, sj = -1, fi = -1, fj = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'S') {
                si = i, sj = j;
            } else if (s[i][j] == 'T') {
                fi = i, fj = j;
            }
        }
    }

    auto test = [](bool b) {
        if (b) {
            puts("YES");
            exit(0);
        }
    };

    int ti, tj;
    for (int i = 1; i <= n; i++) {
        if (is_clear(i, sj, si, sj)) {
            ti = i, tj = fj;
            test(is_clear(i, sj, ti, tj) && is_clear(ti, tj, fi, fj));

            ti = fi, tj = sj;
            test(is_clear(i, sj, ti, tj) && is_clear(ti, tj, fi, fj));
        }
    }
    
    for (int j = 1; j <= m; j++) {
//        cerr << j << ' ' << is_clear(si, j, si, sj) << endl;
        if (is_clear(si, j, si, sj)) {
            ti = fi, tj = j;
            test(is_clear(si, j, ti, tj) && is_clear(ti, tj, fi, fj));

            if (ti == 3 && tj == 5) {
                cout << is_clear(si, j, ti, tj) << ' ' << is_clear(ti, tj, fi, fj) << endl;
            }

            ti = si, tj = fj;
            test(is_clear(si, j, ti, tj) && is_clear(ti, tj, fi, fj));
        }
    }

    puts("NO");

    return 0;
}
