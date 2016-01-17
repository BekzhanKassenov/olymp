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
char s[MAXN], t[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    gets(s);
    gets(t);

    int ans = 0;
    for (int i = 0; i < n; i++) {
    	int dig1 = s[i] - '0';
    	int dig2 = t[i] - '0';
    	int diff = abs(dig1 - dig2);

    	ans += min(diff, 10 - diff);
    }

    printf("%d\n", ans);

    return 0;
}
