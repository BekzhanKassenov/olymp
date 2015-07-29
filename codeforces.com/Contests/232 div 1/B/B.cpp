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

bool prime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
            
    return true;
}

int u(int n) {
    while (n++) {
        if (prime(n))
            return n;
    }
    
    return 0;
}

int v(int n) {
    do {
        if (prime(n))
            return n;
    } while (n--);
    
    return 0;
}

ll gcd(ll a, ll b) {
    while (a && b) {
        a %= b;
        swap(a, b);
    }
    
    return a + b;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        int un = u(n);
        int vn = v(n);
        
        ll num = un * 1ll * vn - 2ll * un + 2ll * n - 2ll * vn + 2;
        ll den = 2ll * un * vn;
        
        ll g = gcd(num, den);
        
        num /= g;
        den /= g;
        
        cout << num << '/' << den << endl;
    } 
    return 0;
}
