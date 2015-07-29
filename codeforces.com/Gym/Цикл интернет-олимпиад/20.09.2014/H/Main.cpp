/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "message"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const int MAXN = 5010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int dp[MAXN][MAXN];
bool calced[MAXN][MAXN];
int k;
char s[MAXN];
int ansl = -1, ansr = -1;

int calc(int l, int r) {
 	if (calced[l][r])
 		return dp[l][r];

   	if (l >= r)
   		return 0;

   	calced[l][r] = true;

    dp[l][r] = min(calc(l + 1, r), calc(l, r - 1)) + 1;

    if (s[l] == s[r])
        dp[l][r] = min(dp[l][r], calc(l + 1, r - 1));

    return dp[l][r];
}

void expand(int& l, int& r, int cnt) {
    while (l > 0 && cnt > 0) {
        l--;
        cnt--;
    }

    while (s[r + 1] && cnt > 0) {
        r++;
        cnt--;
    }
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    scanf("%d\n", &k);
    gets(s);

    for (int l = 0; s[l]; l++) {
		for (int r = l; s[r]; r++) {
            if (calc(l, r) <= k) {
                int a = l, b = r;
                expand(a, b, calc(l, r) - k);

                //cout << a << ' ' << b << endl;

                if (ansl == -1 || b - a > ansr - ansl || (b - a == ansr - ansl && a < l)) {
                    ansl = a;
                    ansr = b;
                }
            }
        }
    }

    printf("%d %d\n", ansl + 1, ansr + 1);

    return 0;
}
