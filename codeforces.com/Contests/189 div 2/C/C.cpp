/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define INF (int)(2e9)
#define EPS 1e-9
#define MOD (1000 * 1000 * 1000 + 7)
#define all(x) (x).begin(), (x).end()

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

char s[110];
int n;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    gets(s);
    n = strlen(s);

    int power = 1;
    int f = 0;

    for (int i = n - 1; i >= 0; i--) {
        f = (f * 2ll) % MOD;

        if (s[i] == '1')
            f = (f + power) % MOD;
        power = (power * 4ll) % MOD;
    }

    printf("%d\n", f);

    return 0;
}
