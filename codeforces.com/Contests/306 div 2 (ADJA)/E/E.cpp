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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN];

int calc(int l, int r) {
    int result = a[l];

    for (int i = l + 1; i <= r; i++) {
        result = (!result || a[i]);
    }

    return result;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    if (a[n - 1] != 0) {
        puts("NO");
        return 0;
    }

    if (n == 1) {
        puts("YES");
        printf("%d\n", a[0]);
        return 0;
    }

    if (n == 2) {
        if (a[0] != 1 || a[1] != 0) {
            puts("NO");
        } else {
            puts("YES");
            printf("%d->%d\n", a[0], a[1]);
        }

        return 0;
    }

    if (a[0] == 0) {
        puts("YES");
        printf("%d->(", a[0]);
        for (int i = 1; i < n - 1; i++) {
            printf("%d", a[i]);
            
            if (i + 1 < n - 1){
                printf("->");
            } else {
                printf(")");
            }
        }

        printf("->%d\n", a[n - 1]);
    } else {
        int pos = -1;
        for (int i = 1; i < n; i++) {
            if (a[i] == 0) {
                pos = i;
                break;
            }
        }

        if (pos + 1 == n - 1) {
            puts("NO");
            return 0;
        }

        puts("YES");
        for (int i = 0; i < pos; i++) {
            printf("%d->", a[i]);
        }


        if (pos != n - 1) {
            printf("%d->(", a[pos]);

            for (int i = pos + 1; i < n - 1; i++) {
                printf("%d", a[i]);

                if (i + 1 < n - 1) {
                    printf("->");
                }
            }

            printf(")->%d\n", a[n - 1]);
        } else {
            printf("%d\n", a[n - 1]);
        }
        
    }

    return 0;
}
