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
const int MAXN = 25;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
int a[MAXN][MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> m;
        vector <pair <int, int> > vec;
        vec.reserve(n * m);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                vec.emplace_back(i, j);
            }
        }

        sort(all(vec), [](const pair <int, int>& a, const pair <int, int>& b) {
            int va = a.first - 1 + a.second - 1;
            int vb = b.first - 1 + b.second - 1;

            return va < vb;
        });

        int iter = n * m;
        for (const auto& p : vec) {
            a[p.first][p.second] = iter--;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
    
    return 0;
}
