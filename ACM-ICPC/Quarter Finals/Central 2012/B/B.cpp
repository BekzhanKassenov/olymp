/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int n, m;

bool ok(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> m;

    char a[1010][1010];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '+') {
                bool flag = false;
                
                for (int k = 0; k < 4; k++) {
                    int tx = i + dx[k];
                    int ty = j + dy[k];

                    if (ok(tx, ty) && a[tx][ty] != '+')
                        flag = true;
                }
                
                res += flag;
            }
        }
    }

    cout << res;

    return 0;
}
