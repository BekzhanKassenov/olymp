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
const int maxn = 100010;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

char s[maxn];
int n, z[maxn], st[maxn];
vector <pair <int, int> > ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    
    gets(s);
    n = strlen(s);

    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;

        st[i] = z[i];
    }

    sort(st, st + n);

    for (int i = 1; i < n; i++) {
        if (z[n - i] == i) {
            ans.push_back(MP(i, n - (lower_bound(st, st + n, i) - st) + 1));
        }
    }

    ans.push_back(MP(n, 1));

    printf("%u\n", ans.size());

    for (size_t i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].F, ans[i].S);

    return 0;
}
