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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, k, x, mx;
int cnt[MAXN], pref[MAXN];

int sum(int l, int r) {
    return pref[r] - pref[l - 1];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }

    for (int i = 1; i < MAXN; i++) {
        pref[i] = pref[i - 1] + cnt[i];
    }

    int ans = 1;

    for (int i = 2; i < MAXN; i++) {
        int total = 0;

        for (int j = i; j < MAXN; j += i) {
            int nxt = min(min(j + i - 1, j + k), MAXN - 1);
            total += sum(j, nxt);
        }

        if (total == n)
            ans = i;
    }

    printf("%d\n", ans);
    
    return 0;
}
