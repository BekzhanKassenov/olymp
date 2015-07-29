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
const int MAXN = 110;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, ans;
char s[MAXN];
int cntA = 0;
int posF = -1;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    
    scanf("%d\n", &n);

    gets(s);

    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A') {
            cntA++;
        }
    }

    for (int i = 0; s[i]; i++) {
        if (s[i] == 'F') {
            if (posF == -1) {
                posF = i;
            }

            ans += cntA;
        } else if (s[i] == 'N') {
            if (posF != -1) {
                ans += min(i - posF, cntA);
            }
        } else {
            cntA--;
        }
    }

    printf("%d\n", ans);
    return 0;
}
