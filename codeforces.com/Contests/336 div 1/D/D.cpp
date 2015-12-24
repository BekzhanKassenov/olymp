/****************************************
**     Solution by Bekzhan Kassenov    **
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
const int BSIZE = 450;
const int MAXN = 200010;

template <typename T>
inline T sqr(T n) {
    return n * n;
}

int n;
vector <int> child[MAXN];

int size[MAXN], val[MAXN];
long long sumval[MAXN];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d", &val[1]);
    size[1] = 1;

    scanf("%d", &n);

    int last = 2;
    for (int i = 0; i < n; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int p, v;
            scanf("%d%d", &p, &v);

            child[p].push_back(v);
            size[p]++
        }
    }

    return 0;
}
