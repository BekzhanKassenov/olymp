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


int cnt[2];
int *a, *b;
int n, q;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &q);

    a = cnt;
    b = a + 1;

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int addend;
            scanf("%d", &addend);

            addend = (addend + 2 * n) % n;
            if (addend % 2 == 1) {
                addend--;
                *b = (*b + 2) % n;
                swap(a, b);
            }

            *a = (*a + addend) % n;
            *b = (*b + addend) % n;
        } else {
            swap(a, b);
        }
    }

    int start_a = 1, start_b = 2;

    if (a == &cnt[1]) {
        swap(start_a, start_b);
    }

    start_a = start_a + n - *a;
    start_b = start_b + n - *b;

    for (int i = 0; i < n / 2; i++) {
        if (start_a > n) {
            start_a -= n;
        }

        if (start_b > n) {
            start_b -= n;
        }

        printf("%d %d ", start_a, start_b);

        start_a += 2;
        start_b += 2;
    }

    puts("");

    return 0;
}
