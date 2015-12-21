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
const int MAXN = 100010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
char s[MAXN];

bool smile(int pos) {
    return (s[pos] == ':' && s[pos + 1] == ')') ||
           (s[pos] == '(' && s[pos + 1] == ':');
}

bool frown(int pos) {
    return (s[pos] == ':' && s[pos + 1] == '(') ||
           (s[pos] == ')' && s[pos + 1] == ':');
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d\n", &n);
    
    gets(s);

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i + 1 < n; i++) {
        cnt1 += smile(i);
        cnt2 += frown(i);
    }

    if (cnt1 > cnt2) {
        puts("HAPPY");
    } else if (cnt1 == cnt2) {
        puts("BORED");
    } else {
        puts("SAD");
    }

    return 0;
}
