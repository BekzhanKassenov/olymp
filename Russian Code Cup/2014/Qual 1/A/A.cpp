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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int t, n, a[20][20];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

bool ok(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        bool has_emp = false, has = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);

                has_emp |= !a[i][j];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    int tx = i + dx[k];
                    int ty = j + dy[k];

                    if (ok(tx, ty) && a[tx][ty] == a[i][j])
                        has = true;
                }
            }
        }

        if (has || has_emp)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}
