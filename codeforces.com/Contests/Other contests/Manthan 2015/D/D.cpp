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
const int MAXN = 1010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN];
map <int, int> Map;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    int cnt0 = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        Map[a[i]]++;
        cnt0 += a[i] == 0;
    }


    Map[0] = 0;

    int ans = cnt0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || a[i] == 0 || a[j] == 0) {
                continue;
            }

            map <int, int> temp;
            temp[a[i]]++;
            temp[a[j]]++;

            int f1 = a[i], f2 = a[j];

            int len = 2;

            for (int k = 3; k <= n; k++) {
                int sum = f1 + f2;

                temp[sum]++;
                if (Map.count(sum) && temp[sum] <= Map[sum]) {
                    len++;
                    f1 = f2;
                    f2 = sum;
                } else {
                    break;
                }
            }

            len += cnt0;
            ans = max(ans, len);
        }
    }

    printf("%d\n", ans);

    return 0;
}
