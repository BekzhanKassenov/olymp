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
const int MAXN = 2010;
const int di[] = {1, 0, 0, -1};
const int dj[] = {0, 1, -1, 0};

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXN][MAXN];
bool used[MAXN][MAXN];
vector <int> start_i, start_j;
vector <int> max_i, max_j, min_i, min_j;
int n, m;

bool ok(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

void bfs(int i, int j) {
    queue <int> I, J;
    I.push(i);
    J.push(j);

    used[i][j] = true;

    while (!I.empty()) {
        int ii = I.front();
        int jj = J.front();

        I.pop();
        J.pop();
        
        for (int k = 0; k < 4; k++) {
            int ti = ii + di[k];
            int tj = jj + dj[k];

            if (ok(ti, tj)) {
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &m);
    
    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j] && s[i][j] == '.') {
                bfs(i, j);
            }
        }
    }

    memset(used, false, sizeof used);

    for (size_t pos = 0; pos < start_i.size(); pos++) {
        int i = start_i[pos];
        int j = start_j[pos];

        if (!used[i][j]) {
            bfs1(pos);
        }
    }

    for (int i = 0; i < n; i++) {
        puts(s[i]);
    }

    return 0;
}
