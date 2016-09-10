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
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, 1, -1, 0};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
char s[MAXN][MAXN];
bool cutpoint[MAXN][MAXN];
bool used[MAXN][MAXN];
int tin[MAXN][MAXN], fup[MAXN][MAXN];
int timer = 0;

bool ok(int i, int j) {
    return 0 <= i && i < n
        && 0 <= j && j < m
        && (s[i][j] == '.' || s[i][j] == '?');
}

void dfs(int i, int j, int pi = -1, int pj = -1) {
    fup[i][j] = tin[i][j] = timer++;
    used[i][j] = true;
    int children = 0;
    for (int k = 0; k < 4; k++) {
        int ti = i + di[k];
        int tj = j + dj[k];

        if (ti == pi && tj == pj) {
            continue;
        }

        if (ok(ti, tj)) {
            if (used[ti][tj]) {
                fup[i][j] = min(fup[i][j], tin[ti][tj]);
            } else {
                children++;
                dfs(ti, tj, i, j);
                fup[i][j] = min(fup[i][j], fup[ti][tj]);
                if (tin[i][j] <= fup[ti][tj] && pi != -1) {
                    cutpoint[i][j] = true;
                }
            }
        }
    }

    if (pi == -1 && children > 1) {
        cutpoint[i][j] = true;
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }
    
    int posi = -1, posj = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                posi = i, posj = j;
            }
        }
    }

    dfs(posi, posj);

    bool ambig = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.' && !used[i][j]) {
                puts("Impossible");
                return 0;
            } else if (s[i][j] == '?') {
                if (used[i][j] && !cutpoint[i][j]) {
                    ambig = true;
                }

                if (used[i][j]) {
                    s[i][j] = '.';
                } else {
                    s[i][j] = '#';
                }
            }
        }
    }
    
    if (ambig) {
        puts("Ambiguous");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        puts(s[i]);
    }

    return 0;
}
