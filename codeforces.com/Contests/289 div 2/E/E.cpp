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
const int MAXN = 500010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

char s[MAXN];
int n;
long long sum[MAXN];
double num, ans;

bool vowel(char c) {
    return c == 'I' || c == 'E' || c == 'A' ||
           c == 'O' || c == 'U' || c == 'Y';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    gets(s);
    n = strlen(s);

    for (int i = n - 1; i >= 0; i--) {
        sum[i] = sum[i + 1] + vowel(s[i]);
    }

    for (int i = 0; i < n; i++) {
        num += sum[i];
        num -= sum[n - i];
        ans += num / (i + 1);
    }

    printf("%.10lf\n", ans);

    return 0;
}
