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

ll f[100];

ll gcd(ll a, ll b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }

    return a + b;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    int n;
    cin >> n;

    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    ll den = f[n];
    ll num = (1ll << n);

    ll g = gcd(num, den);

    num /= g;
    den /= g;

    cout << num << '/' << den << endl;

    return 0;
}
