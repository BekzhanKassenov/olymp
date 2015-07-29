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

const int maxn = 1010;

struct st {
    int x, y, l;
};

st a[maxn], b[maxn];

bool intersects(const st& aa, const st& bb) {
    return (aa.y < bb.y && aa.y + aa.l > bb.y && bb.x < aa.x && bb.x + bb.l > aa.x);
}

int get(const st& aa, const st& bb) {
    int cx = aa.x, cy = bb.y;
    
    return (min(min(abs(bb.x - cx), abs(bb.x + bb.l - cx)), min(abs(aa.y - cy), abs(aa.y + aa.l - cy))));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n, m;
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y >> a[i].l;
    
    for (int i = 0; i < m; i++)
        cin >> b[i].x >> b[i].y >> b[i].l;
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (intersects(a[i], b[j]))
                ans = max(ans, get(a[i], b[j]));
        }
    }
    
    cout << ans;
    
    return 0;
}
