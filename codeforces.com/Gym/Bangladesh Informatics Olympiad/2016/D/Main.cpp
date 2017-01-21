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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T;
int n, r, k;
int x[MAXN], v[MAXN];
int dp[MAXN][60];
int cnt[MAXN];
int sum[MAXN];
vector <int> num;

void clear() {
    for (int i = 0; i <= n + 1; i++) {
        cnt[i] = 0;
        for (int j = 0; j <= k + 1; j++) {
            dp[i][j] = 0;
        }
    }
}

void build() {
    num = vector <int>(x, x + n);
    num.push_back(-INF);
    sort(all(num));
    num.resize(unique(all(num)) - num.begin());
}

int getPos(int x) {
    return lower_bound(all(num), x) - num.begin();
}

int getLeft(int pos) {
    int x = num[pos];
    x -= 2 * r;
    return lower_bound(all(num), x) - num.begin() - 1;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d", &T);

    for (int _case = 1; _case <= T; _case++) {
        scanf("%d%d%d", &n, &r, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &v[i]);
        }

        clear();
        build();

        for (int i = 0; i < n; i++) {
            cnt[getPos(x[i])] += v[i];
        }

        for (size_t i = 1; i < num.size(); i++) {
            sum[i] = sum[i - 1] + cnt[i];
        }

        for (size_t i = 1; i < num.size(); i++) {
            for (int j = 1; j <= k; j++) {
                int L = getLeft(i);

                dp[i][j] = max(dp[i][j], dp[L][j - 1] + sum[i] - sum[L]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }

        int ans = 0;
        size_t last = num.size() - 1;
        for (int j = 0; j <= k; j++) {
            ans = max(ans, dp[last][j]);
        }

        printf("Case %d: %d\n", _case, ans);
    }
    
    return 0;
}
