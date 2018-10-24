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
int a[MAXN], b[MAXN];
vector <pair <int, int> > ans[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < m; i++) {
        int x = 2 * i + 1;
        int y = 2 * i + 2;
        ans[a[i]].emplace_back(x, x);
        ans[b[i]].emplace_back(y, y);
        ans[a[i]].emplace_back(x, y);

        for (int j = 0; j < i; j++) {
            if (a[j] == a[i]) {
                int pr = 2 * j + 1;
                ans[a[i]].emplace_back(x, pr);
                break;
            }
            if (b[j] == a[i]) {
                int pr = 2 * j + 2;
                ans[a[i]].emplace_back(x, pr);
                break;
            }
        }

        for (int j = 0; j < i; j++) {
            if (a[j] == b[i]) {
                int pr = 2 * j + 1;
                ans[b[i]].emplace_back(y, pr);
                break;
            }
            if (b[j] == b[i]) {
                int pr = 2 * j + 2;
                ans[b[i]].emplace_back(y, pr);
                break;
            }
        }
    }

    int cur = 2 * m + 10;
    for (int i = 1; i <= n; i++) {
        if (ans[i].empty()) {
            ans[i].emplace_back(cur, cur);
            cur++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i].size() << endl;
        for (const auto& p : ans[i]) {
            cout << p.first << ' ' << p.second << endl;
        }
    }

    /*
    int res[110][110];
    for (int i = 0; i < 110; i++) {
        for (int j = 0; j < 110; j++) {
            res[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (const auto& p : ans[i]) {
            res[p.first][p.second] = i;
        }
    }

    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            cout << res[i][j];
        }
        cout << endl;
    }*/<   
    
    return 0;
}
