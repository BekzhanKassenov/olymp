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

int n, k;
long long ans;
int p[10];

void go(int lev) {
    if (lev == k) {
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (p[j] < p[i]) {
                    ans++;
                }
            }
        }

        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            reverse(p + i, p + j + 1);
            go(lev + 1);
            reverse(p + i, p + j + 1);
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    go(0);
    long long prob = (n * (n + 1)) / 2;
    long long den = 1;
    for (int i = 0; i < k; i++) {
        den *= prob;
    }

    printf("%.15lf\n", (ans + .0) / (den + .0)); 
    
    return 0;
}
