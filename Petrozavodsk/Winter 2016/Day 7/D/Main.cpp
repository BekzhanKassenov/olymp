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
const int MAXN = 510;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
int g[4][MAXN][MAXN];
char buf[MAXN];
bool used[MAXN];
int res[MAXN];
int last;
int dist[MAXN];
vector <int> ver;

void mul(int res, int a, int b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                g[res][i][j] += g[a][i][k] * g[b][k][j];
            }
        }
    }
}

bool go(int v) {
    res[last++] = v + 1;
    used[v] = true;

    if (last == n) {
        for (int len = 3; len >= 1; len--) {
            if (g[len][v][0]) {
                return true;
            }
        }

        last--;
        used[v] = false;

        return false;
    }

    for (int i: ver) {
        for (int len = 3; len >= 1; len--) {
            if (g[len][v][i] && !used[i] && go(i)) {
                return true;
            }
        }
    }

    last--;
    used[v] = false;
    return false;
}

void bfs(int S) {
    queue <int> q;
    dist[S] = 0;
    used[S] = true;
    q.push(S);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (g[1][v][i] && !used[i]) {
                dist[i] = dist[v] + 1;
                used[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &k);

    for (int i = 0; i < n; i++) {
        gets(buf);

        for (int j = 0; j < n; j++) {
            if (buf[j] == '1') {
                g[1][i][j] = 1;
            }
        }
    }

    for (int i = 2; i <= 3; i++) {
        mul(i, i - 1, 1);
    }



    /*
    for (int len = 1; len <= 3; len++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cerr << g[len][i][j] << ' ';
            }
            cerr << endl;
        }
        cerr << endl;
    }
    cerr << endl;
    */

    bfs(0);

    for (int i = 0; i < n; i++) {
        ver.push_back(i);
    }

    sort(all(ver) , [](int a, int b) {
        return dist[a] > dist[b];
    });

    memset(used, false, sizeof(used));
    go(0);

    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    
    return 0;
}
