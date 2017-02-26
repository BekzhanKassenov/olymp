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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char t[MAXN], p[MAXN];
int a[MAXN];
bool used[MAXN];

bool check(int pref) {
    for (int i = 0; i <= pref; i++) {
        used[a[i]] = true;
    }


    bool res = true;

    int ptr = 0;
    for (int i = 0; p[i]; i++) {
        while (ptr < n && (used[ptr] || t[ptr] != p[i])) {
            ptr++;
        }

        if (ptr == n) {
            res = false;
        }

        ptr++;
    }

    for (int i = 0; i <= pref; i++) {
        used[a[i]] = false;
    }

    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(t);
    n = strlen(t);

    gets(p);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }

    int l = 0, r = n - 1;
    int ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (check(mid)) {
            ans = mid + 1;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }   

    printf("%d\n", ans);
    return 0;
}
