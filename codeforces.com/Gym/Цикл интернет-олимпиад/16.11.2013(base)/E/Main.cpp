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
#define File "poker"

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

int x, b;

int make(int cnt, char c) {
    int ans = 0;

    while (cnt > 0) {
        if (c == 'L') {
            cnt -= b;
            c = 'T';
        } else {
            cnt -= 2 * b;
            c = 'L';
        }
        ans++;
    }

    return ans;
}

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);

    cin >> x >> b;

    char c;

    cin >> c;

    cout << (x / (3 * b)) * 2 + make(x % (3 * b), c);

    return 0;
}
