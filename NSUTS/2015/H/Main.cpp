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
const int MAXN = 1010;
const int MAXS = 50010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int last[MAXS]; // last used type
int dp[MAXS]; // max_diff types
pair <int, int> a[MAXN];
int n, S;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    scanf("%d%d", &n, &S);

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }

    memset(dp, 255, sizeof(dp));

    sort(a, a + n);

    dp[0] = 0;
    last[0] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = S; j >= 0; j--) {
            int pos = j + a[i].second;

            if (pos > S || dp[j] == -1) {
                continue;
            }

            int nlast = a[i].first;
            int ndp = dp[j];
            if (a[i].first != last[j]) {
                ndp++;
            }

            if (dp[pos] < ndp) {
                dp[pos] = ndp;
                last[pos] = nlast;
            }
        }
    }

    if (dp[S] != -1) {
        printf("%d\n", dp[S]);
    } else {
        puts("Impossible");
    }

    return 0;
}
