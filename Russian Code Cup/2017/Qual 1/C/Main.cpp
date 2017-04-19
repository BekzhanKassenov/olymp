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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

pair <int, int> a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef Local
    freopen("in", "r", stdin);
#endif

    int T;
    cin >> T;

    cout << fixed << setprecision(16);
    while (T--) {
        int n;
        cin >> n;

        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            int v1, v2, x;
            cin >> v1 >> v2 >> x;
            sum += v1;
            a[i].first = v1 - v2;
            a[i].second = x;
        }

        sort(a + 1, a + 1 + n, [](const pair <int, int>& a, const pair <int, int>& b) {
            long long lhs = a.second;
            lhs *= b.first;

            long long rhs = b.second;
            rhs *= a.first;

            return lhs > rhs;
        });

        long long suff = 0;
        double ans = sum;
        for (int i = n; i >= 1; i--) {
            double val = a[i].second;
            val /= 1e7;
            val *= suff;
            ans -= val;
            suff += a[i].first;
        }

        cout << ans << endl;
    }

    return 0;
}
