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
int c[MAXN], d[MAXN];
int r[MAXN];

bool checkDiv(int pos) {
    if (d[pos] == 1) {
        return r[pos] >= 1900;
    }

    return r[pos] <= 1899;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);
    bool has1 = false, has2 = false;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &c[i], &d[i]);
        if (d[i] == 1) {
            has1 = true;
        } else {
            has2 = true;
        }
    }

    if (has1 && !has2) {
        puts("Infinity");
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        r[i] = r[i - 1] + c[i - 1];
    }

    int deltaUp = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1 && r[i] < 1900) {
            deltaUp = max(deltaUp, 1900 - r[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        r[i] += deltaUp;
    }

    /*
    for (int i = 1; i <= n; i++) {
        cout << r[i] << ' ';
    }
    cout << endl;
    */

    int deltaDown = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 2 && r[i] > 1899) {
            deltaDown = max(deltaDown, r[i] - 1899); 
        }
    }

    for (int i = 1; i <= n; i++) {
        r[i] -= deltaDown;
    }

    for (int i = 1; i <= n; i++) {
        if (!checkDiv(i)) {
            puts("Impossible");
            return 0;
        }
    }

    deltaUp = INF;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 2 && r[i] <= 1899) {
            deltaUp = min(deltaUp, 1899 - r[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        r[i] += deltaUp;
    }

    printf("%d\n", r[n] + c[n]);

    return 0;
}
