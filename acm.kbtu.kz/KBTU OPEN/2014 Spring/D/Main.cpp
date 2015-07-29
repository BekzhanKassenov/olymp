/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "factorial"

typedef pair <int, int> PII;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld MOD = 3469708049238200000ll;
const int INF = 2000 * 1000 * 1000;
const double EPS = 1e-9;
const double pi = acos(-1.0);

template <typename T>
inline T sqr(T n) {
    return (n * n);
}

void take_mod(ld& n) {
    n -= ((int)(n / MOD)) * MOD;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    ll n;
    cin >> n;

    if (n > 60) {
        cout << 0;
        return 0;
    }

    ld fact = 1;

    for (int i = 1; i <= n; i++) {
        fact *= i;

        take_mod(fact);
    }

    cout << (ll)fact;

    return 0;
}
