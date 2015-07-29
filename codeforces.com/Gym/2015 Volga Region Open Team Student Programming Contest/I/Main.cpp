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
const int MAXN = 210;
const int MAXM = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, size[MAXN];
pair <int, int> a[MAXN][MAXM];
int ans = INF, num[MAXN];
int tempans, tempnum[MAXN];

bool cmp(const pair <int, int>& a, const pair <int, int>& b) {
    return a.first < b.first;
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &size[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &a[i][j].first);
            a[i][j].second = j;
        }

        sort(a[i], a[i] + size[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < size[i]; j++) {
            memset(tempnum, 0, sizeof(int) * (n + 1));
            tempnum[i] = a[i][j].second;

            tempans = 0;
            bool found = true;
            pair <int, int> to_search(a[i][j].first, 0);

            for (int k = 0; k < n; k++) {
                if (k == i) {
                    continue;
                }

                int pos = lower_bound(a[k], a[k] + size[k], to_search, cmp) - a[k];

                if (pos < size[k]) {
                    tempans = max(tempans, a[k][pos].first - a[i][j].first);
                    tempnum[k] = a[k][pos].second;
                } else {
                    found = false;
                }
            }

            if (found && tempans < ans) {
                ans = tempans;
                memcpy(num, tempnum, sizeof(int) * (n + 1));
            }
        }
    }

    printf("%d\n", ans);
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i] + 1);
    }

    puts("");
    
    return 0;
}
