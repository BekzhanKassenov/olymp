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
const int maxn = 1010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

bool play[maxn][maxn];
int n, k, res;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int dist = 1; dist <= k; dist++) {
        for (int i = 0; i < n; i++) {
            int enemy = (i + dist) % n;

            if (enemy == i || play[i][enemy] || play[enemy][i]) {
                cout << -1;
                return 0;
            } 

            play[i][enemy] = true;
            res++;
        }
    }

    cout << res << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (play[i][j]) {
                printf("%d %d\n", i + 1, j + 1);
            }
        }
    }

    return 0;
}
