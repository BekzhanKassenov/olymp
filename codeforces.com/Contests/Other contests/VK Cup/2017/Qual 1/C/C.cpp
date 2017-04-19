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

bool ok(const point& p) {
    return 0 <= p.x && p.x < n
        && 0 <= p.y && p.y < m; 
}

char s[MAXN * MAXN];
int sn;

void dfs(const point& v) {
    for (char dir : {'D', 'L', 'R', 'U'}) {
        point nx = v + delta.at(dir);
        if (ok(nx) && a[nx.x][nx.y] != '*' && dist[nx.x][nx.y] <= k - sn - 1) {
            s[sn++] = dir;
            dfs(nx);
            return;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d\n", &n, &m, &k);

    point start{-1, -1};
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

    memset(dist, 255, sizeof dist);
    dist[start.x][start.y] = 0;

    queue <point> q;
    q.push(start);

    while (!q.empty()) {
        point v{q.front()};
        q.pop();

        for (char dir : {'D', 'L', 'R', 'U'}) {
            point nx = v + delta.at(dir);
            if (ok(nx) && a[nx.x][nx.y] != '*' && dist[nx.x][nx.y] == -1) {
                dist[nx.x][nx.y] = dist[v.x][v.y] + 1;
                q.push(nx);
            }
        }
    }

    dfs(start);

    puts(s);

    return 0;
}
