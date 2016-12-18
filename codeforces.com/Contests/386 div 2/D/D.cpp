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

int n, k, a, b;

bool check(const char s[]) {
    #define work(x, delta) \
        if (s[x] == 'G') { \
            sumA += delta; \
        } else { \
            sumB += delta; \
        } \

    if (k == n) {
        return true;
    }

    int sumA = 0, sumB = 0;
    for (int i = 0; i <= k; i++) {
        work(i, 1);
    }

    int pos = k + 1;
    do {
        if (sumA > k || sumB > k) {
            return false;
        }

        work(pos - k - 1, -1);
        work(pos, 1);

        pos++;
    } while (pos <= n);

    return true;
}

void solve(int a, int b, char ca, char cb) {
    string ans;
    
    int C = b / (a + 1);
    int m = b % (a + 1);

    for (int i = 0; i < a; i++) {
        int cnt = C;
        if (i < m) {
            cnt++;
        }

        ans.append(cnt, cb);
        ans.append(1, ca);
        b -= cnt;
    }

    ans.append(b, cb);

    if (!check(ans.c_str())) {
        puts("NO");
    } else {
        puts(ans.c_str());
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d%d", &n, &k, &a, &b);

    if (a < b) {
        solve(a, b, 'G', 'B');
    } else {
        solve(b, a, 'B', 'G');
    }

    return 0;
}
