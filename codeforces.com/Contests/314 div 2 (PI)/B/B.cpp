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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, cnt, ans;
int type[MAXN], a[MAXN];
bool used[1000010];
char t;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%c %d\n", &t, &a[i]);

        if (t == '+') {
            type[i] = 1;
        } else {
            type[i] = -1;
        }

        if (type[i] == -1 && !used[a[i]]) {
            cnt++;
        }

        used[a[i]] = true;
    }
    
    ans = cnt;

    for (int i = 0; i < n; i++) {
        cnt += type[i];
        ans = max(ans, cnt);
    }

    printf("%d\n", ans);

    return 0;
}
