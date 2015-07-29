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
const int MAXN = 1100;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int T, casenum;
int n;
char s[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &T);

    while (T--) {
        casenum++;
        scanf("%d ", &n);
        gets(s);

        int cur = s[0] - '0';
        int ans = 0;
        for (int i = 1; i < n + 1; i++) {
            if (i > cur) {
                ans += i - cur;
                cur = i;
            }
            
            cur += s[i] - '0';
        }

        printf("Case #%d: %d\n", casenum, ans);
    }
    
    return 0;
}
