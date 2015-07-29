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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

map<ll, int> Map;
long long ssa, ssb;
void collatz(long long a, long long b) {
    ssa = a;
    ssb = b;
    Map.clear();
    Map[a] = 0;
    int i = 0;

    while (a != 1ll) {
        if (a & 1ll) {
            a = 3ll * a + 1ll;
        } else {
            a = (a >> 1ll);
        }
        //cout << a << ' ' << i << endl;
        Map[a] = ++i;
    }

    i = 0;
    int sa = 0, sb = 0;
    long long c = 0;

    if (Map.count(b)) {
        sa = Map[b];
        sb = i;
        c = b;    
    } else {
        while (b != 1ll) {
            i++;
            
            if (b & 1ll) {
                b = 3ll * b + 1ll;
            } else {
                b = (b >> 1ll);
            }
            
            if (Map.count(b)) {
                sa = Map[b];
                sb = i;
                c = b;
                break;    
            }
        }
    }

    printf("%I64d needs %d steps, %I64d needs %d steps, they meet at %I64d\n", ssa, sa, ssb, sb, c);
}

int main() {
#ifdef Local
    freopen("in", "r", stdin);
#endif
    long long a, b;
    while (cin >> a >> b && a && b) {
        collatz(a, b);
    }
    return 0;
}
