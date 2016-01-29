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
const int MAXN = 60;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN][MAXN];
int p[MAXN];

int cntOf(int num, int pos) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[pos][i] == num) {
            cnt++;
        }
    }
    
    return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int goal = n - 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cntOf(i, j) == goal) {
                p[j] = i;
                break;
            }
        }

        goal--;
    }

    for (int i = 1; i <= n; i++) {
        if (p[i] == 0) {
            p[i] = n;
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", p[i]);
    }

    return 0;
}
