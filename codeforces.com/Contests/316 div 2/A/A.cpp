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

int n, m, x, num, cnt;
int ansc[110];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &m, &n);

    for (int i = 1; i <= n; i++) {
        cnt = -1, num = -1;

        for (int j = 1; j <= m; j++) {
            scanf("%d", &x);

            if (x > cnt) {
                cnt = x;
                num = j;
            }
        }

        ansc[num]++;
    }

    int pos = 1;
    for (int i = 2; i <= m; i++) {
        if (ansc[i] > ansc[pos]) {
            pos = i;
        }
    }

    printf("%d\n", pos);
    
    return 0;
}
