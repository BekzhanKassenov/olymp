/****************************************
**          Solution by NU #2          **
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
const int MAXN = 2010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, ans;
int p[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    sort(p + 1, p + n + 1);

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        int cnt = 0;

        for (int j = 1; j < i; j++) {
            if (sum + p[j] <= p[i]) {
                sum += p[j];
                cnt++;
            }
        }
        
        ans = max(ans, cnt + 1);
    }

    printf("%d\n", ans);
    
    return 0;
}
