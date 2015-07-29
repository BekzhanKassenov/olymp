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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int a[MAXN];
int n, t, x;
int last = 1;
char res[MAXN * 10];
int lastRes;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &t);

        if (t == 0) {
            a[last++] = 1;
        } else {
            scanf("%d", &x);

            int sum = 0;
            for (int j = x + 1; j < last; j++) {
                sum += a[j];
            }

            a[x] = 0;
            sprintf(res + lastRes, "%d\n", sum);
            while (res[lastRes]) {
                lastRes++;
            }
        }
    }

    puts(res);
    
    return 0;
}
