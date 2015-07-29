/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "binary"

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
int f(int i){
    if (i == 1 || i == 0)
        return 1;
    return f(i - 1) + f(i - 2);
}
double bin_pow(double a, int st){
    if (st == 0)
        return 1.0;
    if (st&1)
        return bin_pow(a, st - 1) * a;
    double b = bin_pow(a, st>>1);
    return b*b;
}
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    for (int i = 1; i < 10; ++i){
        double p, ans = 0.0;
        p = (double)f(i + 1)/double(1<<(i));
        for (int k = 1; k < 1000000; ++k)
            ans += k*bin_pow(1.0 - p, k-1)*p;
        cout << i << " " << ans << " " << p + 1.0/p - 1.0 << endl;
    }
    return 0;
}
