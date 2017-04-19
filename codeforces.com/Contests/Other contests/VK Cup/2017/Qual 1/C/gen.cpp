/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> point;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m, k;
char a[MAXN][MAXN];

int rnd(int l, int r) {
    if (l > r) {
        return 0;
    }

    int num = (rand() << 16) ^ rand();
    return l + num % (r - l + 1);
}

int main(int argc, char* argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    assert(argc > 1);
    int lim = atoi(argv[1]);

    srand(time(NULL));

    int n = rnd(1, 10);
    int m = rnd(1, 10);
    int k = rnd(1, min((n * m) / 2, lim)) * 2;

    cout << n << ' ' << m << ' ' << k << endl;

    point start{rnd(0, n - 1), rnd(0, m - 1)};

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            if (x == start.x && y == start.y) {
                cout << 'X';
            } else {
                if (rnd(1, 100) <= 30) {
                    cout << '*';
                } else {
                    cout << '.';
                }
            }
        }
        cout << endl;
    }

    return 0;
}
