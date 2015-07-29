/****************************************
**      Solution by NU: Black Kex      **
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
const int MAXN = 5010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, k;
int a[MAXN];
int q, C;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &q);

    while (q--) {
        scanf("%d", &C);

        bool found = false;

        for (int num = 1; num <= k && !found; num++) {
            int cnt = 0;

            if (C % num == 0 && binary_search(a, a + n, C / num)) {
                cnt = 1;
            }

            for (int A = 1; A < num; A++) {
                for (int i = 0; i < n; i++) {
                    int x = a[i];
                    int B = num - A;

                    int left = C - A * x;

                    if (left < 0 || left % B != 0) {
                        continue;
                    }

                    int y = left / B;

                    if (x < y && binary_search(a, a + n, y)) {
                        cnt++;
                    }
                }
            }

            if (cnt >= 1) {
                printf("%d\n", num);
                found = true;
            }
        }

        if (!found) {
            puts("-1");
        }
    }

    return 0;
}
