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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int color[MAXN];
int size[3 * MAXN];
set <int> g[MAXN];

void dfs(int v, int c, int par = 0) {
    color[v] = c;
    size[c]++;
    for (int to: g[v]) {
        if (to != par) {
            dfs(to, c, v);
        }
    }
}

int getSmaller(int a, int b) {
    struct State {
        State(int v, set <int>::iterator iter, int par) : v(v), iter(iter), par(par) { }
        int v;
        set <int>::iterator iter;
        int par;
    };

    queue <State> q1, q2;
    q1.emplace(a, g[a].begin(), 0);
    q2.emplace(b, g[b].begin(), 0);

    while (!q1.empty() && !q2.empty()) {
        State& s1 = q1.front();

        if (s1.iter != g[s1.v].end()) {
            int to = *s1.iter;
            s1.iter++;

            if (to != s1.par) {
                q1.emplace(to, g[to].begin(), s1.v);
            }
        }

        if (s1.iter == g[s1.v].end()) {
            q1.pop();
        }

        State& s2 = q2.front();

        if (s2.iter != g[s2.v].end()) {
            int to = *s2.iter;
            s2.iter++;

            if (to != s2.par) {
                q2.emplace(to, g[to].begin(), s2.v);
            }
        }

        if (s2.iter == g[s2.v].end()) {
            q2.pop();
        }
    }

    if (q1.empty()) {
        return a;
    }

    return b;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        color[i] = i;
        size[i] = 1;
    }

    char c;

    int ncol = n + 1;
    while (scanf("\n%c", &c) == 1 && c != 'E') {
        int a, b;
        scanf("%d%d", &a, &b);

        if (c == 'T') {
            if (color[a] == color[b]) {
                puts("YES");
            } else {
                puts("NO");
            }

            fflush(stdout);
        } else if (c == 'C') {
            if (size[color[a]] > size[color[b]]) {
                swap(a, b);
            }

            dfs(a, color[b]);
            g[a].insert(b);
            g[b].insert(a);

        } else {
            g[a].erase(b);
            g[b].erase(a);

            int ocolor = color[a];
            int v = getSmaller(a, b);
            size[ncol] = 0;
            dfs(v, ncol);
            size[ocolor] -= size[ncol];
            ncol++;
        }

        /*
        cerr << c << ' ' << a << ' ' << b << endl;
        for (int i = 1; i <= n; i++) {
            cerr << color[i] << ' ';
        }
        cerr << endl;
        */
    }

    return 0;
}
