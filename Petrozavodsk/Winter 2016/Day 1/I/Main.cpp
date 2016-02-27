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
const int N = 6010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int bitcount[1 << 6];
char s[N][N];
int n;

int inter(int r1, int r2) {
    int ans = 0;
    for (int i = 0; i < (2 * n + 5) / 6; i++) {
        int intr = s[r1][i] & s[r2][i];
        ans += bitcount[intr];
    }

    return ans;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    for (int i = 1; i < (1 << 6); i++) {
        bitcount[i] = bitcount[i >> 1] + (i & 1);
    }

    scanf("%d\n", &n);

    for (int i = 0; i < n + 1; i++) {
        gets(s[i]);
        for (int j = 0; j < (2 * n + 5) / 6; j++) {
            s[i][j] -= 33;
        }
    }

    srand(time(NULL));
    while (true) {
        int r1 = rand() % (n + 1);
        int r2 = rand() % (n + 1);

        if (r1 != r2 && inter(r1, r2) >= n / 2) {
            printf("%d %d\n", r1 + 1, r2 + 1);
            return 0;
        }
    }

    return 0;
}
