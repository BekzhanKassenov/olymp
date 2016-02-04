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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int cnt[26];
long long ans;
set <int> used;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < 26; i++) {
        scanf("%d", &cnt[i]);
    }

    sort(cnt, cnt + n);
    reverse(cnt, cnt + n);

    for (int i = 0; i < n; i++) {
        while (cnt[i] > 0 && used.count(cnt[i])) {
            cnt[i]--;
        }

        if (cnt[i] > 0) {
            ans += cnt[i];
            used.insert(cnt[i]);
        }
    }
    
    printf("%I64d\n", ans);

    return 0;
}
