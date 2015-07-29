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
const int MAXN = 310;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int m, t, r, ans;
int w[MAXN];
int memint[2000];
bool membool[2000];
int *cnt;
bool *burn;

bool turnOn(int pos) {
    int to_burn = pos - 1;

    while (cnt[pos] < r) {
        while (burn[to_burn]) {
            to_burn--;
        }

        if (to_burn + t < pos) {
            return false;
        }

        burn[to_burn] = true;
        for (int i = to_burn + 1; i <= to_burn + t; i++) {
            cnt[i]++;
        }
        ans++;
    }

    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    cnt = memint + 1000;
    burn = membool + 1000;

    scanf("%d%d%d", &m, &t, &r);
    for (int i = 0; i < m; i++) {
        scanf("%d", &w[i]);

        if (!turnOn(w[i])) {
            puts("-1");
            return 0;
        }
    }

    printf("%d\n", ans);

    return 0;
}
