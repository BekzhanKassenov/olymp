/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))

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

void make_mod(double& a, double M) {
    double b = (int)(a / M);
    a -= M * b;
}

bool cmp(double a, double b) {
    if (fabs(b - a) <= EPS)
        return true;
        
    return b - a >= 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    double a, d;
    
    scanf("%lf%lf", &a, &d);
    
    int n;
    scanf("%d", &n);
    
    double len = 4 * a;
    make_mod(d, len);
    
    double cur = 0;
    
    for (int i = 0; i < n; i++) {
        cur += d;
        make_mod(cur, len);
        
        if (cmp(cur, a)) {
            printf("%8lf %8lf", cur, .0);
        } else if (cmp(cur, 2 * a)) {
            printf("%8lf %8lf", a, cur - a);
        } else if (cmp(cur, 3 * a)) {
            printf("%8lf %8lf", 3 * a - cur, a);
        } else {
            printf("%8lf %8lf", .0, 4 * a - cur);
        }
        puts("");
    }
    
    return 0;
}
