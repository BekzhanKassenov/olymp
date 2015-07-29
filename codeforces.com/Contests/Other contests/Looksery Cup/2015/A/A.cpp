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
char s[100][100];
char buf[5];
int ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        gets(s[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            buf[0] = s[i][j];
            buf[1] = s[i + 1][j];
            buf[2] = s[i][j + 1];
            buf[3] = s[i + 1][j + 1];

            sort(buf, buf + 4);

            if (strcmp(buf, "acef") == 0) {
                ans++;
            }
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
