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

int n, m;

int cnt(int k) {
    if (k == 0) {
        return 1;
    }

    int ans = 0;
    while (k > 0) {
        ans++;
        k /= 7;
    }

    return ans;
}

bool used[7];

int go(int cntn, int cntm, int num1 = 0, int num2 = 0) {
    if (cntn == 0 && cntm == 0) {
        return num1 < n && num2 < m;
    }

    int ans = 0;
    for (int i = 0; i < 7; i++) {
        if (!used[i]) {
            used[i] = true;
            
            if (cntn > 0) {
                ans += go(cntn - 1, cntm, num1 * 7 + i, num2);
            } else {
                ans += go(cntn, cntm - 1, num1, num2 * 7 + i);
            }

            used[i] = false;
        }
    }
    
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &m);

    int cntn = cnt(n - 1);
    int cntm = cnt(m - 1);

    if (cntn + cntm > 7) {
        puts("0");
        return 0;
    }

    printf("%d\n", go(cntn, cntm));

    return 0;
}
