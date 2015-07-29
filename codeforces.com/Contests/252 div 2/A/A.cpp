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

int n, v, k, x;
vector <int> ans;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    scanf("%d%d", &n, &v);

    for (int i = 0; i < n; i++) {
        scanf("%d", &k);

        bool can = false;

        for (int j = 0; j < k; j++) {
            scanf("%d", &x);

            if (x < v)
                can = true;
        }

        if (can)
            ans.push_back(i + 1);
    }

    printf("%u\n", ans.size());

    for (size_t j = 0; j < ans.size(); j++)
        printf("%d ", ans[j]);
    
    return 0;
}
