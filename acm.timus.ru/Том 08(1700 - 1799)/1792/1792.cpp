/****************************************
**          Solution by NU #2          **
****************************************/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset((x), y, sizeof(x))
#define File "hamming"

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

int main() {
#ifndef ONLINE_JUDGE    
    freopen("in", "r", stdin);
#endif
    
    int n = 7, a[10];
    
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int A = (a[1] + a[2] + a[3]) % 2;
    int B = (a[0] + a[2] + a[3]) % 2;
    int C = (a[0] + a[1] + a[3]) % 2;
    
    if (A != a[4] && B != a[5] && C != a[6]) a[3] = !a[3];
    if (A != a[4] && B == a[5] && C == a[6]) a[4] = !a[4];
    if (A == a[4] && B != a[5] && C == a[6]) a[5] = !a[5];
    if (A == a[4] && B == a[5] && C != a[6]) a[6] = !a[6];
    if (A != a[4] && B != a[5] && C == a[6]) a[2] = !a[2];
    if (A != a[4] && B == a[5] && C != a[6]) a[1] = !a[1];
    if (A == a[4] && B != a[5] && C != a[6]) a[0] = !a[0];
    
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    
    return 0;
}
