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
const int MAXN = 1000010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

double result;
int w, h, n;
double fact[MAXN];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    cin >> w >> h >> n;

    double den = n * log(2);

    fact[0] = fact[1] = 0.0;
    for (int i = 2; i <= n; i++) {
        fact[i] = fact[i - 1] + log(i);
    }

    for (int i = 0; i <= n; i++) {
        long double cnk = fact[n] - fact[i] - fact[n - i];
        result += exp(cnk - den - 2 * log(i + 1) - 2 * log(n - i + 1));
    }

    cout << result * w * h << endl;

    return 0;
}
