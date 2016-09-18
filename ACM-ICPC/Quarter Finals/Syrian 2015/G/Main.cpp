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
const int MAXN = 510;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n;
char s[3][MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &T);

    while (T--) {
        scanf("%d\n", &n);
        for (int i = 0; i < 3; i++) {
            gets(s[i]);
        }

        int ans = 0;
        for (int block = 0; block < n; block++) {
            int l = 3 * block, r = 3 * (block + 1);

            int cnt = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = l; j < r; j++) {
                    if (s[i][j] == '*') {
                        cnt++;
                    }
                }
            }

            ans = max(ans, cnt);
        }

        printf("%d\n", 4 * ans);
    }
    
    return 0;
}
