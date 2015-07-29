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
#define File "round"

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
long long cur, tot = 0, a[5010];
long long ans[5010];
bool used[5010];
int main() {
    freopen(File".in", "r", stdin);
    freopen(File".out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        tot += a[i];
    }
    for (int i = 0; i < n; ++i){
        if ((a[i]*m)%tot == 0)
            used[i] = 1;
        cur += (a[i]*m)/tot;
        ans[i] = (a[i]*m)/tot;
    }
    int i = 0;
    while (cur < m){
        while (used[i])
            ++i;
        ans[i] = (a[i]*m + tot)/tot;
        i++;
        cur++;
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    return 0;
}
