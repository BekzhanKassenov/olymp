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
#define File "heroes"

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
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n;
    cin >> n;
    
    if (n <= 4) {
        cout << "few";
    } else if (n <= 9) {
        cout << "several";
    } else if (n <= 19) {
        cout << "pack";
    } else if (n <= 49) {
        cout << "lots";
    } else if (n <= 99) {
        cout << "horde";
    } else if (n <= 249) {
        cout << "throng";
    } else if (n <= 499) {
        cout << "swarm";
    } else if (n <= 999) {
        cout << "zounds";
    } else
        cout << "legion";
    
    return 0;
}
