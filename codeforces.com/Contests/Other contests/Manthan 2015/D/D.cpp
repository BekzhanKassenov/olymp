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

    int ans = max(2, cnt0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || (a[i] == 0 && a[j] == 0)) {
                continue;
            }


            Map[a[i]]--;
            Map[a[j]]--;

            int f1 = a[i], f2 = a[j];

            int len = 2;

            for (int i = 3; i <= n; i++) {
                int sum = f1 + f2;

                if (Map.count(sum) && Map[sum] != 0) {
                    Map[sum]--;
                    len++;

                    f1 = f2;
                    f2 = sum;
                } else {
                    break;
                }
            }

            ans = max(ans, len);

            Map[a[i]]++;
            Map[a[j]]++;
            
            f1 = a[i], f2 = a[j];
            for (int i = 3; i <= len; i++) {
                int sum = f1 + f2;
                Map[sum]++;
                f1 = f2;
                f2 = sum;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}