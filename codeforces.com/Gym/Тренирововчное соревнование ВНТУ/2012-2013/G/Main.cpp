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
const int maxn = 2010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int a[maxn];
int pos[maxn];
stringstream ss;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;

        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            pos[a[i]] = i;
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int ps = pos[i];

            if (ps == i)
                continue;

            swap(a[i], a[ps]);
            pos[a[ps]] = ps;
            ans++;
        }

        ss << ans << endl;
    }

    cout << ss.str();

    return 0;
}
