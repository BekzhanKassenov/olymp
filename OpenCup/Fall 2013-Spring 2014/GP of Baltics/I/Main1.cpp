/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "stat"

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
const int maxn = 100;

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

int n, k;
double p;

double bin_pow(double a, int st) {
    double res = 1.0;

    while (st) {
        if (st & 1)
            res *= a;

        a *= a;
        st >>= 1;
    }

    return res;
}

double C(int kk, int nn) {
    if (kk <= 0 || nn <= 1 || nn <= kk)
        return 1.0;

    double ans = 1.0;
    
    if (kk > nn/2)
        kk = nn - kk;
    
    for (int i = 1; i <= kk; ++i){
        ans *= double(nn - kk + i)/(i + .0);
    }
    
    return ans;
}

double f(int m) {
    return C(k - 1, m - 1) * bin_pow(1.0 - p, m - k) * bin_pow(p, k);
}
 
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    double ans = 0.0;
    
    cin >> n >> k >> p;

    double cur = 1, u = 1;

    for (int i = 0; i < 100; i++) {
        ans += cur * u;

        cur -= u * f(k + i);
        u *= (1 - p);
    }

    ans *= n;
    ans *= (1 - u);

    printf("%.15lf", ans);
    
    return 0;                      
}
