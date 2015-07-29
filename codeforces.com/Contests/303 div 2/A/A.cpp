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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
int a[MAXN][MAXN];
stringstream ans;
int cnt;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        bool good = true;
        
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1 || a[i][j] == 3) {
                good = false;
            }
        }

        if (good) {
            ans << i + 1 << ' ';
            cnt++;
        }
    }

    printf("%d\n", cnt);
    puts(ans.str().c_str());
    
    return 0;
}
