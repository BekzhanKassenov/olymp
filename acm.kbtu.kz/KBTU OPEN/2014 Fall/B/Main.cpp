/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define File "sum"

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

void test(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += i*i*(n/i);
    }
    cout << n << " " << ans << " " << n*(n+1)*n/2 - ans << endl;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    long long n, answer = 0, md = 123456789ll;
    cin >> n;

    answer += (n%md)*(n%md)*((n+1ll)%md)/2ll;

    for (long long i = 1ll; i <= n; i++) {
        answer -= i*(n%i);
    }

    for (int i = 1; i < 100; i++) {
        test(i);
    }

    cout << answer << endl;

    return 0;
}
