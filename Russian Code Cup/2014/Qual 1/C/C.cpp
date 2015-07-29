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
const int maxn = 300010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int t, n;
int a[maxn], cnt[maxn];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
            cnt[i] = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
            cnt[a[i]]++;
        }

        for (int i = 1; i <= n && cnt[i]; i++)
            cnt[i] += cnt[i - 1];

        for (int i = 0; i < n; i++) {
            printf("%d ", cnt[a[i]]--);
        }

        puts("");
    }                   

    return 0;
}
