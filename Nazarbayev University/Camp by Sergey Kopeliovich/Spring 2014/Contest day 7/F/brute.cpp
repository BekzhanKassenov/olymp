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
#define File ""

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
bool check(ull x){
    for (ull i = 2; i*i <= x; ++i)
        if (x%i == 0){
            return 0;
            }
    return 1;        
}

vector<ull> p;

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    ull n = 10;
    while (n <= 1000000000000000000ull){
        ull t = n;
        while (!check(t))
            ++t;
        cout << t << ',' << endl;
        if (n == 1000000000000000000ull)
            break;
        n *= (ull)10;
    }
    cin >> n;
    return 0;
}

1000000000039