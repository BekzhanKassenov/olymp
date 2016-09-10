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
const int MAXN = 200010;
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, 1, -1, 0};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
string s[MAXN];

bool ok(int i, int j) {
    return 0 <= i && i < n
        && 0 <= j && j < m
        && s[i][j] != '#';
}

void bfs(int i2, int j2, vector <vector <bool> >& used) {
    queue <int> I, J;
    used[i2][j2] = true;
    I.push(i2);
    J.push(j2);

    while (!I.empty()) {
        assert(!J.empty());

        int curi = I.front();
        int curj = J.front();

        I.pop();
        J.pop();

        for (int k = 0; k < 4; k++) {
            int ti = curi + di[k];
            int tj = curj + dj[k];

            if (ok(ti, tj) && !used[ti][tj]) {
                I.push(ti);
                J.push(tj);
                used[ti][tj] = true;
            }
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        getline(cin, s[i]);
    }

    int i1 = -1, j1 = -1;
    int i2 = -1, j2 = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') {
                i1 = i, j1 = j;
            } else if (s[i][j] == '2') {
                i2 = i, j2 = j;
            }
        }
    }

    vector <vector <bool> > used(n, vector <bool>(m));
    s[i1][j1] = '#';
    bfs(i2, j2, used);
    int cnt = 0;
    for (int k = 0; k < 4; k++) {
        int ti = i1 + di[k];
        int tj = j1 + dj[k];
        if (ok(ti, tj) && used[ti][tj]) {
            cnt++;
        }
    }

    if (cnt > 1) {
        puts("YES");
        return 0;
    }

    used.assign(n, vector <bool>(m));
    s[i1][j1] = '1';
    bfs(i2, j2, used);

    if (!used[i1][j1]) {
        puts("NO");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (used[i][j]) {
                int deg = 0;
                for (int k = 0; k < 4; k++) {
                    int ti = i + di[k];
                    int tj = j + dj[k];
                    if (ok(ti, tj)) {
                        deg++;
                    }
                }

                if (deg > 2) {
                    puts("YES");
                    return 0;
                }
            }
        }
    }

    puts("NO");

    return 0;
}
