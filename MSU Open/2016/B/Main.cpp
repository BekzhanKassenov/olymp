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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n, m;
long long k;
char res[100];

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%lld", &n, &m, &k);

    k--;
    for (int i = 0; i < m; i++) {
        res[i] = 'a' + k % n;
        k /= n;
    }

    reverse(res, res + m);
    puts(res);
    
    return 0;
}
