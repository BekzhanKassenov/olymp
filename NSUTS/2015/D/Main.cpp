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
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

struct Item {
    double area, rho, sigma;

    bool operator < (const Item& it) const {
        return sigma / rho < it.sigma / it.rho;
    }
};

Item it[MAXN];

double d;
int n;

bool check(double weight) {
    double suff = 0;
    double len = 0;

    for (int i = 0; i < n && len < d; i++) {
        double x = (it[i].area * it[i].sigma - weight - suff) / (it[i].area * it[i].rho);

        if (x > 0) {
            suff = min(suff + x * it[i].area * it[i].rho, (len + x) * it[i].area * it[i].rho);
            len += x;
        }
    }

    return len >= d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    cin >> d >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> it[i].area >> it[i].rho >> it[i].sigma;
    }

    sort(it, it + n);

    double l = 0, r = INF;

    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;

        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << setprecision(10) << fixed;
    cout << l;

    return 0;
}
