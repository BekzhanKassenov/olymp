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

struct st {
    int x, num, col;

    bool operator < (const st& s) const {
        return (x < s.x);
    }
};

bool cmp(const st& lhs, const st& rhs) {
    return lhs.num < rhs.num;
}

st a[110];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].x);
        a[i].num = i;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++)
        a[i].col = i % 2;

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++)
        cout << a[i].col << ' ';
    
    return 0;
}
