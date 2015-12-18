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

template <typename T>
inline T sqr(T n) {
    return n * n;
}

enum RTYPE {
    VOVA,
    VANYA,
    BOTH
};

char name[][10] = {
    "Vova",
    "Vanya", 
    "Both"
};

int n, x, y;
int a;

int gcd(int x, int y) {
    while (x && y) {
        x %= y;
        swap(x, y);
    }

    return x + y;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d%d", &n, &x, &y);

    int g = gcd(x, y);
    int xx = x / g;
    int yy = y / g;

    map <long long, RTYPE> Map;
    for (int i = 1; i <= x; i++) {
        if (Map.count(1ll * i * yy)) {
            Map[1ll * i * yy] = BOTH;
        } else {
            Map[1ll * i * yy] = VANYA;
        }
    }

    for (int i = 1; i <= y; i++) {
        if (Map.count(1ll * i * xx)) {
            Map[1ll * i * xx] = BOTH;
        } else {
            Map[1ll * i * xx] = VOVA;
        }
    }

    vector <RTYPE> ans;
    ans.push_back(BOTH);

    for (const auto it: Map) {
        ans.push_back(it.second);

        if (it.second == BOTH) {
            ans.push_back(it.second);
        }
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        
        a %= xx + yy;

        puts(name[ans[a]]);
    }

    return 0;
}
