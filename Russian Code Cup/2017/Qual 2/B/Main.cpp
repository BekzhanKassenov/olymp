/*****************************************
**     Solution by Bekzhan Kassenov     **
*****************************************/

#include <bits/stdc++.h>

using namespace std;

#define by(T, x) [](const T& a, const T& b) { return a.x < b.x; }
#define all(x) (x).begin(), (x).end()

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const double EPS = 1e-9;
const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2000 * 1000 * 1000;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

long long gcd(long long a, long long b) {
    while (a && b) {
        a %= b;
        swap(a, b);    
    }
    return a + b;
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

long long a, b, c, d;

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif

    int T;
    cin >> T;

    while (T--) {
        cin >> a >> b >> c >> d;
        long long num = a * c;
        long long den = gcd(a * d, c * b);

        long long g = gcd(num, den);
        num /= g;
        den /= g;

        cout << num << ' ' << den << endl;
    }
    
    return 0;
}
