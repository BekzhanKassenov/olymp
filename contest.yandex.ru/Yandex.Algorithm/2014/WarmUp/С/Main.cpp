/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()

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

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

//r ^ 2 = 2 * (p - a) * (p - b) * (p - c) / P

map <double, int> ans;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b, c;

        scanf("%d%d%d", &a, &b, &c);
        double P = a + b + c;
        double p = P / 2;

        double r = 2.0 * (p - a) * (p - b) * (p - c) / P;
        ans[r]++;
    }

    int res = 0;

    for (map <double, int> :: iterator it = ans.begin(); it != ans.end(); it++)
        res = max(res, it -> S);

    printf("%d\n", res);

    return 0;
}
