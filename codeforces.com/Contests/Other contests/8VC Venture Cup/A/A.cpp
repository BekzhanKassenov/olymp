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
int a[MAXN], b[MAXN];
int c[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int posa = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            posa = i;
            break;
        }
    }

    int posb = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            posb = i;
            break;
        }
    }

    while (posa != 0) {
        swap(a[posa], a[(posa + 1) % n]);
        posa = (posa + 1) % n;
    }

    while (posb != 0) {
        swap(b[posb], b[(posb + 1) % n]);
        posb = (posb + 1) % n;
    }

    posa = 0, posb = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == 1) {
            posa = i;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        if (b[i] == 1) {
            posb = i;
            break;
        }
    }

    rotate(a + 1, a + posa, a + n);
    rotate(b + 1, b + posb, b + n);

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            puts("No");
            return 0;
        }
    }

    puts("Yes");

    return 0;
}
