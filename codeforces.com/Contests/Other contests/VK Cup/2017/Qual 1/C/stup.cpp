/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> point;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1010;
const map <char, point> delta {
    {'D', {1, 0}},
    {'L', {0, -1}},
    {'R', {0, 1}},
    {'U', {-1, 0}}
};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

point& operator += (point& a, const point& b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

point operator + (point a, const point& b) {
    return a += b;
}

int n, m, k;
char a[MAXN][MAXN];
int dist[MAXN][MAXN];
point start{-1, -1};

bool ok(const point& p) {
    return 0 <= p.x && p.x < n
        && 0 <= p.y && p.y < m; 
}

bool found;
char ans[MAXN];
char s[MAXN];
int sn;

bool check() {
    point cur = start;
    for (char dir : s) {
        if (dir) {
            cur += delta.at(dir);
            if (!ok(cur) || a[cur.x][cur.y] == '*') {
                return false;
            }
        }
    }

    return cur == start;
}

void work(int d, int u, int l, int r) {
    if (d == 0 && u == 0 && l == 0 && r == 0) {
        s[sn] = '\0';
        //puts(s);
        if (check()) {
            if (!found || strcmp(s, ans) < 0) {
                strcpy(ans, s);
                found = true;
            }
        }

        return;
    }

    if (d > 0) {
        s[sn++] = 'D';
        work(d - 1, u, l, r);
        sn--;
    }

    if (u > 0) {
        s[sn++] = 'U';
        work(d, u - 1, l, r);
        sn--;
    }

    if (l > 0) {
        s[sn++] = 'L';
        work(d, u, l - 1, r);
        sn--;
    }

    if (r > 0) {
        s[sn++] = 'R';
        work(d, u, l, r - 1);
        sn--;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d\n", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        gets(a[i]);
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'X') {
                start = {i, j};
            }
        }
    }

    if (k & 1) {
        puts("IMPOSSIBLE");
        return 0;
    }

    bool have_move = false;
    for (char dir : {'D', 'L', 'R', 'U'}) {
        point nx = start + delta.at(dir);
        if (ok(nx) && a[nx.x][nx.y] != '*') {
            have_move = true;
        }
    }

    if (!have_move) {
        puts("IMPOSSIBLE");
        return 0;
    }

    for (int d = 0; d <= k / 2; d++) {
        int l = k / 2 - d;
        work(d, d, l, l);
    }

    puts(ans);

    return 0;
}
