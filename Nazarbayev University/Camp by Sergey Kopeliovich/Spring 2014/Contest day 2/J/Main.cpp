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
#define File "wrong"

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

bool used[1010];

int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    
    int n, k;
    cin >> n >> k;
    
    k %= n;

    int ans = 0;
    
    for (int cur = k; !used[cur]; cur = (cur + k) % n) {
        used[cur] = true;
        ans++;
    }
    
    cout << n - ans;
    
    return 0;
}
