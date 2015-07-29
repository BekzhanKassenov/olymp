/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 50010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, m, t[maxn][10], curT, cur[10], ans[maxn];
set <PII> closest;
queue <int> q[10];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        q[0].push(i);

        for (int j = 0; j < m; j++)
            scanf("%d", &t[i][j]);
    }

    memset(cur, 255, sizeof cur);
    cur[0] = q[0].front();
    q[0].pop();
    closest.insert(MP(t[0][0], 0));

    while (!closest.empty()) {
        PII p = *closest.begin();
        closest.erase(closest.begin());

        curT = p.F;

        if (p.S == m - 1) {
            ans[cur[p.S]] = curT;
        } else {
            q[p.S + 1].push(cur[p.S]);
        }

        cur[p.S] = -1;

        for (int i = 0; i < m; i++) {
            if (cur[i] == -1 && !q[i].empty()) {
                cur[i] = q[i].front();
                closest.insert(MP(curT + t[cur[i]][i], i));
                q[i].pop();
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}
