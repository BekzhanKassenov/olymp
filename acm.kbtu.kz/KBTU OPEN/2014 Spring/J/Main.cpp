/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "strcutting"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);
const int maxn = 110;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

bool calced[maxn][maxn];
int dp[maxn][maxn], n;
char s[maxn], t[maxn];

int calc(int l, int r) {
    if (l == r)
        return 1;

    if (r - l == 1) {
        return 2 * (s[l] != s[r]);
    }

    if (calced[l][r])
        return dp[l][r];

    calced[l][r] = true;
    int& ans = dp[l][r];
    ans = INF;

    if (s[l] == s[r]) {
        ans = calc(l + 1, r - 1);
    } 
    
    for (int k = l; k < r; k++) {
        ans = min(ans, calc(l, k) + calc(k + 1, r));
    }

    return ans;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    gets(t);

    char last = 0;
    int cnt = 0;

    for (int i = 0; t[i]; i++) {
        if (t[i] == last)
            cnt++;
        else {
            if (last && (cnt & 1)) {
                s[n++] = last;
            }

            last = t[i];
            cnt = 1;
        }
    }

    if (cnt & 1) {
        s[n++] = last;
    }

    //puts(s);

    cout << calc(0, n - 1);

    return 0;
}
